#include <stdio.h>

static void my_counter(void);
static void print_result(char str[]);

int main(int argc, char const *argv[]) {
  auto char ch = 10;
  auto float const f_a = 8.;
  auto float const f_b = 3.;

  if (f_a > f_b) {
    static unsigned char const n = 5;
    printf("char value: %d\n", n);
  } else {
    auto unsigned char const n = 6;
    printf("char value in another block: %d\n", n);
  }

  for (char i = 0; i < 3; i++) {
    for (char j = 0; j < 4; j++) {
      static int n = 0;
      auto int m = 0;
      printf("value n: %d, m: %d\n", n++, m++);
    }
  }

  static char i = 0;
  do {
    register char j = 0;
    do {
      printf("value i: %d, j: %d\n", i, j);
    } while(j++ < 4);
  } while(i++ < 3);

  for (auto char i = 0; i < 10; i++)
    my_counter();

  return 0;
}

static void my_counter() {
  auto char i = 0;
  static char g = 0;
  printf("i = %d, g = %d\n", i++, g++);
}

static void print_result(char str[]) {
  printf("%s %.5f\n", str, res);
}
