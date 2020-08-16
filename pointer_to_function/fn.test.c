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

int main(int argc, char const *argv[]) {
  void (*pf)();
  pf = &foo_a;
  (*pf)();

  pf = &foo_b;
  (*pf)();

  pf = &foo_c;
  (*pf)();
  return 0;
}
