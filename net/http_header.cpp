#include "http_header.hpp"
#include "http_method.hpp"
#include "stl/cvt/to_hex_string.hpp"

#include <iostream>

enum class scan_status : u08 {
 success = 0,
 out_of_bounds = 1,
 crlf_reached = 2
};

scan_status scan_to_crlf(auto& it, auto end) noexcept {
 for (; *it != '\r' && it < std::prev(end); ++it);
 if (*std::next(it) == '\n') [[likely]] {
  return scan_status::success;
 } else [[unlikely]] {
  return scan_status::out_of_bounds;
 }
}

scan_status scan_to_colon(auto& it, auto end) noexcept {
 while (true) {
  if (it == end) [[unlikely]] {
   return scan_status::out_of_bounds;
  } else if (*it == '\r') [[unlikely]] {
   return scan_status::crlf_reached;
  } else if (*it == ':') [[unlikely]] {
   return scan_status::success;
  } else [[likely]] {
   ++it;
  }
 }
}

void scan_past_space(auto& it, auto end) noexcept {
 for (; it < end && *it == ' '; ++it);
}

namespace net {
 std::tuple<http_header, char const*> http_header::scan(std::string_view const request) noexcept {
  std::cout << "Scanning\n";
  auto c_it = std::begin(request);
  if (std::size(request) < 18) [[unlikely]] /* Shortest viable HTTP Request ("GET / HTTP/1.2\r\n\r\n") is 18 bytes long */ {
   std::cout << "Too Small\n";
   return {};
  }
  http_method const http_method = std::invoke([&] {
   if (request[0] == 'G' && request[1] == 'E' && request[2] == 'T' && request[3] == ' ') /* Follow-up space is mandatory */ {
    c_it += 4;
    return http_method::GET;
   } else if (request[0] == 'P' && request[1] == 'O' && request[2] == 'S' && request[3] == 'T' && request[4] == ' ') /* Follow-up space is mandatory */ {
    c_it += 5;
    return http_method::POST;
   } else [[unlikely]] /* Might be a valid HTTP method, but not in this context. */ {
    return http_method::INVALID;
   }
  });
  if (http_method == http_method::INVALID) [[unlikely]] {
   std::cout << "Invalid HTTP Method\n";
   return {};
  }

  std::cout << std::format("HTTP Method: {}\n", net::lookup_enum(http_method));

  std::string_view const resource = std::invoke([&] {
   for (auto it = c_it; it < std::end(request); ++it) {
    if (*it == ' ') [[unlikely]] /* Follow-up space is mandatory */ {
     return std::string_view{c_it, it};
    }
   }
   return std::string_view{""};
  });
  if (std::size(resource) == 0) [[unlikely]] /* Not allowed, as empty resource is denoted as '/' */ {
   std::cout << "Empty Resource\n";
   return {};
  }
  c_it += std::size(resource);

  if (scan_to_crlf(c_it, std::cend(request)) == scan_status::success) [[likely]] {
   c_it += 2;
  } else [[unlikely]] {
   return {};
  }

  std::unordered_map<std::string, std::string> headers;
  while (c_it < std::end(request)) {
   if (c_it + 1 < std::end(request)) [[likely]] {
    if (*c_it == '\r' && *(c_it + 1) == '\n') {
     break;
    }
   }

   std::string_view header_key, header_value;

   auto const header_key_start = c_it;
   auto const colon_status = scan_to_colon(c_it, std::end(request));
   if (colon_status == scan_status::success) [[likely]] {
    header_key = std::string_view{header_key_start, c_it};
    ++c_it;
   } else [[unlikely]] { 
    std::cout << std::format("Weird Colon: {}\n", static_cast<u64>(colon_status));
    return {};
   }
   if (std::size(header_key) == 0) {
    std::cout << "Header Key may not be NULL\n";
    return {};
   }

   scan_past_space(c_it, std::end(request));
   auto const header_value_start = c_it;
   if (scan_to_crlf(c_it, std::end(request)) == scan_status::success) [[likely]] {
    header_value = std::string_view{header_value_start, c_it};
   } else [[unlikely]] {
    std::cout << "Weird Header Value\n";
    return {};
   }
   c_it += 2;

   headers.insert({ std::string(header_key), std::string(header_value) });
  }

  return std::tuple<http_header, char const*>{
   http_header{
    .resource = std::string(resource),
    .headers = std::move(headers),
    .variables{}
   },
   &(*c_it)
  };
 }
}