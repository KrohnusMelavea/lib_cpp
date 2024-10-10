#pragma once

#include "types.hpp"
#include <array>
#include <string_view>

/* As per: https://datatracker.ietf.org/doc/html/rfc8446*/

namespace net {
 enum class tls_supported_group : u16 {
  /* ECDHE */
  secp256r1 = 0x0017,
  secp384r1 = 0x0018,
  secp521r1 = 0x0019,
  x25519    = 0x001d,
  x448      = 0x001e,
  /* DHE */
  ffdhe2048 = 0x0100,
  ffdhe3072 = 0x0101,
  ffdhe4096 = 0x0102,
  ffdhe6144 = 0x0103,
  ffdhe8192 = 0x0104,
 };

 inline constexpr std::array<std::pair<tls_supported_group, std::string_view>, 10> TLS_SUPPORTED_GROUP_LOOKUP {
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::secp256r1, "tls_supported_group::secp256r1" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::secp384r1, "tls_supported_group::secp384r1" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::secp521r1, "tls_supported_group::secp521r1" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::x25519   , "tls_supported_group::x25519"    },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::x448     , "tls_supported_group::x448"      },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::ffdhe2048, "tls_supported_group::ffdhe2048" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::ffdhe3072, "tls_supported_group::ffdhe3072" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::ffdhe4096, "tls_supported_group::ffdhe4096" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::ffdhe6144, "tls_supported_group::ffdhe6144" },
  std::pair<tls_supported_group, std::string_view>{ tls_supported_group::ffdhe8192, "tls_supported_group::ffdhe8192" },
 };
 [[nodiscard]] inline constexpr std::string_view lookup_enum(tls_supported_group const tls_supported_group) noexcept {
  auto const it = std::find_if(std::cbegin(TLS_SUPPORTED_GROUP_LOOKUP), std::cend(TLS_SUPPORTED_GROUP_LOOKUP), [&tls_supported_group](auto const& entry) { return entry.first == tls_supported_group; });
  if (it == std::cend(TLS_SUPPORTED_GROUP_LOOKUP)) [[unlikely]] {
   return "";
  } else [[likely]] {
   return it->second;
  }
 }
}