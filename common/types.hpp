#pragma once

#include <cstdint>
#include <string_view>
#include <type_traits>

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

constexpr bool is_hex(char const c) noexcept {
 return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
constexpr bool is_uuid(std::string_view const string) noexcept {
 if (std::size(string) != 36) [[unlikely]] {
  return false;
 }
 for (char const c : string) {
  if (!::is_hex(c) && c != '-') [[unlikely]] {
   return false;
  }
 }
 return true;
}

