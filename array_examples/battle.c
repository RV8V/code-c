#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_LINES 13
#define FIELD_SIZE 10
#define PLAYER_1 0
#define PLAYER_2 ~PLAYER_1

#define ARROW_KEY_PRESSED 0xE0
#define KEY_ENTER 13
#define KEY_UP 72
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_DOWN 80

#define TARGET '+'

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

void draw_field(fiedInfo *, unsigned short);
void ship_generate(fiedInfo *);
unsigned char get_target_position(unsigned char *, unsigned char *);

int main() {
  gameState game_state = INIT;
  unsigned char isRun = 1;
  int player = PLAYER_1;

  fiedInfo p1_data[FIELD_SIZE * FIELD_SIZE] = { EMPTY };
  fiedInfo p2_data[FIELD_SIZE * FIELD_SIZE] = { EMPTY };
  fiedInfo *tmp;

  unsigned char target_x = 0, target_y = 0;
  unsigned short shot_position = 0;

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
      draw_field(tmp, shot_position);
      if (get_target_position(&target_x, &target_y)) game_state = PROGRESSING;
      shot_position = (target_y << 8) | target_x;
    }
    if (game_state == PROGRESSING) {
      player = ~player;
      game_state = DRAW;
    }
    if (game_state == EXIT) {}
  }
  return 0;
}

void draw_field(fiedInfo *p_data, unsigned short a_target) {
  int i = 0;
  do fprintf(stdout, "%s\n", field[i]);
  while(i++ < 1);

  unsigned char target_x = 0, target_y = 0;
  target_x = a_target; // 1 10
  target_y = a_target >> 8;

  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%c%c", field[i + 2][0], field[i + 2][2]);
    for (int j = 0; j < FIELD_SIZE; j++) fprintf(stdout, "%c", draw_symbol[p_data[i * FIELD_SIZE + j]]);
    for (int j = 12; j < 20; j++) fprintf(stdout, "%c", field[i + 2][j]);
    for (int j = 0; j < FIELD_SIZE; j++) {
      if (i == target_y && j == target_x) printf("%c", TARGET);
      else fprintf(stdout, " ");
    }

    fprintf(stdout, "%c\n", field[i + 2][30]);
  }
  fprintf(stdout, "%s\n", field[N_LINES - 1]);
}

void ship_generate(fiedInfo *p_data) {
  srand(time(NULL));  /*i * n + j*/
  for (int i = 0; i < FIELD_SIZE; i++)
    p_data[i + FIELD_SIZE + (rand() % 10) + 1] = SHIP;
}

unsigned char get_target_position(unsigned char *ap_x, unsigned char *ap_y) {
  int key = 0;
  key = getchar();
  if (key == ARROW_KEY_PRESSED) {
    key = getchar();
    if (key == KEY_DOWN) {
      if (*ap_y < FIELD_SIZE -1) *ap_y++;
      return 0;
    }
    if (key == KEY_UP) {
      if (*ap_y > 0) *ap_y--;
      return 0;
    }
    if (key == KEY_LEFT) {
      if (*ap_x < FIELD_SIZE -1) *ap_x++;
      return 0;
    }
    if (key == KEY_RIGHT) {
      if (*ap_x > 0) *ap_x--;
      return 0;
    }
  }
  if (key == KEY_ENTER) return 1;
  return 0;
}
