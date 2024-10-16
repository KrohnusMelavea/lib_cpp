#pragma once

#include "types.hpp"
#include "wthread.hpp"
#include <array>
#include <thread>
#include <iostream>

namespace stl::threadpool {
 template <std::size_t jobqueue_size, std::size_t threadpool_size, class callback_t, class callable_t,  class... Args>
 class dynamic_decaying_centralised_threadpool {
 public:
  ~dynamic_decaying_centralised_threadpool() noexcept {
   for (auto& wthread : this->m_wthreads) {
    wthread.stop();
   }
   for (auto& wthread : this->m_wthreads) {
    wthread.join();
   }
  }

  void assign(callback_t&& callback, callable_t&& callable, Args&&... args) {
   //find running thread with no work
   auto wthread_it = std::find_if(std::begin(this->m_wthreads), std::end(this->m_wthreads), [&](auto const& wthread) noexcept { return wthread.running() && !wthread.working(); });
   if (wthread_it == std::end(m_wthreads)) [[unlikely]] {
    wthread_it = std::find_if(std::begin(this->m_wthreads), std::end(this->m_wthreads), [&](auto const& wthread){ return !wthread.running(); });
   }
   wthread_it->assign(
    std::forward<callback_t>(callback), 
    std::forward<callable_t>(callable), 
    std::forward<Args>(args)...);
  }

 private:
  std::array<wthread<callback_t, callable_t, Args...>, threadpool_size> m_wthreads;
 };
}