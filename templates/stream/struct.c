#include <stdio.h>
#include <string.h>

struct Test {
  char name[20];
};

struct Test fn(void);

int main(int argc, char const *argv[]) {
  struct Test test_struct = fn();
  return 0;
}

struct Test fn() {
  struct Test test;
  strcpy(test.name, "hello");
  return test;
}
