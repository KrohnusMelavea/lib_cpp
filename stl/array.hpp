/*
Motivation: std::array contains private members, thereby resulting in the class being non-structural.
Non-structural classes cannot be used as non-type template parameters.
The aim of array.hpp is to provide a structural variant of std::array which can be used as a compile-time constructed non-type template parameter.
*/

#pragma once

#include "types.hpp"
#include <span>

namespace stl {
 template <class T, std::size_t _size> struct array {
  T _data[_size];

  constexpr void operator=(array<T, _size> const& array) noexcept {
   for (std::size_t i = 0; i < _size; ++i) {
    this->_data[i] = array._data[i];
   }
  }

  inline constexpr operator std::span<T, _size>() const {
   return std::span<T, _size>{ &this->_data[0], _size };
  }

  template <class Self> inline constexpr auto&& operator[](this Self&& self, std::size_t const index) noexcept {
   return std::forward<Self>(self)._data[index];
  }
  template <class Self, std::size_t index> inline constexpr auto&& at(this Self&& self) noexcept {
   return std::forward<Self>(self)._data[index];
  }

  static consteval auto size() noexcept {
   return _size;
  }
  template <class Self> inline constexpr auto&& data(this Self&& self) noexcept {
   return &std::forward<Self>(self)._data[0];
  }

  template <class Self> inline constexpr auto&& begin(this Self&& self) noexcept {
   return &std::forward<Self>(self)._data[0];
  }
  template <class Self> inline constexpr auto&& end(this Self&& self) noexcept {
   return &std::forward<Self>(self)._data[0] + _size;
  }
  inline constexpr auto&& cbegin() const noexcept {
   return &this->_data[0];
  }
  inline constexpr auto&& cend() const noexcept {
   return this->_data[] + _size;
  }
 };
}