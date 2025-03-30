#pragma once

#include "iterator_sentinel.hpp"
#include "read_file.hpp"
#include "directory_walker_iterator.hpp"
#include "stl/ctconfig.hpp"
#include "stl/dynamic_array.hpp"
#include "crypto/gen_sha256.hpp"
#include <array>
#include <print>
#include <string>
#include <ranges>

namespace file {
 struct this_super {
  stl::dynamic_array<bool> &m_file_exists;
  std::size_t m_existing_file_count;
 };
 template <stl::ctconfig config> static constexpr auto should_handle_deleted_files = CHECK_CONFIG(config, "should_handle_deleted_files");
 template <stl::ctconfig config>
 using this_super_t = std::conditional_t<
 should_handle_deleted_files<config>,
  this_super,
  empty
 >;

 template <stl::ctconfig config> 
 struct directory_watchdog_iterator : public this_super_t<config> {
  using file_exists_t = stl::dynamic_array<bool>&;
  
  directory_walker_iterator<config> iterator;
  stl::dynamic_array<std::string>& file_paths;
  stl::dynamic_array<std::array<u32, 8>>& file_hashes;
  std::string_view file_path;

  static directory_watchdog_iterator<config> construct(
   directory_walker_iterator<config> iterator, 
   stl::dynamic_array<std::string>& file_paths, 
   stl::dynamic_array<std::array<u32, 8>>& file_hashes
  ) {
   return directory_watchdog_iterator<config>(
    iterator, 
    file_paths, 
    file_hashes
   );
  }
  static directory_watchdog_iterator<config> construct(
    directory_walker_iterator<config> iterator, 
    stl::dynamic_array<std::string>& file_paths, 
    stl::dynamic_array<std::array<u32, 8>>& file_hashes,
    file_exists_t file_exists
   ) {
    return directory_watchdog_iterator<config>(
     iterator, 
     file_paths, 
     file_hashes, 
     file_exists
    );
   }
  
  directory_watchdog_iterator(
   directory_walker_iterator<config> iterator, 
   stl::dynamic_array<std::string>& file_paths, 
   stl::dynamic_array<std::array<u32, 8>>& file_hashes
  ) noexcept :
   iterator{iterator}, 
   file_paths{file_paths}, 
   file_hashes{file_hashes}
  {
   this->scan_forward();
   if (this->iterator == iterator_sentinel{}) {
    return;
   }
   this->file_path = *(this->iterator);
  }
  directory_watchdog_iterator(
   directory_walker_iterator<config> iterator, 
   stl::dynamic_array<std::string>& file_paths, 
   stl::dynamic_array<std::array<u32, 8>>& file_hashes,
   stl::dynamic_array<bool>& file_exists
  ) noexcept : 
   this_super_t<config>{file_exists, 0},
   iterator{iterator},
   file_paths{file_paths},
   file_hashes{file_hashes} 
  {
   this->file_path = *(this->iterator);
   std::fill(
    std::begin(this->m_file_exists),
    std::end(this->m_file_exists),
    false
   );
   this->scan_forward();
   if (this->iterator == iterator_sentinel{}) {
    return;
   }
  }

  void operator++() noexcept {
   ++this->iterator;
   this->scan_forward();
   if (this->iterator == iterator_sentinel{}) {
    return;
   }
  }
  [[nodiscard]] constexpr auto&& operator*() noexcept {
   return this->file_path;
  }
  [[nodiscard]] bool operator==(iterator_sentinel const) const noexcept {
   if (this->iterator == iterator_sentinel{}) [[unlikely]] {
    if constexpr (should_handle_deleted_files<config>) {
     if (this->m_existing_file_count != std::size(this->file_paths)) [[unlikely]] {
      std::size_t new_size = 0; /* Also serves as a running pointer */
      for (std::size_t i = 0; i < std::size(this->file_paths); ++i) {
       if (this->m_file_exists[i]) [[likely]] {
        this->file_paths[new_size] = std::move(this->file_paths[i]);
        this->file_hashes[new_size] = std::move(this->file_hashes[i]);
        ++new_size;
       }
      }
      this->file_paths.truncate(new_size);
      this->file_hashes.truncate(new_size);
      this->m_file_exists.truncate(new_size);
      }
    }
    return true;
   } else [[likely]] {
    return false;
   }
  }

  void scan_forward() noexcept {
   while (this->iterator != iterator_sentinel{}) {
    this->file_path = *this->iterator;
    auto const file_contents = read_file(file_path);
    auto const file_hash = crypto::gen_sha256_impl(file_contents);
    auto it = std::find(
     std::begin(this->file_paths), 
     std::end(this->file_paths), 
     file_path
    );
    if (it == std::end(this->file_paths)) [[unlikely]] /* New File Found */ {
     this->file_paths.push_back(std::string(file_path));
     this->file_hashes.push_back(file_hash);
     if constexpr (should_handle_deleted_files<config>) {
      this->m_file_exists.push_back(true);
      ++this->m_existing_file_count;
     }
     return;
    }
    else [[likely]] /* Existing File */ {
     const auto file_index = it - std::begin(this->file_paths);
     auto& existing_file_hash = this->file_hashes[file_index];
     if constexpr (should_handle_deleted_files<config>) {
      this->m_file_exists[file_index] = true;
      ++this->m_existing_file_count;
     }
     if (!hashes_equal(existing_file_hash, file_hash)) [[likely]] /* File Contents Modified Since Last Call */ {
      existing_file_hash = file_hash;
      return;
     }
    }
    ++this->iterator;
   }
  }

  [[nodiscard]] static constexpr bool hashes_equal(std::span<u32 const, 8> const lhs, std::span<u32 const, 8> const rhs) noexcept {
   return std::ranges::all_of(
    std::views::zip(lhs, rhs),
    [](auto const zipped_dwords) noexcept {
     auto&& lhs = std::get<0>(zipped_dwords);
     auto&& rhs = std::get<1>(zipped_dwords);
     return lhs == rhs;
    } 
   );
  }
 };
}