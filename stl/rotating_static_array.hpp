#pragma once

#include "types.hpp"
#include "iterator_sentinel.hpp"
#include "rotating_array_iterator.hpp"
#include "rotating_array_const_iterator.hpp"

namespace stl {
 template <class T, std::size_t array_size> class rotating_static_array {
 public:
  constexpr rotating_static_array() noexcept : m_data{}, m_index{}, m_capacity{} {}
  constexpr rotating_static_array(std::size_t const init_size) noexcept : m_data{}, m_index{}, m_capacity{init_size} {}

  constexpr void push(T const& value) noexcept { 
   if (m_capacity == array_size) [[likely]] {
    m_data[((m_index = (m_index + 1) % array_size) + array_size - 1) % array_size] = value;
   } else [[unlikely]] {
    m_data[m_capacity++] = value;
   }
  }
  [[nodiscard]] inline constexpr auto& operator[] (std::size_t const i) noexcept { return m_data[(m_index + i) % array_size]; }
  [[nodiscard]] inline constexpr auto const& operator[] (std::size_t const i) const noexcept { return m_data[(m_index + i) % array_size]; }

  [[nodiscard]] inline constexpr auto begin() noexcept { return rotating_array_iterator{ m_data, m_index, m_capacity }; }
  [[nodiscard]] inline constexpr auto end() noexcept { return iterator_sentinel{}; }
  [[nodiscard]] inline constexpr auto begin() const noexcept { return rotating_array_const_iterator{ m_data, m_index, m_capacity }; }
  [[nodiscard]] inline constexpr auto end() const noexcept { return iterator_sentinel{}; }
  [[nodiscard]] inline constexpr auto cbegin() const noexcept { return rotating_array_const_iterator{ m_data, m_index, m_capacity }; }
  [[nodiscard]] inline constexpr auto cend() const noexcept { return iterator_sentinel{}; }

  [[nodiscard]] inline constexpr auto& front() noexcept { return m_data[m_index]; }
  [[nodiscard]] inline constexpr auto const& front() const noexcept { return m_data[m_index]; }
  [[nodiscard]] inline constexpr auto& back() noexcept { return m_data[(m_index + m_capacity - 1) % m_capacity]; }
  [[nodiscard]] inline constexpr auto const& back() const noexcept { return m_data[(m_index + m_capacity - 1) % m_capacity]; } 

  [[nodiscard]] inline constexpr auto full() const noexcept { return m_capacity == array_size; }
  [[nodiscard]] inline constexpr auto empty() const noexcept { return m_capacity == 0; }

  [[nodiscard]] inline constexpr auto data() noexcept { return m_data; }
  [[nodiscard]] inline constexpr auto const data() const noexcept { return m_data; }
  [[nodiscard]] inline constexpr auto size() const noexcept { return array_size; }
  [[nodiscard]] inline constexpr auto capacity() const noexcept { return m_capacity; };

 private:
  T m_data[array_size];
  std::size_t m_index;
  std::size_t m_capacity;
 };
}