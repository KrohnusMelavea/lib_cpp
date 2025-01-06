#pragma once

#include "types.hpp"
#include "stl/ctconfig.hpp"
#include "file/directory_walker_iterator.hpp"
#include <string_view>
#include <minwinbase.h>
#include <array>
#include <string_view>


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
  ::WIN32_FIND_DATAA& data;
  std::array<char[256], 16>& file_paths;
  std::array<std::size_t, 16>& file_path_lengths;
  std::array<void*, 16>& file_iterator_handles;
  char (&file_path)[256];
  std::size_t file_path_length;
  std::string_view const& directory;

  auto begin() noexcept {
   auto walker = directory_walker_iterator<config>{ this->data, this->file_paths, this->file_path_lengths, this->file_iterator_handles, this->file_path, this->file_path_length, this->directory, 0 };
   walker.fetch();
   return walker;
  }
  iterator_sentinel end() noexcept {
   return {};
  }
 };

 template <stl::ctconfig config> auto walk_directory(std::string_view const directory) noexcept {
  thread_local ::WIN32_FIND_DATAA data;
  thread_local std::array<char[256], 16> file_paths;
  thread_local std::array<std::size_t, 16> file_path_lengths;
  thread_local std::array<void*, 16> file_iterator_handles;
  thread_local char file_path[256];

  (void)std::memcpy(file_paths[0], std::data(directory), std::size(directory));
  if (file_paths[0][std::size(directory) - 1] == '\\') /* Directory is suffixed with '\' */ [[likely]] {
   append_unslashed_path_suffix(file_paths[0], std::size(directory));
   file_path_lengths[0] = std::size(directory);
  } else [[unlikely]] /* Directory is not suffixed with '\' */ {
   append_slashed_path_suffix(file_paths[0], std::size(directory));
   file_path_lengths[0] = std::size(directory) + 1;
  }
  file_iterator_handles[0] = ::FindFirstFileA(file_paths[0], &data);
  (void)::FindNextFileA(file_iterator_handles[0], &data);
  (void)::FindNextFileA(file_iterator_handles[0], &data);
  if (file_iterator_handles[0] == reinterpret_cast<void*>(-1)) [[unlikely]] /* Folder Empty */ {
   file_iterator_handles[0] = nullptr;
  }
  auto const file_name_length = std::strlen(data.cFileName);
  (void)std::memcpy(file_path, file_paths[0], file_path_lengths[0]);
  (void)std::memcpy(file_path + file_path_lengths[0], data.cFileName, file_name_length);
  file_path[file_path_lengths[0] + file_name_length] = 0;

  return directory_walker<config>{ data, file_paths, file_path_lengths, file_iterator_handles, file_path, file_name_length, directory };
 }
}


