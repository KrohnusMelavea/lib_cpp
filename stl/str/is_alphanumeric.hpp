#pragma once

#include "is_alpha.hpp"
#include "is_numeric.hpp"
#include <xutility>
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_alphanumeric(char const c) noexcept {
  return is_alpha(c) || is_numeric(c);
 }
 [[nodiscard]] inline constexpr bool is_alphanumeric(std::string_view const s) noexcept {
  return std::all_of(
   std::cbegin(s),
   std::cend(s),
   static_cast<bool(&)(char const c)>(is_alphanumeric)
  );
 }
}