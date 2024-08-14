#include "socket.hpp"
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <array>
#include <string_view>
#include <iostream>
#pragma warning(pop)

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
 socket::socket(u32 const host) noexcept : socket_handle{::socket(AF_INET, SOCK_STREAM, static_cast<i32>(protocol::tcp))}, host{host}, port{0}, protocol{net::protocol::tcp} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host, net::protocol const protocol) noexcept : socket_handle{::socket(AF_INET, SOCK_STREAM, static_cast<i32>(protocol))}, host{host}, port{0}, protocol{protocol} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host, u16 const port) noexcept : socket_handle{::socket(AF_INET, SOCK_STREAM, static_cast<i32>(protocol::tcp))}, host{host}, port{port}, protocol{net::protocol::tcp} {
  #ifdef NET_HANDLE_ERR
   if (this->socket_handle == INVALID_SOCKET) [[unlikely]] {
    auto const socket_error_code = static_cast<net::socket_error_code>(::WSAGetLastError());
    SPDLOG_ERROR("unhandled socket_error_code for ::socket - {}", lookup_enum_verbose(socket_error_code));
   }
  #endif
 }
 socket::socket(u32 const host, u16 const port, net::protocol const protocol) noexcept : socket_handle{::socket(AF_INET, SOCK_STREAM, static_cast<i32>(protocol))}, host{host}, port{port}, protocol{protocol} {
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
   .sin_port = static_cast<u16>(((this->port & 0xff) << 8) | (this->port >> 8)),
   .sin_addr = {
    .S_un = {
     .S_addr = this->host
    }
   }
  };
  if (::bind(socket_handle, reinterpret_cast<::sockaddr const*>(&sockaddr_in), sizeof(sockaddr_in)) == SOCKET_ERROR) [[unlikely]] {
   return static_cast<net::socket_error_code>(::WSAGetLastError());
  } else [[likely]] {
   return net::socket_error_code::success;
  }
 }
 stl::status_type<net::socket_error_code, u32> socket::send(stl::buffer const data) const noexcept {
  auto const size = ::send(socket_handle, reinterpret_cast<char const*>(std::data(data)), static_cast<i32>(std::size(data)), 0);
  if (size == SOCKET_ERROR) [[unlikely]] {
   return {static_cast<net::socket_error_code>(::WSAGetLastError()), 0_u32};
  } else [[likely]] {
   return {net::socket_error_code::success, static_cast<u32>(size)};
  }
 }
 stl::status_type<net::socket_error_code, u32> socket::send(std::string_view const data) const noexcept {
  auto const size = ::send(socket_handle, reinterpret_cast<char const*>(std::data(data)), static_cast<i32>(std::size(data) + 1), 0);
  if (size == SOCKET_ERROR) [[unlikely]] {
   return {static_cast<net::socket_error_code>(::WSAGetLastError()), 0_u32};
  } else [[likely]] {
   return {net::socket_error_code::success, static_cast<u32>(size)};
  }
 }
 sock_err_ret_t socket::close() noexcept {
  if (::closesocket(this->socket_handle) == SOCKET_ERROR) [[unlikely]] {
   return static_cast<net::socket_error_code>(::WSAGetLastError());
  } else {
   return net::socket_error_code::success;
  }
 }
 [[nodiscard]] sock_err_sock_ret_t socket::accept() const noexcept {
  ::sockaddr_in sockaddr_in;
  auto length = static_cast<i32>(sizeof(sockaddr_in));
  auto const client_socket_handle = ::accept(this->socket_handle, reinterpret_cast<::sockaddr*>(&sockaddr_in), &length);
  if (client_socket_handle == INVALID_SOCKET) [[unlikely]] {
   return {static_cast<net::socket_error_code>(::WSAGetLastError()), {}};
  } else [[likely]] {
   return {net::socket_error_code::success, net::socket{client_socket_handle, sockaddr_in.sin_addr.S_un.S_addr, sockaddr_in.sin_port, this->protocol}};
  }
 }
 sock_err_ret_t socket::listen() const noexcept {
  if (::listen(this->socket_handle, SOMAXCONN) == SOCKET_ERROR) [[unlikely]] {
   return static_cast<net::socket_error_code>(::WSAGetLastError());
  } else [[likely]] {
   return net::socket_error_code::success;
  }
 }
 sock_err_ret_t socket::connect() const noexcept {
  ::sockaddr_in const address {
   .sin_family = AF_INET,
   .sin_port = static_cast<u16>(((this->port & 0xff) << 8) | (this->port >> 8)),
   .sin_addr = { .S_un = { .S_addr = this->host } }
  };
  if (::connect(this->socket_handle, reinterpret_cast<::sockaddr const*>(&address), sizeof(sockaddr_in)) == SOCKET_ERROR) [[unlikely]] {
   return static_cast<net::socket_error_code>(::WSAGetLastError());
  } else [[likely]] {
   return net::socket_error_code::success;
  }
 }
 
 stl::status_type<net::socket_error_code, u32> socket::receive(stl::buffer const data) const noexcept {
  auto const size = ::recv(this->socket_handle, reinterpret_cast<char*>(std::data(data)), static_cast<i32>(std::size(data)), 0);
  if (size == SOCKET_ERROR) [[unlikely]] {
   return {static_cast<net::socket_error_code>(::WSAGetLastError()), 0_u32};
  } else [[likely]] {
   return {net::socket_error_code::success, static_cast<u32>(size)};
  }
 }
 sock_err_ret_t socket::shutdown() noexcept {
  this->socket_handle = INVALID_SOCKET;
  if (::shutdown(this->socket_handle, SD_SEND) == SOCKET_ERROR) [[unlikely]] {
   return static_cast<net::socket_error_code>(::WSAGetLastError());
  } else [[likely]] {
   return net::socket_error_code::success;
  }
 }

 bool socket::is_active() const noexcept {
  return this->socket_handle != INVALID_SOCKET;
 }

 sock_err_ret_t socket::init_backend() noexcept {
  return static_cast<net::socket_error_code>(::WSAStartup(MAKEWORD(2, 2), &wsa_data));
 }
 sock_err_ret_t socket::deinit_backend() noexcept {
  [[maybe_unused]] auto const result = ::WSACleanup();
  if (::WSACleanup() == SOCKET_ERROR) [[unlikely]] {
   return static_cast<net::socket_error_code>(::WSAGetLastError());
  } else [[likely]] {
   return net::socket_error_code::success;
  }
 }

 WSAData socket::wsa_data{};
}