#pragma once

#include "types.hpp"
#include "meta/file_attribute.hpp"
#include "meta/system_error_code.hpp"
#include "stl/ctconfig.hpp"
#include <minwinbase.h>
#include <array>
#include <string_view>

namespace file {
 static void append_unslashed_path_suffix(char *const data, std::size_t const size) noexcept {
  data[size + 0] = '*';
  data[size + 1] = 0;
 }
 static void append_slashed_path_suffix(char *const data, std::size_t const size) noexcept {
  data[size + 0] = '\\';
  data[size + 1] = '*';
  data[size + 2] = 0;
 }

 template <stl::ctconfig config> struct directory_walker_iterator {
  ::WIN32_FIND_DATAA& data;
  std::array<char[256], 16>& file_paths;
  std::array<std::size_t, 16>& file_path_lengths;
  std::array<void*, 16>& file_iterator_handles;
  char (&file_path)[256];
  std::size_t file_path_length;
  std::string_view const& directory;
  std::size_t index;

  inline constexpr bool is_directory_blacklisted() const noexcept {
   return std::ranges::find_if(READ_CONFIG(config, "folder_blacklist"), [&](std::string_view const blacklisted_folder) noexcept {
    auto const relative_path = std::string_view{file_paths[index], file_path_lengths[index]}.substr(std::size(directory));
    if (std::size(relative_path) + file_path_length != std::size(blacklisted_folder)) {
     return false;
    }
    auto const blacklisted_folder_parent = blacklisted_folder.substr(0, std::size(blacklisted_folder) - file_path_length);
    auto const blacklisted_folder_folder = blacklisted_folder.substr(std::size(blacklisted_folder) - file_path_length);
    auto const neq_pred = [](auto&& cs) noexcept { return std ::get<0>(cs) != std::get<1>(cs); };
    auto const parent_neq = std::ranges::any_of(std::views::zip(blacklisted_folder_parent, relative_path), neq_pred);
    auto const folder_neq = std::ranges::any_of(std::views::zip(blacklisted_folder_folder, std::string_view{data.cFileName, file_path_length}), neq_pred);
    return !(parent_neq || folder_neq);
   }) != std::cend(READ_CONFIG(config, "folder_blacklist"));
  }
  inline constexpr bool is_extension_whitelisted() const noexcept {
   auto&& extension_whitelist = READ_CONFIG(config, "extension_whitelist");
   return std::ranges::find_if(extension_whitelist, [&](std::string_view const whitelisted_extension) noexcept {
    std::string_view const filename{data.cFileName, this->file_path_length};
    auto const zipped = std::views::zip(std::views::reverse(whitelisted_extension), std::views::reverse(filename));
    return std::ranges::find_if(zipped, [&](auto&& cs) noexcept {
     return std::get<0>(cs) != std::get<1>(cs);
    }) == std::cend(zipped);
   }) != std::cend(extension_whitelist);
  }
  void fetch() noexcept {
   while (file_iterator_handles[0] != nullptr) {
    if (file_iterator_handles[index] == nullptr) [[unlikely]] /* New Directory */ {
     (void)std::memcpy(file_paths[index], file_paths[index - 1], file_path_lengths[index - 1]);
     (void)std::memcpy(file_paths[index] + file_path_lengths[index - 1], data.cFileName, file_path_length);
     append_slashed_path_suffix(file_paths[index], file_path_lengths[index - 1] + file_path_length);
     file_path_lengths[index] = file_path_lengths[index - 1] + file_path_length + 1;
     file_iterator_handles[index] = ::FindFirstFileA(file_paths[index], &data);
     (void)::FindNextFileA(file_iterator_handles[index], &data);
     (void)::FindNextFileA(file_iterator_handles[index], &data);
     if (file_iterator_handles[index] == reinterpret_cast<void*>(-1)) [[unlikely]] /* Folder Empty */ {
      file_iterator_handles[index--] = nullptr;
      continue;
     }
    } else [[likely]] /* Existing Directory */ {
     auto const result = ::FindNextFileA(file_iterator_handles[index], &data);
     if (result == 0) [[unlikely]] /* Likely End-of-Folder */ {
      auto const system_error_code = static_cast<win32::system_error_code>(::GetLastError());
      if (system_error_code == win32::system_error_code::error_no_more_files) [[likely]] /* End-of-Folder */ {
       file_iterator_handles[index--] = nullptr; /* Step Out of Directory */
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
     if constexpr (config.find<"folder_blacklist">() != std::numeric_limits<std::size_t>::max()) /* CT Folder Blacklist is Set */ {
      if (this->is_directory_blacklisted()) {
       continue; /* Skip */
      }
     }
     file_iterator_handles[++index] = nullptr; /* Step into Directory */
    } else if (win32::check_flag(file_attribute, win32::file_attribute::normal)) [[unlikely]] /* Entry is File */ {
     (void)std::memcpy(this->file_path, this->file_paths[index], this->file_path_lengths[this->index]);
     (void)std::memcpy(this->file_path + this->file_path_lengths[index], this->data.cFileName, this->file_path_length);
     this->file_path[this->file_path_lengths[this->index] + this->file_path_length] = 0;
     if constexpr (CHECK_CONFIG(config, "extension_whitelist")) {
      if (!this->is_extension_whitelisted()) {
       continue;
      }
     }
     return;
    } else if (win32::check_flag(file_attribute, win32::file_attribute::archive)) [[likely]] /* Neither file nor directory */ {
     (void)std::memcpy(this->file_path, this->file_paths[index], this->file_path_lengths[index]);
     (void)std::memcpy(this->file_path + this->file_path_lengths[index], data.cFileName, file_path_length);
     this->file_path[this->file_path_lengths[this->index] + this->file_path_length] = 0;
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

  std::string_view operator*() noexcept {
   return std::string_view{file_path, file_path_lengths[this->index] + file_path_length};
  }
  bool operator==(iterator_sentinel) const noexcept {
   return file_iterator_handles[0] == nullptr;
  }
  void operator++() noexcept {
   fetch();
  }


 };
}