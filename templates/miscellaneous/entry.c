#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
//#include <Windows.h>
//#include <winuser.h>
//#include <conio.h>

#define cnt 5
#define _celoe int
#define show_i printf("%d\n", cnt);

typedef int celoe;
typedef struct {} _point;
typedef int (*f)(int, int, void(*)(void));
typedef int (*fa[4])(int, int);
typedef struct _o {} o_, *_o_;

enum {BOLD = 0b0001, ITALIC = 0b0010, UNDERLINE = 0b0100};

union {
  struct {
    unsigned char is_bold: 1;
    unsigned char is_italic: 1;
    unsigned char is_underline: 1;
    unsigned char: 2;
    unsigned char l: 4;
  };
  unsigned char flags;
};

void free_and_null(void** p) {
  free(*p);
  *p = NULL;
}

BOOL check_in(int x, int y) {
  return (() && () && () && ());
}

int main(int argc, const char* argv[]) {
  /*setlocale(LC_ALL, "Ukraine");
  srand(time(NULL));
  if (int a = 4, celoe x, i = 0, arr[10], m[9], char v[10]; !a) {
    printf("%s\n", "enter"), scanf("%d", &x), printf("x = %g\n", (float)x), sprintf(&v[0], "hello\0");
    while(i <= 10) printf("i = %d\n", i++), printf("%s\n%d\n", v, *(arr + i));;
    do a += ++x++ + ++a;; while(a-- != -1);
    for (;;) for (; i < 9; i++, *(m + i) = i + 1); if (a--) return -1;
  }/

  celoe i = cnt;
  OemToChar(s, s);*/

  int i = 0;
  for (; i < argc; ++i) {
    char* c;
    float f = strtof(argv[i], &c);
    printf("%s -- %s --\n", *c == 0 ? "digit" : "string", argv[i]);
  }

  while(*argv)
    printf("%s\n", *argv++);

  struct _text t;
  t.is_bold = t.is_italic = 1;
  t.is_underline = 0;

  char text = BOLD | UNDERLINE;
  if (text & BOLD) {
    printf("%s\n", "Text is in bold");
  }

  int i = 2;
  char c[2];
  sprintf(&c[0], "%i", i);

  itoa(i, c, 10);
  printf("string = %s\n", c);

  float f;
  char s[40] = "567";
  i = atoi(s);
  f = atof(s);

  char _s[21];
  _s[20] = '\0';

  for (int i = 0; i < 20; ++i) {
    _s[i] = rand() % ('z' - 'a' + 1) + 'a';
  }

  void* p;
  *p = 0;

  int* ptr;
  ptr = &i;

  if (ptr != NULL) {
    *ptr = 4;
  }

  int* ai = NULL;
  ai = (int*)malloc(sizeof(int) * 2);

  *ai = 0;

  ai = (int*)realloc(ai, sizeof(int) * 5);

  free(ai);
  ai = (int*)malloc(sizeof(int) * 3);

  free(ai);
  ai = NULL;

  int l = 4;
  for (int i = 0; i < l; ++i) {
    printf("address = %d\n", &*(arr + i));
    printf("address = %d\n", arr + i);
  }

  void* o = NULL;
  o = malloc(8);

  if (o != NULL) {
    *(int*)o = 8;
    *(double*)o = 0.23;

    free_and_null(&o);
    printf("%d\n", *(int*)o);
  }

  free(o);
  o = NULL;

  printf("%s\n", _s);
  return 0;
}
