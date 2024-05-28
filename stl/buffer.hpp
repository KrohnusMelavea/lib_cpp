#pragma once

#include "types.hpp"
#include <cstdio>

namespace stl {
 struct buffer {
  void* m_data;
  std::size_t m_size;

  void* data() noexcept { return m_data; }
  void* data() const noexcept { return m_data; }
  std::size_t size() const noexcept { return m_size; }
 };
}