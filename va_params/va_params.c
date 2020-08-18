#include <stdarg.h>

void f_a(int count, ...) {
  int value = 0;
  va_list(vl);
  va_start(vl, count);
  char g = count;
  do {
    value = va_arg(vl, int);
    printf("%d\n", value);
  } while(g-- > 0);
  va_end(vl);
  printf("\n");
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

void example_a() {
  char a = 4;
  do f_a(a, a + 1, a * 2, a - 2);
  while(a-- > 0);
}

void example_b() {
  f_b("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
}

void example_c() {
  Unit unit = { 100, 200 };
  Data data = { 1, 2, 3 };
  Type args[] = { UNIT, DATA, END };
  f_c(args, unit, data);
}
