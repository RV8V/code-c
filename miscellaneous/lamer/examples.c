#include <stdio.h>
#include <time.h>

int main(void) {

  short number = 10;
  while (number > 0)
    fprintf(stdout, "number: %d\n", number--);

  printf("\n");

  short number2 = 10;
  while (number2-- > 0)
    fprintf(stdout, "number: %d\n", number2);

  printf("\n%m\n");

  const time_t tm = time(NULL);
  fprintf(stdout, "time: %s\n", ctime(&tm));
}
