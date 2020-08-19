#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[]) {
  printf("signed char min    = %14d, signed char max    = %14d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char min  = %14u, unsigned char max  = %14u\n", 0, UCHAR_MAX);
  printf("signed short min   = %14d, signed short max   = %14d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short min = %14u, unsigned short max = %14u\n", 0, USHRT_MAX);
  printf("signed int min     = %14d, signed int max     = %14d\n", INT_MIN, INT_MAX);
  printf("unsigned int min   = %14u, unsigned int max   = %14u\n", 0, UINT_MAX);
  printf("signed long min    = %14ld, signed long max   = %14ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long min  = %14u, unsigned long max = %14lu\n", 0, LONG_MAX);
  printf("float  min = %14e, float max  = %14e\n", FLT_MIN, FLT_MAX);
  printf("double min = %14e, double max = %14e\n", DBL_MIN, DBL_MAX);
  return 0;
}
