#pragma once

#include <string_view>

namespace net {
 struct db_credentials {
  std::string_view hostport;
  std::string_view username;
  std::string_view password;

  [[nodiscard]] bool operator==(db_credentials const& credentials) const noexcept {
  return 
   std::strcmp(std::data(this->hostport), std::data(credentials.hostport)) == 0 &&
   std::strcmp(std::data(this->username), std::data(credentials.username)) == 0 &&
   std::strcmp(std::data(this->password), std::data(credentials.password)) == 0;
 }
 };
}