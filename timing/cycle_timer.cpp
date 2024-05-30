#include "cycle_timer.hpp"

namespace timing {
 cycle_timer::cycle_timer(stl::source_location const& source_location) noexcept : m_callback{nullptr}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
 cycle_timer::cycle_timer(callback_t callback, stl::source_location const& source_location) noexcept : m_callback{callback}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
  
 std::chrono::nanoseconds cycle_timer::lap() noexcept {
  auto const start_time = std::chrono::steady_clock::now();
  auto const delta = start_time - m_start_time;
  if (m_callback) [[likely]] {
   m_callback(m_source_location, delta);
  }
  m_start_time = start_time;
  return delta;
 }
}