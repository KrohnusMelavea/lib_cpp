/*
Motivation: std::string_view contains private members, thereby resulting in the class being non-structural.
Non-structural classes cannot be used as non-type template parameters.
The aim of string_view.hpp is to provide a structural variant of std::string_view which can be used as a compile-time constructed non-type template parameter.
*/

#pragma once

#include "types.hpp"

namespace stl {
 struct string_view {
  char _data[256] {};
  std::size_t _size {};

  consteval string_view() noexcept = default;
  template <std::size_t length> constexpr string_view(char const(&_data)[length]) noexcept : _size{length - 1} {
   for (std::size_t i = 0; i < length; ++i) {
    this->_data[i] = _data[i];
   }
  }

  [[nodiscard]] constexpr operator std::string_view() const noexcept {
   return std::string_view{
    this->_data,
    this->_size
   };
  }

  constexpr void operator=(string_view const& string_view) noexcept {
   for (std::size_t i = 0; i < string_view._size; ++i) {
    this->_data[i] = string_view._data[i];
   }
   this->_size = string_view._size;
  }

  inline constexpr char operator[](std::size_t const index) const noexcept {
   return this->_data[index];
  }

  inline constexpr char const* data() const noexcept {
   return this->_data;
  }
  inline constexpr std::size_t size() const noexcept {
   return this->_size;
  }

  inline constexpr char const* begin() const noexcept {
   return this->_data;
  }
  inline constexpr char const* end() const noexcept {
   return this->_data + this->_size;
  }
  inline constexpr char const* cbegin() const noexcept {
   return this->_data;
  }
  inline constexpr char const* cend() const noexcept {
   return this->_data + this->_size;
  }
 };
}