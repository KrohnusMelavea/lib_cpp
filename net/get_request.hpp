#pragma once

#include "types.hpp"
#include <array>
#include <string_view>
#include <unordered_map>

namespace net {
 class get_request {
 public:
  get_request(std::string_view const request_string) noexcept;

  std::string_view url;
  std::unordered_map<std::string_view, std::string_view> variables;

  private:
   std::array<char, 256> url_buffer;
 };
}