#pragma once

#include "types.hpp"
#include <string>
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
 [[nodiscard]] inline std::string convert_ipv4_u32_to_string(u32 const address) {
  static char buffer[16];

  u08 const octets[4] {
   address & 0xff,
   (address >> 8) & 0xff,
   (address >> 16) & 0xff, 
   address >> 24,
  };

  u08 const calcs[12] {
   octets[0] / 100u,
   (octets[0] % 100u) / 10u,
   octets[0] % 10u,
   octets[1] / 100u,
   (octets[1] % 100u) / 10u,
   octets[1] % 10u,
   octets[2] / 100u,
   (octets[2] % 100u) / 10u,
   octets[2] % 10u,
   octets[3] / 100u,
   (octets[3] % 100u) / 10u,
   octets[3] % 10u,
  };

  u08 i = 0;
  /* Octet #1 */
  if (calcs[0]) {
   buffer[i] = calcs[0] + '0';
   buffer[i + 1] = calcs[1] + '0';
   i += 2;
  } else if (calcs[1]) buffer[i++] = calcs[1] + '0';
  buffer[i] = calcs[2] + '0';
  buffer[i + 1] = '.';
  i += 2;
  /* Octet #2 */
  if (calcs[3]) {
   buffer[i] = calcs[3] + '0';
   buffer[i + 1] = calcs[4] + '0';
   i += 2;
  } else if (calcs[4]) buffer[i++] = calcs[4] + '0';
  buffer[i] = calcs[5] + '0';
  buffer[i + 1] = '.';
  i += 2;
  /* Octet #3 */
  if (calcs[6]) {
   buffer[i] = calcs[6] + '0';
   buffer[i + 1] = calcs[7] + '0';
   i += 2;
  } else if (calcs[7]) buffer[i++] = calcs[7] + '0';
  buffer[i] = calcs[8] + '0';
  buffer[i + 1] = '.';
  i += 2;
  /* Octet #4 */
  if (calcs[9]) {
   buffer[i] = calcs[9] + '0';
   buffer[i + 1] = calcs[10] + '0';
   i += 2;
  } else if (calcs[10]) buffer[i++] = calcs[10] + '0';
  buffer[i] = calcs[11] + '0';
  buffer[i + 1] = '\0';

  return std::string(buffer, i + 1);
 }
}