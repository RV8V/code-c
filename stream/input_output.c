#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input_output_a(void);

int main(int argc, char const *argv[]) {
  input_output_a();
  return 0;
}

void input_output_a() {
  FILE *p_file = NULL;
  char *test_str = "input_output_a";
  size_t len = strlen(test_str);

  p_file = fopen("text.txt", "a+");
  fwrite(test_str, sizeof(char), len, p_file);

  fflush(p_file);

  int i = 2;
  do fwrite(test_str, sizeof(char), len, p_file);
  while(i-- > 0);

  fclose(p_file);
}
