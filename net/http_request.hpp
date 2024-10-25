#pragma once

#include "http_header.hpp"
#include "http_content.hpp"
#include <string>
#include <string_view>
#include <unordered_map>
#include <nlohmann/json.hpp>

namespace net {
 class http_request {
 public:
  //http_request(std::string_view request) noexcept;

  std::string resource;
  std::unordered_map<std::string, std::string> header_fields;
  nlohmann::json header_data;

 template <class Self> auto&& header(this Self&& self) noexcept {
  return std::forward<Self>(self).m_header;
 }
 template <class Self> auto&& content(this Self&& self) noexcept {
  return std::forward<Self>(self).m_content;
 }

 private:
  http_header m_header;
  http_content m_content;
 };
}