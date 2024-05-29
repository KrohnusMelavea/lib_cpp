#pragma once

#include "types.hpp"
#include "iterator_sentinel.hpp"
#include "rotating_array_iterator.hpp"
#include "rotating_array_const_iterator.hpp"

namespace stl {
 template <class T, std::size_t array_size> class rotating_static_array {
 public:
  constexpr rotating_static_array() : m_data{}, m_index{}, m_capacity{} {}

  constexpr void push(T const& value) noexcept { 
   if (m_capacity == array_size) [[likely]] {
    m_data[((m_index = (m_index + 1) % array_size) + array_size - 1) % array_size] = value;
   } else {
    m_data[m_capacity++] = value;
   }
  }
  inline constexpr auto& operator[] (std::size_t const i) noexcept { return m_data[(m_index + i) % array_size]; }
  inline constexpr auto const& operator[] (std::size_t const i) const noexcept { return m_data[(m_index + i) % array_size]; }

  inline constexpr auto begin() noexcept { return rotating_array_iterator{ m_data, m_index, m_capacity }; }
  inline constexpr auto end() noexcept { return iterator_sentinel{}; }
  inline constexpr auto begin() const noexcept { return rotating_array_const_iterator{ m_data, m_index, m_capacity }; }
  inline constexpr auto end() const noexcept { return iterator_sentinel{}; }
  inline constexpr auto cbegin() const noexcept { return rotating_array_const_iterator{ m_data, m_index, m_capacity }; }
  inline constexpr auto cend() const noexcept { return iterator_sentinel{}; }

  inline constexpr auto size() const noexcept { return array_size; }
  inline constexpr auto capacity() const noexcept { return m_capacity; };

 private:
  T m_data[array_size];
  std::size_t m_index;
  std::size_t m_capacity;
 };
}