#pragma once

#include <functional>

namespace func::pred {
 template <class ret, class...Args> [[nodiscard]] inline constexpr std::function<bool(char)> pred_or(std::function<ret(Args...)>lhs, std::function<ret(Args...)> rhs) noexcept {
  return std::function<ret(Args...)>([&] (Args&&... args) noexcept {
   return lhs(std::forward<Args>(args)) || rhs(std::forward<Args>(args));
  });
 }
}