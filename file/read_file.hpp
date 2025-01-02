#pragma once

#include "stl/dynamic_array.hpp"
#include <string_view>

namespace file {
 stl::dynamic_array<u08> read_file(std::string_view const file_path) noexcept;
}