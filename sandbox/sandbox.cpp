#include "types.hpp"
#include "timing/core.hpp"
#include <spdlog/spdlog.h>

int main() {
 {
  timing::cycle_timer timer(timing::timing_archive::global_callback);
  for (u32 i = 0; i < 10; ++i) {
   for (u32 j = 0; j < 1000000000; ++j) {
    
   }
   SPDLOG_INFO("{}", timer.lap().count());
  }
 }
}