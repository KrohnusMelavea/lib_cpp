#include "timer.hpp"

namespace timing {
 timer::timer(stl::source_location const& source_location) noexcept : m_source_location{source_location} {

 }

 void timer::set() noexcept {
  this->m_start_time = std::chrono::steady_clock::now();
 }
 std::chrono::nanoseconds timer::get() const noexcept {
  return static_cast<std::chrono::nanoseconds>(this->m_start_time.time_since_epoch());
 }
 std::chrono::nanoseconds timer::get_delta() const noexcept {
  return static_cast<std::chrono::nanoseconds>(
   std::chrono::steady_clock::now().time_since_epoch() - 
   this->m_start_time.time_since_epoch());
 }
 std::chrono::nanoseconds timer::reset() noexcept {
  auto const start_time = std::chrono::steady_clock::now();
  auto const delta = start_time - this->m_start_time;
  this->m_start_time = start_time;
  return delta;
 }
}