#pragma once

#include "types.hpp"

namespace stl {
 template <class T> struct rotating_array_iterator {
  constexpr rotating_array_iterator(T *const data, std::size_t const front_index, std::size_t const capacity) : m_data{data}, m_index{}, m_front_index{front_index}, m_capacity{capacity} {}

  inline constexpr auto operator== (auto const&) noexcept { return m_index == m_capacity; }
  inline constexpr auto& operator* () noexcept { return *(m_data + (m_front_index + m_index) % m_capacity); }
  inline constexpr void operator++ () noexcept { ++m_index; } 

  T* const m_data;
  std::size_t m_index;
  std::size_t const m_front_index;
  std::size_t const m_capacity;
 };
}