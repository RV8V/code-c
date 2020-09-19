#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_strcpy(char* str1, const char* str2) {
  while(*(str1++) = *(str2++));
}

char my_toupper(char c) {
  return c >= 'a' && c <= 'z' ? c - 32 : c - 0;
}

char my_tolower(char c) {
  return c += c >= 'A' && c <= 'Z' ? +32 : 0;
}

char* hello(const char* name) {
  char* res = (char*)malloc(20 * sizeof(char) + 1);
  strcpy(res, "Hello, ");
  if (name == NULL) return strcat(res, " World!");
  char i = 7;
  char len = strlen(name);
  *(res + i) = my_toupper(*(name + 0));
  for (i = 1; i < len; i++)
    *(res + 7) = my_tolower(*(name + i))
  *(res + len + 7) = '!';
  *(res + len + 8) = '\0';
  return res;
}

int main() {
  const char* name = "hog";
  hello(name);
  printf("size: %ld\n", sizeof("hello"));

  char* input = "hello";
  char str[80];
  char* str_d = NULL;
  str_d = (char*)malloc(sizeof(char) * 5 + 1);

  my_strcpy(str, input);
  my_strcpy(str_d, input);

  char i = 0;
  while(*(str + i))
    printf("%c\n", *(str + i++));

  i = 0;
  while(*(str_d++))
    printf("%c\n", *(str_d++));

  char s1[10] = "test";
  char s2[10] = "string";
  int i = 0;
  strcat(s1, s2);
  for(char i = 0; i < sizeof(s1)/sizeof(char); ++i)
    printf("%d", s1[i]);
  printf("\n");
}
