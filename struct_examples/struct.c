#include <stdio.h>
#include "struct.h"

void s_a_print_info(void) {
  {
    s_a_d s;
    s.ch_a = 0;
    s.ch_b = 1;
    printf("size of s_a_d = %ld\n", sizeof(s_a_d));
    printf("\t+------+------+\n");
    printf("\t| ch_a | ch_b |\n");
    printf("\t+------+------+\n\n");

    printf("\t0x%p(ch_a): %x\n", &s.ch_a, *(char *)(&s.ch_a));
    printf("\t0x%p(ch_b): %x\n", &s.ch_b, *(char *)(&s.ch_b));
    printf("<----->\n");
  }
  {
    s_a_p s;
    s.ch_a = 0;
    s.ch_b = 1;
    printf("size of s_a_p = %ld\n", sizeof(s_a_p));
    printf("\t+------+------+\n");
    printf("\t| ch_a | ch_b |\n");
    printf("\t+------+------+\n\n");

    printf("\t0x%p(ch_a): %x\n", &s.ch_a, *(char *)(&s.ch_a));
    printf("\t0x%p(ch_b): %x\n", &s.ch_b, *(char *)(&s.ch_b));
    printf("<----->\n");
  }
}

void s_b_print_info(void) {
  {
    s_b_p s;
    unsigned char *p;

    s.ch_a = 0xB0;
    s.sh_a = 0xACDE;
    s.sh_b = 0xF00E;
    printf("size of s_b_p = %ld\n", sizeof(s_b_p));
    printf("ch_a - 0x%p\n", &s.ch_a);
    printf("sh_a - 0x%p\n", &s.sh_a);
    printf("sh_b - 0x%p\n", &s.sh_b);

    printf("\t+------+------+------+\n");
    printf("\t| ch_a | sh_a | sh_b |\n");
    printf("\t+------+------+------|\n\n");

    printf("\t+------+------+------|\n");
    p = (unsigned char *)(&s.ch_a);
    printf("\t|  %.2x  |", *p);
    p = (unsigned char *)(&s_sh_a);
    printf("\t|  %.2x  |  %.2x", *p, *(p + 1));
    p = (unsigned char *)(&s.sh_b);
    printf("\t|  %.2x  |  %.2x\n", *p, *(p + 1));
    printf("\t+------+------+------|\n\n");
  }
  {
    s_b_d s;
    unsigned char *p;

    s.ch_a = 0xB0;
    s.sh_a = 0xACDE;
    s.sh_b = 0xF00E;
    printf("size of s_b_d = %ld\n", sizeof(s_b_d));
    printf("ch_a - 0x%p\n", &s.ch_a);
    printf("sh_a - 0x%p\n", &s.sh_a);
    printf("sh_b - 0x%p\n", &s.sh_b);

    printf("\t+------+------+------+\n");
    printf("\t| ch_a | sh_a | sh_b |\n");
    printf("\t+------+------+------|\n\n");

    printf("\t+------+------+------|\n");
    p = (unsigned char *)(&s.ch_a);
    printf("\t|  %.2x  |", *p);
    p = (unsigned char *)(&s_sh_a);
    printf("\t|  %.2x  |  %.2x", *p, *(p + 1));
    p = (unsigned char *)(&s.sh_b);
    printf("\t|  %.2x  |  %.2x\n", *p, *(p + 1));
    printf("\t+------+------+------|\n\n");
  }
}

