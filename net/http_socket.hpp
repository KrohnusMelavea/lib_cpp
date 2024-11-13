#pragma once

#include "types.hpp"
#include "socket.hpp"
#include "socket_error_code.hpp"
#include "stl/status_type.hpp"
#include "stl/dynamic_array.hpp"
#include "net/http_request.hpp"
#include <nlohmann/json.hpp>
#include <string>

namespace net {
 class http_socket;
 class http_socket {
 public:
  http_socket() noexcept = default;
  http_socket(u32 const host, u16 const port) noexcept;
  http_socket(socket const socket) noexcept;
  ~http_socket() noexcept = default;

  [[nodiscard]] stl::status_type<socket_error_code>                          bind() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>                          listen() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>                          connect() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>                          connect(u32 const host, u16 const port) noexcept;
  [[nodiscard]] stl::status_type<socket_error_code, http_socket>             accept() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>                          send(stl::buffer const data) const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code, stl::dynamic_array<u08>> receive() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>                          close() noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>                          shutdown() noexcept;

  [[nodiscard]] bool is_valid() const noexcept;
  [[nodiscard]] socket const& socket() const noexcept;

  [[nodiscard]] stl::status_type<socket_error_code, http_request> receive_request() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>               send_response() const noexcept;
  [[nodiscard]] stl::status_type<socket_error_code>               send_response(nlohmann::json const& json) const noexcept;

  [[nodiscard]] static stl::status_type<socket_error_code, http_socket> create_server(u32 const host, u16 const port);
  [[nodiscard]] static stl::status_type<socket_error_code, http_socket> create_client(u32 const host, u16 const port);

 private:
  net::socket m_socket;
 };

 [[nodiscard]] std::string pid_client_prefix(http_socket const *const client) noexcept;
}