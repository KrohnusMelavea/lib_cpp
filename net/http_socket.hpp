#pragma once

#include "types.hpp"
#include "socket.hpp"
#include "socket_error_code.hpp"
#include "stl/status_type.hpp"
#include "stl/dynamic_array.hpp"
#include "net/http_request.hpp"
#include <nlohmann/json.hpp>

namespace net {
 class http_socket {
 public:
  http_socket() noexcept = default;
  http_socket(u32 const host, u16 const port) noexcept;
  http_socket(net::socket const socket) noexcept;
  ~http_socket();

  stl::status_type<net::socket_error_code> bind() const;
  stl::status_type<net::socket_error_code> listen() const;
  stl::status_type<net::socket_error_code> connect() const;
  stl::status_type<net::socket_error_code> connect(u32 const host, u16 const port);
  stl::status_type<net::socket_error_code, http_socket> accept() const;
  stl::status_type<net::socket_error_code> send(stl::buffer const data) const;
  stl::status_type<net::socket_error_code, stl::dynamic_array<u08>> receive() const;
  stl::status_type<net::socket_error_code> close();
  stl::status_type<net::socket_error_code> shutdown();

  net::socket const& socket() const noexcept;

  stl::status_type<net::socket_error_code, net::http_request> receive_request() const noexcept;
  stl::status_type<net::socket_error_code> send_response(nlohmann::json const& json) const noexcept;

  stl::status_type<net::socket_error_code, std::string> receive_get_request() const;
  stl::status_type<net::socket_error_code, stl::dynamic_array<u08>> receive_get_request_raw() const;
  stl::status_type<net::socket_error_code> send_get_response(stl::buffer const data) const;

  static stl::status_type<net::socket_error_code, http_socket> create_server(u32 const host, u16 const port);
  static stl::status_type<net::socket_error_code, http_socket> create_client(u32 const host, u16 const port);

 private:
  net::socket m_socket;
 };
}