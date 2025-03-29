#pragma once

#include "types.hpp"
#include "meta/file_attribute.hpp"
#include "meta/system_error_code.hpp"
#include "iterator_sentinel.hpp"
#include "stl/ctconfig.hpp"
//#include <minwinbase.h>
#include <array>
#include <print>
#include <string_view>
#include <windows.h>

#undef min
#undef max

namespace file {
 static void append_unslashed_path_suffix(char *const data, std::size_t const size) noexcept {
  data[size + 0] = '*';
  data[size + 1] = '\0';
 }
 static void append_slashed_path_suffix(char *const data, std::size_t const size) noexcept {
  data[size + 0] = '\\';
  data[size + 1] = '*';
  data[size + 2] = '\0';
 }

 template <stl::ctconfig config> struct directory_walker_iterator {
  inline bool is_directory_blacklisted() const noexcept {
   auto&& directory_walker_data = file::directory_walker_data::get_thread_instance();
   auto&& data = directory_walker_data.data;
   auto&& file_paths = directory_walker_data.file_paths;
   auto&& file_path_lengths = directory_walker_data.file_path_lengths;
   auto&& directory_depth = directory_walker_data.directory_depth;
   auto&& file_path_length = directory_walker_data.file_path_length;
   auto&& directory = directory_walker_data.directory;

   auto const blacklisted_folder_it = std::ranges::find_if(
    READ_CONFIG(config, "folder_blacklist"), 
    [&](auto const _blacklisted_folder) noexcept {
     auto const blacklisted_folder = static_cast<std::string_view>(_blacklisted_folder);
     auto const relative_path = std::string_view{
      file_paths[directory_depth], 
      file_path_lengths[directory_depth]
     }.substr(std::size(directory));
     auto const maybe_blacklisted_folder_length = std::size(relative_path) + file_path_length;
     if (maybe_blacklisted_folder_length != std::size(blacklisted_folder)) {
      return false;
     }
     auto const blacklisted_folder_parent = blacklisted_folder.substr(0, std::size(blacklisted_folder) - file_path_length);
     auto const blacklisted_folder_folder = blacklisted_folder.substr(std::size(blacklisted_folder) - file_path_length);
     auto const neq_pred = [](auto&& cs) noexcept { return std::get<0>(cs) != std::get<1>(cs); };
     auto const parent_neq = std::ranges::any_of(
      std::views::zip(blacklisted_folder_parent, relative_path), 
      neq_pred
     );
     auto const folder_neq = std::ranges::any_of(
      std::views::zip(
       blacklisted_folder_folder, 
       std::string_view{ 
        data.cFileName, 
        file_path_length 
       }
      ), 
      neq_pred
     );
     return !(parent_neq || folder_neq);
    }
   );

   return blacklisted_folder_it != std::cend(READ_CONFIG(config, "folder_blacklist"));
  }
  inline bool is_extension_whitelisted() const noexcept {
   auto&& directory_walker_data = file::directory_walker_data::get_thread_instance();
   auto&& data = directory_walker_data.data;
   auto&& file_path_length = directory_walker_data.file_path_length;

   auto&& extension_whitelist = READ_CONFIG(config, "extension_whitelist");
   auto const extension_whitelist_bitset = extension_whitelist | std::views::transform([&](auto&& whitelisted_extension) {
    bool const file_name_long_enough = file_path_length >= std::size(whitelisted_extension);
    std::string_view const file_name_extension_range = { 
     data.cFileName + file_path_length - std::size(whitelisted_extension), 
     std::size(whitelisted_extension)
    }; /* Readable only if file_name_long_enough */
    auto const extension_equality_bitset_iterable = 
     std::views::zip(
      file_name_extension_range, 
      whitelisted_extension
     ) | 
     std::views::transform([](auto&& zipped_extension_characters) noexcept {
      char const current_file_name_extension_character = std::get<0>(zipped_extension_characters);
      char const whitelisted_extension_character = std::get<1>(zipped_extension_characters);
      return current_file_name_extension_character == whitelisted_extension_character;
     });

    return 
     file_name_long_enough && 
     std::ranges::all_of(
      std::cbegin(extension_equality_bitset_iterable), 
      std::cend(extension_equality_bitset_iterable),
      [](auto&& a) { return a; }
     );
   });
   return std::ranges::any_of(
    std::cbegin(extension_whitelist_bitset), 
    std::cend(extension_whitelist_bitset), 
    [](auto const a) { return a; }
   );
  }
  void fetch() noexcept {
   auto&& directory_walker_data = file::directory_walker_data::get_thread_instance();
   auto&& data = directory_walker_data.data;
   auto&& file_iterator_handles = directory_walker_data.file_iterator_handles;
   auto&& file_paths = directory_walker_data.file_paths;
   auto&& file_path_lengths = directory_walker_data.file_path_lengths;
   auto&& directory_depth = directory_walker_data.directory_depth;
   auto&& file_path = directory_walker_data.file_path;
   auto&& file_path_length = directory_walker_data.file_path_length;

   while (file_iterator_handles[0] != nullptr) {
    if (file_iterator_handles[directory_depth] == nullptr) [[unlikely]] /* New Directory */ {
     (void)std::memcpy(
      file_paths[directory_depth], 
      file_paths[directory_depth - 1], 
      file_path_lengths[directory_depth - 1]
     );
     (void)std::memcpy(
      file_paths[directory_depth] + file_path_lengths[directory_depth - 1], 
      data.cFileName, 
      file_path_length
     );
     append_slashed_path_suffix(
      file_paths[directory_depth], 
      file_path_lengths[directory_depth - 1] + file_path_length
     );
     file_path_lengths[directory_depth] = file_path_lengths[directory_depth - 1] + file_path_length + 1;
     file_iterator_handles[directory_depth] = ::FindFirstFileA(
      file_paths[directory_depth], 
      &data
     );
     (void)::FindNextFileA(
      file_iterator_handles[directory_depth], 
      &data
     );
     (void)::FindNextFileA(
      file_iterator_handles[directory_depth], 
      &data
     );
     if (file_iterator_handles[directory_depth] == reinterpret_cast<void*>(-1)) [[unlikely]] /* Folder Empty */ {
      file_iterator_handles[directory_depth--] = nullptr;
      continue;
     }
    } else [[likely]] /* Existing Directory */ {
     auto const result = ::FindNextFileA(
      file_iterator_handles[directory_depth], 
      &data
     );
     if (result == 0) [[unlikely]] /* Likely End-of-Folder */ {
      auto const system_error_code = static_cast<win32::system_error_code>(::GetLastError());
      if (system_error_code == win32::system_error_code::error_no_more_files) [[likely]] /* End-of-Folder */ {
       file_iterator_handles[directory_depth--] = nullptr; /* Step Out of Directory */
       continue;
      } else [[unlikely]] {
       return;
      }
     }
    }
    file_path_length = std::strlen(data.cFileName);
    auto const file_attribute = static_cast<win32::file_attribute>(data.dwFileAttributes);
    if (win32::check_flag(file_attribute, win32::file_attribute::directory)) [[unlikely]] /* Entry is Folder */ {
     /* Skip Parent and Current */
     if (data.cFileName[0] == '.') [[unlikely]] {
      if (data.cFileName[1] == 0 || (data.cFileName[1] == '.' && data.cFileName[2] == 0)) [[likely]] {
       continue;
      }
     }
     if constexpr (CHECK_CONFIG(config, "folder_blacklist")) /* CT Folder Blacklist is Set */ {
      if (this->is_directory_blacklisted()) {
       continue; /* Skip */
      }
     }
     file_iterator_handles[++directory_depth] = nullptr; /* Step into Directory */
    } else if (win32::check_flag(file_attribute, win32::file_attribute::normal)) [[unlikely]] /* Entry is File */ {
     (void)std::memcpy(
      file_path, 
      file_paths[directory_depth], 
      file_path_lengths[directory_depth]
     );
     (void)std::memcpy(
      file_path + file_path_lengths[directory_depth], 
      data.cFileName, 
      file_path_length
     );
     file_path[file_path_lengths[directory_depth] + file_path_length] = '\0';
     if constexpr (CHECK_CONFIG(config, "extension_whitelist")) {
      if (!this->is_extension_whitelisted()) {
       continue;
      }
     }
     return;
    } else if (win32::check_flag(file_attribute, win32::file_attribute::archive)) [[likely]] /* Neither file nor directory */ {
     (void)std::memcpy(
      file_path, 
      file_paths[directory_depth], 
      file_path_lengths[directory_depth]
     );
     (void)std::memcpy(
      file_path + file_path_lengths[directory_depth], 
      data.cFileName, file_path_length
     );
     file_path[file_path_lengths[directory_depth] + file_path_length] = '\0';
     if constexpr (CHECK_CONFIG(config, "extension_whitelist")) {
      if (!this->is_extension_whitelisted()) {
       continue;
      }
     }
     return;
    } else [[unlikely]] {
     continue; /* Skip */
    }
   }
  }

  [[nodiscard]] inline std::string_view operator*() noexcept {
   auto&& directory_walker_data = file::directory_walker_data::get_thread_instance();
   auto&& file_path_lengths = directory_walker_data.file_path_lengths;
   auto&& directory_depth = directory_walker_data.directory_depth;
   auto&& file_path = directory_walker_data.file_path;
   auto&& file_path_length = directory_walker_data.file_path_length;

   return std::string_view{
    file_path, 
    file_path_lengths[directory_depth] + file_path_length
   };
  }
  [[nodiscard]] inline bool operator==(iterator_sentinel const) const noexcept {
   auto&& directory_walker_data = file::directory_walker_data::get_thread_instance(); 
   auto&& file_iterator_handles = directory_walker_data.file_iterator_handles;
   
   return file_iterator_handles[0] == nullptr;
  }
  auto&& operator++() noexcept {
   this->fetch();
   return *this;
  }
  auto&& operator++(int) noexcept {
   
  }
 };
}