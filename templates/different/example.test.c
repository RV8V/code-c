#include "example.test.h"

void example_test() {
  char c = 0, i = 0, str[SIZE];
  int *string = calloc(LIM - 1, sizeof(int));
  for (short int i = 0; i < LIM - 1 && (c = getchar()) != EOF && c != '\n'; ++i, string++)
    str[i] = c, *string = c;
  for (short int i = 0; i < LIM - 1; i++, printf("%d\n", *string++));
  do; while(printf("%d,\n", *string++), i-- > 0);
  free(string);
}
