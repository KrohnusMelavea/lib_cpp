#pragma once

#include "types.hpp"
#include <string_view>

namespace net {
 [[nodiscard]] inline constexpr u32 convert_ipv4_string_to_u32(std::string_view const address_string) {
  u32 address = 0;
  for (auto const c : address_string) {
   if (c == '.') [[unlikely]] {
    address <<= 8;
   } else [[likely]] {
    address = (address & 0xFFFFFF00) | ((address & 0xFF) * 10 + (c - '0'));
   }
  }
  return (address << 24) | ((address << 8) & 0xFF0000) | ((address >> 8) & 0xFF00) | (address >> 24); // reverse
 }
}