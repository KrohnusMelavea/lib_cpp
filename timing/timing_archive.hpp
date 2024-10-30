#pragma once

#include "timing_archive_entry.hpp"
#include "stl/dynamic_array.hpp"
#include "stl/source_location.hpp"
#include <chrono>

namespace timing {
 class timing_archive;
 #ifdef CREATE_GLOBAL_TIMING_ARCHIVE
  extern timing_archive GLOBAL_TIMING_ARCHIVE;
 #endif

 class timing_archive {
 public:
  using timing_t = std::chrono::nanoseconds;

  void update(stl::source_location&& source_location, timing_t&& timing) noexcept;

  static void callback(timing_archive&& timing_archive, stl::source_location&& source_location, timing_t&& timing) noexcept;
#ifdef CREATE_GLOBAL_TIMING_ARCHIVE
  static void global_callback(stl::source_location&& source_location, timing_t&& timing) noexcept;
#endif

 private:
  stl::dynamic_array<timing_archive_entry> m_timing_archive_entries;
 };

 
}