#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stdout, "%s\n", "not specified code listing extention .c and .out");
    return 1;
  }
  if (argc > 3) {
    fprintf(stdout, "%s\n", "there must be one file with the extention .c and .out");
    return 1;
  }

  char output[100] = "gcc -g -o ";
  const char *file_out = argv[2];
  const char *file_name = argv[1];
  strcat(output, file_out);
  strcat(output, " ");
  strcat(output, file_name);
  system(output);
  fprintf(stdout, "%s\n", "press enter to start program");
  getchar();
  const char *start = file_out;
  system(start);
  fprintf(stdout, "%m\n");
  return 0;
}
