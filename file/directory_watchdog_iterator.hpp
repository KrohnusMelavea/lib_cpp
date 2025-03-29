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

namespace file {
 struct this_super {

 };
 template <stl::ctconfig config>
 using this_super_t = this_super
;

 template <stl::ctconfig config> 
 struct directory_watchdog_iterator : public this_super_t<config> {
  using file_exists_t = stl::dynamic_array<bool>&;
  
  directory_walker_iterator<config> iterator;
  stl::dynamic_array<std::string>& file_paths;
  stl::dynamic_array<std::array<u32, 8>>& file_hashes;
  std::string_view file_path;

  template <class... Args> static directory_watchdog_iterator<config> construct(Args&&... args) {
   return directory_watchdog_iterator<config>{args...};
  }

  static directory_watchdog_iterator<config> construct(
   directory_walker_iterator<config> iterator, 
   stl::dynamic_array<std::string>& file_paths, 
   stl::dynamic_array<std::array<u32, 8>>& file_hashes
  ) {
   return directory_watchdog_iterator<config>(iterator, file_paths, file_hashes);
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


  void operator++() noexcept {
   ++this->iterator;
   this->scan_forward();
   if (this->iterator == iterator_sentinel{}) {
    return;
   }
   this->file_path = *(this->iterator);
  }
  constexpr auto&& operator*() noexcept {
   return this->file_path;
  }
  bool operator==(iterator_sentinel const) const noexcept {
   return this->iterator == iterator_sentinel{};
  }

  void scan_forward() noexcept {
   while (this->iterator != iterator_sentinel{}) {
    auto const file_path = *this->iterator;
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
     return;
    }
    else [[likely]] /* Existing File */ {
     auto& existing_file_hash = this->file_hashes[it - std::begin(this->file_paths)];
     if (!hashes_equal(existing_file_hash, file_hash)) [[likely]] /* File Contents Modified Since Last Call */ {
      existing_file_hash = file_hash;
      return;
     }
    }
    ++this->iterator;
   }
  }

  static constexpr bool hashes_equal(std::span<u32 const, 8> const lhs, std::span<u32 const, 8> const rhs) noexcept {
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