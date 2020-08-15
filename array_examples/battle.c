#include <stdio.h>
#include <stdlib.h>

#define N_LINES 13

char *field[] = {
  "   ABCDEFGHIJ       ABCDEFGHIJ ",
  "  *----------*     *----------*",
  "0 |          |   0 |          |",
  "1 |          |   1 |          |",
  "2 |          |   2 |          |",
  "3 |          |   3 |          |",
  "4 |          |   4 |          |",
  "5 |          |   5 |          |",
  "6 |          |   6 |          |",
  "7 |          |   7 |          |",
  "8 |          |   8 |          |",
  "9 |          |   9 |          |",
  "  *----------*     *----------*"
};

int main() {
  for (int i = 0; i < N_LINES; i++)
    printf("%s\n", field[i]);
  return 0;
}
