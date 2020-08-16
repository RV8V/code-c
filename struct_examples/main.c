#include <stdio.h>

#pragma pack(push, 1)
typedef struct {
  char a;
  short b;
  short c;
  char d;
  int e;
} s_a;
#pragma pack(pop)

int main(int argc, char const *argv[]) {
  s_a s;
  s.a = 0x01;
  s.b = 0x0203;
  s.c = 0x0405;
  s.d = 0x08;
  s.e = 0x090A0B0C;

  printf("%ld\n", sizeof(s));
  return 0;
}
