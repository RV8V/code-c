#include <stdio.h>
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

void f_a(int, ...);
void f_b(char *, ...);

void example_a(void);

void example_a() {
  char a = 4;
  do f_a(a, a + 1, a * 2, a - 2);
  while(a-- > 0);
}

void f_b(char *p_format, ...) {
  va_list(p_array);
  va_start(p_array, p_format);
  for (char *p = p_format; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    p++;
    if (*p == 'd') {
      int i_val = 0;
      i_val = va_arg(p_array, int);
      printf("%d", i_val);
    }
    if (*p == 'f') {
      double d_val = 0.;
      d_val = va_arg(p_array, double);
      printf("%f", d_val);
    }
    if (*p == 's') {
      for (char *s_val = va_arg(p_array, char *); *s_val; s_val++)
        putchar(*s_val);
    }
    else putchar(*p);
    va_end(p_array);
  }
}

void example_b() {
  f_b("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
}

void f_a(int count, ...) {
  int value = 0;
  va_list(vl);          /* init variable */
  va_start(vl, count);  /* enable access to the variable argument */
  char g = count;
  do {
    value = va_arg(vl, int); /* get next value from list */
    printf("%d\n", value);
  } while(g-- > 0);
  va_end(vl);  /* clear off what was needed */
  printf("\n");
}

typedef struct { int health; int armor; } Unit;
typedef struct { int value_a; int value_b; int value_c; } Data;

void f_c(Type args[], ...) {
  int index = 0;
  va_list(p_args);
  va_start(p_args, args);
  while(args[index] != END) {
    int value = args[index]
    if (value == UNIT) {
      Unit unit = va_arg(p_args, Unit);
      printf("Unit info:\nArmor: %d\nHealth: %d", unit.armor, unit.health);
    }
    if (value == DATA) {
      Data data = va_arg(p_args, Data);
      printf("Data info:\nvalue_a: %d, value_a: %d\nvalue_c: %d", data.value_a, data.value_b, data.value_c);
    }
    index++;
    va_list(p_args);
  }
}

int main(int argc, char const *argv[]) {
  example_b();
  return 0;
}
