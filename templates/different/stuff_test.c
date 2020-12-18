#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CONST 100lu
typedef enum { ONE = 0, TWO, THREE, END } Test;

void strcopy(char *, char *);

typedef struct {
  char value;
  char test;
} TestStruct;

typedef struct {
  char ch;
  short sh;
} s_problem_default;

#pragma pack(push, 1)
typedef struct {
  char ch; short sh;
} s_problem_packaged;
#pragma pack(pop)

void test_data(char *p_data) {
  s_problem_default defaul;
  defaul = *((s_problem_default *)(p_data));
  printf("ch = %c\n", defaul.ch);
  printf("sh = %i\n", defaul.sh);
}

void problem_example(void) {
  s_problem_default data;
  char *send_buffer;
  data.ch = 'a';
  data.sh = 0x200;
  printf("%p\n", &data);
  send_buffer = (char*)&(data);
  test_data(send_buffer);
}

bool fn(unsigned, unsigned);
bool fn(unsigned int a, unsigned int b) {
  return a > b;
}

typedef struct {
  int data;
} NodeData;

int main() {
  NodeData node;
  node.data = 10;

  printf("%p\n%p\n", fn, &fn);
  problem_example();
  TestStruct st;
  st.value = 0x01;
  st.test = 0x0A;

  printf("size of struct is: %ld\n", sizeof(st));
  printf("\t+------+------+\n");
  printf("\t| ch_a | ch_b |\n");
  printf("\t+------+------+\n\n");
  printf("\t%p(value): %x\n", &st.value, *(int *)(&st.value/**(char *)(&st.value)*/));
  printf("\t%p(test): %x\n", &st.test, *(char *)(&st.test));
  printf("<----->\n");

  int i = 10;
  printf("%7i\n", i);

  Test test = 20;
  Test array[END] = { ONE };
  // test is one of accepted values in 'Test'
  printf("%d - %d\n", END, test);
  int g = END;
  do printf("%d\n", (*array)++);
  while(g-- > 0);
  printf("\n");

  unsigned short target = 1;
  unsigned char x = 0, y = 0;
  x = target;
  y = target >> 8;
  printf("%d-%d-%d\n", target, x, y);

  int x = 0;
  int y;

  if((y = x) == 0)
    printf("%s\n", "this is working");

  for (int i = (x = y++); i < 4, y++;)
    printf("current value: i = %d, x = %d, y = %d\n", i, x, y);

  for (int i = 0; i < 4; i++, printf("%d\n", i));

  int i = 2;
  do; while(printf("i = %d\n", i), i-- > 0);

  unsigned short int a = 4;
  unsigned long int b = 5;

  short char g = 'a';

  short c = 4;
  long d = 5;
  char f = 'a';

  printf("short char: %ld\n", sizeof(short char));
  printf("char: %ld\n", sizeof(char));

  printf("short: %ld\n", sizeof(short));
  printf("long: %ld\n", sizeof(long));

  printf("short int: %ld\n", sizeof(unsigned short int));
  printf("long int: %ld\n", sizeof(unsigned long int));

  printf("unsigned long number: %ld\n", CONST);

  printf("5 / 10 = %d\n", 5 / 10);
  printf("5 / 10.0 = %.2f\n\n", 5 / 10.);

  printf("%d\n", __BOOL);

  int j = (int)getchar();
  putchar(j);
  printf("int: %d\n", j);

  char ch;
  printf("A symbol: %c\n", ch - 32);

  putchar(42); putchar('*' + '0');
  printf("\n");

  putchar('*' + '\0');
  printf("\n");

  int *p_array = calloc(3, sizeof(short int));
  putchar((*p_array = 41) + '\0');
  printf("\n");

  free(p_array);

  char *s2 = "hello, world", s1[15];
  strcopy(s1, s2);
  puts(s1);
}

void strcopy(char *s1, char *s2) {
  int i = 0;
  while((s1[i] = s2[i]) != '\0')
    i++;
}
