#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("args count: %d\n", argc);
  printf("%p\n%p\n", argv, *argv);
  for (int i = 0; i < argc; i++)
    printf("%d: %s\n", i, *argv + i);

  return 0;
}
