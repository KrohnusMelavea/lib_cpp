#pragma once

#include "types.hpp"
#include "directory_walker_data.hpp"
#include "directory_walker_iterator.hpp"
#include "stl/ctconfig.hpp"
#include <array>
#include <string_view>
#include <print>


/*
Win32 Functions:
- GetLastError: https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror
- FindNextFileA: https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findnextfilea
- FindFirstFileA: https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfilea
Win32 Data Structures:
- WIN32_FIND_DATAA: https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa
*/

namespace file {
 template <stl::ctconfig config> struct directory_walker {
  void operator=(auto) { 
    
  }

  auto begin() noexcept {
   directory_walker_iterator<config> walker{};
   walker.fetch();
   return walker;
  }
  iterator_sentinel end() noexcept {
   return iterator_sentinel{};
  }
 };

 template <stl::ctconfig config> auto walk_directory(std::string_view const directory) noexcept {
  auto&& directory_walker_data = file::directory_walker_data::get_thread_instance();
  auto&& data = directory_walker_data.data;
  auto&& file_iterator_handles = directory_walker_data.file_iterator_handles;
  auto&& file_paths = directory_walker_data.file_paths;
  auto&& file_path_lengths = directory_walker_data.file_path_lengths;
  auto&& file_path = directory_walker_data.file_path;
  auto&& file_path_length = directory_walker_data.file_path_length;
  directory_walker_data.directory_depth = 0;

  (void)std::memcpy(
   file_paths[0], 
   std::data(directory), 
   std::size(directory)
  );
  if (file_paths[0][std::size(directory) - 1] == '\\') /* Directory is suffixed with '\' */ [[likely]] {
   append_unslashed_path_suffix(
    file_paths[0], 
    std::size(directory)
   );
   file_path_lengths[0] = std::size(directory);
  } else [[unlikely]] /* Directory is not suffixed with '\' */ {
   append_slashed_path_suffix(
    file_paths[0], 
    std::size(directory)
   );
   file_path_lengths[0] = std::size(directory) + 1;
  }
  file_iterator_handles[0] = ::FindFirstFileA(
   file_paths[0], 
   &data
  );
  (void)::FindNextFileA(
   file_iterator_handles[0], 
   &data
  ); /* Skip Current Path (".") */

  if (file_iterator_handles[0] == reinterpret_cast<void*>(-1)) [[unlikely]] /* Folder Empty */ {
   file_iterator_handles[0] = nullptr;
  }
  file_path_length = std::strlen(data.cFileName);
  (void)std::memcpy(
   file_path, 
   file_paths[0], 
   file_path_lengths[0]
  ); /* Copy Path */
  (void)std::memcpy(
   file_path + file_path_lengths[0], 
   data.cFileName, 
   file_path_length
  ); /* Copy File Name */
  file_path[file_path_lengths[0] + file_path_length] = '\0';

  return directory_walker<config>{};
 }
}


