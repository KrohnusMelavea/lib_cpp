#pragma once

#include "types.hpp"
#include "socket_error_code.hpp"
#include "stl/status_type.hpp"
#include "stl/dynamic_array.hpp"
#include <string_view>

namespace net {
 stl::status_type<net::socket_error_code, u32> nslookup(std::string_view const domain_name);
}