#pragma once

#include <tuple>

namespace stl {
 template <class T, class U, class... Args> struct threadjob {
  T callback;
  U callable;
  std::tuple<Args...> args;
 };
}