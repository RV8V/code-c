#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <winuser.h>
#include <conio.h>

int main(void) {

  char arr[10][21];
  int i, x, y;
  int ox, oy;
  int ax, ay;
  int apples;
  char key;

  i = apples = 0, x = 10, y = 5;
  ax = ay = 5;

  srand(time(NULL));

  do {
    sprintf(*(arr + 0), "####################");
    for (i = 1; i < 9; ++i)
      sprintf(*(arr + i), "#                  #");
    sprintf(*(arr + 9), "####################");

    *(*(arr + y) + x) = '@';
    *(*(arr + ax) + ay) = '&';

    system("clear");

    i = 0;
    for (; i < 10; ++i)
      printf("%s\n", *(arr + i));

    printf("apples: %d\n", apples);

    scanf("%c", &key);

    ox = x;
    oy = y;

    if (key == 'w') y--;
    else if (key == 's') y++;
    else if (key == 'a') x--;
    else if (key == 'd') x++;

    printf("%d\n", *(*(arr + x) + y));

    if (*(*(arr + x) + y) == '#')
      x = ox; y = oy;

    if (x == ax && y == ay)
      ax = rand() * 1.0 / RAND_MAX * 18 + 1, ay = rand() * 1.0 / RAND_MAX * 8 + 1, ++apples;

  } while(key != 'e');
  return 0;
}
