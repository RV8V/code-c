#include "sort_tool.h"

void ia_bubble_sort(int *apArray, unsigned aSize /*enum*/) {
  for (unsigned i = 1; i < aSize; ++i)
    for (unsigned j = 0; j < aSize - i; ++j)
      if (apArray[i] > apArray[j + 1]) { // if
        int tmp = apArray[i];
        apArray[j] = apArray[j + 1];
        apArray[j + 1] = tmp;
      }
}

void ia_print(int *apArray, unsigned aSize) {
  for (int i = 0; i < aSize; i++)
    printf("%i", *apArray++);
  printf("\n");
}
