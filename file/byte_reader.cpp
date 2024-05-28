#include "byte_reader.hpp"

namespace file {
    byte_reader::byte_reader(std::string_view const file_path) noexcept {
        (void)::fopen_s(&m_file_handle, std::data(file_path), "rb");
    }
    byte_reader::byte_reader(std::FILE* const file_handle) noexcept : m_file_handle{file_handle} {}

    std::pair<std::size_t, byte_reader::error_code> byte_reader::read(stl::buffer buffer) const noexcept {
        auto const read_count = ::fread_s(std::data(buffer), std::size(buffer), 1, std::size(buffer), m_file_handle);
        if (read_count != std::size(buffer)) {
            if (::feof(m_file_handle) != 0) [[likely]] {
                return std::pair<std::size_t, error_code>{ read_count, error_code::eof };
            } else if (::ferror(m_file_handle) != 0) [[unlikely]] {
                return std::pair<std::size_t, error_code>{ read_count, error_code::err };
            }
            return std::pair<std::size_t, error_code>{ read_count, error_code::unknown };
        }
        return std::pair<std::size_t, error_code>{ read_count, error_code::success };
    }

    std::FILE* byte_reader::file_handle() noexcept { return m_file_handle; }
}