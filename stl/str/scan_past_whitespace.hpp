#pragma once

#include "types.hpp"
#include "is_whitespace.hpp"
#include <limits>
#include <xutility>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr std::size_t scan_past_whitespace(std::string_view const s, std::size_t const ptr) noexcept {
  for (auto&& c : s.substr(ptr)) {
   if (!is_whitespace(c)) {
    return static_cast<std::size_t>(&c - std::data(s));
   }
  }
  return std::numeric_limits<std::size_t>::max();
 }
 [[nodiscard]] inline constexpr std::string_view scan_past_whitespace(std::string_view const s) noexcept {
  for (auto&& c : s) {
   if (!is_whitespace(c)) {
    return s.substr(&c - std::data(s));
   }
  }
  return std::string_view{ nullptr, 0 };
 }
}