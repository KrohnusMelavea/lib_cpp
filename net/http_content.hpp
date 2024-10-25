#pragma once

#include "types.hpp"
#include "http_content_type.hpp"
#include <nlohmann/json.hpp>
#include <string_view>

namespace net {
 template <http_content_type type> struct content_enum_to_type {
  using T = void;
 };
 template <> struct content_enum_to_type<http_content_type::json> {
  using T = nlohmann::json;
 };
 template <http_content_type type> using content_enum_to_type_t = content_enum_to_type<type>::T;

 struct http_content {
  http_content_type type;
  std::array<u08, max_type_size_v<nlohmann::json>> memory;

  http_content() noexcept;
  http_content(http_content&&) noexcept;
  http_content(http_content const&) noexcept = delete;
  http_content(http_content_type const type, auto&& content) noexcept;
  ~http_content() noexcept;

  /* I'm not even sure if this is legal */
  template <http_content_type type, class Self> auto&& get_content(this Self&& self) noexcept {
   return *reinterpret_cast<content_enum_to_type_t<type>>(std::data(std::forward<Self>(self).memory));
  }
  template <class Self> auto&& get_json_content(this Self&& self) noexcept {
   return *reinterpret_cast<content_enum_to_type_t<http_content_type::json>*>(std::data(std::forward<Self>(self).memory));
  }

  bool parse(http_content_type const type, std::string_view const data) noexcept;
 };
}