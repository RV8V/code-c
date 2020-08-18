#include <stdio.h>

#define BUFFER_SIZE 5

typedef struct {
  int read_index;
  int write_index;
  int is_empty;
  int is_full;
  int data[BUFFER_SIZE];
} CircularBuffer;

void init(CircularBuffer *);
int put(CircularBuffer *, int);
int get(CircularBuffer *);
void clear(CircularBuffer *);
int is_empty(CircularBuffer *);
int is_full(CircularBuffer *);

/*
  in = 0
  out = 0
  [] [] [] []

  put(1)
    [1] [] [] []
    in++

  put(2)
    [1] [2] [] []
    in++

  put(3)
    [1] [2] [3] []
    in++

  put(4)
    [1] [2] [3] [4]
    in++

  put(5)
    [1] [2] [3] [4]

  get() = 1
    out++
    [] [2] [3] [4]
*/

void init(CircularBuffer *p_buffer) {
  p_buffer->read_index = 0;
  p_buffer->write_index = 0;
  p_buffer->is_empty = 1;
  p_buffer->is_full = 0;
}

int put(CircularBuffer *p_buffer, int const value) {
  if (p_buffer->is_full) return -1;
  if (p_buffer->write_index >= BUFFER_SIZE) p_buffer->write_index = p_buffer->read_index;

  if (p_buffer->is_empty) {
    p_buffer->is_empty = 0;
    p_buffer->data[p_buffer->write_index++] = value;
    if (p_buffer->write_index == p_buffer->read_index) p_buffer->is_full = 1;
    return 1;
  }

  p_buffer->data[p_buffer->write_index++] = value;
  if (p_buffer->write_index == p_buffer->read_index) p_buffer->is_full = 1;
  return 1;
}

int get(CircularBuffer *p_buffer) {
  if (p_buffer->is_empty) return -1;
  p_buffer->is_full = 0;

  if (p_buffer->read_index >= BUFFER_SIZE) p_buffer->read_index = 0;
  int const res = p_buffer->data[p_buffer->read_index++];

  if (p_buffer->read_index == p_buffer->write_index) p_buffer->is_empty = 1;
  return res;
}

void clear(CircularBuffer *p_buffer) {
  p_buffer->is_empty = 1;
  p_buffer->is_full = 0;
  p_buffer->write_index = 0;
  p_buffer->read_index = 0;
}

int is_empty(CircularBuffer *p_buffer) {
  return p_buffer->is_empty;
}

int is_full(CircularBuffer *p_buffer) {
  return p_buffer->is_full;
}

int main(int argc, char const *argv[]) {
  CircularBuffer buffer;
  init(&buffer);

  char i = 5, g = 4;
  do {
    put(&buffer, i);
    get(&buffer);
    if (i == 5) clear(&buffer);
  } while(i-- > 0);

  i = 3;
  do {
    put(&buffer, i);
    get(&buffer);
  } while(i-- > 0);

  i = 6;
  do get(&buffer); while(i-- > 0);
  do put(&buffer, i + g); while(i-- > 0);

  i = 6;
  do get(&buffer); while(i-- > 0);
  return 0;
}
