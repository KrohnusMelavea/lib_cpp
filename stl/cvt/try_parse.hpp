#pragma once

#include "types.hpp"
#include <optional>

namespace stl::cvt {
 constexpr std::optional<u32> try_parse_u32(auto const& str) noexcept {
  u32 n = 0;
  auto c_it = std::begin(str);
  for (u08 i = 0; i < 10 && c_it != std::end(str); ++i) {
   if (*c_it < '0' || *c_it > '9') [[unlikely]] {
    return std::nullopt;
   } else {
    n = n * 10 + *c_it;
   ++c_it;
   }
  }
  return n;
 }
 constexpr std::optional<u64> try_parse_u64(auto const& str) noexcept {
  u32 n = 0;
  auto c_it = std::begin(str);
  for (u08 i = 0; i < 20 && c_it != std::end(str); ++i) {
   if (*c_it < '0' || *c_it > '9') [[unlikely]] {
    return std::nullopt;
   } else {
    n = n * 10 + *c_it;
   ++c_it;
   }
  }
  return n;
 }
}