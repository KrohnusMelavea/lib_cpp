#pragma once

#define CREATE_GLOBAL_TIMING_ARCHIVE

#include "timing_archive_entry.hpp"
#include "stl/dynamic_array.hpp"
#include <chrono>
#include <source_location>

namespace timing {
 class timing_archive {
 public:
  void update(timing_archive_entry const& timing_archive_entry) noexcept;

 private:
  stl::dynamic_array<timing_archive_entry> m_timing_archive_entries;
 };

 #ifdef CREATE_GLOBAL_TIMING_ARCHIVE
  extern timing_archive GLOBAL_TIMING_ARCHIVE;
 #endif
}