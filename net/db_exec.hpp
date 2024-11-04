#pragma once

#include <string_view>
#include <mysql_connection.h>

namespace net {
 void db_exec(sql::Connection* const connection, std::string_view const database, std::string_view const query) noexcept;
 void db_exec(std::string_view const hostport, std::string_view const username, std::string_view const password, std::string_view const database, std::string_view const query) noexcept; 
}