#include <stdio.h>
#include <stdlib.h>

#include "sort_tool.h"

#define ARRAY_SIZE 30

bool pred_ascending(unsigned, unsigned);
bool pred_descending(unsigned, unsigned);

typedef enum { E_SO_ASCENDING = 0, E_SO_DESCENDING, E_SO_END } SortOrder;

int main(int argc, char const *argv[]) {
  int iarray[ARRAY_SIZE] = { 0 };
  for (int i = 0; i < ARRAY_SIZE; ++i)
    iarray[i] = rand() % 1000;

  ia_print(&iarray[0], ARRAY_SIZE);
  ia_bubble_sort(&iarray[0], ARRAY_SIZE, &pred_ascending);
  printf("\n\n");
  ia_print(&iarray[0], ARRAY_SIZE);

  ia_bubble_sort(&iarray[0], ARRAY_SIZE, &pred_descending);
  printf("\n\n");
  ia_print(&iarray[0], ARRAY_SIZE);

  pf_compare pfa[E_SO_END];
  pfa[E_SO_ASCENDING] = &pred_ascending;
  pfa[E_SO_DESCENDING] = &pred_descending;

  for (char i = 0; i < E_SO_END, i++) {
    ia_bubble_sort(&iarray[0], ARRAY_SIZE, pfa[i]);
    printf("\n");
    ia_print(&iarray[0], ARRAY_SIZE);
  }

  return 0;
}

bool pred_ascending(unsigned int a, unsigned int b) {
  return a >= b;
}

bool pred_descending(unsigned int a, unsigned int b) {
  return a < b;
}
