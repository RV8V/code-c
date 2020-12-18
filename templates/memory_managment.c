#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *m_pointer = NULL;
  unsigned char m_l = 20;
  unsigned char n_s = 0;
  m_pointer = malloc((sizeof(char) * m_l) +1);
  memset(m_pointer, 0, (sizeof(char) * m_l) +1);
  char i = 0;
  for (; i < m_l; ++i)
    printf("%d -> %c\n", i, *m_pointer++);

  char *c_pointer = NULL;
  unsigned char c_l = 5;
  c_pointer = calloc(c_l + 1, sizeof(char));
  char g = c_l;
  do printf("%d -> %c\n", g, *c_pointer++);
  while(g-- > 0);

  strcpy(c_pointer, "Hello");
  printf("%s\n", c_pointer);

  n_s = c_l + strlen(" world") + 1;
  printf("%p -- \n", c_pointer);
  c_pointer = realloc(c_pointer, n_s);
  printf("%p -- \n", c_pointer);

  strcat(c_pointer, " world");
  c_pointer[n_s] = '\0';
  printf("%s\n", c_pointer);

  if (c_pointer != NULL) free(c_pointer);
  if (m_pointer != NULL) free(m_pointer);
  c_pointer = NULL;
  m_pointer = NULL;
  return 0;
}
