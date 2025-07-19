#pragma once

#include "byte_reader.hpp"
#include "stl/status_type.hpp"
#include "stl/dynamic_array.hpp"
#include <string_view>

namespace file {
 stl::status_type<byte_reader::error_code, stl::dynamic_array<u08>> read_file(std::string_view const file_path) noexcept;
}