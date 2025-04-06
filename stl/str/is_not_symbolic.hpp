#pragma once

#include "is_not_alphanumeric.hpp"
#include <xutility>
#include <algorithm>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr bool is_not_symbolic(char const c) noexcept {
  return stl::str::is_not_alphanumeric(c) && c != '_';
 }
}