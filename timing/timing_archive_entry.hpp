#pragma once

#include "stl/rotating_static_array.hpp"
#include <chrono>
#include <source_location>

namespace timing {
 struct timing_archive_entry {
  std::source_location const source_location;
  stl::rotating_static_array<std::chrono::nanoseconds, 512> timings{1};
  u64 min;
  u64 max;
  u64 avg;

  void update_timings(std::chrono::nanoseconds const& new_timing) noexcept {
   auto const new_time = static_cast<u64>(new_timing.count());
   if (timings.full()) [[likely]] {
    auto const front_time = static_cast<u64>(timings.front().count());
    avg = (avg * std::size(timings) + new_time - front_time) / std::size(timings);
   } else [[unlikely]] {
    avg = (avg * std::size(timings) + new_time) / (std::size(timings) + 1);
   }
   if (new_time < min) [[unlikely]] { min = new_time; }
   if (new_time > max) [[unlikely]] { max = new_time; }
   timings.push(new_timing);
  }

  inline constexpr auto operator==(auto const& other) const noexcept { return source_location.line() == other.source_location.line() && source_location.column() == other.source_location.column() && source_location.file_name() == other.source_location.file_name() && source_location.function_name() == other.source_location.function_name(); }
 };

}