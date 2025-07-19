#include "read_file.hpp"
#include "byte_reader.hpp"

namespace file {
 stl::status_type<file::byte_reader::error_code, stl::dynamic_array<u08>> read_file(std::string_view const file_path) noexcept {
  thread_local std::array<u08, 16384> buffer;
  stl::status_type<file::byte_reader::error_code, stl::dynamic_array<u08>> file_contents{ file::byte_reader::error_code::unknown, stl::dynamic_array<u08>{} };
  byte_reader reader(file_path);
  if (reader.file_handle() == nullptr) [[unlikely]] {
   return file_contents;
  }
  while (true) {
   auto result = reader.read(stl::buffer{std::data(buffer), std::size(buffer)});
   if (result.value > 0) [[likely]] {
    if (result.value < std::size(buffer)) {}
    file_contents.value.grow(stl::buffer{std::data(buffer), result.value});
   } else [[unlikely]] {
    file_contents.status = result.status;
    return file_contents;
   }
  }
 }
}