#pragma once

#include <thread>
#include <iostream>

namespace stl::threadpool {
 template <class callback_t, class callable_t, class... Args> class wthread {
 public:
  wthread() noexcept : m_thread{std::thread(&wthread::run, std::ref(*this))}, m_callback{}, m_callable{}, m_args{}, m_running{true}, m_working{false} {

  }

  void run() {
   while (this->m_running) {
    if (this->m_working) {
     this->m_callback(std::apply(this->m_callable, this->m_args));
     this->m_working = false;
    }
   }
  }
  /*
  Assumes:
  - this->m_working == false || this->m_running = false
  */
  void assign(callback_t&& callback, callable_t&& callable, Args&&... args) noexcept {
   this->m_callback = std::forward<callback_t>(callback);
   this->m_callable = std::forward<callable_t>(callable);
   this->m_args = std::forward_as_tuple<Args&&...>(std::forward<Args>(args)...);
   this->m_working = true;
   if (!this->m_running) [[unlikely]] /* Revive the thread */ {
    this->m_running = true;
    this->m_thread = std::thread(&wthread::run, std::ref(*this));
   }
  }

  [[nodiscard]] bool running() const noexcept { return this->m_running; }
  [[nodiscard]] bool working() const noexcept { return this->m_working; }
  void stop() noexcept { this->m_running = false; }
  void join() noexcept {
   if (this->m_thread.joinable()) {
    this->m_thread.join();
   }
  }

 private:
  std::thread m_thread;
  callback_t m_callback;
  callable_t m_callable;
  std::tuple<Args...> m_args;
  bool m_running; /* Signals that the thread is actively taking on work */
  bool m_working; /* Signals that the thread is busy with existing work */
 };
}