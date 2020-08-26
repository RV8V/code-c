#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int a = 0xFE340056;
  printf("value a is: \t\t0x%08X\n", a);

  unsigned int *p_a = &a;
  printf("value p_a is: \t\t0x%08d\n", (unsigned int)p_a);
  printf("value *p_a is: \t\t0x%08d\n", *p_a);
  *p_a = 0xEF222222;
  unsigned char uch[10] = { 0x33, 0x64, 0x65, 0x88, 0x32 };
  printf("value uch is: \t\t0x%08d\n", (unsigned int)uch);

  unsigned int **p_p_a;
  p_a = &a;
  p_p_a = &p_a;
  printf("p_p_a: \t\t%p\n", p_p_a);
  printf("p_a: \t\t%p\n", p_a);
  printf("*p_a: \t\t%d\n", *p_a);
  printf("**p_p_a: \t\t%d\n", **p_p_a);

  **p_p_a = 0xB2182490;
  printf("%d\n", a);

  return 0;
}
