#pragma once

#include <type_traits>

namespace stl {
 template <class status_t> struct status_super_0 {
  status_t status;
 };
 #pragma warning(push)
 #pragma warning(disable : 4820)
 template <class status_t, class value_t> struct status_super_1 {
  status_t status;
  value_t value;
 };
 #pragma warning(pop)
 template <class T> static inline constexpr auto is_void = std::is_same_v<T, void>;
 template <class status_t, class value_t>
 using status_super_t = std::conditional_t<is_void<value_t>, status_super_0<status_t>, status_super_1<status_t, value_t>>;
 template <class status_t, class value_t = void> struct status_type : public status_super_t<status_t, value_t> {
  template <class v_t = value_t, typename std::enable_if_t<is_void<v_t>, bool> = true> 
  constexpr status_type(auto&& status) noexcept : 
   status_super_t<status_t, v_t>(std::forward<decltype(status)>(status)) {}
  template <class v_t = value_t, typename std::enable_if_t<!is_void<v_t>, bool> = true> 
  constexpr status_type(auto&& status, auto&& value) noexcept : 
   status_super_t<status_t, v_t>(std::forward<decltype(status)>(status), std::forward<decltype(value)>(value)) {}
 };
}