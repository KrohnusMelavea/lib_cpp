#pragma once

#include <chrono>
#include <thread>
#include <iostream>

namespace stl::threadpool {
 template <class callback_t, class callable_t, class... Args> class wthread {
 public:
  // wthread() noexcept : m_thread{std::thread(&wthread::run, std::ref(*this))}, m_callback{}, m_callable{}, m_args{}, m_last_worked{std::chrono::steady_clock::now()}, m_running{true}, m_working{false} {

  // }

  wthread() noexcept : m_thread{}, m_callback{}, m_callable{}, m_args{}, m_last_worked{std::chrono::steady_clock::now()}, m_running{false}, m_working{false} {

  }

  void run() {
   using namespace std::chrono_literals;

   while (this->m_running) {
    if (this->m_working) {
     this->m_callback(std::apply(this->m_callable, this->m_args));
     this->m_working = false;
     this->m_last_worked = std::chrono::steady_clock::now();
    }
    if (std::chrono::steady_clock::now() - this->m_last_worked >= 10s) {
     std::cout << std::format("Retiring Thread: {}\n", reinterpret_cast<std::size_t>(this));
     this->m_running = false;
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
    std::cout << std::format("Reviving Thread: {}\n", reinterpret_cast<std::size_t>(this));
    this->join();
    this->m_running = true;
    this->m_thread = std::thread(&wthread::run, std::ref(*this));
   } else {
    std::cout << std::format("Reusing Thread: {}\n", reinterpret_cast<std::size_t>(this));
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
  std::chrono::time_point<std::chrono::steady_clock> m_last_worked;
  bool m_running; /* Signals that the thread is actively taking on work */
  bool m_working; /* Signals that the thread is busy with existing work */
 };
}