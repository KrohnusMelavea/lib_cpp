#pragma once

#include "timing_archive_entry.hpp"
#include <chrono>
#include <functional>
#include <source_location>

namespace timing {
 class scoped_timer {
 public:
  using time_point_t = std::chrono::steady_clock::time_point;
  using callback_t = std::function<void (timing_archive_entry const&)>;

  scoped_timer(std::source_location const& source_location = std::source_location::current()) noexcept;
  scoped_timer(callback_t callback, std::source_location const& source_location = std::source_location::current()) noexcept;
  ~scoped_timer() noexcept;

 private:
  callback_t m_callback;
  std::source_location m_source_location;
  time_point_t m_start_time;
 };
}