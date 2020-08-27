#include <stdio.h>

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
  printf("address3: %p\n", *d_p_i_a);
}
