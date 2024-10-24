#include "http_request.hpp"
#include <iostream>

namespace net {
 char const* http_request::read_header(std::string_view const request) noexcept {
  char const* c_ptr;
  std::tie(this->m_header, c_ptr) = net::http_header::scan(request);
  return c_ptr;
 }
 void http_request::read_body(std::string_view const request) noexcept {

 }

 http_header const& http_request::header() const noexcept {
  return this->m_header;
 }
}