#pragma once

void process_client_handshake(stl::buffer const data) noexcept {
 u08* p = reinterpret_cast<u08*>(std::data(data));
 switch (*p++) {
 case 0x16: {
  std::cout << "Record Type: Handshake\n";
  break;
 }
 default: {
  std::cout << "Record Type: Unknown\n";
  break;
 }
 }
 std::cout << std::format("TLS Legacy Major Version: {}\n", *p++);
 std::cout << std::format("TLS Legacy Minor Version: {}\n", *p++);
 u16 const tls_record_size = (*p++ << 8) + *p++;
 std::cout << std::format("TLS Record Size: {}\n", tls_record_size);
 switch (*p++) {
 case 0x01: {
  std::cout << "TLS Handshake Type: Client\n";
  break;
 }
 default: {
  std::cout << "TLS Handshake Type: Unknown\n";
  break;
 }
 }
 u32 const tls_remaining_record_size = (*p++ << 16) + (*p++ << 8) + (*p++);
 std::cout << std::format("TLS Remaining Record Size: {}\n", tls_remaining_record_size);
 std::cout << std::format("TLS Middlebox Major Version: {}\n", *p++);
 std::cout << std::format("TLS Middlebox Minor Version: {}\n", *p++);
 std::cout << std::format("TLS Client Random: {}\n", stl::cvt::to_hex_string(std::span{p, 32}));
 p += 32;
 u08 const session_id_size = *p++;
 std::cout << std::format("TLS Session ID Size (bytes): {}\n", session_id_size);
 std::span const session_id{ p, static_cast<std::size_t>(session_id_size) };
 p += std::size(session_id);
 std::cout << std::format("TLS Session ID: {}\n", stl::cvt::to_hex_string(session_id));
 std::span const ciphers{ p + 2, static_cast<std::size_t>((*p++ << 8) + *p++) };
 p += std::size(ciphers);
 std::cout << std::format("TLS Cipher Count: {}\n", std::size(ciphers) >> 1);
 bool TLS_AES_128_GCM_SHA256_supported = false;
 for (std::size_t i = 0; i < (std::size(ciphers) >> 1); ++i) {
  u16 const cipher = (ciphers[i * 2] << 8) + ciphers[i * 2 + 1];
  if (cipher == 0x1301) {
   TLS_AES_128_GCM_SHA256_supported = true;
  }
  std::cout << std::format("- Cipher #{}: {}\n", i, cipher);
 }
 u08 const compression_method_count = *p++;
 std::span const compression_methods{ p, compression_method_count };
 p += std::size(compression_methods);
 std::cout << std::format("TLS Compression Method Count: {}\n", compression_method_count);
 for (std::size_t i = 0; i < compression_method_count; ++i) {
  std::cout << std::format("- Compression Method: {}\n", compression_methods[i]);
 }
 u16 const extension_size_total = (*p++ << 8) + *p++;
 std::cout << std::format("TLS Total Extension Size (bytes): {}\n", extension_size_total);
 auto const extensions_end = p + extension_size_total;
 while (p < extensions_end) {
  net::tls_extension const extension_type = static_cast<net::tls_extension>((*p++ << 8) + *p++);
  auto const extension_type_str = net::lookup_enum(extension_type);
  std::cout << std::format("- Extension Type: {}\n", std::size(extension_type_str) != 0 ? extension_type_str : std::format("Unknown Extension ({})", (static_cast<u64>(extension_type))));
  u16 const extension_size = (*p++ << 8) + *p++;
  std::cout << std::format("- Extension Size: {}\n", extension_size);
  switch (extension_type) {
  case net::tls_extension::server_name: {
   u16 const sni_extension_size = (*p++ << 8) + *p++;
   auto sni_end = p + sni_extension_size;
   while (p < sni_end) {
    u08 const sni_record_type = *p++;
    switch (sni_record_type) {
    case 0x00: {
     std::cout << "-- SNI Record Type: Hostname\n";
     u16 const sni_hostname_size = (*p++ << 8) + *p++;
     std::string_view const sni_hostname{ reinterpret_cast<char*>(p), sni_hostname_size };
     p += sni_hostname_size;
     std::cout << std::format("-- SNI Hostname: {}\n", sni_hostname);
     break;
    }
    default: {
     std::cout << std::format("SNI Record Type: Unknown ({})\n", static_cast<u64>(sni_record_type));
     break;
    }
    }
   }
   break;
  }
  case net::tls_extension::supported_groups: {
   std::span const supported_groups{ p + 2, static_cast<std::size_t>((*p++ << 8) + *p++) };
   p += std::size(supported_groups);
   for (std::size_t i = 0; i < (std::size(supported_groups) >> 1); ++i) {
    net::tls_supported_group const supported_group = static_cast<net::tls_supported_group>((supported_groups[i << 1] << 8) + supported_groups[(i << 1) + 1]);
    auto const supported_group_str = net::lookup_enum(supported_group);
    std::cout << std::format("-- Supported Group: {}\n", std::size(supported_group_str) != 0 ? supported_group_str : std::format("Unknown ({})", static_cast<u64>(supported_group)));
   }
   break;
  }
  case net::tls_extension::ec_point_formats: {
   u08 const ec_point_formats_extension_size = *p++;
   auto ec_point_formats_extension_end = p + ec_point_formats_extension_size;
   while (p < ec_point_formats_extension_end) {
    u08 const ec_point_format = *p++;
    switch (ec_point_format) {
    case 0x00: {
     std::cout << "-- EC Point Format: Uncompressed\n";
     break;
    }
    default: {
     std::cout << std::format("-- EC Point Format: Unknown ({})\n", ec_point_format);
     break;
    }
    }
   }
   break;
  }
  case net::tls_extension::signature_algorithms: {
   //if not present, abort connection
   std::span const signature_algorithms{ p + 2, static_cast<std::size_t>((*p++ << 8) + *p++) };
   p += std::size(signature_algorithms);
   for (std::size_t i = 0; i < (std::size(signature_algorithms) >> 1); ++i) {
    net::tls_signature_algorithm const signature_algorithm = static_cast<net::tls_signature_algorithm>((signature_algorithms[i << 1] << 8) + signature_algorithms[(i << 1) + 1]);
    auto const signature_algorithm_str = net::lookup_enum(signature_algorithm);
    std::cout << std::format("-- Signature Algorithm: {}\n", std::size(signature_algorithm_str) != 0 ? signature_algorithm_str : std::format("Unknown ({})", static_cast<u64>(signature_algorithm)));
   }
   break;
  }
  case net::tls_extension::supported_versions: {
   std::span const supported_versions{ p + 1, static_cast<std::size_t>(*p++) };
   p += std::size(supported_versions);
   for (std::size_t i = 0; i < std::size(supported_versions) >> 1; ++i) {
    u08 const major = supported_versions[i << 1]; /* TLS is assumed */
    u08 const minor = supported_versions[(i << 1) + 1];
    switch (minor) {
    case 1: {
     std::cout << "-- TLS Version 1.0\n";
     break;
    }
    case 2: {
     std::cout << "-- TLS Version 1.1\n";
     break;
    }
    case 3: {
     std::cout << "-- TLS Version 1.2\n";
     break;
    }
    case 4: {
     std::cout << "-- TLS Version 1.3\n";
     break;
    }
    default: {
     std::cout << std::format("-- TLS Version: Unknown ({})\n", stl::cvt::to_hex_string(std::span{&supported_versions[i << 1], 2}));
     break;
    }
    }
   }
   break;
  }
  case net::tls_extension::key_share: {
   u16 const key_share_extension_size = (*p++ << 8) + *p++;
   std::cout << std::format("-- Key Share Extension Size: {}\n", key_share_extension_size);
   auto const key_share_end = p + key_share_extension_size;
   while (p < key_share_end) {
    net::tls_supported_group const key_share_type = static_cast<net::tls_supported_group>((*p++ << 8) + *p++); 
    auto const key_share_type_str = net::lookup_enum(key_share_type);
    std::cout << std::format("--- Key Share Type: {}\n", std::size(key_share_type_str) != 0 ? key_share_type_str : std::format("Unknown ({})", static_cast<u64>(key_share_type)));
    u16 const key_share_size = (*p++ << 8) + *p++;
    std::cout << std::format("--- Key Share Size: {}\n", key_share_size);
    switch (key_share_type) {
    case net::tls_supported_group::secp256r1: {
     u08 const point_format = *p++;
     switch (point_format) {
     case 0x04: {
      std::cout << "---- Point Format: Uncompressed\n";
      break;
     }
     default: {
      std::cout << std::format("---- Point Format: Unknown ({})\n", static_cast<u64>(point_format));
      break;
     }
     }
     std::span const x_coord{ p, 32 };
     std::span const y_coord{ p + 32, 32 };
     p += 64;
     std::cout << std::format("---- X: {}\n", stl::cvt::to_hex_string(x_coord));
     std::cout << std::format("---- Y: {}\n", stl::cvt::to_hex_string(y_coord));
     break;
    }
    default: {
     p += key_share_size;
     break;
    }
    }
   }
   break;
  }
  default: {
   p += extension_size;
   break;
  }
  }
 }
}