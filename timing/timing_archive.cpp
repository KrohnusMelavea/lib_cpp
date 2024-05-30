#include "timing_archive.hpp"
#include <algorithm>

namespace timing {
 void timing_archive::update(stl::source_location const& source_location, timing_t const timing) noexcept {
  auto timing_archive_entry_it = std::find_if(std::begin(m_timing_archive_entries), std::end(m_timing_archive_entries), [&source_location](auto const& timing_archive_entry) { return timing_archive_entry.source_location == source_location; });
  if (timing_archive_entry_it == std::end(m_timing_archive_entries)) [[unlikely]] {
   m_timing_archive_entries.push_back(timing_archive_entry{source_location, timing});
  } else {
   timing_archive_entry_it->update_timings(timing);
  }
 }

 void timing_archive::callback(timing_archive& timing_archive, stl::source_location const& source_location, timing_t const timing) noexcept { 
  timing_archive.update(source_location, timing); 
 }
#ifdef CREATE_GLOBAL_TIMING_ARCHIVE
 void timing_archive::global_callback(stl::source_location const& source_location, timing_t const timing) noexcept { 
  GLOBAL_TIMING_ARCHIVE.update(source_location, timing); 
 } 
 timing_archive GLOBAL_TIMING_ARCHIVE{};
#endif
}