#include <print>
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

struct json_arr;
struct json_map;
struct json_pair;
struct json_object;

template <class T>
struct parse_result {
 char const* ptr;
 T value;
};

enum class json_type {
 str,
 bit,
 i64,
 f64,
 num,
 arr,
 map
};

constexpr char const* scan_past_whitespace_to_double_quote(char const* ptr) noexcept {
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
   case '{': return ptr;
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
  if ('0' <= c && c <= '9') return { ptr, json_type::num };
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
   case '"': return { ptr, json_type::str };
   case '[': return { ptr, json_type::arr };
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
struct json_arr {
 json_object* objects;
 std::size_t object_count;

 [[nodiscard]]
 static constexpr parse_result<json_arr> construct(char const* json) noexcept;
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
  char* str;
  i64 i64;
  f64 f64;
  json_arr arr;
  json_map map;
 } value;

 static constexpr parse_result<json_object> construct(json_type type, char const* json) noexcept {
  switch (type) {
   case json_type::arr: {
    auto const json_arr_parse_result = json_arr::construct(json);
    return {
     json_arr_parse_result.ptr,
     {
      .type = type,
      .value{ .arr = json_arr_parse_result.value }
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
   case json_type::str: {
    ++json; // double-check that it does actually start with " and that im not just crazy
    auto const end_of_string = scan_to_double_quote(json);
    if (end_of_string == nullptr) [[unlikely]] return {};
    auto const str = std::copy(json, end_of_string, new char[end_of_string - json + 1]);
    str[end_of_string - json] = '\0';
    return {
     end_of_string,
     {
      .type = type,
      .value{ .str = str }
     }
    };
   }
   case json_type::num: {
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
       .value{ .f64 = value }
      }
     };
    } else {
     i64 value;
     std::from_chars(json, after_digits, value);
     return {
      after_digits,
      {
       .type = type,
       .value{ .i64 = value }
      }
     };
    }
   }
   default: std::unreachable();
  }
 }
 constexpr void destruct() const noexcept {
  switch (this->type) {
   case json_type::i64: [[fallthrough]];
   case json_type::f64: break;
   case json_type::str: {
    delete[] this->value.str;
    break;
   }
   case json_type::arr: {
    this->value.arr.destruct();
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
  json = scan_past_whitespace_to_double_quote(json);
  if (json == nullptr) [[unlikely]] return {};

  auto const end_of_key = scan_to_double_quote(++json);
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
  .pairs = nullptr,
  .pair_count = 0
 };
 auto const pair = json_pair::construct(json);
 map.insert(pair.value);
 return {
  pair.ptr, //remember scanning past the whole everything stuffs
  map
 };
}
constexpr void json_map::destruct() const noexcept {
 for (std::size_t i = 0; i < this->pair_count; ++i) {
  this->pairs[i].destruct();
 }
 delete[] this->pairs;
}
constexpr void json_map::insert(json_pair const pair) noexcept {
 auto const pairs_copy = std::copy(
  this->pairs,
  this->pairs + this->pair_count,
  new json_pair[this->pair_count + 1]
 );
 delete[] this->pairs;
 this->pairs = pairs_copy;
 ++this->pairs;
}
constexpr void json_arr::destruct() const noexcept {
 for (std::size_t i = 0; i < this->object_count; ++i) this->objects[i].destruct();
 delete[] this->objects;
}

constexpr json_object read_json_object(std::string_view json) noexcept {
 json_object root = json_object{ .type = json_type::map };
 return root;
}

int main() {
 static constexpr std::string_view json_sample = "{\"key\": \"val\"}";
 static constexpr auto obj = read_json_object(json_sample);
 obj.destruct();
}