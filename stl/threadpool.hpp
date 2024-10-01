#pragma once

#include "types.hpp"
#include "wthread.hpp"
#include "threadjob.hpp"
#include "stack_buffer.hpp"
#include "dynamic_array.hpp"
#include "rotating_static_array.hpp"
#include <thread>
#include <iostream>

namespace stl {
 template <std::size_t buffer_size, class T, class U, class... Args> class threadpool {
 public:
  threadpool(std::size_t const thread_count) : m_threads(thread_count) {
   std::cout << "Threadpool Created\n";
  }
  ~threadpool() {
   std::cout << "Threadpool Destructed";
   for (auto&& wthread : m_threads) {
    wthread.stop();
   }
  }
  bool assign(T&& callback, U&& callable, Args... args) {
   for (auto&& wthread : m_threads) {
    if (!wthread.working()) {
     wthread.assign(std::forward<T>(callback), std::forward<U>(callable), std::forward<Args>(args)...);
     return true;
    }
   }
   if (m_jobqueue.full()) [[unlikely]] {
    return false;
   } else [[likely]] {
    m_jobqueue.emplace(std::forward<T>(callback), std::forward<U>(callable), std::forward<Args>(args)...);
    return true;
   }
  }

 private:
  stl::dynamic_array<stl::wthread<T, U, Args...>> m_threads;
  stl::rotating_static_array<stl::threadjob<T, U, Args...>, buffer_size> m_jobqueue;
 };
}