#pragma once
#include <cstdlib>
#include "type.h"


namespace naive_crypto {
  template <typename T>
  T gcd(const T &a, const T &b) {
    if (b == 0) {
      return a;
    } else {
      return gcd(b, a % b);
    }
  }

  u64 rand();
  u64 add_mod(u64, u64, u64);
  u64 multiply_mod(u64, u64, u64);
  u64 power_mod(u64, u64, u64);
  bool miller_rabin(u64);
  u64 generate_prime();
  u128 exgcd(u128, u128, u128 &, u128 &);
  u128 reverse(u128, u128);
}



