#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_LINES 13
#define FIELD_SIZE 10
#define PLAYER_1 0
#define PLAYER_2 ~PLAYER_1

typedef enum { EMPTY = 0, SHOT, STRIKE, KILL, SHIP, FIELD_INFO_END } fiedInfo;
typedef enum { INIT = 0, DRAW, PROGRESSING, EXIT } gameState;

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

void draw_field(fiedInfo *);
void ship_generate(fiedInfo *);

int main() {
  gameState game_state = INIT;
  unsigned char isRun = 1;
  int player = PLAYER_1;

  fiedInfo p1_data[FIELD_SIZE * FIELD_SIZE] = { EMPTY };
  fiedInfo p2_data[FIELD_SIZE * FIELD_SIZE] = { EMPTY };
  fiedInfo *tmp;

  while(isRun) {
    if (game_state == INIT) {
      ship_generate(p1_data);
      ship_generate(p2_data);
      p1_data[0] = KILL;
      game_state = DRAW;
    }
    if (game_state == DRAW) {
      system("clear");
      tmp = player == PLAYER_1 ? p1_data : p2_data;
      draw_field(tmp);
      game_state = PROGRESSING;
      getchar();
    }
    if (game_state == PROGRESSING) {
      player = ~player;
      game_state = DRAW;
    }
    if (game_state == EXIT) {}
  }
  return 0;
}

void draw_field(fiedInfo *p_data) {
  int i = 0;
  do fprintf(stdout, "%s\n", field[i]);
  while(i++ < 1);

  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%c%c", field[i + 2][0], field[i + 2][2]);
    for (int j = 0; j < FIELD_SIZE; j++)
      fprintf(stdout, "%c", draw_symbol[p_data[i * FIELD_SIZE + j]]);

    for (int j = 12; j < 20; j++)
      fprintf(stdout, "%c", field[i + 2][j]);
    for (int j = 0; j < FIELD_SIZE; j++)
      fprintf(stdout, " ");
    fprintf(stdout, "%c\n", field[i + 2][30]);
  }
  fprintf(stdout, "%s\n", field[N_LINES - 1]);
}

void ship_generate(fiedInfo *p_data) {
  srand(time(NULL));  /*i * n + j*/
  for (int i = 0; i < 10; i++)
    p_data[i + FIELD_SIZE + (rand() % 10) + 1] = SHIP;
}
