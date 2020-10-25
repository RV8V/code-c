#include <stdio.h>
/*    correct .h file    */ /*
#ifndef WHILE_LOOP_H
#define WHILE_LOOP_H

void do_while_example(void);

#endif // WHILE_LOOP_H
*/

int main() {
  printf("%c\n", 7);
  int i = 0;
  do printf("ascii value: #%d -> %c\n", i, i);
  while(i++ < 256);

  printf("line: %d\nfunction: %s\nfile: %s\n", __LINE__, __FUNCTION__, __FILE__);
  // /*(cpp lesson6.c)*/ __LINE__, __FUNCTION__, __FILE__;
  return 0;
}
