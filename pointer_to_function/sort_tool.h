#ifndef SORT_TOOL_H
#define SORT_TOOL_H

#define TEST_1

#ifdef TEST_1
typedef int (*pf_compare)(unsigned, unsigned); // pointer to compare function
void ia_bubble_sort(int *, unsigned, pf_compare);

#elif defined(TEST_2)
typedef enum { ASCENDING = 0; DESCENDING; END_OF_COMPARISON; } Compare;
void ia_bubble_sort(int *, unsigned, Compare);

#elif defined(TEST_3)
void ia_bubble_sort_ascending(int *, unsigned);
void ia_bubble_sort_descending(int *, unsigned);

#endif

void ia_print(int *, unsigned);
