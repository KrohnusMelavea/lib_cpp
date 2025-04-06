#pragma once

#include <utility>
#include <functional>

namespace func::pred {
 template <class ret, class... Args> [[nodiscard]] inline constexpr std::function<ret(Args&&...)> pred_not(std::function<ret(Args&&...)> pred) noexcept {
  return std::function<ret(Args&&...)>([=] (Args&&... args) noexcept {
   return !pred(std::forward<Args&&...>(args...));
  });
 }
}