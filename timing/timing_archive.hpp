#pragma once

#include "timing_archive_entry.hpp"
#include "stl/dynamic_array.hpp"
#include <chrono>
#include <source_location>

namespace timing {
 class timing_archive;
 #ifdef CREATE_GLOBAL_TIMING_ARCHIVE
  extern timing_archive GLOBAL_TIMING_ARCHIVE;
 #endif

 class timing_archive {
 public:
  void update(timing_archive_entry const& timing_archive_entry) noexcept;

  static void callback(timing_archive& timing_archive, timing_archive_entry const& timing_archive_entry) noexcept;
#ifdef CREATE_GLOBAL_TIMING_ARCHIVE
  static void global_callback(timing_archive_entry const& timing_archive_entry) noexcept;
#endif

 private:
  stl::dynamic_array<timing_archive_entry> m_timing_archive_entries;
 };

 
}