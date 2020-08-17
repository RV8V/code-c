#include <stdio.h>

typedef int listDate;
typedef unsigned LengthData;

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
  LengthData length;
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
