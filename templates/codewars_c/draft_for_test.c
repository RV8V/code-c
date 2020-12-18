#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int my_pow(int val, int deg) {
  int res = 1;
  while(deg != 0) {
    res *= val;
    deg--;
  }
  return res;
}

char* repeat_str(unsigned int count, const char* str) {
  int len = 0;
  while(*str++)
    len++;
  printf("length: %d\n", len);
  char* dest = (char*)malloc(sizeof(char) * count * len);
  for(int i = 0; i < count; i++)
    strcpy(dest + i * len, str);
  return dest;
}

char* repeat_str_while(unsigned int count, const char* str) {
  int length = strlen(str);
  char* dest = (char*)malloc(sizeof(char) * count * length);
  while(count--) {
    printf("count: %d\n", count);
    strcat(dest, str);
  }
  return dest;
}

int main() {
  /*const char* base = "hello";
  char* repeated = repeat_str_while(3, base);
  while(*repeated)
    printf("%c", *repeated++);
  printf("\n");

  const int length = strlen(base), count = 2;
  char* test = (char*)malloc(sizeof(char) * length * count);
  strcat(test, base);
  strcat(test, base);
  strcat(test, base);
  while(*test)
    printf("%c", *test++);
  printf("\n");*/

  /*const char* source = "source";
  const char len = strlen(source);
  const char count = 3;
  char* res = (char*)malloc(len * count + 1);
  int i = 0; char* p;
  for (i = 0, p = res; i < count; ++i, p += len)
    memcpy(p, source, len);
  *p = '\0';

  while(*res)
    printf("%c", *res++);
  printf("\n");*/

  int res = round(2.8 / 2);
  printf("res: %d\n", res);
  return 0;
}
