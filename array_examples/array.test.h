#ifndef TEST_H
#define TEST_H

#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define PARAMS_COUNT 4
#define POWER 0
#define ARMOR 1
#define INTELLEGENCE 2
#define POWER_2 3

#define COUNT_FOOD_FARM 5
#define COUNT_OIL_FARM 5
#define FARM_K 1.2

unsigned short food_farm[COUNT_FOOD_FARM] = { 1 };
unsigned short oil_farm[COUNT_OIL_FARM] = { 1 };

unsigned short oil_warehouse = 0;
unsigned short food_warehouse = 0;

unsigned char player_params[PARAMS_COUNT] = { 0 };

void resource_processing(void) {
  float food_produce = 0.0f, oil_produce = 0.0f;

  char i = 0;
  for (; i < COUNT_FOOD_FARM; ++i)
    if ((rand() % 30) == 5) food_farm[i]++;

  i = 0;
  for (; i < COUNT_OIL_FARM; ++i)
    if ((rand() % 30) == 5) oil_farm[i]++;

  for (i = 0; i < COUNT_FOOD_FARM; ++i)
    food_produce += food_farm[i] * FARM_K;
  for (i = 0; i < COUNT_OIL_FARM; ++i)
    oil_produce += oil_farm[i] * FARM_K;
  food_warehouse += food_produce;
  oil_warehouse += oil_produce;

  system("clear");
  fprintf(stdout, "food produce (h) -> %0.f\n", food_produce * 3600.f);
  fprintf(stdout, "oil produce (h) -> %0.f\n", oil_produce * 3600.f);
  fprintf(stdout, "food warehouse: %d\n", food_warehouse);
  fprintf(stdout, "oil warehouse: %d\n", oil_warehouse);
}

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
  do {
    resource_processing();
    sleep(1);
  }
  while(1);
}

#endif
