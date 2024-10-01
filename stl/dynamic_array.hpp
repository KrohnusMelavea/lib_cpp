#pragma once

#include "types.hpp"
#include "buffer.hpp"
#include <span>
#include <cstdlib>
#include <utility>
#include <string_view>
#include <type_traits>
#include <spdlog/spdlog.h>

namespace stl {
 template <class T> class dynamic_array {
 public:
  dynamic_array() noexcept = default;
  dynamic_array(T* const data, std::size_t const size) noexcept : m_data{data}, m_size{size} {}
  dynamic_array(T* const start, T* const end) requires(std::is_trivial_v<T> || std::is_copy_assignable_v<T>) : m_size{static_cast<std::size_t>(end - start)} {
   if constexpr (std::is_trivial_v<T>) {
    this->m_data = reinterpret_cast<T*>(std::memcpy(new T[this->m_size], start, sizeof(T) * this->m_size));
    return;
   }
   if constexpr (std::is_copy_assignable_v<T>) {
    this->m_data = new T[this->m_size];
    for (std::size_t i = 0; i < this->m_size; ++i) {
     this->m_data[i] = start[i];
    }
    return;
   }
  }
  dynamic_array(std::size_t const size) noexcept : m_data{new T[size]}, m_size{size} {}
  dynamic_array(dynamic_array const& dynamic_array) : m_size{dynamic_array.m_size} {
   if constexpr (std::is_trivial_v<T>) {
    this->m_data = reinterpret_cast<T*>(std::memcpy(new T[this->m_size], dynamic_array.m_data, this->m_size));
    return;
   }
   if constexpr (std::is_copy_assignable_v<T>) {
    this->m_data = new T[this->m_size];
    for (std::size_t i = 0; i < this->m_size; ++i) {
     this->m_data[i] = dynamic_array.m_data[i];
    }
    return;
   }
  }
  dynamic_array(dynamic_array&& dynamic_array) noexcept : m_data{dynamic_array.m_data}, m_size{dynamic_array.m_size} { 
   dynamic_array.m_data = nullptr; 
  }
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

  auto& operator=(dynamic_array const& dynamic_array) noexcept requires(std::is_trivial_v<T> || std::is_copy_assignable_v<T>) {
   if constexpr (std::is_trivial_v<T>) {
    if (dynamic_array.m_size != this->m_size) {
     delete[] this->m_size;
     this->m_data = new T[dynamic_array.m_size];
     this->m_size = dynamic_array.m_size;
    }
    (void)std::memcpy(this->m_data, dynamic_array.m_data, this->m_size);
    return *this;
   }
   if constexpr (std::is_copy_assignable_v<T>) {
    if (dynamic_array.m_size != this->m_size) {
     delete[] this->m_size;
     this->m_data = new T[dynamic_array.m_size];
     this->m_size = dynamic_array.m_size;
    }
    for (std::size_t i = 0; i < this->m_size; ++i) {
     this->m_data[i] = dynamic_array.m_data[i];
    }
    return *this;
   }
  }
  void operator=(dynamic_array&& dynamic_array) noexcept {
   this->m_data = dynamic_array.m_data;
   this->m_size = dynamic_array.m_size;
   dynamic_array.m_data = nullptr;
  }

  //Research perfect forwarding
  void push_back(T const& value) noexcept requires(std::is_trivial_v<T> || (std::is_move_assignable_v<T> && std::is_copy_assignable_v<T>) || std::is_copy_assignable_v<T>) {
   if constexpr (std::is_trivial_v<T>) {
    auto new_data = std::memcpy(new T[this->m_size + 1], this->m_data, this->m_size);
    delete[] this->m_data;
    this->m_data = new_data;
    this->m_data[this->m_size++] = value;
    return;
   }
   if constexpr (std::is_move_assignable_v<T> && std::is_copy_assignable_v<T>) {
    auto new_data = new T[this->m_size + 1];
    for (std::size_t i = 0; i < this->m_size; ++i) {
     new_data[i] = std::move(this->m_data[i]);
    }
    delete[] this->m_data;
    this->m_data = new_data;
    this->m_data[this->m_size++] = value;
    return;
   }
   if constexpr (std::is_copy_assignable_v<T>) {
    auto new_data = new T[this->m_size + 1];
    for (std::size_t i = 0; i < this->m_size; ++i) {
     new_data[i] = this->m_data[i];
    }
    delete[] this->m_data;
    this->m_data = new_data;
    this->m_data[this->m_size++] = value;
    return;
   }
  }

  operator std::span<T>() const noexcept { return std::span<T>{ m_data, m_size }; } 
  operator std::span<T>() noexcept { return std::span<T>{ m_data, m_size }; }

  void grow(std::size_t const size) noexcept requires (std::is_trivial_v<T> || std::is_move_assignable_v<T> || std::is_copy_assignable_v<T>) {
   auto const new_data = new T[this->m_size + size];
   if constexpr (std::is_trivial_v<T>) {
    std::memcpy(new_data, this->m_data, this->m_size);
   } else {
    for (std::size_t i = 0; i < this->m_size; ++i) {
     if constexpr (std::is_move_assignable_v<T>) {
      new_data[i] = std::move(this->m_data[i]);
     } else if constexpr (std::is_copy_assignable_v<T>) {
      new_data[i] = this->m_data[i];
     }
    }
   }
   delete[] this->m_data;
   this->m_data = new_data;
   this->m_size += size;
  }
  void grow(stl::buffer const data) noexcept requires(std::is_trivial_v<T> || std::is_move_assignable_v<T> || std::is_copy_assignable_v<T>) {
   auto const new_data = new T[this->m_size + std::size(data)];
   if constexpr (std::is_trivial_v<T>) {
    (void)std::memcpy(new_data, this->m_data, this->m_size);
    (void)std::memcpy(new_data, reinterpret_cast<T*>(std::data(data)) + this->m_size, std::size(data));
   } else {
    for (std::size_t i = 0; i < this->m_size; ++i) {
     if constexpr (std::is_move_assignable_v<T>) {
      new_data[i] = std::move(this->m_data[i]);
     } else if constexpr (std::is_copy_assignable<T>) {
      new_data[i] = this->m_data[i];
     }
    }
    for (std::size_t i = 0; i < std::size(data); ++i) {
     if constexpr (std::is_move_assignable_v<T>) {
      new_data[this->m_size + i] = std::move(data[i]);
     } else {
      new_data[this->m_size + i] = data[i];
     }
    }
   }
   delete[] this->m_data;
   this->m_data = new_data;
   this->m_size += std::size(data);
  }
  void shrink(std::size_t const size) noexcept {
   /* Not yet movable */
   auto const new_data = new T[this->m_size - size];
   (void)std::memcpy(new_data, this->m_data, this->m_size - size);
   delete[] this->m_data;
   this->m_data = new_data;
   this->m_size -= size;
  }

  void free() noexcept /* Does not free contents */ {
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
  auto const begin() const noexcept { return this->m_data; }
  auto const end() const noexcept { return this->m_data + this->m_size; }
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