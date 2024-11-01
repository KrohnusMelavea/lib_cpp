#pragma once

#include "types.hpp"
#include "iterator_sentinel.hpp"
#include "rotating_array_iterator.hpp"

namespace stl {
 template <class T, std::size_t array_size> class rotating_static_array {
 public:
  template <class Self> [[nodiscard]] auto&& operator[](this Self&& self, std::size_t const i) noexcept {
   return std::forward<Self>(self).m_data[(std::forward<Self>(self).m_front + i) % array_size];
  }

  void push(T&& value) noexcept {
   this->m_data[this->m_back] = std::forward<T>(value);
   this->m_back = (this->m_back + 1) % array_size;
  }
  template <class... Args> T& emplace(Args&&... args) {
   this->m_back = (this->m_back + 1) % array_size;
   this->m_data[this->m_back] = T{std::forward<Args>(args)...};
   return this->m_data[this->m_back];
  }
  T&& pop() noexcept {
   T& temp = this->m_data[this->m_front];
   this->m_front = (this->m_front + 1) % array_size;
   return std::move(temp);
  }

  template <class Self> [[nodiscard]] auto&& front(this Self&& self) noexcept { return std::forward<Self>(self).m_data[std::forward<Self>(self).m_front]; }
  template <class Self> [[nodiscard]] auto&& back(this Self&& self) noexcept { return std::forward<Self>(self).m_data[std::forward<Self>(self).m_back]; }

  template <class Self> [[nodiscard]] inline constexpr auto begin(this Self&& self) noexcept {
   return stl::rotating_array_iterator{
    std::forward<Self>(self).m_data, 
    std::forward<Self>(self).m_front, 
    array_size * (std::forward<Self>(self).m_back < std::forward<Self>(self).m_front) + std::forward<Self>(self).m_back - std::forward<Self>(self).m_front}; 
  }
  [[nodiscard]] inline constexpr iterator_sentinel end() const noexcept { return {}; }

  [[nodiscard]] inline constexpr std::size_t capacity() const noexcept { return array_size; }
  [[nodiscard]] inline constexpr std::size_t size() const noexcept { return array_size * (this->m_back < this->m_front) + this->m_back - this->m_front; }

  [[nodiscard]] inline constexpr bool empty() const noexcept { return this->m_front == this->m_back; }
  [[nodiscard]] inline constexpr bool full() const noexcept { return (this->m_back + 1) % array_size == this->m_front;  }

 private:
  std::size_t m_front = 0, m_back = 0;
  T m_data[array_size];
 };
}