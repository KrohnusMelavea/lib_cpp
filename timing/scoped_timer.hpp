#pragma once

#include "stl/source_location.hpp"
#include <chrono>
#include <functional>

namespace timing {
 class scoped_timer {
 public:
  using callback_t = std::function<void(stl::source_location const&, std::chrono::nanoseconds)>;
  using time_point_t = std::chrono::steady_clock::time_point;

  scoped_timer(stl::source_location const& source_location = {}) noexcept;
  scoped_timer(callback_t callback, stl::source_location const& source_location = {}) noexcept;
  ~scoped_timer() noexcept;

 private:
  callback_t m_callback;
  stl::source_location const m_source_location;
  time_point_t m_start_time;
 };
}