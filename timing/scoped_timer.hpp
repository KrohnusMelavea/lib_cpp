#pragma once

#include "timing_archive_entry.hpp"
#include <chrono>
#include <functional>
#include <source_location>

namespace timing {
 template <typename callback_t> class scoped_timer {
 public:
  using time_point_t = std::chrono::steady_clock::time_point;

  scoped_timer(std::source_location const& source_location = std::source_location::current()) noexcept : m_callback{nullptr}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
  scoped_timer(callback_t callback, std::source_location const& source_location = std::source_location::current()) noexcept : m_callback{callback}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
  ~scoped_timer() noexcept {
  if (m_callback) [[likely]] {
   m_callback(timing_archive_entry{m_source_location});
  }
 }

 private:
  callback_t m_callback;
  std::source_location m_source_location;
  time_point_t m_start_time;
 };
}