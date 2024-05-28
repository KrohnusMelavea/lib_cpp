#pragma once

#include "types.hpp"
#include "socket_error_code.hpp"
#include <expected>
#include <winsock2.h>

namespace net {
    struct ping_response {
        u32 address;
        u08 size;
        u08 delta;
        u08 ttl;
        u08 success;
    };

    [[nodiscard]] std::expected<net::ping_response, net::socket_error_code> ping(u32 const address) noexcept;
}