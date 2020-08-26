#include <stdio.h>
#include <string.h>

int main(void) {
  const void *a;
  const void *b;

  int x = *(int *)a;
  fprintf(stdout, "%d\n", x);

  for (short i = 0; i < 50; i += 1)
    fprintf(stdout, "error: %d, value: %s\n", i, strerror(i));

  FILE *no_pointer = fopen("no_file.txt", "r");
  if (no_pointer != NULL) fprintf(stdout, "%s\n", "success");
  else perror("error while opening file");

  const short size = 100;
  char arr[1000];

  FILE *original_pointer = fopen("text.txt", "r");
  FILE *copy_pointer = fopen("copy.txt", "w");

  if (copy_pointer != NULL && original_pointer != NULL) {
    const int lettersR = fread(arr, 1, size, original_pointer);
    const int lettersW = fwrite(arr, 1, lettersR, copy_pointer);
    fprintf(stdout, "file: 'text.txt was read total chars: '%d\n", lettersR);
    fprintf(stdout, "file: 'copy.txt was written total chars: '%d\n", lettersW);
    fclose(original_pointer);
    fclose(copy_pointer);
  } else {
    fprintf(stdout, "file was opened with failure: %s\n", "text.txt");
    fprintf(stdout, "file was opened with failure: %s\n", "copy.txt");
    return 1;
  }

  const int size = 100;
  char str[size];
  char name[100] = { "from lamer to programmer" };
  char value[100];

  FILE *file_pointer;
  file_pointer = fopen("text.txt", "r+a");
  // r, w, a, r+, w+, a+, rb, wb
  if (file_pointer != NULL) {
    fprintf(stdout, "opened file for writing\n");
    fprintf(stdout, "reading data from file\n\n");
    while (fgets(str, size, file_pointer))
      fprintf(stdout, "read file: %s", str);
    fprintf(stdout, "\nreading was stopped\n");

    fputs(name, file_pointer);
    fprintf(stdout, "\n");

    do {
      fprintf(stdout, "value is: %s\n", value);
    }
    while(fgets(value, 100, file_pointer));

    fprintf(stdout, "file will be closed: %s\n", "file.txt");
    fclose(file_pointer);
  }
  else {
    fprintf(stderr, "failed to open file or create file\n");
    return 1;
  }
  return 0;
}
