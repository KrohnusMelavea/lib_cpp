#pragma once

#include "types.hpp"
#include <array>

namespace stl::ext {
 template <class T, class Args> struct array_init_impl_wrapper {
  template <std::size_t... indices> static constexpr std::array<T, sizeof...(indices)> array_init_impl(auto&& args, std::index_sequence<indices...>) noexcept {
   return { ((void)indices, std::make_from_tuple<T>(std::forward<Args>(args)))... };
  }
 };
 template <class T, std::size_t size, class... Args> constexpr std::array<T, size> array_init(Args&&... args) noexcept {
  return array_init_impl_wrapper<T, std::tuple<Args...>>::array_init_impl(std::forward_as_tuple<Args...>(std::forward<Args>(args)...), std::make_index_sequence<size>());
 }
}