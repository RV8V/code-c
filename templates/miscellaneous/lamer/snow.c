#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define h 25
#define w 80

char arr[h][w + 1];

void init() {
  for (int i = 0; i < w; ++i) {
    arr[0][i] = ' ';
  }
  arr[0][w] = '\0';
  for (int i = 0; i < h; ++i) {
    sprintf(arr[i], arr[0]);
  }
}

void show() {
  arr[h - 1][w - 1] = '\0';
  for (int i = 0; i < h; ++i) {
    printf(arr[i]);
  }
}

void new_show() {
  for (int i = 0; i < w; ++i) {
    if (rand() % 12 == 1) {
      arr[0][i] = '*';
    }
  }
}

void move_show() {
  int dx;
  for (int i = h - 1; i >= 0; --i) {
    for (int s = 0; s < w; ++s) {
      if (arr[i][s] == '*') {
        arr[i][s] = ' ';
        dx = 0;
        if (rand() % 10 < 1) dx++;
        if (rand() % 10 > 1) dx--;
        dx = dx + s;
        if ((dx >= 0) && (dx < w) && (i + 1) < h) {
          arr[i + 1] = '*';
        }
      }
    }
  }
}

void set_cur(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_HANDLE), coord);
}

int main() {
  init();

  do {
    set_cur(0, 0);
    new_show();
    move_show();
    show();
    Sleep(100);
  } while(GetKeyState(VK_ESCAPE) >= 0);

  return 0;
}
