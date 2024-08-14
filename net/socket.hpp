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
 struct socket;

 #ifdef NET_HANDLE_ERR
  typedef stl::status_type<socket_error_code> sock_err_ret_t;
  typedef stl::status_type<socket_error_code, u32> sock_err_u32_ret_t;
  typedef stl::status_type<socket_error_code, socket> sock_err_sock_ret_t;
 #else
  typedef void sock_err_ret_t;
  typedef u32 sock_err_u32_ret_t;
  typedef socket sock_err_sock_ret_t;
 #endif

 struct socket {
 public:
  u64 socket_handle;
  u32 host;
  u16 port;
  net::protocol protocol;

  socket() noexcept;   /* Default to TCP localhost:6969 */
  socket(u32 const host) noexcept;
  socket(u32 const host, net::protocol const protocol) noexcept;
  socket(u32 const host, u16 const port) noexcept;
  socket(u32 const host, u16 const port, net::protocol const protocol) noexcept;
  constexpr socket(u64 const socket, u32 const host, u16 const port, net::protocol const protocol) noexcept : socket_handle{socket}, host{host}, port{port}, protocol{protocol} {}
  ~socket() noexcept;

  sock_err_ret_t bind() const noexcept;
  stl::status_type<net::socket_error_code, u32> send(stl::buffer const data) const noexcept;
  stl::status_type<net::socket_error_code, u32> send(std::string_view const data) const noexcept;
  sock_err_ret_t close() noexcept;
  [[nodiscard]] sock_err_sock_ret_t accept() const noexcept;
  sock_err_ret_t listen() const noexcept;
  sock_err_ret_t connect() const noexcept;
  stl::status_type<net::socket_error_code, u32> receive(stl::buffer const data) const noexcept;
  sock_err_ret_t shutdown() noexcept;

  bool is_active() const noexcept;

  static sock_err_ret_t init_backend() noexcept;
  static sock_err_ret_t deinit_backend() noexcept;

 private:
  static WSAData wsa_data;
  static constexpr bool is_reference_counting = false;
  static inline u32 reference_count = 0;
 };
}