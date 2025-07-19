#pragma once

#include <array>
#include <tuple>
#include <cstdint>
#include <utility>
#include <concepts>
#include <algorithm>
#include <string_view>
#include <type_traits>
#include "stl/string_literal.hpp"

typedef std::int8_t   i08;
typedef std::int16_t  i16;
typedef std::int32_t  i32;
typedef std::int64_t  i64;
typedef std::uint8_t  u08;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;
typedef float         f32;
typedef double        f64;
typedef long double   f96;

namespace std {
#ifdef _WIN64
 typedef u64 size_t;
#else
 typedef u32 size_t;
#endif
}

inline consteval i08 operator""_i08(u64 const n) noexcept { return static_cast<i08>(n); }
inline consteval i16 operator""_i16(u64 const n) noexcept { return static_cast<i16>(n); }
inline consteval i32 operator""_i32(u64 const n) noexcept { return static_cast<i32>(n); }
inline consteval i64 operator""_i64(u64 const n) noexcept { return static_cast<i64>(n); }
inline consteval u08 operator""_u08(u64 const n) noexcept { return static_cast<u08>(n); }
inline consteval u16 operator""_u16(u64 const n) noexcept { return static_cast<u16>(n); }
inline consteval u32 operator""_u32(u64 const n) noexcept { return static_cast<u32>(n); }
inline consteval u64 operator""_u64(u64 const n) noexcept { return static_cast<u64>(n); }
inline consteval f32 operator""_f32(f96 const n) noexcept { return static_cast<f32>(n); }
inline consteval f64 operator""_f64(f96 const n) noexcept { return static_cast<f64>(n); }
inline consteval f96 operator""_f96(f96 const n) noexcept { return static_cast<f96>(n); }

template <class T = void, class... Ts> struct max_type_size {
 static constexpr std::size_t value = sizeof(T) < max_type_size<Ts...>::value ? max_type_size<Ts...>::value : sizeof(T);
};
template <> struct max_type_size<> {
 static constexpr std::size_t value = 0;
};
template <class... Ts> static constexpr auto max_type_size_v = max_type_size<Ts...>::value;

/* Atomic Concepts */
template <class T> concept IsAddableWithSelf = requires(T a, T b) {
 a + b;
};
template <class T> concept IsSubtractableWithSelf = requires(T a, T b) {
 a - b;
};
template <class T> concept IsMultipliableWithSelf = requires(T a, T b) {
 a * b;
};
template <class T> concept IsDividableWithSelf = requires(T a, T b) {
 a / b;
};
template <class T> concept IsModableWithSelf = requires(T a, T b) {
 a % b;
};
template <class T> concept IsLeftShiftableWithSelf = requires(T a, T b) {
 a << b;
};
template <class T> concept IsRightShiftableWithSelf = requires(T a, T b) {
 a >> b;
};
template <class T> concept IsORableWithSelf = requires(T a, T b) {
 a | b;
};
template <class T> concept IsANDableWithSelf = requires(T a, T b) {
 a & b;
};
template <class T> concept IsXORableWithSelf = requires(T a, T b) {
 a ^ b;
};

template <class T> concept IsAddAssignableWithSelf = requires(T a, T b) {
 a += b;
};
template <class T> concept IsSubtractAssignableWithSelf = requires(T a, T b) {
 a -= b;
};
template <class T> concept IsMultiplyAssignableWithSelf = requires(T a, T b) {
 a *= b;
};
template <class T> concept IsDivideAssignableWithSelf = requires(T a, T b) {
 a /= b;
};
template <class T> concept IsModAssignableWithSelf = requires(T a, T b) {
 a %= b;
};
template <class T> concept IsLeftShiftAssignableWithSelf = requires(T a, T b) {
 a <<= b;
};
template <class T> concept IsRightShiftAssignableWithSelf = requires(T a, T b) {
 a >>= b;
};
template <class T> concept IsORAssignableWithSelf = requires(T a, T b) {
 a |= b;
};
template <class T> concept IsANDAssignableWithSelf = requires(T a, T b) {
 a &= b;
};

template <typename T> concept HasDataMethod = requires(T a) {
 a.data();
};
template <class T> concept HasSizeMethod = requires(T a) {
 a.size();
};

//Compound Concepts
template <class T> concept IsSpanLike = requires(T a) {
 requires HasDataMethod<T>;
 requires HasSizeMethod<T>;
};

