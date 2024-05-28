#pragma once

#include "types.hpp"
#include "socket.hpp"
#include "file/byte_reader.hpp"
#include <string_view>

namespace net {
    class file_sharer {
    public:
        file_sharer(socket const& socket) noexcept;

        void send_file(std::string_view const file_path) const noexcept;
        void receive_file(std::string_view const file_path) const noexcept;

    private:
        socket m_socket;
    };
}