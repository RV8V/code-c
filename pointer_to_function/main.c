#include <stdio.h>
#include <stdlib.h>

#include "sort_tool.h"

#define ARRAY_SIZE 30

int main(int argc, char const *argv[]) {
  int iarray[ARRAY_SIZE] = { 0 };
  for (int i = 0; i < ARRAY_SIZE; ++i)
    iarray[i] = rand() % 1000;
  ia_print(iarray, ARRAY_SIZE);
  ia_bubble_sort(iarray, ARRAY_SIZE);
  ia_print(iarray, ARRAY_SIZE);
  return 0;
}
