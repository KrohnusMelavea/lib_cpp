#pragma once

#include "is_not_alpha_lowercase.hpp"
#include "is_not_alpha_uppercase.hpp"
#include <xutility>
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_not_alpha(char const c) noexcept {
  return is_not_alpha_lowercase(c) && is_not_alpha_uppercase(c);
 }
 [[nodiscard]] inline constexpr bool is_not_alpha(std::string_view const s) noexcept {
  return std::any_of(
   std::cbegin(s),
   std::cend(s),
   static_cast<bool(&)(char const c)>(is_not_alpha)
  );
 }
}
