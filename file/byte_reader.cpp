#include "byte_reader.hpp"

namespace file {
 byte_reader::byte_reader(std::string_view const file_path) noexcept {
  (void)::fopen_s(&this->m_file_handle, std::data(file_path), "rb");
 }
 byte_reader::byte_reader(std::FILE* const file_handle) noexcept : 
  m_file_handle{file_handle} 
 {

 }
 byte_reader::~byte_reader() noexcept {
  (void)::fclose(this->m_file_handle);
 }

 stl::status_type<byte_reader::error_code, std::size_t> byte_reader::read(stl::buffer buffer) const noexcept {
  auto const read_count = ::fread_s(std::data(buffer), std::size(buffer), 1, std::size(buffer), this->m_file_handle);
  if (read_count != std::size(buffer)) [[unlikely]] {
   if (::feof(this->m_file_handle) != 0) [[likely]] {
    return stl::status_type<byte_reader::error_code, std::size_t>{ error_code::eof, read_count };
   } else if (::ferror(m_file_handle) != 0) [[unlikely]] {
    return stl::status_type<byte_reader::error_code, std::size_t>{ error_code::err, read_count };
   } else [[unlikely]] {
    return stl::status_type<byte_reader::error_code, std::size_t>{ error_code::unknown, read_count };
   }
  } else [[likely]] {
   return stl::status_type<byte_reader::error_code, std::size_t>{ error_code::success, read_count };
  }
 }

 std::FILE* byte_reader::file_handle() noexcept { return m_file_handle; }
}