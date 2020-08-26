#include <stdio.h>

// this value 'MAX_STRING_LENGTH' will be thrown away because of no usage by preprocessor
#define MAX_STRING_LENGTH 100

#define SIZE_OF_MEMORY
#define IS_64_BYTES_PER_TAKT
#define OS_WINDOWS

#define MAX(a, b) a > b
#define MIN(a, b) a < b
#define STR(s1, s2) s1 < s2
#define COMBINE(a, b) MIN(a, b) == MAX(a,b)

int sum(int, int);

int main(void) {
  #ifdef defined(OS_WINDOWS)
    printf("%s\n", "it will be printed, but value to OS_WINDOWS was not assigned");
    //win_print()
  #else //lin_print()

  #ifdef IS_64_BYTES_PER_TAKT
    // loadin config fot this operation system
  #else //...

  #ifdef SIZE_OF_MEMORY == 32
    //...
  #else //...
  #endif

  bool flag = false;
  if (flag = true)
    printf("%s\n", "it will be executed");

  double val1 = 10.2f;
  double test1 = 9139.3131;

  float test2 = test1;
  float val2 = val1;

  {
    const char value = 10;
    printf("%s\n", "internal scope");
  }

  printf("result: %d\n", sum(10, 20));

  const char max = MAX(10, 20);
  const char min = MIN(10, 20);
  const char str = STR("hello", "world");
  const char combine = COMBINE(max, min);

  int arr[10] = { [0 ... 4] = 5, [6 ... 9] = 7 };
  int i = 0;
  for (; i < 10; ++i)
    printf("value: %d, index -> %d\n", arr[i], i);

  char ch = 25;
  char ich = 6;
  printf("we want to understand 'inch' as char: %c\n", ich);

  do {
    printf("value in char: %i\n", ch);
  } while(ch -= 5);
  printf("char: %d\n", ch);

  printf("%c\n", 7);
  int i = 0;
  do printf("ascii value: #%d -> %c\n", i, i);
  while(i++ < 256);

  printf("line: %d\nfunction: %s\nfile: %s\n", __LINE__, __FUNCTION__, __FILE__);

  char arr[3] = { 1, 2, 3 };
  arr[3] = 4;
  printf("arr[3] = %d\n\n", arr[3]);

  int array[10];
  char i = 10;
  do printf("array[%d] = %d\n", i, array[i]);
  while(i-- > 0);

  char *str = "he\0llo";
  char str[] = "he\0llo"; (also is used)
  printf("string will be trimmed to 'he': %s\n", str);

  char *string = "hello world";
  string[2] = 0; (programm is crash)
  while(*string != 0) {
    if (*string == ' ') *string = 0;
    if (*string == 0) break;
    printf("%c", *string++);
  }

  int j = 0;
  while(string[j] != 0)
    printf("%c", string[j++]);
  printf("\n");

  char s[] = "hello!\0";
  s[6] = 'e';
  int k = 0;
  while(s[k] != 0)
    printf("%c", s[k]++);
  printf("\n\n");

  char st[] = "hello!\0";
  st[6] = 'e';
  printf("%s\n", st);

  int a = 10;
  int b = 20;
  test(&a, &b);
  printf("%d - %d\n", a, b);

  short arr[3];

  printf("%p\n", &arr[0]);
  printf("%p\n", &arr[1]);
  printf("%p\n\n", &arr[2]);

  int number = 0x10203040;
  char *pointer = (char *)&number;
  pointer = pointer + 3;
  *pointer = 0x21;
  printf("%#x\n\n", number);

  short num = 102;
  char *point = (char *)&num;
  int i = 4;
  do printf("%p\n", point++);
  while(i-- > 0);
}

void test(int *a, int *b) {
  *a = 100;
  *b = 200;
}

int sum(int a, int b) {
  return a + b;
}
