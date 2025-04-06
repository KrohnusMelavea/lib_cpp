#pragma once

#include <utility>
#include <functional>

namespace func::pred {
 template <class ret, class... Args> [[nodiscard]] inline constexpr std::function<ret(Args&&...)> pred_nor(std::function<ret(Args&&...)> lhs, std::function<ret(Args&&...)> rhs) noexcept {
  return std::function<ret(Args&&...)>([=] (Args&&... args) noexcept {
   return lhs(std::forward<Args&&...>(args...)) == rhs(std::forward<Args&&...>(args...));
  });
 }
}