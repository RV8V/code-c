#include <stdio.h>

void *pointer_test_a(void const *, long int const **);
void ***d_pointer_test_a(char const **);
unsigned short int const **a_d_p_a(void *[]);

int main(int argc, char const **argv) {
  int num = 123, *pr2, **pr1;
  pr2 = &num; pr1 = &pr2;

  printf("Value of num is: \t%d\n", num);
  printf("Value of *pr2 is: \t%d\n", *pr2);
  printf("Value of **pr1 is: \t%d\n\n", **pr1);

  printf("address of num is: \t%p\n", &num);
  printf("address of *pr2 is: \t%p\n", pr2);
  printf("address of **pr1 is: \t%p\n\n", *pr1);

  printf("value of pointer pr2: \t\t%p\n", pr2);
  printf("value of pointer pr2 using pr1: \t%p\n\n", *pr1);

  printf("address of pointer pr2: \t\t%p\n", &pr2);
  printf("address of pointer pr2 using pr1: \t%p\n\n", pr1);

  printf("Value of Pointer pr1 is: %p\n", pr1);
  printf("Address of Pointer pr1 is: %p\n\n", &pr1);

  if (num == *pr2 == **pr1) printf("%s\n", "ok");
  //if (&num == pr2 == *pr1) printf("%s\n", "ok");
  if (&pr2 == pr1) printf("%s\n", "ok");

  short int i_a = 10;
  long int *p_i_a = (long int *)(void *)(&i_a);
  short int **d_p_i_a = (short int **)(void **)(&p_i_a);

  printf("address1: %p\n", &i_a);
  printf("address2: %p\n", p_i_a);
  printf("address3: %p\n\n", *d_p_i_a);

  pointer_test_a((void const *)(p_i_a), (long int const **)(d_p_i_a));
  d_pointer_test_a((char const **)(p_i_a));
  a_d_p_a((void **)(p_i_a));
}

void *pointer_test_a(void const *p_a, long int const **d_p_a) {
  char const ***t_p_a = (char const ***)(&d_p_a);
  printf("address -1: %p\n", d_p_a);
  printf("address 0: %p\n", *t_p_a);
  unsigned short int const **p_pointer = (unsigned short int const **)(&p_a);
  printf("address 1: %p\n", p_a);
  printf("address 2: %p\n", *p_pointer);
  printf("value 0: %d\n", ***t_p_a);
  return (void *)(*p_pointer);
}

void ***d_pointer_test_a(char const **d_poiter) {
  return (void ***)(&d_poiter);
}

unsigned short int const **a_d_p_a(void *a[]) {
  printf("address1: %p\n", a);
  printf("address2: %p\n", *a);
  return (unsigned short int const **)(&a);
}
