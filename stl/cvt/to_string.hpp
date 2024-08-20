#include "types.hpp"

namespace stl::cvt {
 constexpr u32 to_string_size(u64 const n) noexcept {
  return
   static_cast<u32>(n > 9999999999999999999_u64) + 
   static_cast<u32>(n > 999999999999999999_u64) + 
   static_cast<u32>(n > 99999999999999999_u64) + 
   static_cast<u32>(n > 9999999999999999_u64) + 
   static_cast<u32>(n > 999999999999999_u64) + 
   static_cast<u32>(n > 99999999999999_u64) + 
   static_cast<u32>(n > 9999999999999_u64) + 
   static_cast<u32>(n > 999999999999_u64) + 
   static_cast<u32>(n > 99999999999_u64) + 
   static_cast<u32>(n > 9999999999_u64) + 
   static_cast<u32>(n > 999999999_u64) + 
   static_cast<u32>(n > 99999999_u64) + 
   static_cast<u32>(n > 9999999_u64) + 
   static_cast<u32>(n > 999999_u64) + 
   static_cast<u32>(n > 99999_u64) + 
   static_cast<u32>(n > 9999_u64) + 
   static_cast<u32>(n > 999_u64) + 
   static_cast<u32>(n > 99_u64) + 
   static_cast<u32>(n > 9_u64) + 
   1_u32;
 }
 constexpr u32 to_string_size(u32 const n) noexcept {
  return 
   static_cast<u32>(n > 999999999_u32) + 
   static_cast<u32>(n > 99999999_u32) + 
   static_cast<u32>(n > 9999999_u32) + 
   static_cast<u32>(n > 999999_u32) + 
   static_cast<u32>(n > 99999_u32) + 
   static_cast<u32>(n > 9999_u32) + 
   static_cast<u32>(n > 999_u32) + 
   static_cast<u32>(n > 99_u32) + 
   static_cast<u32>(n > 9_u32) + 
   1_u32;
 }
 constexpr u32 to_string_size(u16 const n) noexcept {
  return
   static_cast<u32>(n > 9999_u16) + 
   static_cast<u32>(n > 999_u16) + 
   static_cast<u32>(n > 99_u16) + 
   static_cast<u32>(n > 9_u16) + 
   1_u32;
 }
 constexpr u32 to_string_size(u08 const n) noexcept {
  return
   static_cast<u32>(n > 99_u08) + 
   static_cast<u32>(n > 9_u08) + 
   1_u32;
 }

 constexpr void to_string(u64 n, u32 const size, char *const str) noexcept {
  for (u32 i = 0; i < size; ++i) {
   str[size - i - 1] = (n % 10) + '0';
   n /= 10;
  }
 }
}