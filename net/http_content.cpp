#include "http_content.hpp"
#include <iostream>

namespace net {
 http_content::http_content() noexcept : type{http_content_type::invalid} {

 }
 http_content::http_content(http_content_type const type, auto&& content) noexcept : type{type} {
  switch (this->type) {
  case http_content_type::json: {
   (void)std::construct_at(reinterpret_cast<nlohmann::json*>(std::data(this->memory)), std::forward<decltype(content)>(content));
   break;
  }
  }
 }
 http_content::http_content(http_content&& http_content) noexcept {
  switch (http_content.type) { 
  case net::http_content_type::json: {
   auto* this_object_ptr = reinterpret_cast<nlohmann::json*>(std::data(this->memory));
   auto& that_object = *reinterpret_cast<nlohmann::json*>(std::data(http_content.memory));
   (void)std::construct_at(this_object_ptr, std::move(that_object));
   this->type = net::http_content_type::json;
  }
  [[unlikely]] default: {
   this->type = net::http_content_type::invalid;
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

 bool http_content::parse(net::http_content_type const type, std::string_view const data) noexcept {
  switch (type) {
  case net::http_content_type::json: {
   try {
    std::construct_at(reinterpret_cast<nlohmann::json*>(std::data(this->memory)), nlohmann::json::parse(data));
   } catch (std::exception& e) {
    std::cout << std::format("Failed Parsing JSON: {}", e.what());
    return false;
   }
   this->type = type;
   return true;
  }
  return false;
  }
 }
}