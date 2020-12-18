#include <stdio.h>
#include <string.h>

void print_str(const char *);
void print_chars(const char *);
void print_uint32_arr(const unsigned int *, unsigned int len);

void sum_f(float, float, float *);
void div_f(float, float, float *);

struct Student {
  char name[20];
  unsigned char age;
  unsigned char course;
};

struct Student_list {
  struct Student *st;
  void (*add_course)(struct Student *);
  void (*add_age)(struct Student *);
  void (*modify_name)(struct Student *, char *);
  void (*delete_pos)(struct Student *, unsigned int, unsigned int *);
};

void add_student(struct Student *, unsigned int *, char *, unsigned char, unsigned char);
void add_course(struct Student *);
void add_age(struct Student *);
void modify_name(struct Student*, char *);
void delete_pos(struct Student *, unsigned int, unsigned int *);
void print_student(struct Student *);

int main(int argc, char const *argv[]) {
  unsigned int *print_str_addr;
  print_str_addr = (unsigned int *)(&print_str);
  printf("%p\n", (unsigned int *)(&print_str_addr));

  void (*print_str_new)(const char *c_str);
  print_str_new = (void *)print_str_addr;
  print_str_new("hello world");

  void (*print_str_next)(const char *);
  print_str_next = (void *)(&print_str);
  (*print_str_next)("hello world");

  void (*print_str_next_test)(const char *) = (void *)(&print_str);

  void (*fns_arr[4])(float, float, float *) = { sum_f, div_f };

  float i = 2, a = 2., b = 3., res = 0.;
  do {
    (*fns_arr)(a, b, &res);
    fns_arr++;
  } while((int)i-- > 0);

  struct Student st[20];
  unsigned int st_count = 0, g = 20;

  do {
    add_student(st + st_count, &st_count, "name", 2 + g, 18 + g);
    if (g == 1) break;
  } while(g--> 0);

  for (int i = 0; i < st_count; i++) print_student(st + i);
  printf("student counter: %d\n\n", st_count);

  struct Student_list st_list = { st, add_course, add_age, modify_name, delete_pos };
  st_list.add_course(st + 5);
  st_list.add_age(st + 1);
  st_list.modify_name(st + 2, "hello world");
  for (int i = 0; i < st_count; i++) print_student(st + i);

  st_list.delete_pos(st, 4, &st_count);
  for (int i = 0; i < st_count; i++) print_student(st + i);

  return 0;
}

void print_str_next(const char *c_str) {}
void print_str_new(const char *c_str) {}
void print_str_next_test(const char *c_str) {}

void print_str(const char *c_str) {
  printf("%s\n", c_str);
}

void print_chars(const char *a) {}
void print_uint32_arr(const unsigned int *a, unsigned int len) {}

void sum_f(float a_f, float b_f, float *sum_f) {
  *sum_f = a_f + b_f;
}

void div_f(float a_f, float b_f, float *div_f) {
  *div_f = a_f / b_f;
}

void add_student(struct Student *res_st, unsigned int *student_counter, char *ch, unsigned char cr, unsigned char age) {
  strcpy(res_st->name, ch);
  res_st->course = cr;
  res_st->age = age;
  (*student_counter)++;
}

void delete_pos(struct Student *st_list, unsigned int pos, unsigned int *student_counter) {
  for (unsigned int i = pos; i < *student_counter; i++) {
    strcpy(st_list[i].name, st_list[i + 1].name);
    st_list[i].age = st_list[i].age;
    st_list[i].course = st_list[i + 1].course;
  }
  (*student_counter)--;
}

void add_course(struct Student *st) {
  st->course++;
}

void add_age(struct Student *st) {
  st->age++;
}

void modify_name(struct Student *st, char *ch) {
  strcpy(st->name, ch);
}

void print_student(struct Student *st) {
  printf("name: %s, age: %d, course: %d\n", st->name, st->age, st->course);
}
