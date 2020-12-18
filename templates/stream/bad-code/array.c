#include <stdio.h>

int main(void) {
  int arr[10] = { [0 ... 4] = 5, [6 ... 9] = 7 };
  int i = 0;
  for (; i < 10; ++i)
    printf("value: %d, index -> %d\n", arr[i], i);
}
