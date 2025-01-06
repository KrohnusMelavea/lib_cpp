#pragma once

#include "types.hpp"

namespace stl::bit {
 [[nodiscard]] constexpr auto rotate_left(std::unsigned_integral auto const value, auto const count = 1_u32) noexcept -> decltype(value) {
  return static_cast<decltype(value)>((value << count) | static_cast<decltype(value)>(value >> ((sizeof(value) << 3) - count)));
 }
 [[nodiscard]] constexpr auto rotate_right(std::unsigned_integral auto const value, auto const count = 1_u32) noexcept -> decltype(value) {
  return static_cast<decltype(value)>((value >> count) | static_cast<decltype(value)>(value << ((sizeof(value) << 3) - count)));
 }
}