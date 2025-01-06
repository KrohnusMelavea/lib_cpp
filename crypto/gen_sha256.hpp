#pragma once

#include "types.hpp"
#include "stl/bit/rotate.hpp"
#include <span>
#include <array>

namespace crypto {
 inline constexpr std::array<u32, 8> gen_sha256(std::span<u08 const> const data) noexcept {
  static constexpr std::array<u32, 64> constants {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
  };

  std::array<u32, 8> hash { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

  std::size_t const adjusted_block_size = std::size(data) + 512 - (std::size(data) + 65) % 512;
  auto const block = new u08[adjusted_block_size];
  (void)std::memcpy(block, std::data(data), std::size(data));
  block[std::size(data)] = 1 << 7;
  auto const size = std::size(data);
  (void)std::memcpy(block + adjusted_block_size - 8, &size, 8);

  std::array<u32, 64> schedule;
  for (std::size_t i = 0; i < std::size(data); i += 64) {
   if (adjusted_block_size - i >= 512) [[likely]] {
    (void)std::memcpy(std::data(schedule), block + i, 512);
   } else [[unlikely]] {
    (void)std::memcpy(std::data(schedule), block + i, adjusted_block_size - i);
   }

   for (std::size_t j = 16; j < 64; ++j) {
    schedule[i] = 
     schedule[i - 16] +
     (stl::bit::rotate_right(schedule[i - 15],  7) ^ stl::bit::rotate_right(schedule[i - 15], 18) ^ (schedule[i - 15] >>  3)) +
     schedule[i -  7] +
     (stl::bit::rotate_right(schedule[i -  2], 17) ^ stl::bit::rotate_right(schedule[i -  2], 19) ^ (schedule[i -  2] >> 10));
   }

   std::array<u32, 8> work;
   (void)std::copy(std::cbegin(hash), std::cend(hash), std::begin(work));
   
   for (std::size_t j = 0; j < 64; ++j) {
    auto const s1 = stl::bit::rotate_right(work[4], 6) ^ stl::bit::rotate_right(work[4], 11) ^ stl::bit::rotate_right(work[4], 25);
    auto const ch = (work[4] & work[5]) ^ (~work[4] & work[6]);
    auto const temp1 = work[7] + s1 + ch + constants[j] + schedule[j];
    auto const s0 = stl::bit::rotate_right(work[0], 2) ^ stl::bit::rotate_right(work[0], 13) ^ stl::bit::rotate_right(work[0], 22);
    auto const maj = (work[0] & work[1]) ^ (work[0] & work[2]) ^ (work[1] & work[2]);
    auto const temp2 = s0 + maj;
    
    work[7] = work[6];
    work[6] = work[5];
    work[5] = work[4];
    work[4] = work[3] + temp1;
    work[3] = work[2];
    work[2] = work[1];
    work[1] = work[0];
    work[0] = temp1 + temp2;
   }

   hash[0] += work[0];
   hash[1] += work[1];
   hash[2] += work[2];
   hash[3] += work[3];
   hash[4] += work[4];
   hash[5] += work[5];
   hash[6] += work[6];
   hash[7] += work[7];
  }

  return hash;
 }
}