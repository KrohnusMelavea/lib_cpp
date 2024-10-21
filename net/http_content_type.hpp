#include "types.hpp"
#include <array>
#include <tuple>
#include <algorithm>
#include <string_view>

namespace net {
 enum class http_content_type : u08 {
  json,
  invalid,
 };
 inline constexpr std::array<std::string_view, static_cast<u08>(http_content_type::invalid) + 1> HTTP_CONTENT_TYPE_LOOKUP {
  "http_content_type::json",
  "http_content_type::invalid",
 };
 inline constexpr std::string_view lookup_enum(net::http_content_type const http_content_type) noexcept {
  if (static_cast<u08>(http_content_type) <= static_cast<u08>(net::http_content_type::invalid)) [[likely]] {
   return HTTP_CONTENT_TYPE_LOOKUP[static_cast<u08>(http_content_type)];
  } else [[unlikely]] {
   return "";
  }
 }
}