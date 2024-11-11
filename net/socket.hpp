#pragma once

#define NET_HANDLE_ERR

#include "types.hpp"
#include "ip_header.hpp"
#include "socket_error_code.hpp"
#include "address_conversion.hpp"
#include "stl/buffer.hpp"
#include "stl/status_type.hpp"
#include "stl/dynamic_array.hpp"
#include <span>
#include <expected>
#include <string_view>

struct WSAData;

namespace net {
 struct socket {
 public:
  u64 socket_handle;
  u32 host;
  u16 port;
  net::protocol protocol;

  socket() noexcept;
  socket(u32 const host) noexcept;
  socket(u32 const host, net::protocol const protocol) noexcept;
  socket(u32 const host, u16 const port) noexcept;
  socket(u32 const host, u16 const port, net::protocol const protocol) noexcept;
  constexpr socket(u64 const socket, u32 const host, u16 const port, net::protocol const protocol) noexcept : socket_handle{socket}, host{host}, port{port}, protocol{protocol} {}
  ~socket() noexcept = default;

  [[nodiscard]] stl::status_type<socket_error_code>         bind() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code, u32>    send(stl::buffer const data) const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code, u32>    send(std::string_view const data) const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>         close() noexcept;
  [[nodiscard]] stl::status_type<socket_error_code, socket> accept() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>         listen() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>         connect() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code, u32>    receive(stl::buffer const data) const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>         shutdown() noexcept;

  [[nodiscard]] stl::status_type<socket_error_code, bool> has_read() const noexcept;

  [[nodiscard]] bool is_active() const noexcept;

  static stl::status_type<socket_error_code> init_backend() noexcept;
  static stl::status_type<socket_error_code> deinit_backend() noexcept;

 private:
  static WSAData wsa_data;
 };
}