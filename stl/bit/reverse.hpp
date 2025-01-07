#pragma once

#include "types.hpp"

namespace stl::bit {
 [[nodiscard]] constexpr std::size_t reverse(std::size_t const value) noexcept {
  return 
   (((value >>  0) & 0xff) << 56) |
   (((value >>  8) & 0xff) << 48) |
   (((value >> 16) & 0xff) << 40) |
   (((value >> 24) & 0xff) << 32) |
   (((value >> 32) & 0xff) << 24) |
   (((value >> 40) & 0xff) << 16) |
   (((value >> 48) & 0xff) <<  8) |
   (((value >> 56) & 0xff) <<  0);
 }
 [[nodiscard]] constexpr u32 reverse(u32 const value) noexcept {
  return 
   (((value >>  0) & 0xff) << 24) |
   (((value >>  8) & 0xff) << 16) |
   (((value >> 16) & 0xff) <<  8) |
   (((value >> 24) & 0xff) <<  0);
 } 
}