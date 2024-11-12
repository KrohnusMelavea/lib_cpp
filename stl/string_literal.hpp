#pragma once

#include <algorithm>
#include <string_view>

namespace stl {
 template <std::size_t size> struct string_literal {
  char data[size];
  constexpr string_literal(char const (&src)[size]) noexcept { (void)std::copy_n(src, size, data); }
  constexpr operator std::string_view() { return { data, size }; }
 };
}