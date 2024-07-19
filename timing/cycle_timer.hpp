#pragma once

#include "stl/source_location.hpp"
#include <chrono>
#include <functional>

namespace timing {
 class cycle_timer {
 public:
  using callback_t = std::function<void(stl::source_location const&, std::chrono::nanoseconds)>;
  using time_point_t = std::chrono::steady_clock::time_point;

  cycle_timer(stl::source_location const& source_location = {}) noexcept;
  cycle_timer(callback_t callback, stl::source_location const& source_location = {}) noexcept;

  std::chrono::nanoseconds lap() noexcept;

 private:
  callback_t m_callback;
  stl::source_location m_source_location;
  time_point_t m_start_time;
 };
}