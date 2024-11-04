#include "http_socket.hpp"
#include "stl/cvt/to_string.hpp"
#include "stl/cvt/try_parse.hpp"
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
  return this->m_socket.bind();
 }
 stl::status_type<net::socket_error_code> http_socket::listen() const {
  return this->m_socket.listen();
 }
 stl::status_type<net::socket_error_code> http_socket::connect() const {
  return this->m_socket.connect();
 }
 stl::status_type<net::socket_error_code> http_socket::connect(u32 const host, u16 const port) {
  this->m_socket.host = host;
  this->m_socket.port = port;
  return this->m_socket.connect();
 }
 stl::status_type<net::socket_error_code, net::http_socket> http_socket::accept() const {
  auto client_st = this->m_socket.accept();
  return { client_st.status, net::http_socket{client_st.value} };
 }
 stl::status_type<net::socket_error_code> http_socket::send(stl::buffer const data) const {
  std::size_t total_sent = 0;
  do {
   auto const sent_size_st = this->m_socket.send(stl::buffer{
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
   auto const receive_size_st =  this->m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
   if (receive_size_st.status != net::socket_error_code::success || receive_size_st.value == 0_u32) [[unlikely]] {
    return { receive_size_st.status, std::move(data) };
   } else [[likely]] {
    data.grow(stl::buffer{std::data(buffer), static_cast<std::size_t>(receive_size_st.value)});
   }
  }
 }
 stl::status_type<net::socket_error_code> http_socket::close() {
  return this->m_socket.close();
 }
 stl::status_type<net::socket_error_code> http_socket::shutdown() {
  return this->m_socket.shutdown();
 }

 net::socket const& http_socket::socket() const noexcept {
  return this->m_socket;
 }

 stl::status_type<net::socket_error_code, net::http_request> http_socket::receive_request() const noexcept {
  net::http_request http_request;
  std::array<u08, 8192> buffer;
  auto const receive_size_st = this->m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
  if (receive_size_st.status != net::socket_error_code::success) [[unlikely]] {
   return stl::status_type<net::socket_error_code, net::http_request>{ receive_size_st.status, net::http_request{} };
  }
  if (receive_size_st.value == 0) {
   return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::malformed_request, net::http_request{} };
  }
  auto const receive_size = receive_size_st.value;
  auto& header = http_request.header();
  auto const c_ptr = header.scan(std::string_view{reinterpret_cast<char*>(std::data(buffer)), receive_size});
  if (c_ptr == nullptr) [[unlikely]] {
   return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::malformed_request, net::http_request{} };
  }
  auto const content_type_it = header.header_fields.find("Content-Type");
  if (content_type_it == std::cend(header.header_fields)) /* No Payload */ {
   return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::success, std::move(http_request) };
  }
  auto const& content_type = content_type_it->second;
  if (content_type != "application/json") [[unlikely]] {
   std::cout << std::format("Unimplemented Content-Type: {}\n", content_type);
   //return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::success, std::move(http_request) };
  }
  auto const content_length_it = header.header_fields.find("Content-Length");
  if (content_length_it == std::cend(header.header_fields)) [[unlikely]] /* Need to keep scanning until you get it all */ {
   std::cout << "Unimplemeneted: Scan network input in case there's not Content-Length field\n";
   return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::none, net::http_request{} };
  }
  auto const maybe_content_length = net::cvt::try_parse_u64(content_length_it->second);
  if (!maybe_content_length.has_value()) [[unlikely]] {
   std::cout << std::format("Malformed Content-Length Header Field Value: {}\n", *content_length_it);
   return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::malformed_request, net::http_request{} };
  }
  auto const content_length = maybe_content_length.value();
  auto const scan_distance = c_ptr - reinterpret_cast<char*>(std::data(buffer));
  if (scan_distance + content_length > receive_size) [[likely]] {
   std::vector<u08> data(std::next(std::begin(buffer), scan_distance), std::next(std::begin(buffer), receive_size));
   while (true) {
    auto maybe_has_read = this->m_socket.has_read();
    if (maybe_has_read.status != net::socket_error_code::success) [[unlikely]] {
     return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::malformed_request, net::http_request{} };
    } else if (maybe_has_read.value) {
     auto const read_size_maybe = this->m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
     if (read_size_maybe.status != net::socket_error_code::success) [[unlikely]] {
      return stl::status_type<net::socket_error_code, net::http_request>{ read_size_maybe.status, net::http_request{} };
     }
     data.insert(std::end(data), std::begin(buffer), std::next(std::begin(buffer), read_size_maybe.value));
    } else [[likely]] {
     break;
    }
   }

   std::string_view const parsable{ reinterpret_cast<char const*>(std::data(data)), std::size(data) };
   if (!http_request.content().parse(net::http_content_type::json, parsable)) [[unlikely]] {
    return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::malformed_request, net::http_request{} };
   } else [[likely]] {
    return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::success, std::move(http_request) };
   }
  } else [[likely]] /* Everything's already been read */ {
   if (!http_request.content().parse(net::http_content_type::json, std::string_view{c_ptr, content_length})) [[unlikely]] {
    return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::malformed_request, net::http_request{} };
   } else {
    return stl::status_type<net::socket_error_code, net::http_request>{ net::socket_error_code::success, std::move(http_request) };
   }
  }
 }
 stl::status_type<net::socket_error_code> http_socket::send_response(nlohmann::json const& data) const noexcept {
  auto const dumpy = data.dump();
  auto response = std::format("HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: {}\r\n\r\n{}", std::size(dumpy), dumpy);
  auto const send_response = this->m_socket.send(stl::buffer{reinterpret_cast<void*>(std::data(response)), std::size(response)});
  if (send_response.status != net::socket_error_code::success) [[unlikely]] {
   return send_response.status;
  }
  return net::socket_error_code::success;
 }

 stl::status_type<net::socket_error_code, net::http_socket> http_socket::create_server(u32 const host, u16 const port) {
  http_socket server{host, port};
  if (const auto status = server.bind().status; status != net::socket_error_code::success) [[unlikely]] {
   return { status, server };
  }
  if (const auto status = server.listen().status; status != net::socket_error_code::success) [[unlikely]] {
   return { status, server };
  }
  return { net::socket_error_code::success, server };
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