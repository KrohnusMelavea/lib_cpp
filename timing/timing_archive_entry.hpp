#pragma once

#include "types.hpp"
#include "stl/source_location.hpp"
#include "stl/rotating_static_array.hpp"
#include <chrono>

namespace timing {
 struct timing_archive_entry {
  using timing_t = std::chrono::nanoseconds;

  stl::source_location source_location;
  stl::rotating_static_array<timing_t, 512> timings;
  timing_t min;
  timing_t max;
  timing_t avg;

  constexpr timing_archive_entry(stl::source_location&& source_location, timing_t&& timing) noexcept : source_location{std::forward<stl::source_location>(source_location)}, min{timing}, max{timing}, avg{timing} { timings.push(std::forward<timing_t>(timing)); }

  constexpr auto&& operator=(timing_archive_entry const& timing_archive_entry) noexcept {
   source_location = timing_archive_entry.source_location;
   timings = timing_archive_entry.timings;
   min = timing_archive_entry.min;
   max = timing_archive_entry.max;
   avg = timing_archive_entry.avg;
   return *this;
  }
  constexpr auto&& operator=(timing_archive_entry&& timing_archive_entry) noexcept {
   source_location = timing_archive_entry.source_location;
   timings = std::move(timing_archive_entry.timings);
   min = timing_archive_entry.min;
   max = timing_archive_entry.max;
   avg = timing_archive_entry.avg;
   return *this;
  }

  void update_timings(timing_t&& new_timing) noexcept {
   if (timings.full()) [[likely]] {
    avg = (avg * std::size(timings) + new_timing - timings.front()) / std::size(timings);
   } else [[unlikely]] {
    avg = (avg * std::size(timings) + new_timing) / (std::size(timings) + 1);
   }
   if (new_timing < min) [[unlikely]] { min = new_timing; }
   if (new_timing > max) [[unlikely]] { max = new_timing; }
   timings.push(std::forward<timing_t>(new_timing));
  }
 };
}