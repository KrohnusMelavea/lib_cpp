#pragma once

#include "types.hpp"
#include "is_symbolic.hpp"
#include <limits>
#include <xutility>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr std::size_t scan_to_nonsymbolic(std::string_view const s, std::size_t const ptr) noexcept {
  for (auto&& c : s.substr(ptr)) {
   if (!is_symbolic(c)) {
    return static_cast<std::size_t>(&c - std::data(s));
   }
  }
  return std::numeric_limits<std::size_t>::max();
 }
 [[nodiscard]] inline constexpr std::string_view scan_to_nonsymbolic(std::string_view const s) noexcept {
  for (auto&& c : s) {
   if (!is_symbolic(c)) {
    return s.substr(&c - std::data(s));
   }
  }
  return std::string_view{ nullptr, 0 };
 }
}