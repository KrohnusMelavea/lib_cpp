#include <print>
#include <limits>
#include <vector>
#include <cstdint>
#include <cstring>
#include <utility>
#include <charconv>
#include <stdfloat>
#include <algorithm>
#include <string_view>

typedef std::int64_t i64;
typedef double       f64;

static_assert(sizeof(f64) == 8);

struct json_list;
struct json_map;
struct json_pair;
struct json_object;

template <class T>
struct parse_result {
    char const* ptr;
    T value;
};

enum class json_type {
    invalid,
    null,
    text,
    boolean,
    integer,
    real,
    number,
    list,
    map
};

constexpr char const* scan_past_whitespace_to_double_quote_or_close_brace(char const* ptr) noexcept {
    while (true) {
        switch (*ptr) {
            [[unlikely]]
            case '\0': return nullptr;
            case ' ':  [[fallthrough]];
            case '\t': [[fallthrough]];
            case '\r': [[fallthrough]];
            case '\n': {
                ++ptr;
                break;
            }
            case '"': return ptr;
            default: return nullptr;
        }
    }
}
constexpr char const* scan_past_whitespace_to_colon(char const* ptr) noexcept {
    while (true) {
        switch (*ptr) {
            [[unlikely]]
            case '\0': return nullptr;
            case ' ':  [[fallthrough]];
            case '\t': [[fallthrough]];
            case '\r': [[fallthrough]];
            case '\n': {
                ++ptr;
                break;
            }
            case ':': return ptr;
            default: return nullptr;
        }
    }
}
constexpr char const* scan_past_whitespace_to_comma_or_close_brace(char const* ptr) noexcept {
    while (true) {
        switch (*ptr) {
            [[unlikely]]
            case '\0': return nullptr;
            case ' ':  [[fallthrough]];
            case '\t': [[fallthrough]];
            case '\r': [[fallthrough]];
            case '\n': {
                ++ptr;
                break;
            }
            case ',': [[fallthrough]];
            case '}': return ptr;
            default: return nullptr;
        }
    }
}

constexpr char const* scan_to_double_quote(char const* ptr) noexcept {
    while (true) {
        switch (*ptr) {
            [[unlikely]]
            case '\0': return nullptr;
            case '"': return ptr;
            default: ++ptr;
        }
    }
}

constexpr parse_result<json_type> scan_past_whitespace_to_pair_value(char const* ptr) noexcept {
    while (true) {
        auto const c = *ptr;
        if ('0' <= c && c <= '9') return { ptr, json_type::number };
        switch (*ptr) {
            [[unlikely]]
            case '\0': return {};
            case ' ':  [[fallthrough]];
            case '\t': [[fallthrough]];
            case '\r': [[fallthrough]];
            case '\n': {
                ++ptr;
                break;
            }
            case '"': return { ptr, json_type::text }; //will quit on strings that contain a double quote, check escape
            case '[': return { ptr, json_type::list };
            case '{': return { ptr, json_type::map };
            default: return {};
        }
    }
}
constexpr char const* scan_past_digits(char const* ptr) noexcept {
    while (true) {
        auto const c = *ptr;
        if (c == '\0') [[unlikely]] return nullptr;
        if (c < '0' || c > '9') return ptr;
        ++ptr;
    }
}
struct json_list {
    json_object* objects;
    std::size_t object_count;

    [[nodiscard]]
    static constexpr parse_result<json_list> construct(char const* json) noexcept;
    constexpr void destruct() const noexcept;
};
struct json_map {
    json_pair* pairs;
    std::size_t pair_count;

    [[nodiscard]]
    static constexpr parse_result<json_map> construct(char const* json) noexcept;
    constexpr void destruct() const noexcept;

    constexpr void insert(json_pair const pair) noexcept;
};
struct json_object {
    json_type type;
    union {
        char* text;
        i64 integer;
        f64 real;
        json_list list;
        json_map map;
    } value;

    static constexpr parse_result<json_object> construct(json_type type, char const* json) noexcept {
        switch (type) {
            case json_type::list: {
                auto const json_list_parse_result = json_list::construct(json);
                return {
                    json_list_parse_result.ptr,
                    {
                        .type = type,
                        .value{ .list = json_list_parse_result.value }
                    }
                };
            }
            case json_type::map: {
                auto const json_map_parse_result = json_map::construct(json);
                return {
                    json_map_parse_result.ptr,
                    {
                        .type = type,
                        .value{ .map = json_map_parse_result.value }
                    }
                };
            }
            case json_type::text: {
                ++json; // double-check that it does actually start with " and that im not just crazy
                auto const end_of_string = scan_to_double_quote(json);
                if (end_of_string == nullptr) [[unlikely]] return {};
                auto const size = static_cast<std::size_t>(end_of_string - json);
                auto const str = new char[size + 1];
                (void)std::copy(
                    json, 
                    end_of_string, 
                    str    
                );
                str[size] = '\0';
                auto a = json_object{};
                a.type = json_type::text;
                a.value.text = str;
                return {
                    end_of_string + 1,
                    a
                };
            }
            case json_type::number: {
                auto after_digits = scan_past_digits(json);
                if (after_digits == nullptr) [[unlikely]] return {};

                if (*after_digits == '.') {
                    ++after_digits;
                    auto const after_decimal_digits = scan_past_digits(json);
                    if (after_decimal_digits == nullptr || after_decimal_digits == json) [[unlikely]] return {};

                    f64 value;
                    std::from_chars(json, after_decimal_digits, value); //replace with own function
                    return {
                        after_decimal_digits,
                        {
                            .type = type,
                            .value{ .real = value }
                        }
                    };
                } else {
                    i64 value;
                    std::from_chars(json, after_digits, value);
                    return {
                        after_digits,
                        {
                            .type = type,
                            .value{ .integer = value }
                        }
                    };
                }
            }
            default: std::unreachable();
        }
    }
    constexpr void destruct() const noexcept {
        switch (this->type) {
            case json_type::integer: [[fallthrough]];
            case json_type::real: break;
            case json_type::text: {
                delete[] this->value.text;
                break;
            }
            case json_type::list: {
                this->value.list.destruct();
                break;
            }
            case json_type::map: {
                this->value.map.destruct();
                break;
            }
            default: std::unreachable();
        }
    }
};
struct json_pair {
    std::string_view key; 
    json_object value;

