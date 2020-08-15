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

  return 0;
}

void init_resources(Resources * resources) {}
void resource_processing(Resources * resources) {}
void print_res_info(Resources * resources) {}
void increase_level_mine(Resources * resources, int id) {}
