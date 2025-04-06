#pragma once

#include "is_alphanumeric.hpp"
#include <xutility>
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_symbolic(char const c) noexcept {
  return stl::str::is_alphanumeric(c) || c == '_';
 }
}