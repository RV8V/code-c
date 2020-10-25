#include <stdio.h>
#include <stdbool.h>

// this value 'MAX_STRING_LENGTH' will be thrown away because of no usage by preprocessor
#define MAX_STRING_LENGTH 100

#define SIZE_OF_MEMORY
#define IS_64_BYTES_PER_TAKT
#define OS_WINDOWS

int sum(int, int);

int main(void) {
  #ifdef defined(OS_WINDOWS)
    printf("%s\n", "it will be printed, but value to OS_WINDOWS was not assigned");
    //win_print()
  #else //lin_print()

  #ifdef IS_64_BYTES_PER_TAKT
    // loadin config fot this operation system
  #else //...

  #ifdef SIZE_OF_MEMORY == 32
    //...
  #else //...
  #endif

  bool flag = false;
  if (flag = true)
    printf("%s\n", "it will be executed");

  double val1 = 10.2f;
  double test1 = 9139.3131;

  float test2 = test1;
  float val2 = val1;

  {
    const char value = 10;
    printf("%s\n", "internal scope");
  }

  printf("result: %d\n", sum(10, 20));
}

int sum(int a, int b) {
  return a + b;
}
