#pragma once

#include "types.hpp"
#include <tuple>

namespace stl::ext {
 template <class Callables, class Arg, std::size_t index> struct callables_executor{
  void operator()(Callables&& callables, Arg&& arg) const noexcept {
   callables_executor<Callables, Arg, index - 1>()(std::forward<Callables>(callables), std::forward<Arg>(arg));
   (void)std::get<index>(std::forward<Callables>(callables))(std::forward<Arg>(arg));
  }
 };
 template <class Callables, class Arg> struct callables_executor<Callables, Arg, 0>{
  void operator()(Callables&& callables, Arg&& arg) const noexcept { (void)std::get<0>(std::forward<Callables>(callables))(std::forward<Arg>(arg)); }
 };
 template <class... Callables> class func_seq {
 public:
  using callables_t = std::tuple<Callables...>;

  func_seq(Callables&&... callables) : m_callables{std::forward<Callables>(callables)...} { }

  template <class Arg> void operator()(Arg&& arg) noexcept { callables_executor<callables_t, Arg, std::tuple_size_v<callables_t> - 1>()(std::forward<callables_t>(this->m_callables), std::forward<Arg>(arg)); }

 private:
  callables_t m_callables;
};
}