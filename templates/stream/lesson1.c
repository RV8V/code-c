#include <stdio.h>
#include <stdlib.h>

#if 0
code that will not be executed, to hide code or long comment
some code that do not work
#endif

int main() {
  unsigned char i = 'a';

  printf("%I64ld\n", 28489298891);
  //printf("divide: %d\n", 10 : 2);
  short int k = 1;
  while(k) {
    printf("%d\n", k);
    k--;
  }

  char a = 'A';
  while(a--)
    printf("value: %d\n", a);

  printf("1 = %d\n", !'a');

  int f = 0;
  int arr[10] = {}; // trash, not 0
  do printf("%d\n", arr[i]); while(f++ < 10);

  exit(0);
}
