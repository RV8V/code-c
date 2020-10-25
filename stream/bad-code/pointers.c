#include <stdio.h>

void test(int *a, int *b) {
  *a = 100;
  *b = 200;
}

int main(void) {
  int a = 10;
  int b = 20;
  test(&a, &b);
  printf("%d - %d\n", a, b);

  short arr[3];

  printf("%p\n", &arr[0]);
  printf("%p\n", &arr[1]);
  printf("%p\n\n", &arr[2]);

  int number = 0x10203040;
  char *pointer = (char *)&number;
  pointer = pointer + 3;
  *pointer = 0x21;
  printf("%#x\n\n", number);

  short num = 102;
  char *point = (char *)&num;
  int i = 4;
  do printf("%p\n", point++);
  while(i-- > 0);
}
