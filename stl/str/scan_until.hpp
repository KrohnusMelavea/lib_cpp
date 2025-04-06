#pragma once

#include "types.hpp"
#include "is_whitespace.hpp"
#include <limits>
#include <xutility>
#include <functional>
#include <string_view>

namespace stl::str {
 [[nodiscard]] inline constexpr std::size_t scan_until(std::string_view const s, std::size_t const ptr, std::function<bool(char const)>&& predicate) noexcept {
  for (auto&& c : s.substr(ptr)) {
   if (predicate(c)) {
    return static_cast<std::size_t>(&c - std::data(s));
   }
  }
  return std::numeric_limits<std::size_t>::max();
 }
 [[nodiscard]] inline constexpr std::size_t scan_until(std::string_view const s, std::size_t const ptr, char const sentinel) noexcept {
  for (auto&& c : s.substr(ptr)) {
   if (c == sentinel) {
    return static_cast<std::size_t>(&c - std::data(s));
   }
  }
  return std::numeric_limits<std::size_t>::max();
 }
 [[nodiscard]] inline constexpr std::string_view scan_until(std::string_view const s, std::function<bool(char const)>&& predicate) noexcept {
  for (auto&& c : s) {
   if (predicate(c)) {
    return s.substr(&c - std::data(s));
   }
  }
  return std::string_view{ nullptr, 0 };
 }
 [[nodiscard]] inline constexpr std::string_view scan_until(std::string_view const s, char const sentinel) noexcept {
  for (auto&& c : s) {
   if (c == sentinel) {
    return s.substr(&c - std::data(s));
   }
  }
  return std::string_view{ nullptr, 0 };
 }
}