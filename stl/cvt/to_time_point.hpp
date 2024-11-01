#pragma once

#include <chrono>
#include <string_view>
#include <iostream>

namespace stl::cvt {
 inline std::chrono::system_clock::time_point to_time_point(std::string_view const time) noexcept  {
  std::tm tm{};
  tm.tm_sec = (time[17] - '0') * 10 + (time[18] - '0');
  tm.tm_hour = (time[11] - '0') * 10 + (time[12] - '0');
  tm.tm_min = (time[14] - '0') * 10 + (time[15] - '0');
  tm.tm_mday = (time[8] - '0') * 10 + (time[9] - '0');
  tm.tm_mon = (time[5] - '0') * 10 + (time[6] - '0') - 1;
  tm.tm_year = (time[0] - '0') * 1000 + (time[1] - '0') * 100 + (time[2] - '0') * 10 + (time[3] - '0') - 1900;
  tm.tm_isdst = -1;
  return std::chrono::system_clock::from_time_t(std::mktime(&tm));
 }
}