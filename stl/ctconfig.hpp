#pragma once

#define READ_CONFIG(config, key) (stl::ctconfig<>::get<(config), (key)>())

#include "types.hpp"
#include "tuple.hpp"
#include "cstring.hpp"

namespace stl {
 template <class... Args>
 struct ctconfig {
  char keys[sizeof...(Args)][32];
  tuple<Args...> vals;
  template <std::size_t size, class Arg> consteval auto add(char const(&key)[size], Arg arg) const noexcept {
   ctconfig<Arg, Args...> config;
   for (std::size_t i = 0; i < sizeof...(Args); ++i) {
    for (std::size_t j = 0; j < 32; ++j) {
     config.keys[i + 1][j] = this->keys[i][j];
    }
   }
   for (std::size_t i = 0; i < size; ++i) {
    config.keys[0][i] = key[i];
   }
   for (std::size_t i = size; i < 32; ++i) {
    config.keys[0][i] = 0;
   }
   config.vals.get_rest() = dynamic_cast<tuple_impl<Args...> const&>(this->vals);
   config.vals.get_this() = std::forward<Arg>(arg);
   return config;
  }

  template <cstring str> consteval std::size_t find() const noexcept {
   auto const key = str.get();
   for (std::size_t i = 0; i < sizeof...(Args); ++i) {
    bool is_same = true;
    for (std::size_t j = 0; j < 32 && key[j] != 0; ++j) {
     if (this->keys[i][j] != key[j]) {
      is_same = false;
      break;
     }
    }
    if (is_same) {
     return i;
    }
   }
   return std::numeric_limits<std::size_t>::max();
  }
 };
 template <> struct ctconfig<> {
  template <std::size_t size, class Arg> consteval auto add(char const(&key)[size], Arg arg) const noexcept {
   ctconfig<Arg> config {
    .keys{},
    .vals{ arg }
   };
   for (std::size_t i = 0; i < size; ++i) {
    config.keys[0][i] = key[i];
   }
   for (std::size_t i = size; i < 32; ++i) {
    config.keys[0][i] = 0;
   }
   return config;
  }

  template <auto config, cstring str> static consteval auto&& get() noexcept {
   return config.vals.template get<config.template find<str>()>();
  }
 };
}