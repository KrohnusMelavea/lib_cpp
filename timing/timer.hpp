#pragma once

#include "stl/source_location.hpp"
#include <chrono>
#include <functional>

namespace timing {
 class timer {
 public:
  using time_point_t = std::chrono::steady_clock::time_point;

  timer(stl::source_location const& source_location = {}) noexcept;

  void set() noexcept;
  std::chrono::nanoseconds get() const noexcept;
  std::chrono::nanoseconds get_delta() const noexcept;
  std::chrono::nanoseconds reset() noexcept;

 private:
  stl::source_location m_source_location;
  time_point_t m_start_time;
 };
}