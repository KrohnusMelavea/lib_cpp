#pragma once

#include "types.hpp"
#include "stl/buffer.hpp"
#include <span>
#include <tuple>
#include <cstdio>
#include <string_view>

namespace file {
    class byte_writer {
    public:
        enum class error_code : u08 { success, eof, err, unknown };

        byte_writer(std::string_view const file_path) noexcept;
        byte_writer(std::FILE* const file_handle) noexcept;
        
        std::pair<std::size_t, error_code> write(stl::buffer const buffer) const noexcept;

        std::FILE* file_handle() noexcept;

    private:
        std::FILE* m_file_handle;
    };
}