#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define width 65
#define height 25

typedef struct {
  int x, y;
  int w;
} racket;

typedef struct {
  float x, y;
} ball;

char arr[height][width + 1];
racket r;
ball b;

int lvl = 1;

void init_ball() {
  b.x = 2;
  b.y = 2;
}

void put_ball() {
  arr[(int)round(b.y)][(int)round(b.x)] = '*';
}

void move_ball(int x, int y) {
  b.x = x;
  b.y = y;
}

void init_racket() {
  r.w = 7;
  r.x = (width - r.w) / 2;
  r.y = height - 1;
}

void put_racket() {
  for (int i = r.x; i < r.x + r.w; ++i) {
    arr[r.y][i] = '@';
  }
}

void init() {
  for (int i = 0; i < width; ++i) {
    arr[0][i] = '#';
  }

  arr[0][width] = '\0';

  for (int i = 1; i < width - 1; ++i) {
    arr[1][i] = ' ';
  }

  for (int i = 1; i < width; ++i) {
    strncpy(arr[i], arr[1], width + 1);
  }
}

void move_racket(int x) {
  r.x = x;
  if (r.x < 1) {
    r.x = 1;
  }
  if (r.x + r.w >= width) {
    r.x = width - 1 - r.w;
  }
}

void show() {
  for (int i = 0; i < height; ++i) {
    printf("%s\n", arr[i]);
  }
}

void set_cur(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_HANDLE), coord);
}

void show_preview() {
  system("clear");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t\t        LEVEL %d", lvl);
  Sleep(1000);
  system("clear");
}

int main(void) {
  char c;

  init_racket();
  init_ball();
  move_racket(2);

  show_preview();

  do {
    set_cur(0, 0);
    init();
    put_racket();
    put_ball();
    show();

    scanf("%c", &c);

    if (c == 'a') move_racket(r.x - 1);
    if (c == 'd') move_racket(r.x + 1);

    move_ball(r.x + r.w / 2, r.y - 1);
    Sleep(10);
  } while(c != 'q');
  return 0;
}
