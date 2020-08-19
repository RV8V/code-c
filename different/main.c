#include <stdio.h>
#include "different.h"

int main(int argc, char const *argv[]) {
  char *s2 = "hello, world", s1[15];
  strcopy_c(s1, s2);
  puts(s1);

  return 0;
}
