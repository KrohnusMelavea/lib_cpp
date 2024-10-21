#pragma once

#include <tuple>
#include <string>
#include <string_view>
#include <unordered_map>

namespace net {
 struct http_header {
  std::string resource;
  std::unordered_map<std::string, std::string> headers;
  std::unordered_map<std::string, std::string> variables;

  static std::tuple<http_header, char const*> scan(std::string_view const request) noexcept;
 };
}