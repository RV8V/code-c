#include "main.h"
#include "example.test.h"
#include "limits.h"
#include "different.h"

int main(int argc, char const *argv[]) {
  char *s2 = "hello, world", s1[15];
  strcopy_c(s1, s2);
  puts(s1);

  short int i = 0;
  do {
    print_size_of_types();
    example_test();
  } while(i == 0);
  return 0;
}
