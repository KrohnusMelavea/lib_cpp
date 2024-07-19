#include "timing_archive.hpp"
#include <algorithm>

namespace timing {
 void timing_archive::update(std::source_location const& source_location, std::chrono::nanoseconds const timing) noexcept {
  auto timing_archive_entry_it = std::find_if(std::begin(m_timing_archive_entries), std::end(m_timing_archive_entries), [&source_location](auto const& m_timing_archive_entry) { return m_timing_archive_entry == source_location; });
  if (timing_archive_entry_it == std::end(m_timing_archive_entries)) [[unlikely]] {
   m_timing_archive_entries.push_back();
  } else {
   m_timing_archive_entries
  }
 }

 void timing_archive::callback(timing_archive& timing_archive, timing_archive_entry const& timing_archive_entry) noexcept { timing_archive.update(timing_archive_entry); }
#ifdef CREATE_GLOBAL_TIMING_ARCHIVE
 void timing_archive::global_callback(timing_archive_entry const& timing_archive_entry) noexcept { GLOBAL_TIMING_ARCHIVE.update(timing_archive_entry); } 
 timing_archive GLOBAL_TIMING_ARCHIVE{};
#endif
}