#include "scoped_timer.hpp"
#include "timing_archive_entry.hpp"

namespace timing {
 scoped_timer::scoped_timer(std::source_location const& source_location) noexcept : m_callback{nullptr}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
 scoped_timer::scoped_timer(scoped_timer::callback_t callback, std::source_location const& source_location) noexcept : m_callback{callback}, m_source_location{source_location}, m_start_time{std::chrono::steady_clock::now()} {}
 scoped_timer::~scoped_timer() noexcept {
  if (m_callback) [[likely]] {
   m_callback(timing_archive_entry{ m_source_location });
  }
 }
}