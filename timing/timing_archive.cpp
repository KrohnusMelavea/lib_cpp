#include "timing_archive.hpp"
#include <algorithm>

namespace timing {
 void timing_archive::update(stl::source_location&& source_location, timing_t&& timing) noexcept {
  auto const timing_archive_entry_it = std::find_if(std::cbegin(m_timing_archive_entries), std::cend(m_timing_archive_entries), [&](auto const& timing_archive_entry) { return timing_archive_entry.source_location == source_location; });
  if (timing_archive_entry_it == std::end(m_timing_archive_entries)) [[unlikely]] {
   m_timing_archive_entries.push_back(timing_archive_entry{std::forward<stl::source_location>(source_location), std::forward<timing_t>(timing)});
  } else [[likely]] {
   timing_archive_entry_it->update_timings(std::forward<timing_t>(timing));
  }
 }

 void timing_archive::callback(timing_archive&& timing_archive, stl::source_location&& source_location, timing_t&& timing) noexcept { 
  timing_archive.update(std::forward<stl::source_location>(source_location), std::forward<timing_t>(timing)); 
 }
#ifdef CREATE_GLOBAL_TIMING_ARCHIVE
 void timing_archive::global_callback(stl::source_location&& source_location, timing_t&& timing) noexcept { 
  GLOBAL_TIMING_ARCHIVE.update(std::forward<stl::source_location>(source_location), std::forward<timing_t>(timing)); 
 } 
 timing_archive GLOBAL_TIMING_ARCHIVE{};
#endif
}