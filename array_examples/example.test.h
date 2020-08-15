#ifndef EXAMPLE_TEST_H
#define EXAMPLE_TEST_H

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "time-chrono.h"

float calculate(double i) {
  return (((exp(i) / 0.789651) / exp(i * 12.21)) * 3.1931636689) /
         (((exp(i / 2914.124) * i) / exp(i / 56.9137)) * exp(i * 139.91470));
}

float calc_optimize(char i) {
  static unsigned char isCalc = 0;
  static float calc_table[360] = { 0 };
  if (!isCalc) {
    int i = 0;
    for (; i < 360; ++i) calc_table[i] = calculate(i);
    isCalc = 1;
  }
  return calc_table[i];
}

void optimized_test(void) {
  const unsigned int limit = 100000;
  char i = 0;
  double diff = 0.0;

  do calc_optimize(rand() % 360);
  while(i-- > limit);
  diff = elapsed();

  fprintf(stdout, "optimized: %.5f\n", diff);
}

void not_optimized_test(void) {
  const unsigned int limit = 100000;
  char i = 0;
  double diff = 0.0;

  start_chrono();
  for (; i < limit; ++i)
    calculate(rand() % 360);
  diff = elapsed();

  fprintf(stdout ,"not optimized: %.5f\n", diff);
}

void main_test1(void) {
  char i = 2;
  calc_optimize(1);
  do {
    not_optimized_test();
    optimized_test();
  }
  while(i-- > 0);
}

#endif
