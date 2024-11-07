#pragma once

#include "types.hpp"
#include <array>
#include <spdlog/spdlog.h>

namespace stl::ext {
 template <class T, class callable_t, class Args> struct array_init_impl_wrapper {
  template <std::size_t... indices> static constexpr std::array<T, sizeof...(indices)> array_init_fn_impl(auto&& callable, auto&& args, std::index_sequence<indices...>) noexcept {
   return { ((void)indices, std::apply(std::forward<callable_t>(callable), std::forward<Args>(args)))... };
  }
 };
 template <class T, std::size_t size, class callable_t, class... Args> constexpr std::array<T, size> array_init_fn(callable_t&& callable, Args&&... args) noexcept {
  return array_init_impl_wrapper<T, callable_t, std::tuple<Args...>>::array_init_fn_impl(std::forward<callable_t>(callable), std::forward_as_tuple<Args...>(std::forward<Args>(args)...), std::make_index_sequence<size>());
 }
}