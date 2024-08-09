#include "get_request.hpp"

namespace net {
 get_request::get_request(std::string_view const request_string) noexcept {
  char c;
  std::size_t i = 5_u64;
  while ((c = request_string[i++]) != ' ') {
   url_buffer[i - 6_u64] = c;
  }
  url_buffer[i - 6_u64] = '\0';
  url = std::string_view{std::data(url_buffer), i - 5_u64};
 }
}