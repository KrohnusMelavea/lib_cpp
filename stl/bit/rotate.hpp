#pragma once

#include "types.hpp"

namespace stl::bit {
 inline constexpr uint32_t rotate_left(u32 const n, u32 const c) noexcept {
  return (n << ((c & 31))) | (n >> ((-(c & 31)) & 31));
 }

 inline constexpr uint32_t rotate_right(u32 const n, u32 const c) noexcept {\
  return (n >> (c & 31)) | (n << ((-(c & 31)) & 31));
 }
}