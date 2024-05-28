#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS

#include "socket.hpp"
#include <spdlog/spdlog.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string_view>

/*
WinSock:
- ::bind:            https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-bind
- ::recv:            https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-recv
- ::send:            https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send
- ::accept:          https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept
- ::listen:          https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-listen
- ::socket:          https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-socket
- ::connect:         https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-connect
- ::in_addr:         https://learn.microsoft.com/en-us/windows/win32/api/winsock2/ns-winsock2-in_addr
- ::WSAData:         https://learn.microsoft.com/en-us/windows/win32/api/winsock2/ns-winsock2-wsadata
- ::shutdown:        https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-shutdown
- ::sockaddr:        https://learn.microsoft.com/en-us/windows/win32/winsock/sockaddr-2
- ::WSACleanup:      https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsacleanup
- ::WSAStartup:      https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup
- ::closesocket:     https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-closesocket
- ::WSAGetLastError: https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsagetlasterror
*/

namespace net {
    socket::socket() noexcept : m_socket{ ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) }, m_host{0}, m_port{0} {
        if (m_socket == INVALID_SOCKET) [[unlikely]] {
            auto const error = ::WSAGetLastError();
            SPDLOG_ERROR("socket failed creation ({}) - {}", error, lookup_enum_verbose(static_cast<net::socket_error_code>(error)));
        }
    }
    socket::~socket() noexcept {
        
    }

    socket_error_code socket::bind(u32 const host, u16 const port) noexcept {
        ::sockaddr_in const sockaddr_in {
            .sin_family = AF_INET,
            .sin_port = port,
            .sin_addr = {
                .S_un = {
                    .S_addr = host
                }
            }
        };
        i32 const result = ::bind(m_socket, reinterpret_cast<::sockaddr const*>(&sockaddr_in), sizeof(sockaddr_in));
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::bind - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        m_host = host;
        m_port = port;
        return socket_error_code::success;
    }
    std::expected<u32, socket_error_code> socket::send(stl::buffer const& data) const noexcept {
        i32 const result = ::send(m_socket, reinterpret_cast<char const*>(std::data(data)), std::size(data), 0);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::send - {}", lookup_enum_verbose(socket_error_code));
                return std::unexpected(socket_error_code);
            }
        }
        return static_cast<u32>(result);
    }
    std::expected<u32, socket_error_code> socket::send(std::string_view const data) const noexcept {
        i32 const result = ::send(m_socket, std::data(data), std::size(data) + 1, 0);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::send - {}", lookup_enum_verbose(socket_error_code));
                return std::unexpected(socket_error_code);
            }
        }
        return static_cast<u32>(result);
    }
    socket_error_code socket::close() const noexcept {
        i32 const result = ::closesocket(m_socket);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::closesocket - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        return socket_error_code::success;
    }
    [[nodiscard]] std::expected<socket, socket_error_code> socket::accept() const noexcept {
        ::sockaddr_in sockaddr_in;
        i32 length = sizeof(sockaddr_in);
        auto const socket_handle = ::accept(m_socket, reinterpret_cast<::sockaddr*>(&sockaddr_in), &length);
        if (socket_handle == INVALID_SOCKET) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::accept - {}", lookup_enum_verbose(socket_error_code));
                return std::unexpected(socket_error_code);
            }
        }
        return socket{ socket_handle, sockaddr_in.sin_addr.S_un.S_addr, sockaddr_in.sin_port };
    }
    socket_error_code socket::listen() const noexcept {
        i32 const result = ::listen(m_socket, SOMAXCONN);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::listen - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        return socket_error_code::success;
    }
    socket_error_code socket::connect(u32 const host, u16 const port) const noexcept {
        ::sockaddr_in const sockaddr_in {
            .sin_family = AF_INET,
            .sin_port = port,
            .sin_addr = {
                .S_un = {
                    .S_addr = host
                }
            }
        };
        i32 const result = ::connect(m_socket, reinterpret_cast<::sockaddr const*>(&sockaddr_in), sizeof(sockaddr_in));
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::connect - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        return socket_error_code::success;
    }
    std::expected<u32, socket_error_code> socket::receive(stl::buffer data) const noexcept {
        i32 const result = ::recv(m_socket, reinterpret_cast<char*>(std::data(data)), std::size(data), 0);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::recv - {}", lookup_enum_verbose(socket_error_code));
                return std::unexpected(socket_error_code);
            }
        }
        return static_cast<u32>(result);
    }
    socket_error_code socket::shutdown() const noexcept {
        i32 const result = ::shutdown(m_socket, SD_SEND);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::shutdown - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        return socket_error_code::success;
    }

    socket_error_code socket::init_backend() noexcept {
        i32 const result = ::WSAStartup(MAKEWORD(2, 2), &wsa_data);
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::WSAStartup - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        return socket_error_code::success;
    }
    socket_error_code socket::deinit_backend() noexcept {
        i32 const result = ::WSACleanup();
        if (result == SOCKET_ERROR) [[unlikely]] {
            auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
            switch (socket_error_code) {
            default:
                SPDLOG_ERROR("unhandled socket_error_code for ::WSACleanup - {}", lookup_enum_verbose(socket_error_code));
                return socket_error_code;
            }
        }
        return socket_error_code::success;
    }

    WSAData socket::wsa_data{};
}