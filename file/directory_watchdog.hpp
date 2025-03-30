#pragma once

#include "empty.hpp"
#include "types.hpp"
#include "directory_walker.hpp"
#include "directory_watchdog_iterator.hpp"
#include "stl/array.hpp"
#include "stl/ctconfig.hpp"
#include "stl/string_view.hpp"
#include "stl/dynamic_array.hpp"
#include <array>
#include <print>
#include <string>

namespace file {
 struct super {
  stl::dynamic_array<bool> m_file_exists;
 };
 
 using super_t = super;

 template <stl::ctconfig config> 
 class directory_watchdog : public super_t
 {
 public:
  directory_watchdog(std::string_view const directory) noexcept : 
   m_directory{directory} 
  {

  }

  auto begin() noexcept {
   thread_local auto directory_walker = walk_directory<config>(this->m_directory);
   this->m_directory_walker = walk_directory<config>(this->m_directory);
   if constexpr (CHECK_CONFIG(config, "should_handle_deleted_files")) {
    return directory_watchdog_iterator<config>::construct(
     std::begin(this->m_directory_walker),
     this->m_file_paths,
     this->m_file_hashes,
     this->m_file_exists
    );
   } else {
    return directory_watchdog_iterator<config>::construct(
     std::begin(this->m_directory_walker),
     this->m_file_paths,
     this->m_file_hashes
    );
   }
   
  }
  auto end() noexcept {
   return iterator_sentinel{};
  }

 private:
  std::string m_directory;
  directory_walker<config> m_directory_walker;
  stl::dynamic_array<std::string> m_file_paths;
  stl::dynamic_array<std::array<u32, 8>> m_file_hashes;
 };
}