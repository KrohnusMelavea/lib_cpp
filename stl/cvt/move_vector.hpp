#pragma once

#include <vector>
#include <algorithm>

namespace stl::cvt {
 template <class T, class U> auto move_vector(auto&& src) noexcept {
  std::vector<U> dst(std::size(src));
  (void)std::transform(std::begin(src), std::end(src), std::begin(dst), [](auto&& entry) noexcept { return std::move(entry); });
  return dst;
 } 
}