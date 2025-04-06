#pragma once

#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_whitespace(char const c) noexcept {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
 }
 [[nodiscard]] inline constexpr bool is_whitespace(std::string_view const s) noexcept {
  return std::all_of(
   std::cbegin(s),
   std::cend(s),
   static_cast<bool(&)(char const c)>(is_whitespace)
  );
 }
}