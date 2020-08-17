#ifndef SORT_TOOL_H
#define SORT_TOOL_H

#include <stdbool.h>

#define TEST_1

#ifdef TEST_1
typedef /*int*/ bool (*pf_compare)(unsigned, unsigned); // pointer to compare function
void ia_bubble_sort(int *, unsigned, pf_compare);

#elif defined(TEST_2)
typedef enum { ASCENDING = 0; DESCENDING; END_OF_COMPARISON; } Compare;
void ia_bubble_sort(int *, unsigned, Compare);

#elif defined(TEST_3)
void ia_bubble_sort_ascending(int *, unsigned);
void ia_bubble_sort_descending(int *, unsigned);

#elif defined(BOOL_1)
typedef int bool;
#define TRUE 1
#define FALSE !TRUE

#elif defined(BOOL_2)
typedef enum { FALSE = 0, TRUE } bool;

#elif defined(BOOL_3)
typedef enum { false = 1 == 0, true = !false } bool;

#elif defined(BOOL_4)
#include <stdbool.h>

#endif

void ia_print(int *, unsigned);
