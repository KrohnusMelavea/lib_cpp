#pragma once

#include "http_header.hpp"
#include "http_content.hpp"
#include <string_view>

namespace net {
 class http_request {
 public:
  //http_request(std::string_view request) noexcept;

  char const* read_header(std::string_view const request) noexcept;
  void read_body(std::string_view const request) noexcept;

  http_header const& header() const noexcept;

 private:
  http_header m_header;
  http_content m_content;
 };
}