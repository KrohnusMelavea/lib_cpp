#include "types.hpp"
#include "timing/core.hpp"
#include <spdlog/spdlog.h>

int main() {
 {
  timing::scoped_timer a([](timing::timing_archive_entry const& timing_archive_entry) { 
   timing::GLOBAL_TIMING_ARCHIVE.update(timing_archive_entry);
   SPDLOG_INFO("world");
   });
   SPDLOG_INFO("hello");
 }
}