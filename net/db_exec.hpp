#pragma once

#include <string_view>

namespace net {
 void db_exec(std::string_view const hostport, std::string_view const username, std::string_view const password, std::string_view const database, std::string_view const query) noexcept; 
}