#pragma once

#include "is_not_alpha.hpp"
#include "is_not_numeric.hpp"
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_not_alphanumeric(char const c) noexcept {
  return is_not_alpha(c) && is_not_numeric(c);
 }
 [[nodiscard]]
  inline constexpr bool is_not_alphanumeric(std::string_view const s) noexcept {
  return std::any_of(
   std::cbegin(s),
   std::cend(s),
   static_cast<bool(&)(char const c)>(is_not_alphanumeric)
  );
 }
}