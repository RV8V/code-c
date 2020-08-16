#include <stdio.h>
#include "struct.h"

#pragma pack(push, 1)
typedef struct { char ch; int i; } Data;
#pragma pack(pop)

int main(int argc, char const *argv[]) {
  Data data;
  data.ch = 0x11;
  data.i = 0x02030405;
  char *p = (char *)&data;
  p++;
  *p = 90; // 5a
  s_a_print_info();
  return 0;
}
