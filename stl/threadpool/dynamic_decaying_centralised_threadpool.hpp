#pragma once

#include "types.hpp"
#include "wthread.hpp"
#include "stl/ext/func_seq.hpp"
#include "stl/ext/array_init.hpp"
#include "stl/rotating_static_array.hpp"
#include <array>
#include <tuple>
#include <ranges>
#include <thread>
#include <iostream>
#include <algorithm>
#include <functional>
#include <spdlog/spdlog.h>

namespace stl::threadpool {
 class dynamic_decaying_centralised_threadpool_shared_resource_field_empty{};
 template <class shared_resource_t> class dynamic_decaying_centralised_threadpool_shared_resource_field {
 protected:
  shared_resource_t m_resource;
 };
 template <class shared_resource_t> using dynamic_decaying_centralised_threadpool_shared_resource_super = std::conditional_t<
  std::is_same_v<shared_resource_t, void>, 
  dynamic_decaying_centralised_threadpool_shared_resource_field_empty, 
  dynamic_decaying_centralised_threadpool_shared_resource_field<shared_resource_t>>;
 template <std::size_t jobqueue_size, std::size_t threadpool_size, class callable_t, class shared_resource_t=void, class... Args>
 class dynamic_decaying_centralised_threadpool : private dynamic_decaying_centralised_threadpool_shared_resource_super<shared_resource_t> {
 public:
  using wthread_t = wthread<callable_t, shared_resource_t, Args...>;
  using job_t = std::tuple<callable_t, Args...>;

  // template <class resource_t = shared_resource_t, typename std::enable_if_t<std::is_same_v<resource_t, void>, bool> = true> 
  // dynamic_decaying_centralised_threadpool() noexcept { 
  //  SPDLOG_INFO("Constructing Wrong Threadpool");
  //  std::ranges::for_each(this->m_wthreads | std::views::take(8), std::mem_fn(&wthread_t::turn)); 
  //  std::ranges::for_each(this->m_wthreads | std::views::take(8), std::mem_fn(&wthread_t::prefetch)); 
  // }
  //template <class resource_t = shared_resource_t, typename std::enable_if_t<!std::is_same_v<resource_t, void>, bool> = true> 
  dynamic_decaying_centralised_threadpool() noexcept : m_wthreads{stl::ext::array_init<wthread_t, threadpool_size, shared_resource_t&>(this->m_resource)} { 
   SPDLOG_INFO("Constructing Threadpool");
   std::ranges::for_each(this->m_wthreads | std::views::take(8), std::mem_fn(&wthread_t::turn)); 
   std::ranges::for_each(this->m_wthreads | std::views::take(8), std::mem_fn(&wthread_t::prefetch)); 
  }
  ~dynamic_decaying_centralised_threadpool() noexcept { this->stop(); }

  void stop() noexcept {
   (void)std::for_each(std::begin(this->m_wthreads), std::end(this->m_wthreads), std::mem_fn(&wthread_t::stop));
   (void)std::for_each(std::begin(this->m_wthreads), std::end(this->m_wthreads), std::mem_fn(&wthread_t::join));
  }
  void assign(callable_t&& callable, Args&&... args) {
   auto const [threads, thread_count] = this->get_first_available_threads();
   if (thread_count == NULL) [[unlikely]] {
    SPDLOG_INFO("ThreadPool Full. Pushing to JobQueue");
    this->m_jobqueue.emplace(std::forward<callable_t>(callable), std::forward<Args>(args)...);
    return;
   } else {
    (void)threads[0]->assign(std::forward<callable_t>(callable), std::forward<Args>(args)...);
    for (auto&& wthread : threads | std::views::drop(1)) {
     (void)wthread->prefetch();
    }
   }
  }

  void distribute() noexcept {
   SPDLOG_ERROR("Distribution: Unimplemented");
   /* Assign jobs to running, non-working threads */
   for (auto&& wthread : this->m_wthreads) {
    if (this->m_jobqueue.empty()) { break; }
    if (!(wthread.running() && !wthread.working())) { continue; }
    std::apply(&wthread_t::assign, std::tuple_cat(std::forward_as_tuple<wthread_t>(wthread), std::forward<job_t>(this->m_jobqueue.pop())));
   }
   /* Assign remaining jobs to non-running threads */
   for (auto&& wthread : this->m_wthreads) {
    if (this->m_jobqueue.empty()) { break; }
    if (wthread.working()) { continue; }
    std::apply(&wthread_t::assign, std::tuple_cat(std::forward_as_tuple<wthread_t>(wthread), std::forward<job_t>(this->m_jobqueue.pop())));
   }
  }

  bool has_jobs() noexcept { return !this->m_jobqueue.empty(); }

 private:
  [[nodiscard]] static bool is_running_and_not_working(wthread_t const& wthread) noexcept { return wthread.running() && !wthread.working(); }
  [[nodiscard]] static bool is_not_running(wthread_t const& wthread) noexcept { return !wthread.running(); }
  std::tuple<std::array<wthread_t*, 8>, std::size_t> get_first_available_threads() noexcept {
   std::size_t count = 0;
   std::array<wthread_t*, 8> available_threads;
   for (auto&& wthread : this->m_wthreads | std::views::filter(&is_running_and_not_working)) {
    available_threads[count++] = &wthread;
    if (count == std::size(available_threads)) { return std::make_tuple(available_threads, std::size(available_threads)); }
   }
   for (auto&& wthread : this->m_wthreads | std::views::filter(&is_not_running)) {
    available_threads[count++] = &wthread;
    if (count == std::size(available_threads)) { return std::make_tuple(available_threads, std::size(available_threads)); }
   }
   return std::make_tuple(available_threads, count);
  }

  std::array<wthread_t, threadpool_size> m_wthreads;
  stl::rotating_static_array<job_t, jobqueue_size> m_jobqueue;
 };
}