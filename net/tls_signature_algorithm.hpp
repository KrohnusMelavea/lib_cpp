#pragma once

#include "types.hpp"
#include <array>
#include <string_view>

namespace net {
 enum class tls_signature_algorithm : u16 {
  /* RSASSA-PKCS1-v1_5 */
  rsa_pkcs1_sha256       = 0x0401,
  rsa_pkcs1_sha384       = 0x0501,
  rsa_pkcs1_sha512       = 0x0601,
  /* ECDSA */
  ecdsa_secp256r1_sha256 = 0x0403,
  ecdsa_secp384r1_sha384 = 0x0503,
  ecdsa_secp521r1_sha512 = 0x0603,
  /* RSASSA-PSS PK OID rsaEncryption */
  rsa_pss_rsae_sha256    = 0x0804,
  rsa_pss_rsae_sha384    = 0x0805,
  rsa_pss_rsae_sha512    = 0x0806,
  /* EdDSA  */
  ed25519                = 0x0807,
  ed448                  = 0x0808,
  /* RSASSA-PSS PK OID RSASSA-PSS */
  rsa_pss_pss_sha256     = 0x0809,
  rsa_pss_pss_sha384     = 0x080a,
  rsa_pss_pss_sha512     = 0x080b,
  /* Legacy */
  rsa_pkcs1_sha1         = 0x0201,
  ecdsa_sha1             = 0x0203,
 };
 inline constexpr std::array<std::pair<tls_signature_algorithm, std::string_view>, 16> TLS_SIGNATURE_ALGORITHM_LOOKUP {
  /* RSASSA-PKCS1-v1_5 */
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pkcs1_sha256      , "tls_signature_algorithm::rsa_pkcs1_sha256"       },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pkcs1_sha384      , "tls_signature_algorithm::rsa_pkcs1_sha384"       },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pkcs1_sha512      , "tls_signature_algorithm::rsa_pkcs1_sha512"       },
  /* ECDSA */
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::ecdsa_secp256r1_sha256, "tls_signature_algorithm::ecdsa_secp256r1_sha256" },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::ecdsa_secp384r1_sha384, "tls_signature_algorithm::ecdsa_secp384r1_sha384" },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::ecdsa_secp521r1_sha512, "tls_signature_algorithm::ecdsa_secp521r1_sha512" },
  /* RSASSA-PSS PK OID rsaEncryption */
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pss_rsae_sha256   , "tls_signature_algorithm::rsa_pss_rsae_sha256"    },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pss_rsae_sha384   , "tls_signature_algorithm::rsa_pss_rsae_sha384"    },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pss_rsae_sha512   , "tls_signature_algorithm::rsa_pss_rsae_sha512"    },
  /* EdDSA  */
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::ed25519               , "tls_signature_algorithm::ed25519"                },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::ed448                 , "tls_signature_algorithm::ed448"                  },
  /* RSASSA-PSS PK OID RSASSA-PSS */
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pss_pss_sha256    , "tls_signature_algorithm::rsa_pss_pss_sha256"     },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pss_pss_sha384    , "tls_signature_algorithm::rsa_pss_pss_sha384"     },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pss_pss_sha512    , "tls_signature_algorithm::rsa_pss_pss_sha512"     },
  /* Legacy */
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::rsa_pkcs1_sha1        , "tls_signature_algorithm::rsa_pkcs1_sha1"         },
  std::pair<tls_signature_algorithm, std::string_view>{ tls_signature_algorithm::ecdsa_sha1            , "tls_signature_algorithm::ecdsa_sha1"             },
 };
 [[nodiscard]] inline constexpr std::string_view lookup_enum(tls_signature_algorithm const tls_signature_algorithm) noexcept {
  auto const it = std::find_if(std::cbegin(TLS_SIGNATURE_ALGORITHM_LOOKUP), std::cend(TLS_SIGNATURE_ALGORITHM_LOOKUP), [&tls_signature_algorithm](auto const& entry) { return entry.first == tls_signature_algorithm; });
  if (it == std::cend(TLS_SIGNATURE_ALGORITHM_LOOKUP)) [[unlikely]] {
   return "";
  } else [[likely]] {
   return it->second;
  }
 }
}