#include "io.h"

#define INDEX(ptr, init) (ptr-init)

extern void inputs_io(char* buffer, size_t size) {
  if (size == 0) {
    return;
  }
  char* ptr = buffer;
  while((*ptr = getchar()) != '\n' && INDEX(ptr, buffer) < size - 1) {
    ++ptr;
  }
  *ptr = '\n';
}
