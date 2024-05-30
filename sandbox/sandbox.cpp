#include "types.hpp"
#include "timing/scoped_timer.hpp"
#include "timing/timing_archive.hpp"
#include <spdlog/spdlog.h>

int main() {
 for (u32 i = 0; i < 1024; ++i) {
  timing::scoped_timer timer(timing::timing_archive::global_callback);
  for (u32 j = 0; j < 1000000; ++j) { }
 }
}