#include "http_socket.hpp"
#include "stl/cvt/to_string.hpp"
#include <array>
#include <iostream>

namespace net {
 http_socket::http_socket(u32 const host, u16 const port) noexcept : m_socket{host, port, net::protocol::tcp} {

 }
 http_socket::http_socket(net::socket const socket) noexcept : m_socket{socket} {

 }

 http_socket::~http_socket() {
  //this->close();
 }

 stl::status_type<net::socket_error_code> http_socket::bind() const {
  return m_socket.bind();
 }
 stl::status_type<net::socket_error_code> http_socket::listen() const {
  return m_socket.listen();
 }
 stl::status_type<net::socket_error_code> http_socket::connect() const {
  return m_socket.connect();
 }
 stl::status_type<net::socket_error_code, net::http_socket> http_socket::accept() const {
  auto client_st = m_socket.accept();
  return { client_st.status, net::http_socket{client_st.value} };
 }
 stl::status_type<net::socket_error_code> http_socket::send(stl::buffer const data) const {
  std::size_t total_sent = 0;
  do {
   auto const sent_size_st = m_socket.send(stl::buffer{
    reinterpret_cast<void*>(reinterpret_cast<std::size_t>(std::data(data)) + total_sent), 
    std::size(data) - total_sent
   });
   if (sent_size_st.status != net::socket_error_code::success) [[unlikely]] {
    return { sent_size_st.status };
   }
   total_sent += sent_size_st.value;
  }
  while (total_sent < std::size(data));
  return net::socket_error_code::success;
 }
 stl::status_type<net::socket_error_code, stl::dynamic_array<u08>> http_socket::receive() const {
  std::array<u08, 8192> buffer;
  stl::dynamic_array<u08> data;
  while (true) {
   auto const receive_size_st = m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
   if (receive_size_st.status != net::socket_error_code::success || receive_size_st.value == 0_u32) [[unlikely]] {
    return { receive_size_st.status, std::move(data) };
   } else [[likely]] {
    data.grow(stl::buffer{std::data(buffer), static_cast<std::size_t>(receive_size_st.value)});
   }
  }
 }
 stl::status_type<net::socket_error_code> http_socket::close() {
  return m_socket.close();
 }
 stl::status_type<net::socket_error_code> http_socket::shutdown() {
  return m_socket.shutdown();
 }

 stl::status_type<net::socket_error_code, stl::dynamic_array<u08>> http_socket::receive_get_request() const {
  std::array<u08, 8192> buffer;
  auto const receive_size_st = m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
  if (receive_size_st.status != net::socket_error_code::success) [[unlikely]] {
   return { receive_size_st.status, {} };
  } else [[likely]] {
   return { net::socket_error_code::success, stl::dynamic_array(std::data(buffer), std::data(buffer) + receive_size_st.value) }; 
  }
 }
 stl::status_type<net::socket_error_code> http_socket::send_get_response(stl::buffer const data) const {
  static constexpr std::string_view http_response_header_prefix = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: ";
  static constexpr std::string_view http_response_header_suffix = "\r\n\r\n";
  auto const content_length_size = stl::cvt::to_string_size(std::size(data));
  stl::dynamic_array<char> response(std::size(http_response_header_prefix) + content_length_size + std::size(http_response_header_suffix) + std::size(data) + 1);
  (void)std::memcpy(std::data(response), std::data(http_response_header_prefix), std::size(http_response_header_prefix));
  stl::cvt::to_string(std::size(data), content_length_size, std::data(response) + std::size(http_response_header_prefix));
  (void)std::memcpy(std::data(response) + std::size(http_response_header_prefix) + content_length_size, std::data(http_response_header_suffix), std::size(http_response_header_suffix));
  (void)std::memcpy(std::data(response) + std::size(http_response_header_prefix) + content_length_size + std::size(http_response_header_suffix), std::data(data), std::size(data));
  response[std::size(response) - 1] = 0;
  auto const result = this->send(stl::buffer{std::data(response), std::size(response)});
  return result.status;
  /* Note: If going async, response is destructed at this point, so be weary */
 }

 stl::status_type<net::socket_error_code, net::http_socket> http_socket::create_server(u32 const host, u16 const port) {
  http_socket server{host, port};
  if (const auto status = server.bind().status; status != net::socket_error_code::success) [[unlikely]] {
   return { status, server };
  } else if (const auto status = server.listen().status; status != net::socket_error_code::success) [[unlikely]] {
   return { status, server };
  } else [[likely]] {
   return { net::socket_error_code::success, server };
  }
 }
 stl::status_type<net::socket_error_code, net::http_socket> http_socket::create_client(u32 const host, u16 const port) {
  http_socket client{host, port};
  if (const auto status = client.connect().status; status != net::socket_error_code::success) [[unlikely]] {
   return { status, client };
  } else [[likely]] {
   return { net::socket_error_code::success, client };
  }
 }
}