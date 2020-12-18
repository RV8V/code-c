#include <stdio.h>

int main(void) {
  char arr[3] = { 1, 2, 3 };
  //arr[3] = 4; aborted (core dump)
  printf("arr[3] = %d\n\n", arr[3]);

  int array[10];
  char i = 10; // random 40 bytes in memory (every time is different values in elements)
  do printf("array[%d] = %d\n", i, array[i]);
  while(i-- > 0);

  char *str = "he\0llo";
  // char str[] = "he\0llo"; (also is used)
  printf("string will be trimmed to 'he': %s\n", str);

  char *string = "hello world";
  //string[2] = 0; (programm is crash)
  /*while(*string != 0) {
    if (*string == ' ') *string = 0;
    if (*string == 0) break;
    printf("%c", *string++);
  }*/

  /*int j = 0;
  while(string[j] != 0)
    printf("%c", string[j++]);
  printf("\n");*/

  char s[] = "hello!\0";
  s[6] = 'e';
  int k = 0;
  while(s[k] != 0)
    printf("%c", s[k]++);
  printf("\n\n");

  char st[] = "hello!\0";
  st[6] = 'e';
  printf("%s\n", st);
}
