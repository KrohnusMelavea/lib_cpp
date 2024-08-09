#include "get_request.hpp"

#include <iostream>

namespace net {
 get_request::get_request(std::string_view const request_string) noexcept {
  std::size_t i = 5_u64;
  for (; request_string[i] != ' ' && request_string[i] != '?'; ++i) url_buffer[i - 5_u64] = request_string[i];
  if (request_string[i] == '?') {
   url_buffer[i - 5_u64] = request_string[i];
   char const* var = &request_string[i + 1], * val = nullptr;
   while (request_string[++i] != ' ') {
    if (!val) {
     if (request_string[i] == '=') {
      val = &request_string[i + 1];
     }
    } else {
     if (request_string[i] == '&') {
      variables.insert({std::string_view{var, static_cast<u64>(val - var - 1)}, std::string_view{val, static_cast<u64>(&request_string[i] - val)}});
      var = &request_string[i + 1];
      val = nullptr;
     }
    }
    url_buffer[i - 5_u64] = request_string[i];
   }
   variables.insert({std::string_view{var, static_cast<u64>(val - var - 1)}, std::string_view{val, static_cast<u64>(&request_string[i] - val)}});
  }
  url_buffer[i - 5_u64] = '\0';
  url = std::string_view{std::data(url_buffer), i - 5_u64};
 }
}