#include <stdio.h>

void print_str(const char *);
void print_chars(const char *);
void print_uint32_arr(const unsigned int *, unsigned int len);

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

  return 0;
}

void print_str_next(const char *c_str) {}
void print_str_new(const char *c_str) {}

void print_str(const char *c_str) {
  printf("%s\n", c_str);
}

void print_chars(const char *a) {}
void print_uint32_arr(const unsigned int *a, unsigned int len) {}
