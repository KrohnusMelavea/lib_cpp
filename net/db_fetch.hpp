#pragma once

#include "types.hpp"
#include "timing/scoped_timer.hpp"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mutex>
#include <vector>
#include <iostream>
#include <filesystem>
#include <type_traits>

namespace net {
 enum class mysql_field_type : u08 {
  blob,
  boolean,
  i32,
  u32,
  i64,
  u64,
  f64,
  str,
  none
 };
 template <mysql_field_type t> using get_field_type = 
  std::conditional_t<t == mysql_field_type::blob, std::istream*,
  std::conditional_t<t == mysql_field_type::boolean, bool,
  std::conditional_t<t == mysql_field_type::i32, int,
  std::conditional_t<t == mysql_field_type::u32, unsigned int,
  std::conditional_t<t == mysql_field_type::i64, long long,
  std::conditional_t<t == mysql_field_type::u64, unsigned long long,
  std::conditional_t<t == mysql_field_type::f64, long double,
  std::conditional_t<t == mysql_field_type::str, std::string,
  void>>>>>>>>;
 template <class T> auto consteval get_field_value() noexcept {
  if (std::is_same_v<T, std::istream*>) {
   return mysql_field_type::blob;
  } else if (std::is_same_v<T, bool>) {
   return mysql_field_type::boolean;
  } else if (std::is_same_v<T, int>) {
   return mysql_field_type::i32;
  } else if (std::is_same_v<T, unsigned int>) {
   return mysql_field_type::u32;
  } else if (std::is_same_v<T, long long>) {
   return mysql_field_type::i64;
  } else if (std::is_same_v<T, unsigned long long>) {
   return mysql_field_type::u64;
  } else if (std::is_same_v<T, long double>) {
   return mysql_field_type::f64;
  } else if (std::is_same_v<T, std::string>) {
   return mysql_field_type::str;
  } else {
   return mysql_field_type::none;
  }
 }
 template <std::size_t i> std::tuple<> db_fetch_row(auto const& resource) noexcept {
  return {};
 }
 template <std::size_t i, mysql_field_type T, mysql_field_type... Args> auto db_fetch_row(auto const& resource) noexcept {
  using FT = get_field_type<T>;
  using FTs = std::tuple<get_field_type<Args>...>;

  if constexpr (T == mysql_field_type::blob) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getBlob(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::boolean) {
   try { return std::tuple_cat(std::tuple<FT{}>{resource->getBoolean(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::i32) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getInt(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); }
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::u32) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getUInt(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::i64) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getInt64(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::u64) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getUInt64(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::f64) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getDouble(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::str) {
   try { return std::tuple_cat(std::tuple<FT>{resource->getString(i).move_to_string()}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource))); } 
   catch (sql::SQLException& e) {
    SPDLOG_ERROR("Thread {} SQL Fetch Error on Item #{}: {}", std::bit_cast<u32>(std::this_thread::get_id()), i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else { SPDLOG_ERROR("Thread {} Attempted to Fetch Invalid DB Type: {}", std::bit_cast<u32>(std::this_thread::get_id()), static_cast<u32>(T)); }
 }
 template <mysql_field_type... Args> auto db_fetch(sql::Connection* const connection, std::string_view const database, std::string_view const query) noexcept {
  timing::scoped_timer timer([](auto&& location, auto&&timing) { 
   SPDLOG_INFO("Thread {} at {}:line {}\n{}\nran for {}ms", 
   std::bit_cast<u32>(std::this_thread::get_id()), 
   std::filesystem::path(location.file_name).filename().string(), location.line, location.function_name,
   std::chrono::duration_cast<std::chrono::milliseconds>(timing).count()); 
  });

  /* Set Schema */
  try { connection->setSchema(std::data(database)); } 
  catch (std::exception& e) {
   SPDLOG_ERROR("Thread {} Setting DB Schema ({}) Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), database, e.what());
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  /* Create Statement */
  sql::Statement *statement = nullptr;
  try { statement = connection->createStatement(); } 
  catch (std::exception& e) {
   SPDLOG_ERROR("Thread {} Creating DB Statement Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), e.what());
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  if (statement == nullptr) [[unlikely]] { 
   SPDLOG_ERROR("Thread {} Creating DB Statement Failed", std::bit_cast<u32>(std::this_thread::get_id()));
   return std::vector<std::tuple<get_field_type<Args>...>>{}; 
  }
  /* Execute Query */
  sql::ResultSet *resource = nullptr;
  try { resource = statement->executeQuery(std::data(query)); } 
  catch (std::exception& e) {
   SPDLOG_ERROR("Thread {} Executing DB Query ({}) Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), query, e.what());
   delete statement;
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  if (resource == nullptr) [[unlikely]] {
   SPDLOG_ERROR("Thread {} Executing DB Query ({}) Failed", std::bit_cast<u32>(std::this_thread::get_id()), query);
   delete statement;
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  std::vector<std::tuple<get_field_type<Args>...>> data;
  while (resource->next()) { data.push_back(db_fetch_row<1, Args...>(resource)); }

  delete resource;
  delete statement;

  return data;
 }
 template <mysql_field_type... Args> auto db_fetch(std::string_view const hostport, std::string_view const username, std::string_view const password, std::string_view const database, std::string_view const query) {
  auto *const driver = ::get_driver_instance();
  sql::Connection *connection = nullptr;
  try { connection = driver->connect(std::data(hostport), std::data(username), std::data(password)); }
  catch (std::exception& e) {
   SPDLOG_ERROR("Thread {} Connection to DB (hostport: {}; username: {}; password: {}) Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), hostport, username, password, e.what());
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  if (connection == nullptr || !connection->isValid()) [[unlikely]] {
   SPDLOG_ERROR("Thread {} Connection to DB (hostport: {}; username: {}; password: {}) Failed", std::bit_cast<u32>(std::this_thread::get_id()), hostport, username, password);
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  } 
  auto data = db_fetch<Args...>(connection, database, query);
  delete connection;
  return data;
 }
}