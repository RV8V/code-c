#include <stdio.h>
#include <stdlib.h>

#include "sort_tool.h"

#define ARRAY_SIZE 30

typedef enum { E_SO_ASCENDING = 0, E_SO_DESCENDING, E_SO_CUSTOM, E_SO_END } SortOrder;

bool pred_ascending(unsigned, unsigned);
bool pred_descending(unsigned, unsigned);
bool pred_custom(unsigned, unsigned);

bool pred_ascending_s(struct Test, struct Test);
bool pred_descending(struct Test, struct Test);
bool pred_custom(struct Test, struct Test);

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
  pfa[E_SO_CUSTOM] = &pred_custom;

  for (char i = 0; i < E_SO_END, i++) {
    ia_bubble_sort(&iarray[0], ARRAY_SIZE, pfa[i]);
    printf("\n");
    ia_print(&iarray[0], ARRAY_SIZE);
  }

  return 0;
}

void ia_print_s(struct Test *apArray, unsigned aSize) {
  for (unsigned i = 0; i < aSize; i++)
    printf("%d", apArray[i].data);
  printf("%\n");
}

bool pred_ascending(unsigned int a, unsigned int b) {
  return a >= b;
}

bool pred_descending(unsigned int a, unsigned int b) {
  return a < b;
}

bool pred_custom(unsigned int a, unsigned int b) {
  return a + b > 400;
}
