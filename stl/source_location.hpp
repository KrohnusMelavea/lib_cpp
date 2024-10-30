#pragma once

#include <source_location>

namespace stl {
 struct source_location {
  decltype(std::source_location::current().line()) line;
  decltype(std::source_location::current().column()) column;
  decltype(std::source_location::current().file_name()) file_name;
  decltype(std::source_location::current().function_name()) function_name;

  constexpr source_location(std::source_location const& source_location = std::source_location::current()) noexcept : line{source_location.line()}, column{source_location.column()}, file_name{source_location.file_name()}, function_name{source_location.function_name()} {}

  inline constexpr auto operator==(source_location const& other) const noexcept { return other.line == line && other.column == column && other.file_name && file_name && other.function_name == function_name; }
 };
}