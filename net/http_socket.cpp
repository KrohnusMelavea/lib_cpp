#include "http_socket.hpp"
#include <array>

namespace net {
 http_socket::http_socket(u32 const host, u16 const port) noexcept : m_socket{host, port, net::protocol::tcp} {

 }
 http_socket::http_socket(net::socket const socket) noexcept : m_socket{socket} {

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
  std::array<u08, 8193> buffer;
  while (true) {
   auto const receive_size_st = m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer) - 1});
   if (receive_size_st.status != net::socket_error_code::success) [[unlikely]] {
    return { receive_size_st.status, {} };
   } else if (receive_size_st.value != )
  }
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