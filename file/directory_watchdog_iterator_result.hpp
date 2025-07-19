#pragma once

#include "stl/dynamic_array.hpp"
#include <span>
#include <string_view>

namespace file {
 struct directory_watchdog_iterator_result {
  std::string_view const path;
  std::span<u08> const data;
 };
}