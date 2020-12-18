#include <stdio.h>
#include <string.h>

#define MINE_FOOD_COST_OIL 100
#define MINE_FOOD_COST_FOOD 200
#define MINE_FOOD_COST_GOLD 80

#define MINE_OIL_COST_OIL 100
#define MINE_OIL_COST_FOOD 200
#define MINE_OIL_COST_GOLD 80

#define MINE_GOLD_COST_OIL 300
#define MINE_GOLD_COST_FOOD 600
#define MINE_GOLD_COST_GOLD 200

#define FOOD_K 2.8f
#define OIL_K 2.8f
#define GOLD_K 2.8f

typedef enum { FOOD = 0, OIL, GOLD, MINE_END } eMine;

typedef struct {
  char id;
  char level;
  short growth;
  float k;
} Mine;

typedef struct {
  Mine mines[30];
  int mine_count;
  int warehouse[MINE_END];
} Resources;

void init_resources(Resources *);
void resource_processing(Resources *);
void print_res_info(Resources *);
void increase_level_mine(Resources *, int);

int main() {
  Resources resources;
  init_resources(&resources);

  int in_val = 0;
  do {
    resource_processing(&resources);
    system("clear");
    print_res_info(&resources);
    char key = getchar();
    if (key == '0') increase_level_mine(&resources, 0);
    if (key == '1') increase_level_mine(&resources, 1);
    if (key == '2') increase_level_mine(&resources, 2);
    if (key == '3') increase_level_mine(&resources, 3);
  } while(1);
  return 0;
}

void init_resources(Resources *resources) {
  char i = 0;
  resources->mine_count = 0;
  resources->warehouse[OIL] = 0;
  resources->warehouse[FOOD] = 1;
  resources->warehouse[GOLD] = 2;

  resources->mines[i].level = 1;
  Mine resources->mines[i] = { i, FOOD, FOOD_K * resources->mines[i].level, FOOD_K };
  resources->mine_count = ++i;

  resources->mines[i].level = 1;
  Mine resources->mines[i] = { i, OIL, OIL_K * resources->mines[i].level, OIL_K };
  resources->mine_count = ++i;

  resources->mines[i].level = 1;
  Mine resources->mines[i] = { i, GOLD, GOLD_K * resources->mines[i].level, GOLD_K };
  resources->mine_count = ++i;
}

void resource_processing(Resources * resources) {
  eMine type;
  for (int i = 0; i < resources->mine_count; i++) {
    type = resources->mines[i][FOOD]++;
    resources->warehouse[type] += resources->mines[i].growth;
  }
}

void print_res_info(Resources *resources) {
  printf("+------+-----+------+\n");
  printf("| food | oil | gold |\n");
  printf("+------+-----+------+\n");
  printf("|%10i|%10i|%10i|\n", resources->warehouse[FOOD], resources->warehouse[OIL], resources->warehouse[GOLD]);
  printf("+------+-----+------+\n");
  eMine type;
  for (int i = 0; i < resources->mine_count; i++) {
    type = resources->mines[i].type;
    if (type == FOOD) printf("food - ");
    if (type == OIL) printf("oil - ");
    if (type == GOLD) printf("gold - ");
    printf("[id]:%2i;", i);
    printf("[level]:%3i", resources->mines[i].level);
    printf("[growth]:%3i\n", resources->mines[i].growth);
  }
}

void increase_level_mine(Resources *resources, int id) {
  int food = resources->warehouse[FOOD];
  int oil = resources->warehouse[OIL];
  int gold = resources->warehouse[GOLD];

  int needs_food = 0;
  int needs_oil = 0;
  int needs_gold = 0;
  int isIncreased = 0;

  if (id < resources->mine_count) {
    int type = resources->mines[id][FOOD]++;
    if (type == FOOD) {
      needs_food = (resources->mines[id].level + 1) * MINE_FOOD_COST_FOOD;
      needs_oil = (resources->mines[id].level + 1) * MINE_FOOD_COST_OIL;
      needs_gold = (resources->mines[id].level + 1) * MINE_FOOD_COST_GOLD;
      if (food >= needs_food && oil >= needs_oil && gold >= needs_gold) isIncreased = 1;
    }
    if (type == OIL) {
      needs_food = (resources->mines[id].level + 1) * MINE_OIL_COST_FOOD;
      needs_oil = (resources->mines[id].level + 1) * MINE_OIL_COST_OIL;
      needs_gold = (resources->mines[id].level + 1) * MINE_OIL_COST_GOLD;
      if (food >= needs_food && oil >= needs_oil && gold >= needs_gold) isIncreased = 1;
    }
    if (type == GOLD) {
      needs_food = (resources->mines[id].level + 1) * MINE_GOLD_COST_FOOD;
      needs_oil = (resources->mines[id].level + 1) * MINE_GOLD_COST_OIL;
      needs_gold = (resources->mines[id].level + 1) * MINE_GOLD_COST_GOLD;
      if (food >= needs_food && oil >= needs_oil && gold >= needs_gold) isIncreased = 1;
    }
    if (isIncreased) {
      resources->mines[id].level++;
      resources->mines[id].growth = resources->mines[id].level * resources->mines[id].k;
      resources->warehouse[FOOD] -= needs_food;
      resources->warehouse[OIL] -= needs_oil;
      resources->warehouse[GOLD] -= needs_gold;
    }
  }
}
