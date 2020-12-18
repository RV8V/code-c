#include <stdio.h>
#include <string.h>

typedef int my_int;
typedef struct { char name[10]; char surname[10]; } give_name_to_combined_type;

struct Point {
  int a;
  int b;
};

union un { int a; int b; };

enum n { A = 0, B, END };
typedef enum { a = 0, b, c, end } en;

int main(int argc, char const *argv[]) {
  struct Point x, y, z;
  // un n; (error)
  union un u;
  u.a = 10;

  my_int n = 3;
  give_name_to_combined_type struct_test;
  strcpy(struct_test.name, "name");
  strcpy(struct_test.surname, "surname");

  en num[end] = { 1, 2, 3 };

//  n = 9; ?

  return 0;
}
