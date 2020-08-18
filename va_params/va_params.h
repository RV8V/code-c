#ifndef VA_PARAMS_H
#define VA_PARAMS_H

typedef enum { UNIT = 0, DATA, END } Type;

typedef struct { int health; int armor; } Unit;
typedef struct { int value_a; int value_b; int value_c; } Data;

void f_a(int, ...);
void f_b(char *, ...);
void f_c(Type, ...);

void example_a(void);
void example_a(void);
void example_a(void);

#endif
