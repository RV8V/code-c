#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//#include <Windows.h>
//#include <winuser.h>
//#include <conio.h>

int main(void) {
  /*setlocale(LC_ALL, "Ukraine");
  if (int a = 4, int x, i = 0, arr[10], m[9], char v[10]; !a) {
    printf("%s\n", "enter"), scanf("%d", &x), printf("x = %g\n", (float)x), sprintf(&v[0], "hello\0");
    while(i <= 10) printf("i = %d\n", i++), printf("%s\n%d\n", v, *(arr + i));;
    do a += ++x++ + ++a;; while(a-- != -1);
    for (;;) for (; i < 9; i++, *(m + i) = i + 1); if (a--) return -1;
  }/
  OemToChar(s, s);*/

  char arr[10][21];
  int i, x, y;
  int ox, oy;
  int ax, ay;
  char key;

  i = 0, x = 10, y = 5;
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
      ax = rand() * 1.0 / RAND_MAX * 18 + 1, ay = rand() * 1.0 / RAND_MAX * 8 + 1;

  } while(key != 'e');
  return 0;
}
