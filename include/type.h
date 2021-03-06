#pragma once
#include <cstdint>
#include <iostream>
namespace naive_crypto {
  using i32 = int32_t;
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;
  using i128 = __int128_t;
  using u128 = __uint128_t;
  std::ostream & operator<<(std::ostream & os, u128);
}