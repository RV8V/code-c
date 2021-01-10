#include <stdio.h>
#include <stdint.h>

#include "extclib/net.h"
#include "extclib/io.h"

#define BUFFER_SIZE 256

extern void inputs_io(char* buffer, size_t size);

int main(void) {
  int con = connect_net("127.0.0.1:8080");
  if (con < 0) {
    fprintf(stderr, "%d\n", con);
    return 1;
  }

  char buffer[BUFFER_SIZE];
  inputs_io(buffer, BUFFER_SIZE);

  send_net(con, buffer, BUFFER_SIZE);
  recv_net(con, buffer, BUFFER_SIZE);

  fprintf(stdout, "%s\n", buffer);
  close_net(con);

  return 0;
}
