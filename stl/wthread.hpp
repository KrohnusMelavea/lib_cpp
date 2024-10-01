#pragma once

#include "threadjob.hpp"
#include <thread>
#include <iostream>

namespace stl {
 template <class T, class U, class... Args> class wthread {
 public:
  wthread() : m_thread(&wthread::run, std::ref(*this)), m_threadjob{}, m_working{false}, m_running{true} {
   std::cout << "created thread\n";
  }
  wthread(T&& callback, U&& callable, Args&&... args) : m_thread(&wthread::run, std::ref(*this)), m_threadjob{std::forward(callback), std::forward(callable), std::forward<Args>(args)...}, m_working{false}, m_running{true} {
   std::cout << std::format("Thread #{} Created\n", std::get<0>(this->m_threadjob.args));
   this->m_working = true; /* I'm not aware of any guarantees regarding member initialiser execution order. */
  }
  ~wthread() {
   std::cout << std::format("Thread #{} Destructed\n", std::get<0>(this->m_threadjob.args));
   m_running = false;
  }

  void run() {
   std::cout << std::format("Thread #{} Running\n", std::get<0>(this->m_threadjob.args));
   while (this->m_running) {
    if (this->m_working) {
     this->m_threadjob.callback(std::apply(this->m_threadjob.callable, this->m_threadjob.args));
     this->m_working = false;
    }
   }
  }

  inline bool working() const noexcept { return this->m_working; }
  inline bool running() const noexcept { return this->m_running; }
  inline void stop() noexcept { this->m_running = false; }

  void assign(T&& callback, U&& callable, Args&&... args) {
   this->m_threadjob = stl::threadjob<T, U, Args...>{std::forward<T>(callback), std::forward<U>(callable), std::forward<Args>(args)...};
   this->m_working = true;
  }

 private:
  std::jthread m_thread;
  stl::threadjob<T, U, Args...> m_threadjob;
  bool m_working;
  bool m_running;
 };
}