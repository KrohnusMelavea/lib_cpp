#include "types.hpp"
#include "db_exec.hpp"
#include "timing/scoped_timer.hpp"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <spdlog/spdlog.h>
#include <mutex>
#include <filesystem>

namespace net {
 /* Remember to driver->threadInit() and driver->threadEnd() */
 void db_exec(sql::Connection* const connection, std::string_view const database, std::string_view const query) noexcept {
  timing::scoped_timer timer([](auto&& location, auto&&timing) { 
   SPDLOG_INFO("Thread {} at {}:line {}\n{}\nran for {}ms", 
   std::bit_cast<u32>(std::this_thread::get_id()), 
   std::filesystem::path(location.file_name).filename().string(), location.line, location.function_name,
   std::chrono::duration_cast<std::chrono::milliseconds>(timing).count()); 
  });

  std::cout << "a\n";

  /* Set Schema */
  try { connection->setSchema(std::data(database)); } 
  catch (std::exception& e) {
   SPDLOG_ERROR("Thread {} Setting DB Schema ({}) Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), database, e.what());
   return;
  }
  std::cout << "b\n";
  /* Create Statement */
  auto *const statement = std::invoke([&] () noexcept -> sql::Statement* {
   try { return connection->createStatement(); } 
   catch (std::exception& e) {
    SPDLOG_ERROR("Thread {} Creating DB Statement Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), e.what());
    return nullptr;
   }
  });
  std::cout << "c\n";
  if (statement == nullptr) [[unlikely]] { return; }
  /* Execute Query */
  try { statement->execute(std::data(query)); } 
  catch (std::exception& e) { SPDLOG_ERROR("Thread {} Executing DB Query ({}) Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), query, e.what()); }
  std::cout << "d\n";

  delete statement;
 }
 void db_exec(std::string_view const hostport, std::string_view const username, std::string_view const password, std::string_view const database, std::string_view const query) noexcept {
  /* Get Driver */
  auto *const driver = ::get_driver_instance();
  /* Establish Connection */
  auto *const connection = std::invoke([&] () noexcept -> sql::Connection* {
   try { return driver->connect(std::string(hostport), std::string(username), std::string(password)); } 
   catch (std::exception& e) {
    SPDLOG_ERROR("Thread {} Connection to DB (hostport: {}; username: {}; password: {}) Failed: {}", std::bit_cast<u32>(std::this_thread::get_id()), hostport, username, password, e.what());
    return nullptr;
   }
  });
  if (connection == nullptr) [[unlikely]] { return; }
  /* Set Schema */
  db_exec(connection, database, query);
  delete connection;
 }
}