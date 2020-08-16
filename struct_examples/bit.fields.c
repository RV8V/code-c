#include <stdio.h>
#include <stdlib.h>

#define TEST_3

void print_struct_info(void);

#ifdef TEST_1
typedef struct { char a; char b; } s_a;
typedef struct { char a; short b; } s_b;
typedef struct { char a; int b; } s_c;
typedef struct { char a; double b; } s_d;
typedef struct { long a; char b; } s_e;
typedef struct { float a; long double b; } s_f;

#pragma pack(push, 4)
typedef struct { char a; long long b; } s_e_p;
typedef struct { short a; long double b; } s_f_p;
#pragma pack(pop)

void print_struct_info() {
  printf("size of s_a { char; char }   = %li\n", sizeof(s_a));
  printf("size of s_b { char; short }  = %li\n", sizeof(s_b));
  printf("size of s_c { char;int }     = %li\n", sizeof(s_c));
  printf("size of s_d { char; double } = %li\n", sizeof(s_d));
  printf("size of s_c { long; char }   = %li\n", sizeof(s_e));
  printf("size of s_d { float; long double } = %li\n", sizeof(s_f));

  printf("size of s_c { char; long long }    = %li\n", sizeof(s_e_p));
  printf("size of s_d { short; long double } = %li\n", sizeof(s_f_p));
}

#elif defined(TEST_2)
typedef struct { char a : 1; char b : 1; } s_a; // 6 unused
typedef struct { char a : 5; char b : 3; } s_b; // 0
typedef struct { char a : 5; char b : 4; } s_c; // 7 unused -> 2 bytes
typedef struct { char a : 2; char : 0; char b : 4; } s_d; // takes rest of 8 -> 8 -2 = 6
typedef struct { char a : 4; char : 0; char b : 4; } s_e; // takes rest of 8 -> 8 -4 = 4 // 28 unused -> char extended to int (32b)

void print_struct_info() {
  printf("size of s_a { char a: 1;           char b: 1 }  = %li\n", sizeof(s_a));
  printf("size of s_b { char a: 5;           char b: 3 }  = %li\n", sizeof(s_b));
  printf("size of s_c { char a: 5;           char b: 4 }  = %li\n", sizeof(s_c));
  printf("size of s_d { char a: 4; char  : 0; char b: 4 } = %li\n", sizeof(s_d));
  printf("size of s_e { char a: 4; int   : 0; char b: 4 } = %li\n", sizeof(s_e));
}

#elif defined(TEST_3)
typedef struct { char a : 1; char  : 0; } s_a;
typedef struct { char a : 5; short : 0; } s_b;
typedef struct { char a : 5; int   : 0; } s_c;
typedef struct { char a : 4; long long : 0; } s_d;

void print_struct_info() {
  printf("size of s_a { char a: 1;            char      : 0 } = %ld\n", sizeof(s_a));
  printf("size of s_b { char a: 5;            short     : 0 } = %ld\n", sizeof(s_b));
  printf("size of s_c { char a: 5;            int       : 0 } = %ld\n", sizeof(s_c));
  printf("size of s_d { char a: 4; char  : 0; long long : 0 } = %ld\n", sizeof(s_d));
}

#elif defined(TEST_4)
typedef struct { char a : 1; char  : 0; char b; } s_a;
typedef struct { char a : 5; short : 0; char b } s_b;
typedef struct { char a : 5; int   : 0; char b } s_c;

typedef struct {
  char a : 1; // 1
  char   : 0 // 7 unused
  char b : 2 // 2
  char   : 4 // 4 unused
  char c : 2 // 2
} s_d;

typedef struct {
  char a : 1; // 1
  short  : 0; // 15 unused
  char b : 2; // 2
  char   : 4; // 4 unused
  char c : 2; // 2
} s_e;

typedef struct {
  char a : 1; // 1
  int    : 0; // 31 unused
  char b : 2; // 2
  char   : 4; // 4 unused
  char c : 2; // 2
} s_f;

void print_struct_info() {
  printf("size of s_a = %li\n", sizeof(s_a));
  printf("size of s_b = %li\n", sizeof(s_b));
  printf("size of s_c = %li\n", sizeof(s_c));
  printf("size of s_d = %li\n", sizeof(s_d));
  printf("size of s_e = %li\n", sizeof(s_e));
  printf("size of s_f = %li\n", sizeof(s_f));
}

#endif

typedef struct { char b1: 1; char b2: 1; char b3: 1; char b4: 1; char b5: 1; char b6: 1; char b7: 1; char b8: 1; } sByte;

/*
(C99, 6.7.2.1p4)
"A bit-field shall have a type that is a qualified or
unqualified version of _Bool, signed int, unsigned int, or some other
implementation-defined type."

(C99, 6.7.2.1p10)
"If enough space remains, a bit-field that immediately follows another bit-field
in a structure shall be packed into adjacent bits of the same unit"
(C99, 6.7.2.1p11)

"A bit-field declaration with no declarator, but only a colon and a width, indicates an
unnamed bit-field.As a special case, a bit-field structure member with a width of 0
indicates that no further bit-field is to be packed into the unit in which the previous bitfield,if any, was placed."
The special unnamed bit field of width zero breaks up padding:
it specifies that the next bit field begins at the beginning of the next
allocation unit.
*/

int main(int argc, char const *argv[]) {
  print_struct_info();
  return 0;
}
