#pragma once

#include "is_alpha_lowercase.hpp"
#include "is_alpha_uppercase.hpp"
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_alpha(char const c) noexcept {
  return is_alpha_lowercase(c) || is_alpha_uppercase(c);
 }
 [[nodiscard]] inline constexpr bool is_alpha(std::string_view const s) noexcept {
  return std::all_of(
   std::cbegin(s),
   std::cend(s),
   static_cast<bool(&)(char const c)>(is_alpha)
  );
 }
}
