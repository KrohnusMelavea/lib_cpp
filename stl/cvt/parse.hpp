#pragma once

#include "types.hpp"
#include <optional>

namespace stl::cvt {
 constexpr u32 parse_u32(auto const& str) noexcept {
  u32 n = 0;
  auto c_it = std::begin(str);
  for (u08 i = 0; i < 10 && c_it != std::end(str); ++i) {
   n = n * 10 + *(c_it++);
  }
  return n;
 }
 constexpr u64 parse_u64(auto const& str) noexcept {
  u32 n = 0;
  auto c_it = std::begin(str);
  for (u08 i = 0; i < 20 && c_it != std::end(str); ++i) {
   n = n * 10 + *(c_it++);
  }
  return n;
 }
}