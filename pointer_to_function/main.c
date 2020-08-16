#include <stdio.h>
#include <stdlib.h>

void foo_a() {
  printf("%s\n", __FUNCTION__);
}

int main(int argc, char const *argv[]) {
  void (*pf)() = &foo_a;
  pf();
  (*pf)();
  return 0;
}
