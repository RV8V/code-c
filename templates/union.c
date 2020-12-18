#include <stdio.h>
#include <string.h>

typedef union { char ch; short sh; int i; long l; } Example_a;
/* ch: #, sh: ##, i: ####, l: ######## */

typedef union { char ch; short sh; int i; char buffer[9]; } Example_b;
/* ch: #, sh: ##, i: ####, buffer: ######## #??????? */

typedef union { char buffer[9]; char ch; short sh; int i; } Example_c;
/* buffer: ######## #??????? ,ch: #, sh: ##, i: #### */

typedef enum { KEY_PRESSED = 0, MOUSE_PRESSED } InputType;

typedef struct {
  InputType input_type;
  union {
    int key_code;
    struct { int x; int y; int key_code; } mouse_info;
  } union;
} InputEvent_a;

typedef struct {
  InputType input_type;
  union {
    int key_code;
    struct { int x; int y; int key_mouse_codel; };
  };
} InputEvent_b;

typedef enum { CHAR = 0, INTEGER, FLOAT, DOUBLE } Type;

typedef struct {
  Type type;
  union { char ch; int i; float f; double d; };
} Variant_a;

int main(int argc, char const *argv[]) {
  printf("size of union example_a: %ld\n", sizeof(Example_a));
  printf("size of union example_b: %ld\n", sizeof(Example_b));
  printf("size of union example_c: %ld\n", sizeof(Example_c));

  {
    InputEvent_a event;
    event.input_type = MOUSE_PRESSED;
    event.union.mouse_info.x = 10;
    event.union.mouse_info.y = 10;
    event.union.key_code = 1;

    event.input_type = KEY_PRESSED;
    event.key_code = 27;
  }

  {
    InputEvent_b event;
    event.input_type = MOUSE_PRESSED;
    event.x = 10;
    event.y = 10;
    event.key_mouse_codel = 1;

    event.input_type = KEY_PRESSED;
    event.key_code = 27;
  }

  Variant_a var;
  var.type = CHAR;
  var.ch = 'A';

  if (var.type == CHAR)
    if (var.ch == 'A') {
      var.type = FLOAT;
      var.f = 1.234f;
    }

  var.type = DOUBLE;
  var.d = 1.412;

  var.type = INTEGER;
  var.i = 1.1;

  return 0;
}
