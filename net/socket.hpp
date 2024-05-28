#pragma once

#include "types.hpp"
#include "socket_error_code.hpp"
#include "stl/buffer.hpp"
#include "stl/dynamic_array.hpp"
#include <span>
#include <expected>
#include <string_view>

struct WSAData;

namespace net {
    class socket {
    public:
        socket() noexcept;
        constexpr socket(u64 const socket, u32 const host, u16 const port) noexcept : m_socket{socket}, m_host{host}, m_port{port} { }
        ~socket() noexcept;

        socket_error_code bind(u32 const host, u16 const port) noexcept;
        std::expected<u32, socket_error_code> send(stl::buffer const& data) const noexcept;
        std::expected<u32, net::socket_error_code> send(std::string_view const data) const noexcept;
        socket_error_code close() const noexcept;
        [[nodiscard]] std::expected<socket, socket_error_code> accept() const noexcept;
        socket_error_code listen() const noexcept;
        socket_error_code connect(u32 const host, u16 const port) const noexcept;
        std::expected<u32, socket_error_code> receive(stl::buffer data) const noexcept;
        socket_error_code shutdown() const noexcept;

        static socket_error_code init_backend() noexcept;
        static socket_error_code deinit_backend() noexcept;

    private:
        u64 m_socket;
        u32 m_host;
        u16 m_port;

        static WSAData wsa_data;
        static constexpr bool is_reference_counting = false;
        static inline u32 reference_count = 0;
    };
}