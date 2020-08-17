#include <stdio.h>
#include <stdlib.h>

void foo_a(void);
void foo_b(void);
void foo_c(void);

unsigned int test_a(unsigned int, int);
unsigned int test_b(unsigned int, int);

typedef int *pint;
typedef void (*pfn_v)(void);
typedef unsigned int (*pfn_s_i)(unsigned int, int);

int main(int argc, char const *argv[]) {
  pint pa, pb, pc;
  pfn_v pf_arr[3];
  pfn_s_i pf_s_i_arr[2];

  pf_s_i_arr[0] = &test_a;
  pf_s_i_arr[1] = &test_b;

  char i = sizeof(pf_s_i_arr) / sizeof(pfn_s_i);
  do printf("%d\n", (*pf_s_i_arr[i])(i, argc));
  while(i-- > 0);

  pf_arr[0] = &foo_a;
  pf_arr[1] = &foo_b;
  pf_arr[2] = &foo_c;

  char g = sizeof(pf_arr) / sizeof(pfn_v);
  do
    printf("pointer to an each element in arr: %p\n", (*pf_arr)++);
  while(g-- > 0);

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

void foo_a(void) {
  printf("%s\n", __FUNCTION__);
}

void foo_b(void) {
  printf("%s\n", __FUNCTION__);
}

void foo_c(void) {
  printf("%s\n", __FUNCTION__);
}

unsigned int test_a(unsigned int a, int argc) {
  return a + argc;
}

unsigned int test_b(unsigned int b, int argc) {
  return b + argc;
}
