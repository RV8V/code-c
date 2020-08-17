#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#define TEST_1
void input_output_a(void);
void input_output_b(void);

#elif defined(TEST_2)
void input_output_a_error(void);
void input_output_b_error(void);

#elif defined(TEST_3)
#define BUF_SIZE 19
void input_output_e(void);
void input_output_f(void);

#elif defined(TEST_4)
typedef struct { int id; int value; } Test1;
typedef struct { int id; char *str; } Test2;

void input_output_struct_a(void);
void input_output_struct_b(void);

#elif
