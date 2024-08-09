#pragma once

#include "types.hpp"
#include <array>
#include <string_view>

namespace net {
 class get_request {
 public:
  get_request(std::string_view const request_string) noexcept;
  
  std::string_view url;

  private:
   std::array<char, 256> url_buffer;
 };
}