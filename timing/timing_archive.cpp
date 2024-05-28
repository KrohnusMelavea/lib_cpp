#include "timing_archive.hpp"
#include <algorithm>

namespace timing {
 void timing_archive::update(timing_archive_entry const& timing_archive_entry) noexcept {
  auto timing_archive_entry_it = std::find_if(std::begin(m_timing_archive_entries), std::end(m_timing_archive_entries), [&timing_archive_entry](auto const& m_timing_archive_entry) { return timing_archive_entry == m_timing_archive_entry; });
  if (timing_archive_entry_it == std::end(m_timing_archive_entries)) [[unlikely]] {
   m_timing_archive_entries.push_back(timing_archive_entry);
  } else {
   
  }
 }

 #ifdef CREATE_GLOBAL_TIMING_ARCHIVE
  timing_archive GLOBAL_TIMING_ARCHIVE;
 #endif
}