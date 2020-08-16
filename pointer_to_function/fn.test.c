#include <stdio.h>
#include <stdlib.h>

void foo_a() {
  printf("%s\n", __FUNCTION__);
}

void foo_b() {
  printf("%s\n", __FUNCTION__);
}

void foo_c() {
  printf("%s\n", __FUNCTION__);
}

typedef int *pint;
typedef void (*pfn_v)();

int main(int argc, char const *argv[]) {
  pint pa, pb, pc;
  printf("%p-%p-%p\n", &pa, &pb, &pc);

  pfn_v a, b, c;
  a = &foo_a, b = &foo_b, c = &foo_c;

  (*a)(), (*b)(), (*c)();

  void (*ps)() = &foo_a;
  ps();

  void (*pf)();
  pf = &foo_a;
  (*pf)();

  pf = &foo_b;
  (*pf)();

  pf = &foo_c;
  (*pf)();
  return 0;
}
