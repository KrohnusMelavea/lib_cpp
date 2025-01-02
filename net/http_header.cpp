#include "http_header.hpp"
#include "http_method.hpp"
#include "stl/cvt/to_hex_string.hpp"
#include <spdlog/spdlog.h>
#include <thread>
#include <numeric>
#include <iostream>

enum class scan_status : u08 {
 success = 0,
 out_of_bounds = 1,
 crlf_reached = 2,
 amps_reached = 3,
 wonky_crlf = 4,
 eq_reached = 5,
 space_reached = 6,
};

scan_status scan_to_crlf(auto& it, auto end) noexcept {
 for (; *it != '\r' && it < std::prev(end); ++it);
 if (*std::next(it) == '\n') [[likely]] {
  return scan_status::success;
 } else [[unlikely]] {
  return scan_status::wonky_crlf;
 }
}
scan_status scan_to_colon(auto& it, auto end) noexcept {
 while (true) {
  if (it == end) [[unlikely]] {
   return scan_status::out_of_bounds;
  } else if (*it == '\r') [[unlikely]] {
   if (it + 1 < end && *(it + 1) == '\n') [[likely]] {
    return scan_status::crlf_reached;
   } else {
    return scan_status::wonky_crlf;
   }
  } else if (*it == ':') [[unlikely]] {
   return scan_status::success;
  } else [[likely]] {
   ++it;
  }
 }
}
scan_status scan_to_eq(auto& it, auto end) noexcept {
 while (true) {
  if (it == end) [[unlikely]] {
   return scan_status::out_of_bounds;
  } else if (*it == '\r') [[unlikely]] /* CRLF only allowed at end of value, not during key */ {
   if (it + 1 < end && *(it + 1) == '\n') [[likely]] {
    return scan_status::crlf_reached;
   } else {
    return scan_status::wonky_crlf;
   }
  } else if (*it == '&') [[unlikely]] {
   return scan_status::amps_reached;
  } else if (*it == '=') [[unlikely]] {
   return scan_status::success;
  } else [[likely]] {
   ++it;
  }
 }
}
scan_status scan_to_amps_or_crlf_or_space(auto& it, auto end) noexcept {
 while (true) {
  if (it == end) [[unlikely]] {
   return scan_status::out_of_bounds;
  } else if (*it == '\r') [[unlikely]] {
   if (it + 1 < end && *(it + 1) == '\n') [[likely]] {
    return scan_status::crlf_reached;
   } else {
    return scan_status::wonky_crlf;
   }
  } else if (*it == '=') {
   return scan_status::eq_reached;
  } else if (*it == '&') {
   return scan_status::amps_reached;
  } else if (*it == ' ') {
   return scan_status::space_reached;
  } else [[likely]] {
   ++it;
  }
 }
}
scan_status scan_past_space(auto& it, auto end) noexcept {
 for (; it < end && *it == ' '; ++it);
 if (it == end) [[unlikely]] {
  return scan_status::out_of_bounds;
 } else [[likely]] {
  return scan_status::success;
 }
}

namespace net {
 char const* http_header::scan(std::string_view const request) noexcept {
  auto c_it = std::begin(request);
  if (std::size(request) < 18) [[unlikely]] /* Shortest viable HTTP Request ("GET / HTTP/1.2\r\n\r\n") is 18 bytes long */ {
   std::cout << "Too Small\n";
   std::cout << std::size(request) << '\n';
   return nullptr;
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
   SPDLOG_ERROR("Thread {}: Invalid HTTP Method", std::bit_cast<u32>(std::this_thread::get_id()));
   return nullptr;
  }

  std::string_view const resource = std::invoke([&] {
   for (auto it = c_it; it < std::end(request); ++it) {
    if (*it == ' ' || *it == '?') [[unlikely]] /* Follow-up space is mandatory */ {
     return std::string_view{c_it, it};
    }
   }
   return std::string_view{""};
  });
  if (std::size(resource) == 0) [[unlikely]] /* Not allowed, as empty resource is denoted as '/' */ {
   SPDLOG_ERROR("Thread {}: Empty Resource", std::bit_cast<u32>(std::this_thread::get_id()));
   return nullptr;
  }
  this->resource = resource;
  c_it += std::size(resource);
  if (*c_it == '?') {
   while (true) /* Scan URL Variables */ {
    ++c_it;
    auto const var_start = c_it;
    auto const eq_scan_status = ::scan_to_eq(c_it, std::end(request));
    if (eq_scan_status != ::scan_status::success) [[unlikely]] {
     std::cout << std::format("Funny '=': {}\n", static_cast<u64>(eq_scan_status));
     return nullptr;
    }
    std::string_view const key{ var_start, c_it };
    ++c_it;
    auto const val_start_it = c_it;
    auto const amps_or_crlf_status = ::scan_to_amps_or_crlf_or_space(c_it, std::end(request));
    std::string_view val{ val_start_it, c_it };
    if (amps_or_crlf_status == ::scan_status::amps_reached) [[likely]] {
     this->header_variables.insert({std::string(key), std::string(val)});
    } else if (amps_or_crlf_status == ::scan_status::crlf_reached) {
     std::cout << "Malformed First Header Line\n";
     return nullptr;
    } else if (amps_or_crlf_status == ::scan_status::space_reached) {
     this->header_variables.insert({std::string(key), std::string(val)});
     break;
    } else [[unlikely]] {
     std::cout << std::format("Funky URL Read: {}", static_cast<u64>(amps_or_crlf_status));
     return nullptr;
    }
   }
  }

  if (scan_to_crlf(c_it, std::cend(request)) == scan_status::success) [[likely]] {
   c_it += 2;
  } else [[unlikely]] {
   return nullptr;
  }

  while (c_it < std::end(request)) /* Scan header fields */ {
   if (c_it + 1 < std::end(request)) [[likely]] {
    if (*c_it == '\r' && *(c_it + 1) == '\n') {
     break;
    }
   }

   auto const header_key_start = c_it;
   auto const colon_status = scan_to_colon(c_it, std::end(request));
   if (colon_status != ::scan_status::success) [[unlikely]] {
    std::cout << std::format("Weird Colon: {}\n", static_cast<u64>(colon_status));
    return nullptr;
   }
   std::string_view const header_key{header_key_start, c_it};
   ++c_it;
   if (std::size(header_key) == 0) {
    std::cout << "Header Key may not be NULL\n";
    return nullptr;
   }

   if (::scan_past_space(c_it, std::end(request)) != scan_status::success) [[unlikely]] {
    return nullptr;
   }
   auto const header_value_start = c_it;
   if (scan_to_crlf(c_it, std::end(request)) != scan_status::success) [[unlikely]] {
    std::cout << "Weird Header Value\n";
    return nullptr;
   }
   std::string_view const header_value{header_value_start, c_it};
   c_it += 2;

   this->header_fields.insert({ std::string(header_key), std::string(header_value) });
  }

  return &*c_it;
 }
}