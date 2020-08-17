#include <stdio.h>
#include <stdlib.h>

typedef int listDate;
typedef unsigned lengthData;

struct singleList {
  listDate p_data;
  struct singleList *p_next;
};

/*                0x400000         0x400004
+--------+       +--------+       +--------+
| p_data |       |   1    |       |   2    |
+--------+       +--------+    .->+--------+
| p_next |       |0x400004| --.   |  NULL  |
+--------+       +--------+       +--------+

for 5 int elements = (4 + 4) * 5 = 40 bytes
*/

struct DoubleList {
  listDate p_data;
  struct DoubleList *p_prev;
  struct DoubleList *p_next;
};

/*                0x400000
+--------+       +--------+
| p_data |       |   1    |
+--------+       +--------+
| p_next |       |  NULL  |
+--------+       +--------+
| p_prev |       |  NULL  |
+--------+       +--------+

for 5 int elements = (4 + 4 + 4) * 5 = 60 bytes
*/

struct unrolledLinkedList {
  listDate *p_data_array;
  lengthData length;
  struct unrolledLinkedList *p_next;
};

/*                   0x400000
+----------+       +-----------+
| p_data[] |       | 1,2,3,4,5 |
+----------+       +-----------+
|  length  |       |     5     |
+----------+       +-----------+
|  p_next  |       |   NULL    |
+----------+       +-----------+

for 5 int elements = ((4 * 5) + 4 + 4) = 28 bytes
*/

int main(int argc, char const *argv[]) {
  struct singleList *p_head;
  struct singleList *p_tail;

  p_head = NULL;
  // append
  char data = 1;

  if (p_head == NULL) {
    p_head = malloc(sizeof(struct singleList));
    p_head->p_data = data;
    p_head = NULL;
  } else {
    struct singleList *tmp;
    tmp = p_head;
    while(tmp->p_next)
      tmp = tmp->p_next;
    tmp->p_next = malloc(sizeof(struct singleList));
    tmp->p_next->p_data = data;
    tmp->p_next->p_next = NULL;
  }

  struct singleList *p_next;
  p_next = p_head;
  while(p_next->p_next) {
    printf("%i, ", p_next->p_data);
    p_next = p_next->p_next;
  }
  printf("%i\n", p_next->p_data);

  return 0;
}
