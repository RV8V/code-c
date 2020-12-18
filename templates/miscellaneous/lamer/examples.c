#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Car {
  int weight;
  char name[50];
  int length;
};

struct Bad {
  int width, height;
};

int calculateBad(struct Bad bad);
int calculateGood(struct Bad *good);

int calculateBad(struct Bad bad) {
  return bad.width * bad.height;
}

int calculateGood(struct Bad *good) {
  printf("address for struct: %p\n", good);
  printf("value for struct.field: %d\n", good->width);
  return good->width * good->height;
}

int main(void) {

  char line[255];
  FILE *file = fopen("draft.txt", "a");
  fprintf(file, "%s\n", "hello world");

  do fprintf(stdout, "line: %s\n", line);
  while (fgets(line, 10, file));
  fclose(file);


  struct Bad object = { 20, 40 };
  int result = calculateBad(object);
  int res = calculateGood(&object);
  printf("value1: %d and value2: %d\n", result, res);


  int ch = &10;
  int *pointer = &ch;


  int number = 10; // address in memory is the same
  int *pointer = &number;

  // the same as above and no need to declare variable 'number'
  // we can not do like that !
  int *pointer2 = 10;

  printf("& value: %p and pointer: %p\n", &number, pointer);

  int *scan_pointer;

  printf("%s\n", "start");
  scanf("%d\n", scan_pointer);
  printf("value: %d\n", *scan_pointer);



  struct Car bmw;
  bmw.weight = 10000; //bmw.name = "bmw m5";
  strcpy(bmw.name, "bmw m5");
  // the same result of declaration of object from structs
  struct Car audi = { 20000, "audi a7" };



  int i = 4;
  do {
    if (i == 2) goto here;
    printf("%s and count: %d\n", "hello world", i);
  }
  while (i-- > 0);

  here: {
    printf("%s\n", "goto to is used");
    printf("%s\n", "and here");
    exit(1);
  }
  printf("%s\n", "not enter here");



  int a = 3;
  float b = 2.12;
  int res = a / b;
  fprintf(stdout, "res: %d\n", res);



  const float x = 1.2344, y = 5.2345;
  float res;
  printf("%f\n", res);

  printf("result: %.3f\n", x / y);

  const bool flag = true;
  const unsigned short val = 20;

  for (int i; i < 2; i++) {
    if (i != 10) { // trash !
      printf("value for uninitialized variable: %d\n", i);
      break;
    }
  }
  printf("%d + %d = %d\n", 1, 2, 3);

  short number = 10;
  while (number > 0)
    fprintf(stdout, "number: %d\n", number--);

  printf("\n");

  short number2 = 10;
  while (number2-- > 0)
    fprintf(stdout, "number: %d\n", number2);

  printf("\n%m\n");

  const time_t tm = time(NULL);
  fprintf(stdout, "time: %s\n", ctime(&tm));
}
