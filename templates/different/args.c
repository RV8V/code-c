#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  printf("args count: %d\n", argc);
  printf("%p\n%p\n", argv, *argv);

  if (argc < 3 || strlen(argv[1]) > 2 ||\
     (argv[1][1] != 'p' && argv[1][1] != 'a' && argv[1][1] != 'c') ||\
      atoi(argv[2]) == 0) {
    printf("-p -> search for position number\n-c -> search for course number\n-a -> search for age");
    return 0;
  }

  for (int i = 0; i < argc; i++)
    printf("%d: %s\n", i, argv[i]);
  return 0;
}
