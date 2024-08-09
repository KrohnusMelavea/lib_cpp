#pragma once

#include <cstdint>

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

inline constexpr i08 operator""_i08(u64 const n) noexcept { return static_cast<i08>(n); }
inline constexpr i16 operator""_i16(u64 const n) noexcept { return static_cast<i16>(n); }
inline constexpr i32 operator""_i32(u64 const n) noexcept { return static_cast<i32>(n); }
inline constexpr i64 operator""_i64(u64 const n) noexcept { return static_cast<i64>(n); }
inline constexpr u08 operator""_u08(u64 const n) noexcept { return static_cast<u08>(n); }
inline constexpr u16 operator""_u16(u64 const n) noexcept { return static_cast<u16>(n); }
inline constexpr u32 operator""_u32(u64 const n) noexcept { return static_cast<u32>(n); }
inline constexpr u64 operator""_u64(u64 const n) noexcept { return static_cast<u64>(n); }
inline constexpr f32 operator""_f32(f96 const n) noexcept { return static_cast<f32>(n); }
inline constexpr f64 operator""_f64(f96 const n) noexcept { return static_cast<f64>(n); }
inline constexpr f96 operator""_f96(f96 const n) noexcept { return static_cast<f96>(n); }