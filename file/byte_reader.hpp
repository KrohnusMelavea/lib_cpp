#pragma once

#include "types.hpp"
#include "stl/buffer.hpp"
#include "stl/status_type.hpp"
#include <span>
#include <tuple>
#include <cstdio>
#include <string_view>

namespace file {
 class byte_reader {
 public:
  enum class error_code : u08 { success, eof, err, unknown };

  byte_reader(std::string_view const file_path) noexcept;
  byte_reader(std::FILE* const file_handle) noexcept;
  ~byte_reader() noexcept;
  
  stl::status_type<error_code, std::size_t> read(stl::buffer buffer) const noexcept;

  std::FILE* file_handle() noexcept;

 private:
  std::FILE* m_file_handle;
 };
}