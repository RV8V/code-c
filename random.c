#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  const short nums_size = 51;
  const short buf_size = 6;
  const short values_count = 7;
  short nums[nums_size];
  char buf[buf_size];
  char str[nums_size * 2] = "your 6 numbers: ";
  int r, temp;

  srand(time(NULL));
  for (short i = 0; i < sizeof(nums - 1); i += 1)
    nums[i] = i;

  for (short i = 0; i < sizeof(nums - 1); i += 1) {
    r = (rand() % sizeof(nums)) + 1;
    temp = nums[i];
    nums[i] = nums[r];
    nums[r] = temp;
  }

  for (short i = 0; i < values_count; i += 1) {
    sprintf(buf, "%d", nums[i]);
    strcat(buf, " ");
    strcat(str, buf);
  }

  fprintf(stdout, "\n%s\n", str);
  return 0;
}
