#include "scoped_timer.hpp"

namespace timing {
 scoped_timer::scoped_timer(stl::source_location&& source_location) noexcept : m_callback{nullptr}, m_source_location{std::forward<stl::source_location>(source_location)}, m_start_time{std::chrono::steady_clock::now()} {}
 scoped_timer::scoped_timer(callback_t callback, stl::source_location&& source_location) noexcept : m_callback{callback}, m_source_location{std::forward<stl::source_location>(source_location)}, m_start_time{std::chrono::steady_clock::now()} {}
 scoped_timer::~scoped_timer() noexcept {
  if (this->m_callback != nullptr) [[likely]] {
   this->m_callback(std::forward<stl::source_location>(this->m_source_location), std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - m_start_time));
  }
 }
}