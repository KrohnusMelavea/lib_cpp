#pragma once

#include "types.hpp"
#include "stl/bit/rotate.hpp"
#include "stl/bit/reverse.hpp"
#include <bit>
#include <span>
#include <array>

namespace crypto {
 inline constexpr std::size_t calculate_adjusted_block_size(std::size_t const size) noexcept {
  return ((size << 3) + 72 + 512 - (((size << 3) + 72) % 512)) >> 3;
 }
 inline constexpr std::array<u32, 64> constants {
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
 };

 consteval std::array<u32, 8> ct_gen_sha256_impl(std::span<u08 const> const data) noexcept {
  std::size_t const adjusted_block_size = calculate_adjusted_block_size(std::size(data));
   auto const block = new u08[adjusted_block_size]{};
   u32 i = 0;
   for (i = 0; i + 4 <= std::size(data); i += 4) {
    block[i + 3] = data[i + 0];
    block[i + 2] = data[i + 1];
    block[i + 1] = data[i + 2];
    block[i + 0] = data[i + 3];
   }
   u32 const diff = static_cast<u32>(std::size(data)) - i;
   switch (diff) {
   case 0: {
    block[i + 0] = 0;
    block[i + 1] = 0;
    block[i + 2] = 0;
    block[i + 3] = 1 << 7;
    break;
   }
   case 1: {
    block[i + 0] = 0;
    block[i + 1] = 0;
    block[i + 2] = 1 << 7;
    block[i + 3] = data[i + 0];
    break;
   }
   case 2: {
    block[i + 0] = 0;
    block[i + 1] = 1 << 7;
    block[i + 2] = data[i + 1];
    block[i + 3] = data[i + 0];
    break;
   }
   case 3: {
    block[i + 0] = 1 << 7;
    block[i + 1] = data[i + 2];
    block[i + 2] = data[i + 1];
    block[i + 3] = data[i + 0];
    break;
   }
   }

   (void)std::fill_n(block + i + 4, adjusted_block_size - i - 12, 0); 

   auto const size = stl::bit::reverse(std::size(data) << 3);
   auto const bytes = std::bit_cast<std::array<u08, 8>>(size);
   block[adjusted_block_size - 8 + 3] = bytes[0];
   block[adjusted_block_size - 8 + 2] = bytes[1];
   block[adjusted_block_size - 8 + 1] = bytes[2];
   block[adjusted_block_size - 8 + 0] = bytes[3];
   block[adjusted_block_size - 8 + 7] = bytes[4];
   block[adjusted_block_size - 8 + 6] = bytes[5];
   block[adjusted_block_size - 8 + 5] = bytes[6];
   block[adjusted_block_size - 8 + 4] = bytes[7];

   u32 hash[8] { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
   u32 work[8] {};
   u32 schedule[64]{};
   for (std::size_t i = 0; i < std::size(data); i += 64) {
    for (std::size_t j = 0; j < 16; ++j) {
     schedule[j] = std::bit_cast<u32>(std::array<u08, 4>{ block[i + j*4 + 0], block[i + j*4 + 1], block[i + j*4 + 2], block[i + j*4 + 3] });
    }

    for (u32 j = 16; j < 64; ++j) {
     auto const a0 = stl::bit::rotate_right(schedule[j - 15],  7);
     auto const a1 = stl::bit::rotate_right(schedule[j - 15], 18);
     auto const a2 = (schedule[j - 15] >> 3);
     auto const a = a0 ^ a1 ^ a2;
     auto const b0 = stl::bit::rotate_right(schedule[j -  2], 17);
     auto const b1 = stl::bit::rotate_right(schedule[j -  2], 19);
     auto const b2 = (schedule[j -  2] >> 10);
     auto const b = b0 ^ b1 ^ b2;
     schedule[j] = 
      schedule[j - 16] +
      a +
      schedule[j -  7] +
      b;
    }

    (void)std::copy_n(hash, 8, work);
    for (u32 j = 0; j < 64; ++j) {
     auto const s00 = stl::bit::rotate_right(work[0], 2);
     auto const s01 = stl::bit::rotate_right(work[0], 13);
     auto const s02 = stl::bit::rotate_right(work[0], 22);
     auto const s10 = stl::bit::rotate_right(work[4], 6);
     auto const s11 = stl::bit::rotate_right(work[4], 11);
     auto const s12 = stl::bit::rotate_right(work[4], 25);
     auto const maj = (work[0] & work[1]) ^ (work[0] & work[2]) ^ (work[1] & work[2]);
     auto const ch = (work[4] & work[5]) ^ ((~work[4]) & work[6]);
     auto const s1 = s10 ^ s11 ^ s12;
     auto const s0 = s00 ^ s01 ^ s02;
     auto const temp1 = work[7] + s1 + ch + constants[j] + schedule[j];
     auto const temp2 = s0 + maj;

     u32 const new_work[8] {
      temp1 + temp2,
      work[0],
      work[1],
      work[2],
      work[3] + temp1,
      work[4],
      work[5],
      work[6]
     };

     (void)std::copy_n(new_work, 8, work);
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
   delete[] block;
   return {
    stl::bit::reverse(hash[0]),
    stl::bit::reverse(hash[1]),
    stl::bit::reverse(hash[2]),
    stl::bit::reverse(hash[3]),
    stl::bit::reverse(hash[4]),
    stl::bit::reverse(hash[5]),
    stl::bit::reverse(hash[6]),
    stl::bit::reverse(hash[7])
   };
  }
  inline std::array<u32, 8> gen_sha256_impl(std::span<u08 const> const data) noexcept {
   std::size_t const adjusted_block_size = calculate_adjusted_block_size(std::size(data));
   auto const block = new u08[adjusted_block_size]{};
   u32 i = 0;
   for (i = 0; i + 4 <= std::size(data); i += 4) {
     u32 data_raw;
     data_raw = stl::bit::reverse(*reinterpret_cast<u32*>(std::memcpy(&data_raw, &data[i], 4)));
     std::memcpy(block + i, &data_raw, 4);
   }
   u32 const diff = static_cast<u32>(std::size(data)) - i;
   switch (diff) {
   case 0: {
    block[i + 0] = 0;
    block[i + 1] = 0;
    block[i + 2] = 0;
    block[i + 3] = 1 << 7;
    break;
   }
   case 1: {
    block[i + 0] = 0;
    block[i + 1] = 0;
    block[i + 2] = 1 << 7;
    block[i + 3] = data[i + 0];
    break;
   }
   case 2: {
    block[i + 0] = 0;
    block[i + 1] = 1 << 7;
    block[i + 2] = data[i + 1];
    block[i + 3] = data[i + 0];
    break;
   }
   case 3: {
    block[i + 0] = 1 << 7;
    block[i + 1] = data[i + 2];
    block[i + 2] = data[i + 1];
    block[i + 3] = data[i + 0];
    break;
   }
   }

   (void)std::memset(block + i + 4, 0, adjusted_block_size - i - 4 - 8);

   auto const size = stl::bit::reverse(std::size(data) << 3);
   u32 a[2];
   (void)std::memcpy(a, &size, 8);
   a[0] = stl::bit::reverse(a[0]);
   a[1] = stl::bit::reverse(a[1]);
   (void)std::memcpy(block + adjusted_block_size - 8, a, 8);

   u32 hash[8] { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
   u32 work[8] {};
   u32 schedule[64]{};
   for (std::size_t i = 0; i < std::size(data); i += 64) {
    for (std::size_t j = 0; j < 16; ++j) {
     schedule[j] = std::bit_cast<u32>(std::array<u08, 4>{ block[i + j*4 + 0], block[i + j*4 + 1], block[i + j*4 + 2], block[i + j*4 + 3] });
    }
    (void)std::memcpy(schedule, block + i, 64);
    for (u32 j = 16; j < 64; ++j) {
     auto const a0 = stl::bit::rotate_right(schedule[j - 15],  7);
     auto const a1 = stl::bit::rotate_right(schedule[j - 15], 18);
     auto const a2 = (schedule[j - 15] >> 3);
     auto const a = a0 ^ a1 ^ a2;
     auto const b0 = stl::bit::rotate_right(schedule[j -  2], 17);
     auto const b1 = stl::bit::rotate_right(schedule[j -  2], 19);
     auto const b2 = (schedule[j -  2] >> 10);
     auto const b = b0 ^ b1 ^ b2;
     schedule[j] = schedule[j - 16] + a + schedule[j -  7] + b;
    }

    (void)std::memcpy(work, hash, 32);
    for (u32 j = 0; j < 64; ++j) {
     auto const s00 = stl::bit::rotate_right(work[0], 2);
     auto const s01 = stl::bit::rotate_right(work[0], 13);
     auto const s02 = stl::bit::rotate_right(work[0], 22);
     auto const s10 = stl::bit::rotate_right(work[4], 6);
     auto const s11 = stl::bit::rotate_right(work[4], 11);
     auto const s12 = stl::bit::rotate_right(work[4], 25);
     auto const maj = (work[0] & work[1]) ^ (work[0] & work[2]) ^ (work[1] & work[2]);
     auto const ch = (work[4] & work[5]) ^ ((~work[4]) & work[6]);
     auto const s1 = s10 ^ s11 ^ s12;
     auto const s0 = s00 ^ s01 ^ s02;
     auto const temp1 = work[7] + s1 + ch + constants[j] + schedule[j];
     auto const temp2 = s0 + maj;

     u32 const new_work[8] {
      temp1 + temp2,
      work[0],
      work[1],
      work[2],
      work[3] + temp1,
      work[4],
      work[5],
      work[6]
     };
     (void)std::memcpy(work, new_work, 32);
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
   delete[] block;
   return {
    stl::bit::reverse(hash[0]),
    stl::bit::reverse(hash[1]),
    stl::bit::reverse(hash[2]),
    stl::bit::reverse(hash[3]),
    stl::bit::reverse(hash[4]),
    stl::bit::reverse(hash[5]),
    stl::bit::reverse(hash[6]),
    stl::bit::reverse(hash[7])
   };
  }
}