#include "ping.hpp"
#include "stl/buffer.hpp"
#include <numeric>
#include <process.h>


namespace net {
    struct icmp_header {
        u08 type;
        u08 code;
        u16 checksum;
        u16 pid;
        u16 sequence;
    };

    [[nodiscard]] std::expected<net::ping_response, net::socket_error_code> ping(u32 const address) noexcept {
        auto const socket_handle = ::socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if (socket_handle == INVALID_SOCKET) [[unlikely]] {
            return std::unexpected{static_cast<net::socket_error_code>(::WSAGetLastError())};
        }
        std::array<char, sizeof(net::icmp_header) + 32> a;
        (void) new (std::data(a)) net::icmp_header{
            .type = 8,
            .code = 0,
            .checksum = 0,
            .pid = static_cast<u16>(::_getpid()),
            .sequence = 1
        };
        ::sockaddr_in const sockaddr_in {
            .sin_family = AF_INET,
            .sin_port = 0,
            .sin_addr = {
                .S_un = {
                    .S_addr = address
                }
            }
        };
        ::sendto(socket_handle, std::data(a), std::size(a), 0, reinterpret_cast<::sockaddr const* const>(&sockaddr_in), sizeof(::sockaddr));
        ::recvfrom(socket_handle, )
    }
}