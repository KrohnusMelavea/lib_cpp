#pragma once

#include "timing_archive_entry.hpp"
#include <chrono>
#include <functional>
#include <source_location>

namespace timing {
 /*
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
 */

 template <typename callback_t> class cycle_timer {
 public:
  using time_point_t = std::chrono::steady_clock::time_point;

  cycle_timer(std::source_location const& source_location = std::source_location::current()) noexcept : m_callback{nullptr}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
  cycle_timer(callback_t callback, std::source_location const& source_location = std::source_location::current()) noexcept : m_callback{callback}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
  
  std::chrono::nanoseconds lap() noexcept {
   auto const start_time = std::chrono::steady_clock::now();
   auto const delta = start_time - m_start_time;
   if (m_callback) [[likely]] {
    m_callback(timing_archive_entry{m_source_location});
   }
   m_start_time = start_time;
   return delta;
  }

 private:
  callback_t m_callback;
  std::source_location m_source_location;
  time_point_t m_start_time;
 };
}