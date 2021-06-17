#include <iostream>
#include <cstring>
#include "prime.h"
#include "type.h"
using namespace naive_crypto;
const int MAX_LENGTH = 1024 * 1024;
char message[MAX_LENGTH];
char encryption[MAX_LENGTH];
char decryption[MAX_LENGTH];
int main() {
  srand(time(NULL));
  u128 p = generate_prime();
  u128 q = generate_prime();
  u128 n = p * q;
  u128 phi = (p - 1) * (q - 1);
  u128 d, e;
  std::cout << "p = " << p << ", q = " << q << std::endl;
  std::cout << "n = " << n << ", phi = " << phi << std::endl;
  while (true) {
    e = generate_prime();
    if (gcd(e, phi) == 1) {
      break;
    }
  }
  d = reverse(e, phi);
  std::cout << "e = " << e << ", d = " << d << std::endl;
  std::cout << "Please input message to be encrypted: ";
  std::cin.getline(message, MAX_LENGTH);
  int len = strlen(message);
  // 32 bit
  for (int i = 0; i < len; i += 4) {
    u32 x = *((u32 *)(&message[i]));
    u64 y = power_mod(x, e, n);
    u64 z = power_mod(y, d, n);
    // std::cout << "x, y, z =  " << x << ", " << y << ", " << z << std::endl;
    *((u64 *)(&encryption[i * 2])) = y;
    *((u32 *)(&decryption[i])) = z;
  }
  std::cout << "The encryption is: ";
  for (int i = 0; i < len; i += 4) {
    std::cout << *((u64 *)(&encryption[i * 2]));
  }
  std::cout << std::endl;
  std::cout << "The decryption is: " << decryption << std::endl;
  return 0;
}