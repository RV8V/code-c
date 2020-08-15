#ifndef TEST_H
#define TEST_H

#include <math.h>
#include <stdlib.h>

#define PARAMS_COUNT 4
#define POWER 0
#define ARMOR 1
#define INTELLEGENCE 2
#define POWER_2 3

unsigned char player_params[PARAMS_COUNT] = { 0 };

void print_common_power(void) {
  char i = PARAMS_COUNT, result = 0;
  do result += player_params[i];
  while(i-- > 0);
  printf("common: %d\n", result);
}

void print_params(void) {
  unsigned char i = 0;
  for (; i < PARAMS_COUNT; ++i) {
    if (i == POWER) fprintf(stdout, "power: %i\n", player_params[POWER]);
    if (i == ARMOR) fprintf(stdout, "armor: %i\n", player_params[ARMOR]);
    if (i == POWER_2) fprintf(stdout, "power_2: %i\n", player_params[POWER_2]);
    if (i == INTELLEGENCE) fprintf(stdout, "intellegence: %i\n", player_params[INTELLEGENCE]);
  }
}

void init_param_values(void) {
  char i = PARAMS_COUNT;
  do player_params[i] = rand() % 40;
  while(i-- > 0);
}

void main_test2(void) {
  init_param_values();
  print_params();
}

#endif