    static constexpr parse_result<json_pair> construct(char const* json) noexcept {
        // json = scan_past_whitespace_to_double_quote(json);
        // if (json == nullptr) [[unlikely]] return {};

        auto const end_of_key = scan_to_double_quote(++json);
        if (end_of_key == nullptr) [[unlikely]] return {};
        std::string_view const key{json, end_of_key};

        json = scan_past_whitespace_to_colon(end_of_key + 1);
        if (json == nullptr) [[unlikely]] return {};

        auto const parse_result = scan_past_whitespace_to_pair_value(json + 1);
        if (parse_result.ptr == nullptr) [[unlikely]] return {};

        auto const obj_result = json_object::construct(parse_result.value, parse_result.ptr);
        if (obj_result.ptr == nullptr) [[unlikely]] return {};

        return {
            obj_result.ptr,
            {
                .key = key,
                .value = obj_result.value
            }
        };
    }
    constexpr void destruct() const noexcept {
        this->value.destruct();
    }
};

constexpr parse_result<json_map> json_map::construct(char const* json) noexcept {
    ++json; /* skip past '{' */
    json_map map{
        .pairs = new json_pair[0],
        .pair_count = 0
    };

    json = scan_past_whitespace_to_double_quote_or_close_brace(json);

    auto const pair = json_pair::construct(json);
    if (pair.ptr == nullptr) [[unlikely]] {
        delete[] map.pairs;
        return {};
    }

    map.insert(pair.value);

    json = scan_past_whitespace_to_comma_or_close_brace(pair.ptr);
    if (json == nullptr) [[unlikely]] {
        map.pairs[0].destruct();
        delete[] map.pairs;
        return {};
    }
    if (*json == ',') {
        auto const new_pair = json_pair::construct(json + 1);
        if (new_pair.ptr == nullptr) [[unlikely]] {
            map.pairs[0].destruct();
            delete[] map.pairs;
            return {};
        }
        map.insert(new_pair.value);
        return {
            new_pair.ptr, //remember scanning past the whole everything stuffs
            map
        };
    } else {
        return {
            pair.ptr, //remember scanning past the whole everything stuffs
            map
        };
    }
}
constexpr void json_map::destruct() const noexcept {
    for (std::size_t i = 0; i < this->pair_count; ++i) {
        this->pairs[i].destruct();
    }
    delete[] this->pairs;
}
constexpr void json_map::insert(json_pair const pair) noexcept {
    auto const pairs_copy = new json_pair[this->pair_count + 1];
    (void)std::copy(
        this->pairs,
        this->pairs + this->pair_count,
        pairs_copy
    );
    delete[] this->pairs;
    this->pairs = pairs_copy;
    this->pairs[this->pair_count++] = pair;
}
constexpr void json_list::destruct() const noexcept {
    for (std::size_t i = 0; i < this->object_count; ++i) {
        this->objects[i].destruct();
    }
    delete[] this->objects;
}

constexpr json_object read_json_object(std::string_view const json) noexcept {
    auto const map = json_map::construct(std::data(json));
    if (map.ptr == nullptr) [[unlikely]] {
        map.value.destruct();
        return {};
    }

    json_object root{
        .type = json_type::map,
        .value{ .map = map.value }
    };

    return root;
}

constexpr auto get() noexcept {
    std::string_view json_sample = "{\"key\": \"val\", \"key2\": {\"a\": \"b\"}}";
    auto obj = read_json_object(json_sample);
    if (obj.type == json_type::invalid) [[unlikely]] {
        return std::numeric_limits<std::size_t>::max();
    } 
    auto const key = obj.value.map.pairs[1].value.value.map.pair_count;
    obj.destruct();
    return key;
}

constexpr auto get2() noexcept {
    std::string_view json_sample = "{\"key\": \"val\", \"key3\": [], \"key2\": {\"a\": \"b\"}}";
    auto const obj = read_json_object(json_sample);
    return obj;
}

int main() {
    static constexpr auto obj = get();
    if (obj == std::numeric_limits<std::size_t>::max()) {
        return -1;
    } else {
        return static_cast<int>(obj);
    }
    std::print("{}", obj);
}