#include "byte_writer.hpp"

namespace file {
    byte_writer::byte_writer(std::string_view const file_path) noexcept {
        auto const err = ::fopen_s(&m_file_handle, std::data(file_path), "wb");
    }
    byte_writer::byte_writer(std::FILE* const file_handle) noexcept : m_file_handle{file_handle} {}

    std::pair<std::size_t, byte_writer::error_code> byte_writer::write(stl::buffer buffer) const noexcept {
        auto const write_count = ::fwrite(std::data(buffer), 1, std::size(buffer), m_file_handle);
        if (write_count != std::size(buffer)) {
            if (::feof(m_file_handle) != 0) [[likely]] {
                return std::pair<std::size_t, error_code>{ write_count, error_code::eof };
            } else if (::ferror(m_file_handle) != 0) [[unlikely]] {
                return std::pair<std::size_t, error_code>{ write_count, error_code::err };
            }
            return std::pair<std::size_t, error_code>{ write_count, error_code::unknown };
        }
        return std::pair<std::size_t, error_code>{ write_count, error_code::success };
    }

    std::FILE* byte_writer::file_handle() noexcept { return m_file_handle; }
}