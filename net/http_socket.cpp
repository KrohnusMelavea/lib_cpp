#include "http_socket.hpp"
#include "stl/cvt/to_string.hpp"
#include "stl/cvt/try_parse.hpp"
#include <spdlog/spdlog.h>
#include <array>
#include <thread>
#include <iostream>

namespace net {
 [[nodiscard]] std::string pid_client_prefix(http_socket const *const client) noexcept { 
  return std::format("Thread {} Client ({}:{}): ", 
   std::bit_cast<u32>(std::this_thread::get_id()), 
   convert_ipv4_u32_to_string(client->socket().host), client->socket().port); 
 }

 http_socket::http_socket(u32 const host, u16 const port) noexcept : m_socket{host, port, protocol::tcp} {}
 http_socket::http_socket(net::socket const socket) noexcept : m_socket{socket} {}

 [[nodiscard]] stl::status_type<socket_error_code> http_socket::bind() const noexcept { return this->m_socket.bind(); }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::listen() const noexcept { return this->m_socket.listen(); }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::connect() const noexcept { return this->m_socket.connect(); }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::connect(u32 const host, u16 const port) noexcept {
  this->m_socket.host = host;
  this->m_socket.port = port;
  return this->m_socket.connect();
 }
 [[nodiscard]] stl::status_type<socket_error_code, net::http_socket> http_socket::accept() const noexcept {
  auto client_st = this->m_socket.accept();
  return { client_st.status, http_socket{client_st.value} };
 }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::send(stl::buffer const data) const noexcept {
  std::size_t total_sent = 0;
  do {
   auto const sent_size_st = this->m_socket.send(stl::buffer{
    reinterpret_cast<void*>(reinterpret_cast<std::size_t>(std::data(data)) + total_sent), 
    std::size(data) - total_sent
   });
   if (sent_size_st.status != socket_error_code::success) [[unlikely]] { return { sent_size_st.status }; }
   else [[likely]] { total_sent += sent_size_st.value; }
  } while (total_sent < std::size(data));
  return socket_error_code::success;
 }
 [[nodiscard]] stl::status_type<socket_error_code, stl::dynamic_array<u08>> http_socket::receive() const noexcept {
  std::array<u08, 8192> buffer;
  stl::dynamic_array<u08> data;
  while (true) {
   auto [status, receive_size] = this->m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
   if (status != net::socket_error_code::success || receive_size == 0) [[unlikely]] { return { status, std::move(data) }; } 
   else [[likely]] { data.grow(stl::buffer{std::data(buffer), static_cast<std::size_t>(receive_size)}); }
  }
 }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::close() noexcept { return this->m_socket.close(); }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::shutdown() noexcept { return this->m_socket.shutdown(); }

 [[nodiscard]] socket const& http_socket::socket() const noexcept { return this->m_socket; }
 [[nodiscard]] bool http_socket::is_valid() const noexcept { return this->m_socket.is_active(); }

