#include <stdio.h>

void print_str(const char *);
void print_chars(const char *);
void print_uint32_arr(const unsigned int *, unsigned int len);

void sum_f(float, float, float *);
void div_f(float, float, float *);

int main(int argc, char const *argv[]) {
  unsigned int *print_str_addr;
  print_str_addr = (unsigned int *)(&print_str);
  printf("%p\n", (unsigned int *)(&print_str_addr));

  void (*print_str_new)(const char *c_str);
  print_str_new = (void *)print_str_addr;
  print_str_new("hello world");

  void (*print_str_next)(const char *);
  print_str_next = (void *)(&print_str);
  (*print_str_next)("hello world");

  void (*print_str_next_test)(const char *) = (void *)(&print_str);

  void (*fns_arr[4])(float, float, float *) = { sum_f, div_f };

  float i = 2, a = 2., b = 3., res = 0.;
  do {
    (*fns_arr)(a, b, &res);
    fns_arr++;
  } while((int)i-- > 0);

  return 0;
}

void print_str_next(const char *c_str) {}
void print_str_new(const char *c_str) {}
void print_str_next_test(const char *c_str) {}

void print_str(const char *c_str) {
  printf("%s\n", c_str);
}

void print_chars(const char *a) {}
void print_uint32_arr(const unsigned int *a, unsigned int len) {}

void sum_f(float a_f, float b_f, float *sum_f) {
  *sum_f = a_f + b_f;
}

void div_f(float a_f, float b_f, float *div_f) {
  *div_f = a_f / b_f;
}
