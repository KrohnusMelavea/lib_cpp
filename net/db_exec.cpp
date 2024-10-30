#include "db_exec.hpp"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mutex>

namespace net {
 void db_exec(std::string_view const hostport, std::string_view const username, std::string_view const password, std::string_view const database, std::string_view const query) noexcept {
  /* Get Driver */
  auto *const driver = std::invoke([] () noexcept {
   std::mutex mtx;
   mtx.lock();
   auto* driver = ::get_driver_instance();
   mtx.unlock();
   return driver;
  });
  /* Establish Connection */
  auto *const connection = std::invoke([&] () noexcept -> sql::Connection* {
   try {
    return driver->connect(std::string(hostport), std::string(username), std::string(password));
   } catch (std::exception& e) {
    std::cout << std::format("Connection to DB Failed: {}\n", e.what());
    return nullptr;
   }
  });
  if (connection == nullptr) [[unlikely]] {
   return;
  }
  /* Set Schema */
  try {
   connection->setSchema(std::data(database));
  } catch (std::exception& e) {
   std::cout << std::format("Setting DB Schema Failed: {}\n", e.what());
   delete connection;
   return;
  }
  /* Create Statement */
  auto *const statement = std::invoke([&] () noexcept -> sql::Statement* {
   try {
    return connection->createStatement();
   } catch (std::exception& e) {
    std::cout << std::format("Creating DB Connection Statement Failed: {}\n", e.what());
    delete connection;
    return nullptr;
   }
  });
  if (statement == nullptr) [[unlikely]] {
   return;
  }
  /* Execute Query */
  try {
   statement->execute(std::data(query));
  } catch (std::exception& e) {
   std::cout << std::format("Failed to Execute DB Query: {}\n", e.what());
  }
  
  delete statement;
  delete connection;
 }
}