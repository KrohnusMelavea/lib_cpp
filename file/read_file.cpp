#include "read_file.hpp"
#include "byte_reader.hpp"

namespace file {
 stl::dynamic_array<u08> read_file(std::string_view const file_path) noexcept {
  thread_local std::array<u08, 16384> buffer;
  stl::dynamic_array<u08> file_contents{};
  byte_reader reader(file_path);
  while (true) {
   auto result = reader.read(stl::buffer{std::data(buffer), std::size(buffer)});
   if (result.value > 0) [[likely]] {
    if (result.value < std::size(buffer)) {}
    file_contents.grow(stl::buffer{std::data(buffer), result.value});
   } else [[unlikely]] {
    return file_contents;
   }
  }
 }
}