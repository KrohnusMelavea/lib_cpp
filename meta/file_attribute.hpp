#pragma once

#include "types.hpp"
#include <array>   
#include <tuple>
#include <string>
#include <ranges>
#include <numeric>
#include <algorithm>
#include <string_view>

namespace win32 {
 enum class file_attribute : u32 {
  readonly              = 1 <<  0,  
  hidden                = 1 <<  1,  
  system                = 1 <<  2,  
  directory             = 1 <<  4,  
  archive               = 1 <<  5,  
  device                = 1 <<  6,  
  normal                = 1 <<  7,  
  temporary             = 1 <<  8,  
  sparse_file           = 1 <<  9,  
  reparse_point         = 1 << 10,  
  compressed            = 1 << 11,  
  offline               = 1 << 12,  
  not_content_indexed   = 1 << 13,  
  encrypted             = 1 << 14,  
  integrity_stream      = 1 << 15,  
  virt                  = 1 << 16,  
  no_scrub_data         = 1 << 17,  
  recall_on_open        = 1 << 18,  
  pinned                = 1 << 19,  
  unpinned              = 1 << 20,  
  recall_on_data_access = 1 << 22,
 };

 inline constexpr std::array<std::pair<file_attribute, std::string_view>, 21> FILE_ATTRIBUTE_LOOKUP {
  std::pair<file_attribute, std::string_view>{ file_attribute::readonly             , "file_attribute::readonly"              },
  std::pair<file_attribute, std::string_view>{ file_attribute::hidden               , "file_attribute::hidden"                },
  std::pair<file_attribute, std::string_view>{ file_attribute::system               , "file_attribute::system"                },
  std::pair<file_attribute, std::string_view>{ file_attribute::directory            , "file_attribute::directory"             },
  std::pair<file_attribute, std::string_view>{ file_attribute::archive              , "file_attribute::archive"               },
  std::pair<file_attribute, std::string_view>{ file_attribute::device               , "file_attribute::device"                },
  std::pair<file_attribute, std::string_view>{ file_attribute::normal               , "file_attribute::normal"                },
  std::pair<file_attribute, std::string_view>{ file_attribute::temporary            , "file_attribute::temporary"             },
  std::pair<file_attribute, std::string_view>{ file_attribute::sparse_file          , "file_attribute::sparse_file"           },
  std::pair<file_attribute, std::string_view>{ file_attribute::reparse_point        , "file_attribute::reparse_point"         },
  std::pair<file_attribute, std::string_view>{ file_attribute::compressed           , "file_attribute::compressed"            },
  std::pair<file_attribute, std::string_view>{ file_attribute::offline              , "file_attribute::offline"               },
  std::pair<file_attribute, std::string_view>{ file_attribute::not_content_indexed  , "file_attribute::not_content_indexed"   },
  std::pair<file_attribute, std::string_view>{ file_attribute::encrypted            , "file_attribute::encrypted"             },
  std::pair<file_attribute, std::string_view>{ file_attribute::integrity_stream     , "file_attribute::integrity_stream"      },
  std::pair<file_attribute, std::string_view>{ file_attribute::virt                 , "file_attribute::virt"                  },
  std::pair<file_attribute, std::string_view>{ file_attribute::no_scrub_data        , "file_attribute::no_scrub_data"         },
  std::pair<file_attribute, std::string_view>{ file_attribute::recall_on_open       , "file_attribute::recall_on_open"        },
  std::pair<file_attribute, std::string_view>{ file_attribute::pinned               , "file_attribute::pinned"                },
  std::pair<file_attribute, std::string_view>{ file_attribute::unpinned             , "file_attribute::unpinned"              },
  std::pair<file_attribute, std::string_view>{ file_attribute::recall_on_data_access, "file_attribute::recall_on_data_access" },
 };
 inline constexpr bool check_flag(file_attribute const whole, file_attribute const partial) noexcept {
  return static_cast<bool>(std::to_underlying(whole) & std::to_underlying(partial));
 }
 inline constexpr bool check_flag(file_attribute const file_attribute) noexcept {
  return std::ranges::find_if(FILE_ATTRIBUTE_LOOKUP, [&](auto&& entry) noexcept {
   return check_flag(file_attribute, entry.first);
  }) != std::cend(FILE_ATTRIBUTE_LOOKUP);
 }
 inline constexpr std::string lookup_enum(file_attribute const file_attribute) noexcept {
  auto const alloc_size = std::invoke([&]() noexcept {
   std::size_t count = 0;
   auto const alloc_size = std::accumulate(std::cbegin(FILE_ATTRIBUTE_LOOKUP), std::cend(FILE_ATTRIBUTE_LOOKUP), static_cast<std::size_t>(0), [&](auto const sum, auto&& entry) noexcept {
    ++count;
    return sum + std::size(entry.second) * static_cast<std::size_t>(check_flag(file_attribute, entry.first));
   });
   return alloc_size + static_cast<std::size_t>(count > 1) * (count - static_cast<std::size_t>(1));
  });
  std::string file_attributes;
  if (alloc_size == 0) {
   return file_attributes;
  }
  file_attributes.reserve(alloc_size);
  auto const it = std::find_if(std::cbegin(FILE_ATTRIBUTE_LOOKUP), std::cend(FILE_ATTRIBUTE_LOOKUP), [&](auto&& entry) noexcept {
   return check_flag(file_attribute, entry.first);
  });
  if (it != std::cend(FILE_ATTRIBUTE_LOOKUP)) {
   file_attributes.append(std::cbegin(it->second), std::cend(it->second));
   std::for_each(std::next(it), std::cend(FILE_ATTRIBUTE_LOOKUP), [&](auto&& entry) noexcept {
    if (check_flag(file_attribute, entry.first)) {
     file_attributes.push_back('|');
     file_attributes.append(std::cbegin(entry.second), std::cend(entry.second));
    }
   });
  }
  
  return file_attributes;
 }
}