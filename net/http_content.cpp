#include "http_content.hpp"

namespace net {
 http_content::http_content() noexcept : type{http_content_type::invalid} {

 }
 http_content::http_content(http_content_type const type, auto&& content) noexcept : type{type} {
  switch (this->type) {
  case http_content_type::json: {
   std::construct_at(reinterpret_cast<nlohmann::json*>(std::data(this->memory)), std::forward<decltype(content)>(content));
   break;
  }
  }
 }
 http_content::~http_content() noexcept {
  switch (this->type) {
  case http_content_type::json: {
   std::destroy_at(reinterpret_cast<nlohmann::json*>(std::data(this->memory)));
   break;
  }
  }
 }
}