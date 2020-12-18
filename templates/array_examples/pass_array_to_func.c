#include <stdio.h>

void one_dimensional_array_example_a() {
  int arr_a[3] = { 1, 2, 3 };
  int arr_c[] = { 1, 2, 3 };
  int arr_b[] = { [0] = 10, [2] = 3 };

  void print(int  *p_array, int length) {
    for (int i = 0; i < length; i++)
      printf("%i", *(p_array + i));
    printf("\n");
  }

  int get_value(const int *p_array, int index) {
    return *(p_array + index);
  }

  void set_value(int *p_array, int index, int value) {
    *(p_array + index) = value;
  }

  int change_element_of_storing(int *p_array, int index) {
    return *((char *)p_array + index);
  }

  print(arr_a, 3);
  printf("before: [1] = %d\n", get_value(arr_a, 3));
  set_value(arr_a, 4, 0);
  printf("change_element_of_storing: %d\n", change_element_of_storing(arr_a, 3));

  print(arr_c, 3);
  printf("before: [1] = %d\n", get_value(arr_c, 19));
  set_value(arr_c, 0, 0);
  printf("change_element_of_storing: %d\n", change_element_of_storing(arr_c, 2));
}

void one_dimensional_array_example_b() {
  int arr_a[3] = { 1, 2, 3 };
  int arr_c[] = { 1, 2, 3 };
  int arr_b[] = { [0] = 10, [2] = 3 };

  void print(int p_array[], int length) {
    for (int i = 0; i < length; i++)
      printf("%i", p_array[i]);
    printf("\n");
  }

  int get_value(const int p_array[], int index) {
    return p_array[i];
  }

  void set_value(int p_array[], int index, int value) {
    p_array[index] = value;
  }

  print(arr_a, 3);
  printf("before: [1] = %d\n", get_value(arr_a, 3));
  set_value(arr_a, 0, 1);
  printf("change_element_of_storing: %d\n", change_element_of_storing(&arr_a[0], 3));

  print(arr_c, 3);
  printf("before: [1] = %d\n", get_value(arr_c, 19));
  set_value(arr_c, 0, 1);
  printf("change_element_of_storing: %d\n", change_element_of_storing(arr_c, 2));
}

void one_dimensional_array_example_c() {
  int arr_a[3] = { 1, 2, 3 };
  int arr_c[] = { 1, 2, 3 };
  int arr_b[] = { [0] = 10, [2] = 3 };

  void print(int  (*p_array)[], int length) {
    for (int i = 0; i < length; i++)
      printf("%i", *(*p_array + i));
    printf("\n");
  }

  int get_value(const int (*p_array)[], int index) {
    return *(*p_array + index);
  }

  void set_value(int (*p_array)[], int index, int value) {
    *(*p_array + index) = value;
  }

  int change_element_of_storing(int *p_array, int index) {
    return *((char *)*p_array + index);
  }

  print(&arr_a, 3);
  printf("before: [1] = %d\n", get_value(&arr_a, 3));
  set_value(&arr_a, 0, 4);
  printf("change_element_of_storing: %d\n", change_element_of_storing(&arr_a, 3));

  print(&arr_c, 3);
  printf("before: [1] = %d\n", get_value(&arr_c, 19));
  set_value(&arr_c, 0, 6);
  printf("change_element_of_storing: %d\n", change_element_of_storing(&arr_c, 2));
}

void one_dimensional_array_example_d() {
  #define AR1_SIZE 3
  int arr_a[AR1_SIZE + 1] = { AR1_SIZE };

  #define AR2_SIZE 7
  int arr_b[AR2_SIZE + 1] = { AR2_SIZE, 1, 2, 3, 4, 5, 6, 7 };

  #define AR3_SIZE 1
  int arr_c[AR3_SIZE + 1] = {AR3_SIZE, 1};

  void print(int array[]) {
    const int end = array[0] + 1;
    for (int i = 0; i < end; i++)
      printf("%d", array[i]);
    printf("\n");
  }

  int get_value(const int array[], int index) {
    if (index > array[0]) return 0;
    return array[index + 1];
  }

  void set_value(const int array[], int index, int value) {
    if (index > array[0]) return 0;
    array[index + 1] = value;
  }

  set_value(arr_a, 2, 4);
  print(arr_a);

  set_value(arr_b, 5, 6);
  print(arr_b);

  set_value(arr_c, 0, 3);
  print(arr_c);
}

int main(int argc, char const *argv[]) {
  one_dimensional_array_example_a();
  one_dimensional_array_example_b();
  one_dimensional_array_example_c();

  int tmp = 0;
  int *a1 = 0; /* poiner to int or array */
  int *a2[1] = { 0 }; /* array of pointers to int */
  int (*a3)[]; /* poiner to array of int */
  int a4[2] = { 1, 2 }; /* arrays of int */

  // a1 = 1; /* warrning - incompatible type*/
  a1 = &tmp;

  // a2[0] = 1;        /* warrning - incompatible type*/
  a2[0] = &tmp;

  a3 = &a4;
  tmp = a4[0];
  *(*a3) = 2;
  // *(*a3) = &tmp;    /* warrning - incompatible type*/

  tmp = *(*a3);
  tmp = a4[0];

  a = 0; /* -> array[] */
  a = NULL; /* -> *array*/
}
