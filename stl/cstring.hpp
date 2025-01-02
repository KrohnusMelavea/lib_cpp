#pragma once

#include "types.hpp"
#include <algorithm>

namespace stl {
 template <std::size_t size> struct cstring {
  char data[size]{};
  consteval cstring(const char (&str)[size]) noexcept {
   (void)std::copy(std::cbegin(str), std::cend(str), std::begin(data));
  }
  consteval const char *get() const noexcept {
   return data;
  }
 };
}

