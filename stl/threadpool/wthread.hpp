#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <type_traits>
#include <spdlog/spdlog.h>

namespace stl::threadpool {
 class wthread_shared_resource_field_empty{};
 template <class shared_resource_t> class wthread_shared_resource_field {
  shared_resource_t& m_resource;
 };
 template <class shared_resource_t> using wthread_shared_resource_field_super = std::conditional_t<
  std::is_same_v<shared_resource_t, void>,
  wthread_shared_resource_field_empty, 
  wthread_shared_resource_field<shared_resource_t>>;
 template <class callable_t, class shared_resource_t = void, class... Args> class wthread {
 public:
 shared_resource_t& m_resource;
  template <class T = shared_resource_t, typename std::enable_if_t<!std::is_same_v<T, void>, bool> = true> wthread(shared_resource_t& resource) : m_resource{resource} {
   
  }

  void run() noexcept {
   using namespace std::chrono_literals;
   SPDLOG_INFO("Reviving Thread: {}", std::bit_cast<u32>(std::this_thread::get_id()));
   while (this->m_running) {
    if (this->m_working) [[unlikely]] /* Thread has newly assigned work */ {
     if constexpr (std::is_same_v<shared_resource_t, void>) { std::apply(this->m_callable, this->m_args); }
     else if constexpr (!std::is_same_v<shared_resource_t, void>) { std::apply(this->m_callable, std::tuple_cat(std::forward_as_tuple(&this->m_resource), this->m_args)); }
     this->m_working = false;
     this->m_last_worked = std::chrono::steady_clock::now();
    } else if (!this->m_undying && std::chrono::steady_clock::now() - this->m_last_worked > 300s) [[unlikely]] /* Thread expired */ {
     this->m_running = false;
    } else [[likely]] { std::this_thread::sleep_for(500us); }
   }
   SPDLOG_INFO("Retiring Thread: {}\n", this->pid());
  }

  void assign(callable_t&& callable, Args&&... args) noexcept {
   this->m_callable = std::forward<callable_t>(callable);
   this->m_args = std::make_tuple(std::forward<Args>(args)...);
   this->m_working = true;
   if (!this->m_running) [[unlikely]] {
    this->m_running = true;
    this->join();
    this->m_thread = std::thread(&wthread::run, std::ref(*this));
   }
  }

  void revitalise() noexcept { this->m_last_worked = std::chrono::steady_clock::now(); }
  void revive() noexcept {
   this->m_running = true;
   this->join();
   this->m_thread = std::thread(&wthread::run, std::ref(*this));
  }
  void prefetch() noexcept {
   this->revitalise();
   if (!this->m_running) { this->revive(); }
  }

  void turn() noexcept { this->m_undying = true; }
  void sanctify() noexcept {
   this->m_last_worked = std::chrono::steady_clock::now();
   this->m_undying = false;
  }
  
  [[nodiscard]] inline bool running() const noexcept { return this->m_running; }
  [[nodiscard]] inline bool working() const noexcept { return this->m_working; }
  inline void stop() noexcept { this->m_running = false; }
  void join() noexcept {
   if (this->m_thread.joinable()) [[likely]] { this->m_thread.join(); }
  }

  [[nodiscard]] u32 pid() const noexcept { return std::bit_cast<u32>(this->m_thread.get_id()); }
  [[nodiscard]] auto const& args() const noexcept { return this->m_args; }
 
 private:
  std::thread m_thread{};
  callable_t m_callable{};
  std::tuple<Args...> m_args{};
  std::chrono::steady_clock::time_point m_last_worked{};
  bool m_running = false;
  bool m_working = false;
  bool m_undying = false;
 };
}