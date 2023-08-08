#include "adder.h"

namespace zky {
int add(int a, int b) {
  int res = a + b;
  printf("%d + %d = %d\n", a, b, res);
  return res;
}
} // namespace zky