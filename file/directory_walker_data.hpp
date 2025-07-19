#pragma once

#include "types.hpp"
#include "stl/dynamic_array.hpp"
#include <array>
#include <string_view>
#include <windows.h>

namespace file {
 struct directory_walker_data {
  ::WIN32_FIND_DATAA data;
  std::array<char[256], 16> file_paths;
  std::array<std::size_t, 16> file_path_lengths;
  std::array<void*, 16> file_iterator_handles;
  std::size_t directory_depth;
  char file_path[256];
  std::size_t file_path_length;
  std::string_view directory;
  stl::dynamic_array<u08> file_contents;

  static directory_walker_data& get_thread_instance() {
   thread_local directory_walker_data instance{};
   return instance;
  } 
 };
}