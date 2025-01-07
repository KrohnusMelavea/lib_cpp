#pragma once

#include "types.hpp"

namespace stl {
 template <class... Args> struct tuple_impl;
 template <> struct tuple_impl<> {
  static constexpr std::size_t size = 0;
 };
 template <class Arg, class... Args> struct tuple_impl<Arg, Args...> : tuple_impl<Args...> {
  [[no_unique_address]] Arg var{};
  static constexpr std::size_t size = sizeof...(Args) + 1;
  constexpr tuple_impl() noexcept = default;
  template <class T, class... Ts> constexpr tuple_impl(T&& v, Ts&&... vs) : 
   tuple_impl<Args...>(std::forward<Ts>(vs)...),
   var{std::forward<T>(v)}
  {}
  inline constexpr auto& get_this() noexcept {
   return this->var;
  }
  inline constexpr auto const& get_this() const noexcept {
   return this->var;
  }
  inline constexpr auto& get_rest() noexcept {
   return dynamic_cast<tuple_impl<Args...>&>(*this);
  }
  inline constexpr auto const& get_rest() const noexcept {
   return dynamic_cast<tuple_impl<Args...> const&>(*this);
  }
 };
 template <class... Args> struct tuple : public tuple_impl<Args...> {
  template <std::size_t index, class Tuple>
  constexpr auto&& get_impl(auto&& t) noexcept {
   using type = std::remove_reference_t<Tuple>;
   if constexpr (index == 0) {
    return std::forward<type>(t);
   } else {
    using rest_type = std::remove_reference_t<decltype(std::forward<type>(t).get_rest())>;
    return get_impl<index - 1, rest_type>(std::forward<type>(t).get_rest());
   }
  }
  template <std::size_t index, class Tuple>
  constexpr auto&& get_impl(auto&& t) const noexcept {
   using type = std::remove_reference_t<Tuple> const;
   if constexpr (index == 0) {
    return std::forward<type>(t);
   } else {
    using rest_type = std::remove_reference_t<decltype(std::forward<type>(t).get_rest())> const;
    return get_impl<index - 1, rest_type>(std::forward<type>(t).get_rest());
   }
  }
  template <std::size_t index> 
  constexpr auto& get() noexcept {
   return this->get_impl<index, tuple_impl<Args...>>(dynamic_cast<tuple_impl<Args...>&>(*this)).get_this();
  }
  template <std::size_t index> 
  constexpr auto const& get() const noexcept {
   return this->get_impl<index, tuple_impl<Args...> const>(dynamic_cast<tuple_impl<Args...> const&>(*this)).get_this();
  }
 };
}