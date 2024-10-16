#pragma once

#include "types.hpp"

namespace stl {
 template <class T> class  rotating_array_iterator {
 public:
  inline constexpr rotating_array_iterator(T *const data, std::size_t const front, std::size_t const size) noexcept : m_data{data}, m_front{front}, m_size{size} { }

  inline constexpr bool operator==(auto&&...) const noexcept { return this->m_index == this->m_size; }
  inline constexpr T& operator*() noexcept { return *(this->m_data + (this->m_front + this->m_index) % this->m_size); }
  inline constexpr void operator++() noexcept { ++this->m_index; }

 private:
  T *const m_data;
  std::size_t m_index = 0;
  std::size_t const m_front, m_size;
 };
}