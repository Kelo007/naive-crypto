#include "type.h"
#include "prime.h"

namespace native_crypto {
  u64 rand() {
    return (u64(::rand()) << 32) + std::rand();
  }
  u64 add_mod(u64 a, u64 b, u64 mod) {
    return (u128(a) + b) % mod;
  }
  u64 multiply_mod(u64 a, u64 b, u64 mod) {
    return (u128(a) * b) % mod;
  }
  u64 power_mod(u64 a, u64 b, u64 mod) {
    u64 ans = 1;
    while (b) {
      if (b & 1) ans = u128(ans) * a % mod;
      a = u128(a) * a % mod;
      b >>= 1;
    }
    return ans;
  }
  namespace {
    const int test_case_size = 12;
    const u64 test_cases[test_case_size] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    bool _miller_rabin(u64 prime, u64 base) {
      u64 number = prime - 1;
      for (; ~number & 1; number >>= 1)
        continue;
      u64 result = power_mod(base, number, prime);
      for (; number != prime - 1 && result != 1 && result != prime - 1; number <<= 1)
        result = multiply_mod(result, result, prime);
      return result == prime - 1 || (number & 1) == 1;
    }
  }
  bool miller_rabin(u64 prime) {
    if (prime < 2)
      return false;
    if (prime < 4)
      return true;
    if (~prime & 1)
      return false;
    for (int i = 0; i < test_case_size && test_cases[i] < prime; ++i)
      if (!_miller_rabin(prime, test_cases[i]))
        return false;
    return true;
  }
}
