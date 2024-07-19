#pragma once

#include "types.hpp"
#include <span>
#include <cstdlib>
#include <utility>
#include <spdlog/spdlog.h>

namespace stl {
 template <class T> class dynamic_array {
 public:
  dynamic_array() noexcept = default;
  dynamic_array(T* const data, std::size_t const size) noexcept : m_data{data}, m_size{size} {}
  dynamic_array(std::size_t const size) noexcept : m_data{new T[size]}, m_size{size} {}
  dynamic_array(dynamic_array const& dynamic_array) noexcept : m_data{std::memcpy(new T[dynamic_array.m_size], dynamic_array.m_data, dynamic_array.m_size)}, m_size{dynamic_array.m_size} {}
  dynamic_array(dynamic_array&& dynamic_array) noexcept : m_data{ dynamic_array.m_data }, m_size{dynamic_array.m_size} { dynamic_array.m_data = nullptr; }
  ~dynamic_array() noexcept { delete[] m_data; }

  auto& operator=(dynamic_array const& dynamic_array) noexcept {
   if (dynamic_array.m_size != m_size) {
    delete[] m_data;
    m_data = new T[dynamic_array.m_size];
   }
   m_size = dynamic_array.m_size;
   (void)std::memcpy(m_data, dynamic_array.m_data, m_size);
   return *this;
  }
  void operator=(dynamic_array&& dynamic_array) noexcept {
   m_data = dynamic_array.m_data;
   m_size = dynamic_array.m_size;
   dynamic_array.m_data = nullptr;
  }

  void push_back(T const& value) noexcept {
   auto new_data = new T[m_size + 1];

   for (std::size_t i = 0; i < m_size; ++i) {
    new_data[i] = std::move(m_data[i]);
   }
   delete[] m_data;
   new_data[m_size++] = value;
   m_data = new_data;
  }

  operator std::span<T>() const noexcept { return std::span<T>{ m_data, m_size }; } 
  operator std::span<T>() noexcept { return std::span<T>{ m_data, m_size }; }

  void free() noexcept {
   delete[] m_data;
   m_data = nullptr;
  }
  auto release() noexcept {
   auto data = m_data;
   m_data = nullptr;
   return std::span{ data, m_size };
  }

  auto begin() noexcept { return m_data; }
  auto end() noexcept { return m_data + m_size; }
  auto cbegin() const noexcept { return m_data; }
  auto cend() const noexcept{ return m_data + m_size; }

  auto data() noexcept { return m_data; }
  auto data() const noexcept { return m_data; }
  auto size() const noexcept { return m_size; }

 private:
  T* m_data;
  std::size_t m_size;
 };
}