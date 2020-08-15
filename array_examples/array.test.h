#ifndef TEST_H
#define TEST_H

unsigned char player_params[2] = { 0 };

void print_common_power(void) {
  char i = 2, result = 0;
  do result += player_params[i];
  while(i-- > 0);
  printf("common: %d\n", result);
}

void main_test2() {
  player_params[0] = 1;
  player_params[1] = 2;

  print_common_power();
}

#endif
