#include "heap_buffer.hpp"

namespace stl {
 heap_buffer::heap_buffer() noexcept : m_data{ nullptr, 0, } {}
 heap_buffer::heap_buffer(std::size_t const size) noexcept : m_data{ ::operator new(size), size } {}
 heap_buffer::heap_buffer(stl::buffer const& data) noexcept : m_data{ std::data(data), std::size(data) } {}
 heap_buffer::heap_buffer(heap_buffer const& heap_buffer) noexcept : m_data{ std::memcpy(::operator new(std::size(heap_buffer)), std::data(heap_buffer), std::size(heap_buffer)), std::size(heap_buffer) } {}
 heap_buffer::heap_buffer(heap_buffer&& heap_buffer) noexcept : m_data{ heap_buffer.m_data } { heap_buffer.m_data.m_data = nullptr; }
 heap_buffer::~heap_buffer() noexcept { delete[] std::data(m_data); }

 heap_buffer& heap_buffer::operator=(heap_buffer const& heap_buffer) noexcept {
  if (std::size(heap_buffer) != std::size(m_data)) {
   delete[] std::data(m_data);
   m_data.m_size = std::size(heap_buffer);
  }
  m_data.m_data = std::memcpy(::operator new(std::size(m_data)), std::data(heap_buffer), std::size(m_data));
  return *this;
 }
 void heap_buffer::operator=(heap_buffer&& heap_buffer) noexcept {
  m_data = heap_buffer.m_data;
  heap_buffer.m_data.m_data = nullptr;
 }

 heap_buffer::operator stl::buffer() const noexcept { return stl::buffer{ std::data(m_data), std::size(m_data) }; }

 void heap_buffer::free() noexcept {
  delete[] std::data(m_data);
  m_data.m_data = nullptr;
 }
 void* heap_buffer::release() noexcept {
  auto data = std::data(m_data);
  m_data.m_data = nullptr;
  return data;
 }

 void* heap_buffer::data() noexcept { return std::data(m_data); }
 void* heap_buffer::data() const noexcept { return std::data(m_data); }
 std::size_t heap_buffer::size() const noexcept { return std::size(m_data); }
}