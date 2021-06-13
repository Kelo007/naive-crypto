#include <iostream>
#include "type.h"

std::ostream & naive_crypto::operator<<(std::ostream & os, naive_crypto::u128 x) {
  static int tmp[150];
  tmp[0] = 0;
  while (x) {
    tmp[++tmp[0]] = x % 10;
    x /= 10;
  }
  for (int i = tmp[0]; i >= 1; --i) {
    os << tmp[i];
  }
  return os;
}
