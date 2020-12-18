#include <stdio.h>

void two_dimensional_array_example_a() {
  int arr_a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } }; // 0x?? 1 2 3 4 5 6
  int arr_b[][3] = { { 1, 2, 3 }, { 4, 5, 6 } }; // 0x?? 1 2 3 4 5 6
  //int arr_a[][] = { { 1, 2, 3 }, { 4, 5, 6 } }; // error

  void print(int *p_array, int lines, int columns) {
    for (int l = 0; l < lines; l++) {
      for (int c = 0; c < columns; c++)
        printf("%d", p_array[l * columns + c]);
      printf("\n");
    }
  }

  int get_value(const int *p_array, int lines, int columns) {
    return p_array[lines * columns + columns];
  }

  void set_value(const int *p_array, int lines, int columns, int value) {
    p_array[lines * columns + columns] = value;
  }

  printf("%p\n", &arr_a); /* the same address */
  printf("%p\n", &arr_a[0]);
  printf("%p\n", &arr_a[0][0]);

  // print(arr_a, 1, 2); /* warning */
  // print(&arr_a[0], 1, 2); /* warning */
  print(&arr_a[0][0], 1, 2);

  printf("%i\n", get_value(&arr_a[0][0], 3, 1));
  set_value(&arr_a[0][0], 3, 1, 100);
  printf("%i\n", get_value(&arr_a[0][0], 3, 1));
}

void two_dimensional_array_example_b() {
  int arr_a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } }; // 0x?? 1 2 3 4 5 6
  int arr_b[][3] = { { 1, 2, 3 }, { 4, 5, 6 } }; // 0x?? 1 2 3 4 5 6

  void print_a23(int p_array[2][3]) {
    for (int l = 0; l < 2; l++) {
      for (int c = 0; c < 3; c++)
        printf("%d", p_array[l][c]);
      printf("\n");
    }
  }

  int get_value_a23(const int p_array[2][3], int lines, int columns) {
    return  p_array[lines][columns];
  }

  void set_value_a23(const int p_array[2][3], int lines, int columns, int value) {
    p_array[lines][columns] = value;
  }

  print_a23(arr_a);
  print_a23(arr_b);

  printf("%i\n", get_value_a23(arr_a, 1, 1));
  set_value_a23(arr_a, 1, 1, 100);
  printf("%i\n", get_value_a23(arr_a, 1, 1));
}

void two_dimensional_array_example_c() {
  int arr_a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } }; // 0x?? 1 2 3 4 5 6
  int arr_b[][3] = { { 1, 2, 3 }, { 4, 5, 6 } }; // 0x?? 1 2 3 4 5 6

  void print_al3(int p_array[][3]) {
    for (int l = 0; l < lines; l++) {
      for (int c = 0; c < 3; c++)
        printf("%d", p_array[l][c]);
      printf("\n");
    }
  }

  int get_value_al3(const int p_array[][3], int lines, int columns) {
    return  p_array[lines][columns];
  }

  void set_value_al3(const int p_array[][3], int lines, int columns, int value) {
    p_array[lines][columns] = value;
  }

  print_al3(arr_a);
  print_al3(arr_b);

  printf("%i\n", get_value_al3(arr_a, 1, 1));
  set_value_al3(arr_a, 1, 1, 100);
  printf("%i\n", get_value_al3(arr_a, 1, 1));
}

int main(int argc, char const *argv[]) {
  two_dimensional_array_example_a();
  two_dimensional_array_example_b();
  two_dimensional_array_example_c();
  return 0;
}
