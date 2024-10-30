#pragma once

#include "types.hpp"
#include "wthread.hpp"
#include "stl/rotating_static_array.hpp"
#include <array>
#include <thread>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <functional>

namespace stl::threadpool {
 template <std::size_t jobqueue_size, std::size_t threadpool_size, class callback_t, class callable_t,  class... Args>
 class dynamic_decaying_centralised_threadpool {
 public:
  using wthread_t = wthread<callback_t, callable_t, Args...>;
  using job_t = std::tuple<callback_t, callable_t, Args...>;

  ~dynamic_decaying_centralised_threadpool() noexcept {
   this->stop();
  }

  void stop() noexcept {
   (void)std::for_each(std::begin(this->m_wthreads), std::end(this->m_wthreads), std::mem_fn(&wthread_t::stop));
   (void)std::for_each(std::begin(this->m_wthreads), std::end(this->m_wthreads), std::mem_fn(&wthread_t::join));
  }
  //assigning multiple clients because ::assign doesnt reserve socket
  void assign(callback_t&& callback, callable_t&& callable, Args&&... args) {
   auto wthread_it = std::find_if(std::begin(this->m_wthreads), std::end(this->m_wthreads), [](auto const& wthread) noexcept { return wthread.running() && !wthread.working(); }); /* Look for non-working running thread */
   if (wthread_it == std::end(this->m_wthreads)) [[unlikely]] {
    std::cout << "No free working thread found...\n";
    wthread_it = std::find_if(std::begin(this->m_wthreads), std::end(this->m_wthreads), [](auto const& wthread) noexcept { return !wthread.running(); }); /* Look for non-running thread */
    if (wthread_it == std::end(this->m_wthreads)) [[unlikely]] {
     std::cout << "ThreadPool Full. Pushing to JobQueue\n";
     this->m_jobqueue.push(std::forward_as_tuple(
      std::forward<callback_t>(callback), 
      std::forward<callable_t>(callable), 
      std::forward<Args>(args)...));
     return;
    }
   }
   wthread_it->assign(
    std::forward<callback_t>(callback), 
    std::forward<callable_t>(callable), 
    std::forward<Args>(args)...);
  }

  void distribute() noexcept {
   for (auto& wthread : this->m_wthreads) {
    if (this->m_jobqueue.empty()) {
     break;
    }
    if (!(wthread.running() && !wthread.working())) {
     continue;
    }
    std::apply(&wthread_t::assign, std::tuple_cat(std::forward_as_tuple(std::forward<wthread_t>(wthread)), std::forward<job_t>(this->m_jobqueue.pop())));
   }
   for (auto& wthread : this->m_wthreads) {
    if (this->m_jobqueue.empty()) {
     break;
    }
    if (wthread.working()) {
     continue;
    }
    std::apply(&wthread_t::assign, std::tuple_cat(std::forward_as_tuple(std::forward<wthread_t>(wthread)), std::forward<job_t>(this->m_jobqueue.pop())));
   }
  }

  bool has_jobs() noexcept { return !this->m_jobqueue.empty(); }

 private:
  std::array<wthread_t, threadpool_size> m_wthreads;
  stl::rotating_static_array<job_t, jobqueue_size> m_jobqueue;
 };
}