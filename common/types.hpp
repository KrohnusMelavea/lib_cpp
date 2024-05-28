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

namespace std {
#ifdef _WIN64
    typedef u64 size_t;
#else
    typedef u32 size_t;
#endif
}

inline constexpr i08 operator""_i08(unsigned long long n) {
    return n;
}