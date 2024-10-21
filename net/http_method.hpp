#include "types.hpp"
#include <array>
#include <tuple>
#include <algorithm>
#include <string_view>

namespace net {
 enum class http_method : u08 {
  GET,
  HEAD,
  OPTIONS,
  TRACE,
  PUT,
  DELETE,
  POST,
  PATCH,
  CONNECT,
  INVALID,
 };
 inline constexpr std::array<std::string_view, 9> HTTP_METHOD_LOOKUP {
  "http_method::GET",
  "http_method::HEAD",
  "http_method::OPTIONS",
  "http_method::TRACE",
  "http_method::PUT", 
  "http_method::DELETE", 
  "http_method::POST",
  "http_method::PATCH", 
  "http_method::CONNECT",
 };
 inline constexpr std::string_view lookup_enum(http_method const http_method) noexcept {
  if (static_cast<u08>(http_method) >= static_cast<u08>(http_method::INVALID)) [[unlikely]] {
   return "";
  } else {
   return HTTP_METHOD_LOOKUP[static_cast<u08>(http_method)];
  }
 }
}