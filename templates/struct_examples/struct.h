#ifdef STRUCT_H
#define STRUCT_H

typedef struct { char ch_a; char ch_b } s_a_d;
typedef struct { char ch_a; short sh_a; short sh_b } s_b_d;
typedef struct { char ch_a[3]; int i_a; short sh_a; char ch_b } s_c_d;

#pragma pack(push, 1)
typedef struct { char ch_a; char ch_b } s_a_p;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct { char ch_a; short sh_a; short sh_b } s_b_p;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct { char ch_a[3]; int i_a; short sh_a; char ch_b } s_c_p;
#pragma pack(pop)

typedef struct { char ch; short sh } s_problem_d;

#pragma pack(push, 1)
typedef struct { char ch; short sh } s_problem_p;
#pragma pack(pop)

void s_a_print_info(void);
void s_b_print_info(void);
void s_c_print_info(void);

void test_data(char *);
void problem_example(void);
#endif