void s_c_print_info(void) {
  {
    s_c_p s;
    unsigned char *p;

    s.ch_a[0] = 0x01;
    s.ch_a[1] = 0x10;
    s.ch_a[2] = 0x11
    s.i_a = 0x00000002;
    s.sh_a = 0x3333;
    s.sh_b = 0x44;

    printf("size of s_c_p = %ld\n", sizeof(s_c_p));
    printf("ch_a[0] - 0x%p\n", &s.ch_a[0]);
    printf("ch_a[1] - 0x%p\n", &s.ch_a[1]);
    printf("ch_a[2] - 0x%p\n", &s.ch_a[2]);
    printf("i_a     - 0x%p\n", &s.i_a);
    printf("sh_a    - 0x%p\n", &s.sh_a);
    printf("ch_b    - 0x%p\n", &s.ch_b);

    printf("\t+------+------+------+------+------+------+------+------+------+------+\n");
    printf("\t| ch_a | ch_a | ch_a |            i_a             |     sh_a   | ch_b |\n");
    printf("\t+------+------+------+------+------+------+------+------+------+------+\n\n");

    printf("\t+------+------+------+------+------+------+------+------+------+------+\n");
    printf("\t+------+------+------+------+------+------+------+------+------+------+\n");
    p = (unsigned char*)(&s.ch_a[0]);
    printf("\t| %.2x | %.2x | %.2x |", *p, *(p + 1), *(p + 2));
    p = (unsigned char*)(&s.i_a);
    printf("  | %.2x | %.2x | %.2x | %.2x |", *p, *(p + 1), *(p + 2), *(p + 3));
    p = (unsigned char*)(&s.sh_a);
    printf("  | %.2x | %.2x |", *p, *(p + 1));
    p = (unsigned char*)(&s.ch_b);
    printf("  | %.2x |\n", *p);
    printf("\t+------+------+------+------+------+------+------+------+------+------+\n\n");
    printf("<----------> <----------> <---------->\n\n");
  }
  {
    s_c_d s;
    unsigned char *p;

    s.ch_a[0] = 0x01;
    s.ch_a[1] = 0x10;
    s.ch_a[2] = 0x11;
    s.i_a = 0x00000002;
    s.sh_a = 0x3333;
    s.ch_b = 0x44;

   printf("size of s_c_d = %li\n\n", sizeof(s_c_d));
   printf("ch_a[0] - 0x%p\n", &s.ch_a[0]);
   printf("ch_a[1] - 0x%p\n", &s.ch_a[1]);
   printf("ch_a[2] - 0x%p\n", &s.ch_a[2]);
   printf("i_a     - 0x%p\n", &s.i_a);
   printf("sh_a    - 0x%p\n", &s.sh_a);
   printf("ch_b    - 0x%p\n", &s.ch_b);

   printf("\t+------+------+------+------+\n");
   printf("\t| ch_a | ch_a | ch_a |      |\n");
   printf("\t+------+------+------+------+\n");
   printf("\t|            i_a            |\n");
   printf("\t+------+------+------+------+\n");
   printf("\t|    sh_a    | ch_b |       |\n");
   printf("\t+------+------+------+------+\n\n");

   printf("\t+------+------+------+------+\n");
   p = (unsigned char*)(&s.ch_a[0]);
   printf("\t| %.2x | %.2x | %.2x | %.2x |\n", *p, *(p + 1), *(p + 2), *(p + 3));
   printf("\t+------+------+------+------+\n");
   p = (unsigned char*)(&s.i_a);
   printf("\t| %.2x | %.2x | %.2x | %.2x |\n", *p, *(p + 1), *(p + 2), *(p + 3));
   printf("\t+------+------+------+------+\n");
   p = (unsigned char*)(&s.sh_a);
   printf("\t| %.2x | %.2x |", *p, *(p + 1));
   p = (unsigned char*)(&s.ch_b);
   printf("  | %.2x | %.2x |\n", *p, *(p + 1));
   printf("\t+------+------+------+------+\n\n");
 }
}

void test_data(char *p_data) {
  s_problem_d d;
  d = *((s_problem_d*)(p_data));
  printf("ch = %c\n", d.ch);
  printf("sh = %i\n", d.sh);
}

void problem_example(void) {
  s_problem_d data;
  char *send_buffer;
  data.ch = 'a';
  data.sh = 0x200;
  send_buffer = (char*)&(data);
  test_data(send_buffer);
}
