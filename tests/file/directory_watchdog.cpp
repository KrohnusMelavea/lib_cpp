#include "stl/array.hpp"
#include "stl/ctconfig.hpp"
#include "stl/string_view.hpp"
#include "file/directory_watchdog.hpp"
#include <chrono>

void test() {
 using namespace std::chrono_literals;

 static constexpr auto config = stl::ctconfig<>{}
  .add("extension_whitelist", stl::array{ { 
    stl::string_view{"hpp"},
    stl::string_view{"cpp"},
  } })
  .add("folder_blacklist", stl::array{ {
   stl::string_view{"c:\\se\\personal\\lib_cpp\\tests"},
   stl::string_view{"c:\\se\\personal\\lib_cpp\\sandbox"},
  } })
  .add("should_clean_state_on_delete", true) 
  ;

 static constexpr auto should_clean_state_on_delete = CHECK_CONFIG(config, "should_clean_state_on_delete");
 std::print("should_clean_state_on_delete {}", should_clean_state_on_delete);

 file::directory_watchdog<config> watchdog("c:\\se\\personal\\lib_cpp\\");

 std::print("Size Of Watchdog: {}\n", sizeof(watchdog));

 for (std::size_t i = 0; i < 10000; ++i) {
  std::print("Cycle #{}:\n", i + 1);
  auto const start_time = std::chrono::steady_clock::now();
  for (auto const file_path : watchdog) {
   std::print("{}\n", file_path);
  }
  std::print("Done: {}ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count());
  std::this_thread::sleep_for(500ms);
 }
}