#include <stdio.h>
#include <stdlib.h>

#define N_LINES 13
#define FIELD_SIZE 10

typedef enum { EMPTY = 0, SHOT, STRIKE, KILL, SHIP, FIELD_INFO_END } fiedInfo;

char draw_symbol[FIELD_INFO_END] = { ' ', '*', 'x', '#', '&' };

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

void draw_field(void);

int main() {
  draw_field();
  return 0;
}

void draw_field(void) {
  int i = 0;
  do fprintf(stdout, "%s\n", field[i]);
  while(i++ < 1);

  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%c%c", field[i + 2][0], field[i + 2][2]);
    for (int j = 0; j < FIELD_SIZE; j++)
      fprintf(stdout, " ");
    for (int j = 12; j < 20; j++)
      fprintf(stdout, "%c", field[i + 2][j]);
    for (int j = 0; j < FIELD_SIZE; j++)
      fprintf(stdout, " ");
    fprintf(stdout, "%c\n", field[i + 2][30]);
  }
  fprintf(stdout, "%s\n", field[N_LINES - 1]);
}
