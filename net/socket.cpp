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
 socket::socket() noexcept : socket_handle{::socket(AF_INET, SOCK_STREAM, static_cast<i32>(protocol::tcp))}, host{}, port{}, protocol{net::protocol::tcp} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host) noexcept : socket_handle{::socket(AF_INET, SOCK_RAW, static_cast<i32>(protocol::tcp))}, host{host}, port{0}, protocol{net::protocol::tcp} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host, net::protocol const protocol) noexcept : socket_handle{::socket(AF_INET, SOCK_RAW, static_cast<i32>(protocol))}, host{host}, port{0}, protocol{protocol} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host, u16 const port) noexcept : socket_handle{::socket(AF_INET, SOCK_RAW, static_cast<i32>(protocol::tcp))}, host{host}, port{port}, protocol{net::protocol::tcp} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host, u16 const port, net::protocol const protocol) noexcept : socket_handle{::socket(AF_INET, SOCK_RAW, static_cast<i32>(protocol))}, host{host}, port{port}, protocol{protocol} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::~socket() noexcept {

 }

 sock_err_ret_t socket::bind() const noexcept {
  ::sockaddr_in const sockaddr_in {
   .sin_family = AF_INET,
   .sin_port = port,
   .sin_addr = {
    .S_un = {
     .S_addr = host
    }
   }
  };
  [[maybe_unused]] auto const result = ::bind(socket_handle, reinterpret_cast<::sockaddr const*>(&sockaddr_in), sizeof(sockaddr_in));
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::bind - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
   return socket_error_code::success;
  #endif
 }
 sock_err_ret_t socket::bind(u32 const host, u16 const port) noexcept {
  this->host = host;
  this->port = port;
  ::sockaddr_in const sockaddr_in {
   .sin_family = AF_INET,
   .sin_port = port,
   .sin_addr = {
    .S_un = {
     .S_addr = host
    }
   }
  };

  [[maybe_unused]] auto const result = ::bind(socket_handle, reinterpret_cast<::sockaddr const*>(&sockaddr_in), sizeof(sockaddr_in));
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::bind - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
   return socket_error_code::success;
  #endif
 }
 sock_err_u32_ret_t socket::send(stl::buffer const& data) const noexcept {
  auto const result = ::send(socket_handle, reinterpret_cast<char const*>(std::data(data)), std::size(data), 0);
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::send - {}", lookup_enum_verbose(socket_error_code));
     return { socket_error_code, {} };
    }
   }
   return { socket_error_code::success, static_cast<u32>(result) };
  #else
   return static_cast<u32>(result);
  #endif
 }
 sock_err_u32_ret_t socket::send(std::string_view const data) const noexcept {
  auto const result = ::send(socket_handle, std::data(data), std::size(data) + 1, 0);
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::send - {}", lookup_enum_verbose(socket_error_code));
     return { socket_error_code, {} };
    }
   }
   return { socket_error_code::success, static_cast<u32>(result) };
  #else
   return static_cast<u32>(result);
  #endif
 }
 sock_err_ret_t socket::close() noexcept {
  [[maybe_unused]] auto const result = ::closesocket(this->socket_handle);
  this->socket_handle = NULL;
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::closesocket - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
   return socket_error_code::success;
  #endif
 }
 [[nodiscard]] sock_err_sock_ret_t socket::accept() const noexcept {
  ::sockaddr_in sockaddr_in;
  auto length = static_cast<i32>(sizeof(sockaddr_in));
  auto const client_socket_handle = ::accept(this->socket_handle, reinterpret_cast<::sockaddr*>(&sockaddr_in), &length);
  #ifdef NET_HANDLE_ERR
   if (socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::accept - {}", lookup_enum_verbose(socket_error_code));
     return { socket_error_code, {} };
    }
   }
   return { socket_error_code::success, socket{ client_socket_handle, sockaddr_in.sin_addr.S_un.S_addr, sockaddr_in.sin_port, this->protocol } }; /* Possible Unintentional Copy/Move Constructor Invokation */
  #else
   return socket{ socket_handle, sockaddr_in.sin_addr.S_un.S_addr, sockaddr_in.sin_port }; /* Possible Unintentional Copy/Move Constructor Invokation */
  #endif
 }
 sock_err_ret_t socket::listen() const noexcept {
  [[maybe_unused]] auto const result = ::listen(this->socket_handle, SOMAXCONN);
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::listen - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
   return socket_error_code::success;
  #endif
 }
 sock_err_ret_t socket::connect(u32 const host, u16 const port) noexcept {
  this->host = host;
  this->port = port;
  ::sockaddr_in const sockaddr_in {
   .sin_family = AF_INET,
   .sin_port = port,
   .sin_addr = {
    .S_un = {
     .S_addr = host
    }
   }
  };
  [[maybe_unused]] auto const result = ::connect(this->socket_handle, reinterpret_cast<::sockaddr const*>(&sockaddr_in), sizeof(sockaddr_in));
  #ifdef NET_HANDLE_ERR
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
 #endif
 sock_err_u32_ret_t socket::receive(stl::buffer data) const noexcept {
  [[maybe_unused]] auto const result = ::recv(this->socket_handle, reinterpret_cast<char*>(std::data(data)), std::size(data), 0);
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::recv - {}", lookup_enum_verbose(socket_error_code));
     return { socket_error_code, {} };
    }
   }
   return { socket_error_code::success, static_cast<u32>(result) };
  #else
   return static_cast<u32>(result);
  #endif
 }
 sock_err_ret_t socket::shutdown() noexcept {
  [[maybe_unused]] auto const result = ::shutdown(this->socket_handle, SD_SEND);
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::shutdown - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
  #endif
  this->socket_handle = NULL;
  #ifdef NET_HANDLE_ERR
   return socket_error_code::success;
  #endif
 }

 sock_err_ret_t socket::init_backend() noexcept {
  [[maybe_unused]] auto const socket_error_code = static_cast<net::socket_error_code>(::WSAStartup(MAKEWORD(2, 2), &wsa_data));
  #ifdef NET_HANDLE_ERR
   if (socket_error_code != net::socket_error_code::success) [[unlikely]] {
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::WSAStartup - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
   return socket_error_code::success;
  #endif
 }
 sock_err_ret_t socket::deinit_backend() noexcept {
  [[maybe_unused]] auto const result = ::WSACleanup();
  #ifdef NET_HANDLE_ERR
   if (result == SOCKET_ERROR) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    switch (socket_error_code) {
    default:
     SPDLOG_ERROR("unhandled socket_error_code for ::WSACleanup - {}", lookup_enum_verbose(socket_error_code));
     return socket_error_code;
    }
   }
   return socket_error_code::success;
  #endif
 }

 WSAData socket::wsa_data{};
}