 [[nodiscard]] stl::status_type<socket_error_code, http_request> http_socket::receive_request() const noexcept {
  http_request request;
  std::array<u08, 8192> buffer;
  auto const receive_size_st = this->m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
  if (receive_size_st.status != socket_error_code::success) [[unlikely]] { return { receive_size_st.status, http_request{} }; }
  if (receive_size_st.value == 0) [[unlikely]] { return { socket_error_code::malformed_request, http_request{} }; }
  auto const receive_size = receive_size_st.value;
  auto& header = request.header();
  auto const c_ptr = header.scan(std::string_view{reinterpret_cast<char*>(std::data(buffer)), receive_size});
  if (c_ptr == nullptr) [[unlikely]] { return { socket_error_code::malformed_request, http_request{} }; }
  auto const content_type_it = header.header_fields.find("Content-Type");
  if (content_type_it == std::cend(header.header_fields)) /* No Payload */ { return { socket_error_code::success, std::move(request) }; }
  auto const& content_type = content_type_it->second;
  if (!content_type.contains("application/json")) [[unlikely]] {
   SPDLOG_ERROR("{}Unimplemented Content-Type: {}", pid_client_prefix(this), content_type);
   return { socket_error_code::success, std::move(request) };
  }
  auto const content_length_it = header.header_fields.find("Content-Length");
  if (content_length_it == std::cend(header.header_fields)) [[unlikely]] /* Need to keep scanning until you get it all */ {
   SPDLOG_ERROR("{}Unimplemeneted: Scan network input in case there's no Content-Length field", pid_client_prefix(this));
   return { socket_error_code::none, http_request{} };
  }
  auto const maybe_content_length = cvt::try_parse_u64(content_length_it->second);
  if (!maybe_content_length.has_value()) [[unlikely]] {
   SPDLOG_ERROR("{}Malformed Content-Length Header Field Value: {}", pid_client_prefix(this), content_length_it->second);
   return { socket_error_code::malformed_request, http_request{} };
  }
  auto const content_length = maybe_content_length.value();
  auto const scan_distance = c_ptr - reinterpret_cast<char*>(std::data(buffer));
  if (scan_distance + content_length > receive_size) [[likely]] {
   std::vector<u08> data(std::next(std::begin(buffer), scan_distance), std::next(std::begin(buffer), receive_size));
   while (true) {
    auto maybe_has_read = this->m_socket.has_read();
    if (maybe_has_read.status != socket_error_code::success) [[unlikely]] { return { socket_error_code::malformed_request, http_request{} }; } 
    else if (maybe_has_read.value) {
     auto const read_size_maybe = this->m_socket.receive(stl::buffer{std::data(buffer), std::size(buffer)});
     if (read_size_maybe.status != socket_error_code::success) [[unlikely]] { return { read_size_maybe.status, http_request{} }; }
     data.insert(std::end(data), std::begin(buffer), std::next(std::begin(buffer), read_size_maybe.value));
    } else [[likely]] { break; }
   }

   std::string_view const parsable{ reinterpret_cast<char const*>(std::data(data)), std::size(data) };
   if (!request.content().parse(http_content_type::json, parsable)) [[unlikely]] { return { socket_error_code::malformed_request, http_request{} }; } 
   else [[likely]] { return { socket_error_code::success, std::move(request) }; }
  } else [[likely]] /* Everything's already been read */ {
   if (!request.content().parse(http_content_type::json, std::string_view{c_ptr, content_length})) [[unlikely]] { return { socket_error_code::malformed_request, http_request{} }; } 
   else { return { socket_error_code::success, std::move(request) }; }
  }
 }
 [[nodiscard]] stl::status_type<socket_error_code> http_socket::send_response(nlohmann::json const& data) const noexcept {
  auto const dumpy = data.dump();
  auto response = std::format("HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: {}\r\n\r\n{}", std::size(dumpy), dumpy);
  auto const send_response = this->m_socket.send(stl::buffer{reinterpret_cast<void*>(std::data(response)), std::size(response)});
  if (send_response.status != socket_error_code::success) [[unlikely]] { return send_response.status; }
  else [[likely]] { return socket_error_code::success; }
 }

 [[nodiscard]] stl::status_type<socket_error_code, http_socket> http_socket::create_server(u32 const host, u16 const port) {
  http_socket server{host, port};
  if (const auto status = server.bind().status; status != socket_error_code::success) [[unlikely]] { return { status, server }; }
  if (const auto status = server.listen().status; status != socket_error_code::success) [[unlikely]] { return { status, server }; }
  return { socket_error_code::success, server };
 }
 [[nodiscard]] stl::status_type<socket_error_code, http_socket> http_socket::create_client(u32 const host, u16 const port) {
  http_socket client{host, port};
  if (const auto status = client.connect().status; status != socket_error_code::success) [[unlikely]] { return { status, client }; } 
  else [[likely]] { return { socket_error_code::success, client }; }
 }
}