inline constexpr bool is_alpha_lowercase(char const c) noexcept {
 return 'a' <= c && c <= 'z';
}
inline constexpr bool is_alpha_uppercase(char const c) noexcept {
 return 'A' <= c && c <= 'Z';
}
inline constexpr bool is_alpha(char const c) noexcept {
 return is_alpha_lowercase(c) || is_alpha_uppercase(c);
}
inline constexpr std::array<char, 19> SPECIAL_CHARACTERS{'!', '#', '$', '%', '&', '\'', '*', '+', '-', '/', '=', '?', '^', '_', '`', '{', '|', '}', '~'};
inline constexpr bool is_special(char const c) noexcept {
 return std::find(std::cbegin(SPECIAL_CHARACTERS), std::cend(SPECIAL_CHARACTERS), c) != std::cend(SPECIAL_CHARACTERS);
}
inline constexpr bool is_digit(char const c) noexcept {
 return '0' <= c && c <= '9';
}
inline constexpr bool is_alphanumeric(char const c) noexcept {
 return is_alpha(c) || is_digit(c);
}
inline constexpr bool is_printable(char const c) noexcept {
 return is_alphanumeric(c) || is_special(c);
}
inline constexpr bool is_hex(char const c) noexcept {
 return is_digit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F');
}

inline constexpr bool is_uuid(std::string_view const uuid) noexcept {
 if (std::size(uuid) != 36) [[unlikely]] {
  return false;
 }
 for (char const c : uuid) {
  if (!::is_hex(c) && c != '-') [[unlikely]] /* UUIDv4 may only contain hexidecimal and '-' characters */ {
   return false;
  }
 }
 return true;
}
constexpr bool is_email(std::string_view const email) noexcept {
 if (std::size(email) < 5) [[unlikely]] /* Minimal email (a@b.c) is 5 characters  */ {
  return false;
 }
 char const *ptr = std::data(email);
 char const *end_ptr = ptr + std::size(email);
 if (!(is_alpha(*ptr) || is_special(*ptr)) || *ptr == '.' || *ptr == '@') [[unlikely]] {
  return false;
 }
 bool has_at = false;
 bool has_end_dot = false;
 while (++ptr != end_ptr) {
  if (*ptr == '@') [[unlikely]] /* Post characters in Email are alphanumeric */ {
   if (has_at) [[unlikely]] /* Email may have only one domain */ {
    return false;
   } else if (*(ptr - 1) == '.') [[unlikely]] /* Final character in local part of email may not be '.' */ {
    return false;
   } else if (ptr + 3 >= end_ptr) [[unlikely]] /* Shorted domain 'b.c' is 3 characters */ {
    return false;
   } else if (*(ptr + 1) == '.') [[unlikely]] /* Domain may not be empty */ {
    return false;
   } else [[likely]] {
    continue;
   }
  } else if (*ptr == '.') {
   if (ptr + 1 == end_ptr) [[unlikely]] /* Final character of email may not be '.' */ {
    return false;
   } else [[likely]] {
    if (has_at) /* Domain must contain root zone */ {
     has_end_dot = true;
    }
    continue;
   }
  } else if (!is_printable(*ptr)) [[unlikely]] /* Email may only contain printable characters */ {
   return false;
  } else [[likely]] {
   continue;
  }
 }
 return has_end_dot;
}
inline constexpr bool is_hex(std::string_view const hex) noexcept {
 return std::find_if(std::cbegin(hex), std::cend(hex), [&](auto const c) noexcept { return !is_hex(c); }) == std::cend(hex);
}

template <stl::string_literal str> bool is_datetime(std::string_view const dt) noexcept {
 return false;
}
extern template bool is_datetime<"YYYY-MM-DD hh:mm:ss">(std::string_view const dt) noexcept;

template <std::size_t offset, class sequence> struct offset_sequence;
template <std::size_t offset, std::size_t... integers> 
struct offset_sequence<offset, std::index_sequence<integers...>> {
 using type = std::index_sequence<integers + offset...>;
};
template <std::size_t offset, class sequence> 
using offset_sequence_t = typename offset_sequence<offset, sequence>::type;

template <class Tuple, std::size_t a, class sequence> struct tuple_subset_impl;
template <class Tuple, std::size_t a, std::size_t... indices> 
struct tuple_subset_impl<Tuple, a, std::index_sequence<indices...>> {
 using type = std::tuple<typename std::tuple_element<indices, Tuple>::type...>;
};
template <class Tuple, std::size_t a, std::size_t b> 
struct tuple_subset {
 using type = tuple_subset_impl<Tuple, a, offset_sequence_t<a, std::make_index_sequence<b - a>>>::type;
};
template <class Tuple, std::size_t a, std::size_t b = std::tuple_size_v<Tuple>> 
using tuple_subset_t = tuple_subset<Tuple, a, b>::type;




[[nodiscard]] inline constexpr bool is_max(std::integral auto const n) noexcept {
 return std::numeric_limits<decltype(n)>::max();
}
[[nodiscard]] inline constexpr bool is_min(std::integral auto const n) noexcept {
 return std::numeric_limits<decltype(n)>::min();
}