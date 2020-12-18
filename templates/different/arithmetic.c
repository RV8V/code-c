#include <stdio.h>

enum { ONE = 0, TWO, THREE, END };

int main(int argc, char const *argv[]) {
  static unsigned int i_a[END] = { 0xfe34, 0xab34, 0xac57 };
  unsigned int *i_a0 = &i_a[ONE];
  unsigned int *i_a2 = &i_a[TWO];

  unsigned int m, n = i_a2 - i_a0;
  printf("value: %lu\n", sizeof(unsigned int) * n);
  n = *++i_a0;
  printf("pre increment *++: \t0x%x\n", n);
  m = ++*i_a0;
  printf("++*: increment: \t0x%x\n", m);
  m = *(i_a0)++;
  printf("post increment (*)++: \t0x%x\n", m);
  m = *i_a0++;
  printf("post increment ++*: \t0x%x\n", m);
  printf("value: 0x%x\n", *(unsigned char *)i_a2++);
  return 0;
}
