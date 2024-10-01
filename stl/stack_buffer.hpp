#pragma once

#include "types.hpp"

namespace stl {
 template <class T, std::size_t length> class stack_buffer {
 public:
  void push_back(T const& v) noexcept {
   m_data[m_size++] = v;
  }
  void emplace_back(auto&&... args) noexcept {
   m_data[m_size++] = T{std::forward<decltype(args)>(args)...};
  }
  T pop_back() noexcept {
   return m_data[--m_size];
  }

  T* begin() noexcept { return this->m_data; }
  T* end() noexcept { return this->m_data + this->m_size; }
  T const* begin() const noexcept { return this->m_data; }
  T const* end() const noexcept { return this->m_data + this->m_size; }
  T const* cbegin() const noexcept { return this->m_data; }
  T const* cend() const noexcept { return this->m_data + this->m_size; }

  T* data() noexcept { return this->m_data; }
  T const* data() const noexcept { return this->m_data; }
  constexpr std::size_t size() const noexcept { return this->m_size; }
  consteval std::size_t capacity() const noexcept { return length; }

 private:
  T m_data[length];
  std::size_t m_size;
 };
}