#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int sort_numbers(const void *a, const void *b);
int sort_strings(const void *a, const void *b);

int main(void) {
  const short nums_size = 51;
  const short buf_size = 6;
  const short values_count = 7;
  short nums[nums_size];
  char buf[buf_size];
  char str[nums_size * 2] = "your 6 numbers: ";
  int r, temp;
  char *strings[] = { "o", "s", "d" };

  srand(time(NULL));
  for (short i = 0; i < sizeof(nums - 1) / 4; i += 1)
    nums[i] = i;

  for (short i = 0; i < sizeof(nums - 1) / 4; i += 1) {
    r = (rand() % sizeof(nums)) + 1;
    temp = nums[i];
    nums[i] = nums[r];
    nums[r] = temp;
  }

  qsort(nums, nums_size, sizeof(int), sort_numbers);
  for (short i = 0; i < nums_size; i += 1)
    fprintf(stdout, "%i", nums[i]);

  qsort(strings, sizeof(strings), sizeof(char), sort_strings);
  for (short i = 0; i < sizeof(strings); i += 1)
    fprintf(stdout, "%s\n", strings[i]);

  for (short i = 0; i < values_count; i += 1) {
    sprintf(buf, "%d", nums[i]);
    strcat(buf, " ");
    strcat(str, buf);
  }

  fprintf(stdout, "\n%s\n", str);
  return 0;
}

int sort_numbers(const void *a, const void *b) {
  const int x = *(int *)a;
  const int y = *(int *)b;
  return x - y;
}

int sort_strings(const void *a, const void *b) {
  char **x = (char**)a;
  char **y = (char**)b;
  return strcmp(*x, *y);
}
