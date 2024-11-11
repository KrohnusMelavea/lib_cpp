#include "nslookup.hpp"
#include <ws2tcpip.h>

namespace net {
 stl::status_type<socket_error_code, u32> nslookup(std::string_view const domain_name) {
  ::addrinfo const hints{};
  ::addrinfo* addresses;
  socket_error_code error_code = static_cast<net::socket_error_code>(::getaddrinfo(std::data(domain_name), nullptr, &hints, &addresses));
  if (error_code != socket_error_code::success) [[unlikely]] {
   return stl::status_type<socket_error_code, u32>{ error_code, 0_u32 };
  }
  u32 address;
  (void)std::memcpy(&address, reinterpret_cast<void*>(reinterpret_cast<u64>(addresses->ai_addr) + sizeof(u32)), sizeof(u32));
  return { net::socket_error_code::success, address };
 }
}