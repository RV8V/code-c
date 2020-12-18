#include <stdio.h>
#include <string.h>

#define CONST 50
#undef CONST

#define G 20
#define H 30
#define SUM(a, b) (a + b) * 2

#ifdef (if defined)
#ifndef (if not defined)
#endif

static int number = 500;
outer int n = 20;

void print_hello();
short add_number();

short test(const short number);
void recur(int number);

void fn1(int *pointer);
void fn2(int *pointer);

void fn1(int *pointer) {
  *pointer = *pointer + *pointer;
};

void fn2(int *pointer) {
  *pointer = *pointer / *pointer;
};

void string(char *pointer) {
  while (*pointer) {
    *pointer = *pointer ^ 31;
    pointer++;
  }
};

struct coords { int x; int y; };
struct coords Top;
typedef struct { int value1; int value2; } Pointer2;
typedef struct { Pointer2 a; Pointer2 b; } Coordinators;

Pointer2 bottom = { 10, 10 };
Coordinators var;

typedef struct { char str[4]; } Bad;
typedef struct { char *str; } Good;
typedef struct { char *name; char *population; } City;

int main(void) {
  City first, second, third, *fourth;
  first.name = "first city";
  first.population = "123";

  fprintf(stdout, "first struct: city = %s, population = %s\n", first.name, first.population);

  fourth = &second;
  fourth->name = "second city";
  fourth->population = "128";

  fprintf(stdout, "second struct: city = %s, population = %s\n", second.name, second.population);

  fourth = &third;
  fourth -> name = "third city";
  fourth -> population = "981";

  fprintf(stdout, "address: %p and value: %d\n", fourth, *fourth);
  fprintf(stdout, "third struct: city = %s, population = %s\n", fourth -> name, fourth -> population);

  int numbers[] = { 1, 2, 3 };
  fprintf(stdout, "first value: %d\n", *numbers);

  Bad bad = { 'b', 'a', 'd', '\0' };
  Good good = { "good" };

  /* GOOD EXAMPLE */

  fprintf(stdout, "value in struct: %s\n", bad.str);
  char *pointer = "ok";
  for (short i = 0; i < sizeof(bad.str); i += 1)
    bad.str[i] = *pointer++;
  fprintf(stdout, "changed value in struct: %s\n", bad.str);
  fprintf(stdout, "value = %d and address = %p\n", *good.str, good.str);

  var.a = bottom; var.b = bottom;
  Pointer.x = 10; Pointer.y = 20;
  Top.x = 30; Top.y = 40;

  fprintf(stdout, "top: %d %d\n", Top.x, Top.y);
  fprintf(stdout, "pointer: %d %d\n", Pointer.x, Pointer.y);

  printf("char size = %ld\n", sizeof(char));
  printf("int size = %ld\n", sizeof(int));
  printf("short size = %ld\n", sizeof(short));
  printf("long size = %ld\n", sizeof(long));
  printf("short float = %ld\n", sizeof(float));
  printf("long double = %ld\n", sizeof(double));
  printf("void = %ld\n", sizeof(void));*/

  int SIZE = 100;
  char str1[100] = "string 1";
  char str2[] = " string 2\n";
  char str3[100] = "string 3";
  char str4[] = " string 4\n";

  const int size = sizeof str2;
  printf("size of str2 = %d\n", size);

  strcat(str1, str2);
  fputs(str1, stdout);

  printf("%c", '\n');

  const int size = 50;
  char string[size + 1];

  const int s = 50;
  char arr[s + 1];

  fscanf(stdin, "%s\n", string);
  fscanf(stdin, "%[^\n]", arr);

  gets(arr); not use
  fprintf(stdout, "string: %s\n", string);
  fprintf(stdout, "arr: %s\n", arr);

  fgets(string, 50, stdin);
  fputs(string, stdout);

  int number;
  fscanf(stdin, "%d", &number);
  printf("%d\n", number);

  char *p_arr_string[3] = { "item1", "item2", "item3" };
  fprintf(stdout, "pointer p_arr_string: %p\n", p_arr_string);
  fprintf(stdout, "first value: %s\n", p_arr_string[0]);
  fprintf(stdout, "first value pointer: %d\n", *p_arr_string[0]);

  int numbers[] = { 1, 2, 3 };
  int *pointer = &numbers[0];
  fprintf(stdout, "numbers value: %d\n", *numbers);
  fprintf(stdout, "numbers pointer: %p, pointer: %p\n", numbers, pointer);

  int *arr_pointers[2] = { pointer, numbers };
  for (int i = 0; i < 2; i++)
    fprintf(stdout, "%p\n", arr_pointers[i]);

  const int SIZE = 100;
  char str[SIZE];
  char *p_string = str;
  fprintf(stdout, "%s", "enter your string ");
  scanf("%s", str);
  string(str);
  fprintf(stdout, "%s\n", str);
  string(str);
  fprintf(stdout, "%s\n", str);

  int number = 100;
  int *pointer = &number;
  fprintf(stdout, "number: %d, value on pointer: %d, address: %p\n", number, *pointer, pointer);

  fn1(pointer);
  fprintf(stdout, "change value via pointer: %d, number: %d, address: %p\n", *pointer, number, pointer);

  fn2(pointer);
  fprintf(stdout, "change value via pointer: %d, number: %d, address: %p\n", *pointer, number, pointer);

  const int a = 10, b = 20;
  int c = a + b * 2;
  int d = SUM(a, b);
  int s = SUM(G, H);
  printf("%d\n", s);

  extern int number;
  printf("%d\n", number);

  int number = 10;
  short num = 1;
  long numberoc = 100;
  char letter = 'a';
  float fl = 1.234;
  double decimal = 1.234;
  long long n = 19398318931;

  printf("number = %i, short = %d\n", number, num);
  printf("numberoc = %d, letter = %c, float = %f, double = %g\n", number, letter, fl, decimal);

  int age, weight;
  char name[50];
  printf("enter your name ");
  scanf("%s", name);
  printf("enter your age ");
  scanf("%d", &age);
  printf("enter your weight ");
  scanf("%d", &weight);
  printf("weight: %d, age: %i, name: %s\n", weight, age, name);
  printf("address in computer for variable 'name' %p\n", &name);

  short n = 1;
  short hello;
  printf("%p\n", &n);
  scanf("%hd", &hello);

  int a = 100, b = 20;
  int sum = a + b;
  printf("%d\n", sum);
  printf("%i\n", a - b);

  int number = 10;
  float c = (double) number;
  int b = (int) c;
  printf("%f\n", c);
  printf("%d\n", b);

  printf("%i\n", (int) 2.2);

  int numbers[3] = { 1, 2, 3, 4 };
  char arr[4] = { 'a', 'b', 'c', '\0' };
  char str[] = { "abc" };
  printf("arr = %s and str = %s\n", arr, str);
  for (int i = 0; i < 4; i++)
    printf("str[i] = %c\n", str[i]);*/
  char name[] = { "name" };
  char s = name[10];
  char arr[2][3] = { { 'a', 'b', '\0' }, { 'c', 'd', '\0' } };

  #define STR_VALUE "value of this string"
  #define NUMBER 100.01
  #define STRING { "hello world" }
  const int VALUE = 10;
  const char string[] = { "hello world" };

  enum days { monday = 'A', tuesday = 2 };
  printf("%d\n", monday);
  printf("%i\n", tuesday);

  typedef int myType;
  myType value = 10;
  typedef char string[10];
  string str[] = { "abc" };

  int const a = 10, b = 20;
  #if a < b
    printf("%s\n", "hello world");
  #endif
  printf("%s\n", "what is wrong");*/

  int number = 6 % 2 == 0 ? printf("%s\n", "even") : printf("%s\n", "odd");
  printf("%i because length of world 'even\\n' is 5\n", number);

  const int number = 10;
  if (number == 10) printf("%s\n", "true");
  else printf("%s\n", "not equals");

  const char letter = 'A';
  if (letter == 'A') printf("%s\n", "letters are not odd");
  else if (letter == 'V') printf("%s\n", "letter else if");
  else printf("%s\n", "not defined");

  const short result = strcmp("hello", "world");
  printf("%i\n", result);

  short number = 0;
  fprintf(stdout, "%s\n", "fprintf function");
  fscanf(stdin, "%hd", &number);

  switch(number) {
    case 1: fprintf(stdout, "%s\n", "test");
    break;
  }

  const char string[4] = { 's', 't', 'r', '\0' };
  for (short i = 0; i < strlen(string); i+=1)
    fprintf(stdout, "%s%d\n", "current value is ", string[i]);

  const short numbers[] = { 1, 2, 3 };
  for (short i = 0; i < 3; i+=1)
    fprintf(stdout ,"number[%d] = %d\n", i, numbers[i]);

  short i = 0;
  while (i != 5) {
    printf("%d\n", i);
    i++;
  }

  for (short i = 0; i < 5; i+=1) {
    if (i == 2) goto mark;
    printf("%d\n", i);
  }
  mark:
  printf("%s\n", "operator 'go to'");

  print_hello();
  const short number = add_number();
  printf("%d\n", number);

  fprintf(stdout, "%d\n", add_number());

  printf("%d\n", test(10));

  short number;
  fprintf(stdout, "%s\n", "enter value ");
  fscanf(stdin, "%hd", &number);
  recur(number);
  fprintf(stdout, "%s\n", "done");

  const int number = 10;
  const int *p_number;
  p_number = &number;

  const int num = 15;
  const int *p_num = &num;

  printf("Value: %i, address: %p\n", *p_num, p_num);
  printf("Value: %d, address: %p\n", *p_number, p_number);

  const int *p_arr_number;
  int arr[] = { 1, 2, 3, 4 };
  p_arr_number = arr;
  for (short i = 0; i < 4; i++) {
    printf("Index[%d] = value: %d, address: %p\n", i, *p_arr_number, p_arr_number);
    *p_arr_number++;
  }

  char *p_arr_char;
  char string[] = { "test" };
  p_arr_char = string;
  for (short i = 0; i < strlen(string); i++) {
    if (*p_arr_char == 's') *p_arr_char = 'x';
    fprintf(stdout, "value: %c\n", *p_arr_char++);
  }

  int *p_number;
  int number = 10;
  p_number = &number;
  printf("%d\n", *p_number);
  *p_number = 20;
  printf("%d\n", *p_number);

  int number1 = 30;
  int *p_number1 = &number1;
  printf("%d\n", *p_number1);

  int numbers[] = { 1, 2, 3 };
  int *p_arr_number = numbers;
  for (int i = 0; i < 3; i+=1) {
    fprintf(stdout, "%d\n", *(p_arr_number + i));
  }

  int numbers[] = { 1, 2 };
  int *p_numbers = numbers;
  for (int i = 0; i < 2; i+=1) {
    fprintf(stdout, "value: %d\n", numbers[i]);
    p_numbers++;
  }
}

void recur(int number) {
  fprintf(stdout, "%d\n", number);
  if (--number < 0) return;
  else recur(number);
}

short test(const short number) {
  return number;
}

short add_number() {
  const short a = 10, b = 20;
  return a + b;
}

void print_hello(void) {
 fprintf(stdout, "%s\n", "hello Function");
}
