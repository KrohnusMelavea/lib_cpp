#pragma once

#include "types.hpp"
#include "iterator_sentinel.hpp"
#include "rotating_array_iterator.hpp"
#include "rotating_array_const_iterator.hpp"
#include <type_traits>
#include <ranges>

namespace stl {
 template <class T, std::size_t array_size> class rotating_static_array {
 public:
  constexpr rotating_static_array() noexcept = default;
  constexpr rotating_static_array(std::size_t const init_size) noexcept : m_data{}, m_index{}, m_capacity{init_size} {}

  constexpr rotating_static_array(rotating_static_array const& rotating_static_array) noexcept : m_index{rotating_static_array.m_index}, m_capacity{rotating_static_array.m_capacity} {
   for (std::size_t i = 0; i < array_size; ++i) {
    this->m_data[i] = rotating_static_array.m_data[i];
   }
  }
  constexpr rotating_static_array(rotating_static_array&& rotating_static_array) noexcept : m_index{rotating_static_array.m_index}, m_capacity{rotating_static_array.m_capacity} {
   for (std::size_t i = 0; i < array_size; ++i) {
    this->m_data[i] = std::move(rotating_static_array.m_data[i]);
   }
  }

  constexpr auto& operator=(rotating_static_array const& rotating_static_array) noexcept {
   for (std::size_t i = 0; i < array_size; ++i) {
    this->m_data[i] = rotating_static_array.m_data[i];
   }
   return *this;
  }
  constexpr auto& operator=(rotating_static_array&& rotating_static_array) noexcept {
   for (std::size_t i = 0; i < array_size; ++i) {
    this->m_data[i] = std::move(rotating_static_array.m_data[i]);
   }
   return *this;
  }

  constexpr void push(T&& value) noexcept {
   if (this->m_capacity == array_size) [[likely]] {
    this->m_data[((this->m_index = (this->m_index + 1) % array_size) + array_size - 1) % array_size] = std::forward<T>(value);
   } else [[unlikely]] {
    this->m_data[this->m_capacity++] = std::forward<T>(value);
   }
  }
  constexpr T& emplace(auto&&... args) noexcept {
   if (this->m_capacity == array_size) [[likely]] {
    this->m_data[((this->m_index = (this->m_index + 1) % array_size) + array_size - 1) % array_size] = T{std::forward<decltype(args)>(args)...};
   } else [[unlikely]] {
    this->m_data[this->m_capacity++] = T{std::forward<decltype(args)>(args)...};
   }
   return this->m_data[(this->m_index + this->m_capacity - 1) % this->m_capacity];
  }
  [[nodiscard]] inline constexpr auto& operator[] (std::size_t const i) noexcept { return this->m_data[(this->m_index + i) % array_size]; }
  [[nodiscard]] inline constexpr auto const& operator[] (std::size_t const i) const noexcept { return this->m_data[(this->m_index + i) % array_size]; }

  [[nodiscard]] inline constexpr auto begin() noexcept { return rotating_array_iterator{ this->m_data, this->m_index, this->m_capacity }; }
  [[nodiscard]] inline constexpr auto end() noexcept { return iterator_sentinel{}; }
  [[nodiscard]] inline constexpr auto begin() const noexcept { return rotating_array_const_iterator{ this->m_data, this->m_index, this->m_capacity }; }
  [[nodiscard]] inline constexpr auto end() const noexcept { return iterator_sentinel{}; }
  [[nodiscard]] inline constexpr auto cbegin() const noexcept { return rotating_array_const_iterator{ this->m_data, this->m_index, this->m_capacity }; }
  [[nodiscard]] inline constexpr auto cend() const noexcept { return iterator_sentinel{}; }

  [[nodiscard]] inline constexpr auto& front() noexcept { return this->m_data[this->m_index]; }
  [[nodiscard]] inline constexpr auto const& front() const noexcept { return this->m_data[this->m_index]; }
  [[nodiscard]] inline constexpr auto& back() noexcept { return this->m_data[(this->m_index + this->m_capacity - 1) % this->m_capacity]; }
  [[nodiscard]] inline constexpr auto const& back() const noexcept { return this->m_data[(this->m_index + this->m_capacity - 1) % this->m_capacity]; } 

  [[nodiscard]] inline constexpr auto full() const noexcept { return this->m_capacity == array_size; }
  [[nodiscard]] inline constexpr auto empty() const noexcept { return this->m_capacity == 0; }

  [[nodiscard]] inline constexpr auto data() noexcept { return this->m_data; }
  [[nodiscard]] inline constexpr auto const data() const noexcept { return this->m_data; }
  [[nodiscard]] inline constexpr auto size() const noexcept { return array_size; }
  [[nodiscard]] inline constexpr auto capacity() const noexcept { return this->m_capacity; };

 private:
  T m_data[array_size];
  std::size_t m_index;
  std::size_t m_capacity;
 };
}