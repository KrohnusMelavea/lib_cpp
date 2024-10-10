#include "types.hpp"
#include <span>
#include <array>
#include <ranges>
#include <string>

namespace stl {
 namespace cvt {
  std::string to_hex_string(auto&& data) requires(IsSpanLike<decltype(data)>) {
   static constexpr std::array<char, 16> HEX_LOOKUP{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
   std::string hex(std::size(data) << 1, '\0');
   auto s = std::data(hex);
   auto v = reinterpret_cast<u08*>(std::data(data));
   auto v_end = v + std::size(data);
   if (std::size(data) == 0) [[unlikely]] {
    return hex;
   }
   do {
    *s++ = HEX_LOOKUP[*v >> 4];
    *s++ = HEX_LOOKUP[*v & 15];
   } while (++v != v_end);
   return hex;
  }
 }
}