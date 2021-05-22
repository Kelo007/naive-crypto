#include <cassert>
#include <vector>
#include "type.h"
#include "prime.h"

using test_fn = void (*)();
void test_prime() {
  using namespace native_crypto;

  assert(gcd(1, 1) == 1);
  assert(gcd(2, 3) == 1);
  assert(gcd(3, 6) == 3);
  assert(gcd(30, 24) == 6);
  assert(native_crypto::rand() >= 0);
  assert(add_mod(100, 2, 2000) == 102);
  assert(add_mod(4574937543, 238479234, 1000007) == 383086);
  assert(multiply_mod(2, 3, 2) == 0);
  assert(multiply_mod(98504204, 3423423423, 2333) == 502);
  assert(power_mod(2, 3, 5) == 3);
  assert(power_mod(342, 100, 23333) == 2939);
  assert(miller_rabin(2) == true);
  assert(miller_rabin(19) == true);
  assert(miller_rabin(120) == false);
  assert(miller_rabin(u64(1e9 + 7)) == true);
  assert(miller_rabin(u64(1e9 + 11)) == false);
}

int main() {
  std::vector<test_fn> fns = {test_prime};
  for (const auto & fn: fns) {
    fn();
  }
  return 0;
}