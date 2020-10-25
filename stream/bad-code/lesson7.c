#include <stdio.h>
#include <stdbool.h>

void fnWithoutVoid() {}
void fnWithVoid(void) {}

int main(void) {
  fnWithVoid(/*no value shoud be passed in here*/);
  //fnWithVoid(false); error here

  const char letter = 'A';
  printf("value of letter A is: %d\n", letter);

  // this is true (because of data types -> приведение к одному типа данных)
  if (65 == 'A') printf("ascii value and char representation are equal\n");

  fnWithoutVoid(1, 2, "3");
  fnWithoutVoid(true);
  fnWithoutVoid();
  /*
  char a = 0, b = 0;
  a && b && {
    printf("%s\n", "from bash I used this");
  }
  */
  return 0;
}
