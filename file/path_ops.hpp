#pragma once

#include "types.hpp"
#include <tuple>
#include <string_view>

namespace file {
    inline constexpr std::string path_to_filename(std::string_view const path) noexcept {
        for (u32 i = std::size(path) - 1; i > 1; --i) {
            if (path[i] == '/') [[unlikely]] {
                return std::string(std::data(path) + i + 1, std::data(path) + std::size(path));
            }
        }
    }
    inline constexpr std::pair<std::string, std::string> path_to_filename_and_ext(std::string_view const path) noexcept {
        u32 ext_i = 0;
        for (u32 i = std::size(path) - 1; i > 1; --i) {
            if (path[i] == '.' && ext_i) [[likely]] {
                ext_i = i;
            } else if (path[i] == '/') [[unlikely]] {
                return std::pair<std::string, std::string>{ 
                    std::string(std::data(path) + i + 1, std::data(path) + ext_i), 
                    std::string(std::data(path) + ext_i + 1, std::data(path) + std::size(path)) 
                    };
            }
        }
    }
}