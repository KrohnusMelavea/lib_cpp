#pragma once

#include <functional>
#include <source_location>

namespace timing {
 struct timing_archive_entry {
  std::source_location source_location;

  inline constexpr auto operator==(auto const& other) const noexcept { return source_location.line() == other.source_location.line() && source_location.column() == other.source_location.column() && source_location.file_name() == other.source_location.file_name() && source_location.function_name() == other.source_location.function_name(); }
 };

}