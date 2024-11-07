#pragma once

#include "types.hpp"
#include "timing/scoped_timer.hpp"
#include "db_credentials.hpp"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <spdlog/spdlog.h>
#include <mutex>
#include <limits>
#include <memory>
#include <ranges>
#include <algorithm>
#include <functional>

namespace net {
 template <std::size_t size> struct destructing_connection_callback;

 template <class callback_t> class destructing_connection {
 public:
  destructing_connection(std::size_t const index, sql::Connection *const connection, callback_t callback) noexcept : m_index{index}, m_connection{connection}, m_callback{callback} {
   if (connection != nullptr) {
    SPDLOG_INFO("destructing_connection({})", index);
   }
  }
  destructing_connection(destructing_connection&& destructing_connection) noexcept : m_index{destructing_connection.m_index}, m_connection{destructing_connection.m_connection}, m_callback{ destructing_connection.m_callback} {
   SPDLOG_INFO("destructing_connection(&&)");
   destructing_connection.m_connection = nullptr;
  }
  destructing_connection(destructing_connection const&) = delete;
  ~destructing_connection() noexcept { 
   if (this->m_connection != nullptr) { this->m_callback(this->m_index); } 
  }

  auto connection() const noexcept { return this->m_connection; }

 private:
  std::size_t m_index;
  sql::Connection *m_connection;
  callback_t m_callback;
 };

 template <std::size_t max_connection_count> class connection_pool {
 public:
  connection_pool() = default;
  connection_pool(net::db_credentials const credentials) noexcept : m_credentials{credentials} {
   this->m_mtx.lock();
   using namespace std::placeholders;
   for (auto& connection : this->m_connections) { connection = nullptr; }
   for (auto& available : this->m_available) { available = false; }
   this->m_driver = ::get_driver_instance();
   for (std::size_t i = 0; i < max_connection_count; ++i) {
    auto& available = this->m_available[i];
    auto& connection = this->m_connections[i];
    try { 
     timing::scoped_timer timer([](auto&& location, auto&&timing) { 
      SPDLOG_INFO("Thread {} at {}:line {}\n{}\nran for {}ms", 
      std::bit_cast<u32>(std::this_thread::get_id()), 
      std::filesystem::path(location.file_name).filename().string(), location.line, location.function_name,
      std::chrono::duration_cast<std::chrono::milliseconds>(timing).count()); 
     });
     connection = this->m_driver->connect(std::data(this->m_credentials.hostport), std::data(this->m_credentials.username), std::data(this->m_credentials.password));
     SPDLOG_INFO("Added Connection to Database (HostPort: \"{}\"; Username: \"{}\"; Password: \"{}\")", credentials.hostport, credentials.username, credentials.password);
     available = true;
    } catch (std::exception& e) {
     SPDLOG_ERROR("Failed to Create Connection: {}", e.what());
     connection = nullptr;
     available = false;
    }
   }
   this->m_mtx.unlock();
  }
  connection_pool(connection_pool const&) = delete;
  ~connection_pool() noexcept {
   SPDLOG_WARN("Connection Pool Destructor Called...");
   std::ranges::for_each(this->m_connections, std::default_delete<sql::Connection>{});
  }

  auto get() noexcept {
   //auto a = [auto ptr = this](std::size_t const index) { ptr->callback(index); };
   this->m_mtx.lock();
   for (std::size_t index = 0; index < max_connection_count; ++index) {
    auto& available = this->m_available[index];
    auto& connection = this->m_connections[index];
    if (!available) [[likely]] { continue; }
    if (connection == nullptr) [[unlikely]] { continue; }
    /* Attempt Reuse */
    try {
     if (connection->isValid()) [[likely]] {
      available = false;
      this->m_mtx.unlock();
      return destructing_connection(index, connection, destructing_connection_callback<max_connection_count>{this}); 
     }
    } catch (std::exception& e) {
     SPDLOG_ERROR("Thread {} Failed to Reconnect to Database (HostPort: \"{}\"; Username: \"{}\"; Password: \"{}\"): {}", 
      std::bit_cast<u32>(std::this_thread::get_id()), this->m_credentials.hostport, this->m_credentials.username, this->m_credentials.password, e.what());
     continue;
    }
    /* Attempt Reconnect */
    try { 
     if (connection->reconnect()) [[likely]] {
      available = false;
      this->m_mtx.unlock();
      return destructing_connection(index, connection, destructing_connection_callback<max_connection_count>{this}); 
     } 
    } catch (std::exception& e) { 
     SPDLOG_ERROR("Thread {} Failed to Reconnect to Database (HostPort: \"{}\"; Username: \"{}\"; Password: \"{}\"): {}", 
      std::bit_cast<u32>(std::this_thread::get_id()), this->m_credentials.hostport, this->m_credentials.username, this->m_credentials.password, e.what());
     continue;
    } 
    /* Attempt Recreation */
    try {
     delete connection;
     connection = this->m_driver->connect(std::data(this->m_credentials.hostport), std::data(this->m_credentials.username), std::data(this->m_credentials.password));
     SPDLOG_INFO("Recreated Connection to Database (HostPort: \"{}\"; Username: \"{}\"; Password: \"{}\")", this->m_credentials.hostport, this->m_credentials.username, this->m_credentials.password);
     available = false;
     this->m_mtx.unlock();
     return destructing_connection(index, connection, destructing_connection_callback<max_connection_count>{this});
    } catch (std::exception& e) {
     SPDLOG_ERROR("Failed to Rereate Connection: {}", e.what());
     continue;
    }
   }
   this->m_mtx.unlock();
   return destructing_connection(0, static_cast<sql::Connection*>(nullptr), destructing_connection_callback<max_connection_count>{this});
  }

  [[nodiscard]] std::span<bool const> available() const noexcept { return m_available; }

  void callback(std::size_t const index) noexcept {
   if (this != nullptr) {
    SPDLOG_INFO("Connection Pool Callback: {}", index);
    this->m_mtx.lock();
    this->m_available[index] = true;
    this->m_mtx.unlock();
   } else {
    SPDLOG_INFO("Connection Pool Callback on nullptr this");
   }
  }

  // auto&& mtx() {
  //  return this->m_mtx;
  // }

 private:
  sql::Driver* m_driver;
  db_credentials m_credentials;
  std::mutex m_mtx;
  std::array<bool, max_connection_count> m_available;
  std::array<sql::Connection*, max_connection_count> m_connections;
 };

 template <std::size_t size> struct destructing_connection_callback {
  destructing_connection_callback(connection_pool<size>* ptr) noexcept : m_ptr{ptr} {}
  void operator()(std::size_t const index) {
   m_ptr->callback(index);
  }
  connection_pool<size>* m_ptr;
 };
}