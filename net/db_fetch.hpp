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
  std::conditional_t<t == mysql_field_type::str, sql::SQLString,
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
  } else if (std::is_same_v<T, sql::SQLString>) {
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
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getBlob(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::boolean) {
   try {
    return std::tuple_cat(std::tuple<FT{}>{resource->getBoolean(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::i32) {
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getInt(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::u32) {
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getUInt(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::i64) {
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getInt64(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::u64) {
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getUInt64(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::f64) {
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getDouble(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else if constexpr (T == mysql_field_type::str) {
   try {
    return std::tuple_cat(std::tuple<FT>{resource->getString(i)}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   } catch (sql::SQLException& e) {
    std::cout << std::format("SQL Error (Item #{}): {}\n", i, e.what());
    return std::tuple_cat(std::tuple<FT>{FT{}}, std::forward<FTs>(db_fetch_row<i + 1, Args...>(resource)));
   }
  } else {
   std::cout << "Invalid DB Fetch Type\n";
  }
 }
 template <mysql_field_type... Args> auto db_fetch(std::string_view const host_port, std::string_view const user, std::string_view const password, std::string_view const database, std::string_view const query) {

  static auto *driver = ::get_driver_instance();
    
  //driver->threadInit();
  
  sql::Connection *connection = nullptr;
  try {
   connection = driver->connect(std::string(host_port), std::string(user), std::string(password));
  } catch (std::exception& e) {
   std::cout << std::format("Connection to DB Failed: {}\n", e.what());
   //driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  if (connection == nullptr || !connection->isValid()) {
   std::cout << "Connection to DB Failed\n";
   //driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  
  try {
   connection->setSchema(std::string(database));
  } catch (std::exception& e) {
   std::cout << std::format("Failed to Set DB Schema: {}\n", e.what());
   delete connection;
   driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  
  sql::Statement *statement = nullptr;
  try {
   statement = connection->createStatement();
  } catch (std::exception& e) {
   std::cout << std::format("Failed to Create DB Statement: {}\n", e.what());
   delete connection;
   driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  if (statement == nullptr) [[unlikely]] {
   std::cout << "Failed to Create DB Statement\n";
   delete connection;
   driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }

  sql::ResultSet *resource = nullptr;
  try {
   resource = statement->executeQuery(std::string(query));
  } catch (std::exception& e) {
   std::cout << std::format("Failed to Execute Query: {}\n", e.what());
   delete statement;
   delete connection;
   driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }
  if (resource == nullptr) [[unlikely]] {
   std::cout << "Failed to Execute Query\n";
   delete statement;
   delete connection;
   driver->threadEnd();
   return std::vector<std::tuple<get_field_type<Args>...>>{};
  }

  std::vector<std::tuple<get_field_type<Args>...>> data;
  while (resource->next()) {
   data.push_back(db_fetch_row<1, Args...>(resource));
  }

  delete resource;
  delete statement;
  delete connection;

  driver->threadEnd();
  return data;
 }
}