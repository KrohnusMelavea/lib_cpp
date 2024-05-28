#pragma once

#include <chrono>
#include <functional>
#include <source_location>

namespace timing {
 class cycle_timer {
 public:
  using time_point_t = std::chrono::steady_clock::time_point;
  using callback_t = std::function<void (std::source_location const&, std::chrono::nanoseconds)>;

  cycle_timer(std::source_location const& source_location = std::source_location::current()) noexcept;
  cycle_timer(callback_t callback, std::source_location const& source_location = std::source_location::current()) noexcept;
  
  std::chrono::nanoseconds lap() noexcept;

 private:
  callback_t m_callback;
  std::source_location m_source_location;
  time_point_t m_start_time;
 };
}