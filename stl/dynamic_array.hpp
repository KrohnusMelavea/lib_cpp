#pragma once

#include "types.hpp"
#include "buffer.hpp"
#include <span>
#include <cstdlib>
#include <utility>
#include <string_view>
#include <spdlog/spdlog.h>

namespace stl {
 /* Requires T = POD */
 template <class T> class dynamic_array {
 public:
  dynamic_array() noexcept = default;
  dynamic_array(T* const data, std::size_t const size) noexcept : m_data{data}, m_size{size} {}
  dynamic_array(T* const start, T* const end) noexcept : m_data{reinterpret_cast<T*>(std::memcpy(new T[end - start], start, sizeof(T) * (end - start)))}, m_size{static_cast<std::size_t>(end - start)} {}
  dynamic_array(std::size_t const size) noexcept : m_data{new T[size]}, m_size{size} {}
  dynamic_array(dynamic_array const& dynamic_array) noexcept : m_data{reinterpret_cast<T*>(std::memcpy(new T[dynamic_array.m_size], dynamic_array.m_data, dynamic_array.m_size))}, m_size{dynamic_array.m_size} {}
  dynamic_array(dynamic_array&& dynamic_array) noexcept : m_data{ dynamic_array.m_data }, m_size{dynamic_array.m_size} { dynamic_array.m_data = nullptr; }
  ~dynamic_array() noexcept { delete[] this->m_data; }

  explicit operator std::string_view() const {
   return std::string_view{reinterpret_cast<char*>(this->m_data), this->m_size}; /* Includes null-terminator */
  }


  auto const& operator[](std::size_t const i) const noexcept {
   return this->m_data[i];
  }
  auto& operator[](std::size_t const i) noexcept {
   return this->m_data[i];
  }

  auto& operator=(dynamic_array const& dynamic_array) noexcept {
   if (dynamic_array.m_size != this->m_size) {
    delete[] this->m_data;
    this->m_data = new T[dynamic_array.m_size];
   }
   this->m_size = dynamic_array.m_size;
   (void)std::memcpy(this->m_data, dynamic_array.m_data, this->m_size);
   return *this;
  }
  void operator=(dynamic_array&& dynamic_array) noexcept {
   this->m_data = dynamic_array.m_data;
   this->m_size = dynamic_array.m_size;
   dynamic_array.m_data = nullptr;
  }

  void push_back(T const& value) noexcept {
   auto new_data = new T[this->m_size + 1];

   for (std::size_t i = 0; i < this->m_size; ++i) {
    new_data[i] = std::move(this->m_data[i]);
   }
   delete[] this->m_data;
   new_data[this->m_size++] = value;
   this->m_data = new_data;
  }

  operator std::span<T>() const noexcept { return std::span<T>{ m_data, m_size }; } 
  operator std::span<T>() noexcept { return std::span<T>{ m_data, m_size }; }

  void grow(std::size_t const size) noexcept {
   auto const new_data = new T[this->m_size + size];
   (void)std::memcpy(new_data, this->m_data, this->m_size);
   delete[] this->m_data;
   this->m_data = new_data;
   this->m_size += size;
  }
  void grow(stl::buffer const data) noexcept {
   auto const new_data = new T[this->m_size + std::size(data)];
   (void)std::memcpy(new_data, this->m_data, this->m_size);
   (void)std::memcpy(new_data, reinterpret_cast<u08*>(std::data(data)) + this->m_size, std::size(data));
   delete[] this->m_data;
   this->m_data = new_data;
   this->m_size += std::size(data);
  }
  void shrink(std::size_t const size) noexcept {
   auto const new_data = new T[this->m_size - size];
   (void)std::memcpy(new_data, this->m_data, this->m_size - size);
   delete[] this->m_data;
   this->m_data = new_data;
   this->m_size -= size;
  }

  void free() noexcept {
   delete[] this->m_data;
   this->m_data = nullptr;
  }
  auto release() noexcept {
   auto data = this->m_data;
   this->m_data = nullptr;
   return std::span{ data, this->m_size };
  }

  auto begin() noexcept { return this->m_data; }
  auto end() noexcept { return this->m_data + this->m_size; }
  auto cbegin() const noexcept { return this->m_data; }
  auto cend() const noexcept{ return this->m_data + this->m_size; }

  auto data() noexcept { return this->m_data; }
  auto data() const noexcept { return this->m_data; }
  auto size() const noexcept { return this->m_size; }

 private:
  T* m_data;
  std::size_t m_size;
 };
}