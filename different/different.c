#include "different.h"

void strcopy_a(char *s1, char *s2) {
  short int i = 0;
  while((s1[i] = s2[i]) != '\0')
    i++;
}

void strcopy_b(char *s1, char *s2) {
  int i = 0;
  while((s1[i++] = s2[i]) != '\0');
}

void strcopy_c(char *s1, char *s2) {
  while(*s1++ = *s2++);
}
