#pragma once

#include <xutility>
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_not_alpha_lowercase(char const c) noexcept {
  return 'a' > c || c > 'z';
 }
 [[nodiscard]] inline constexpr bool is_not_alpha_lowercase(std::string_view const s) noexcept {
  return std::any_of(
   std::cbegin(s),
   std::cend(s),
   static_cast<bool(&)(char const c)>(is_not_alpha_lowercase)
  );
 }
}