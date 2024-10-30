#pragma once

#include "types.hpp"
#include <span>
#include <array>
#include <ranges>
#include <string>
#include <concepts>

namespace stl::cvt {
 inline constexpr std::array<char, 16> HEX_LOOKUP{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

 std::string to_hex_string(IsSpanLike auto&& data) noexcept {
  std::string hex(std::size(data) << 1, '\0');
  auto s = std::data(hex);
  auto v = reinterpret_cast<u08 const*>(std::data(data));
  auto const v_end = v + std::size(data);
  if (std::size(data) == 0) [[unlikely]] {
   return std::string("");
  }
  do {
   *s++ = HEX_LOOKUP[*v >> 4];
   *s++ = HEX_LOOKUP[*v & 15];
  } while (++v != v_end);
  return hex;
 }

 /* Only works on unsigned. */
 std::string to_hex_string(std::unsigned_integral auto const data) noexcept requires(sizeof(data) == 8) {
  std::array<char, 16> buffer{
   HEX_LOOKUP[data >> 60     ], HEX_LOOKUP[data >> 56 & 15], HEX_LOOKUP[data >> 52 & 15], HEX_LOOKUP[data >> 48 & 15],
   HEX_LOOKUP[data >> 44 & 15], HEX_LOOKUP[data >> 40 & 15], HEX_LOOKUP[data >> 36 & 15], HEX_LOOKUP[data >> 32 & 15],
   HEX_LOOKUP[data >> 28 & 15], HEX_LOOKUP[data >> 24 & 15], HEX_LOOKUP[data >> 20 & 15], HEX_LOOKUP[data >> 16 & 15],
   HEX_LOOKUP[data >> 12 & 15], HEX_LOOKUP[data >>  8 & 15], HEX_LOOKUP[data >>  4 & 15], HEX_LOOKUP[data       & 15],
  };
  return std::string(std::data(buffer), std::size(buffer));
 }
 std::string to_hex_string(std::unsigned_integral auto const data) noexcept requires(sizeof(data) == 4) {
  std::array<char, 8> buffer{
   HEX_LOOKUP[data >> 28     ], HEX_LOOKUP[data >> 24 & 15], HEX_LOOKUP[data >> 20 & 15], HEX_LOOKUP[data >> 16 & 15],
   HEX_LOOKUP[data >> 12 & 15], HEX_LOOKUP[data >>  8 & 15], HEX_LOOKUP[data >>  4 & 15], HEX_LOOKUP[data       & 15],
  };
  return std::string(std::data(buffer), std::size(buffer));
 }
 std::string to_hex_string(std::unsigned_integral auto const data) noexcept requires(sizeof(data) == 2) {
  std::array<char, 4> buffer{ HEX_LOOKUP[data >> 12], HEX_LOOKUP[data >> 8 & 15], HEX_LOOKUP[data >> 4 & 15], HEX_LOOKUP[data & 15] };
  return std::string(std::data(buffer), std::size(buffer));
 }
 std::string to_hex_string(std::unsigned_integral auto const data) noexcept requires(sizeof(data) == 1) {
  std::array<char, 2> buffer{ HEX_LOOKUP[data >> 4], HEX_LOOKUP[data & 15] };
  return std::string(std::data(buffer), std::size(buffer));
 }
}