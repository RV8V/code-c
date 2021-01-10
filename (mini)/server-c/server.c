#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "extclib/net.h"

#define BUFFER 256

int main(void) {
  int listener = listen_net("0.0.0.0:8080");
  if (listener < 0) {
    fprintf(stderr, "%d\n", listener);
    return 1;
  }

  fprintf(stdout, "%s\n", "server is listening");
  char buffer[BUFFER];

  while(1) {
    int con = accept_net(listener);
    if (con < 0) {
      fprintf(stderr, "%s\n", "error: accept");
      return 3;
    }
    while(1) {
      int length = recv_net(con, buffer, BUFFER);
      if (length < 0) {
        break;
      }
      for (char* p = buffer; *p != '\0'; ++p) {
        *p = toupper(*p);
      }
      send_net(con, buffer, BUFFER);
    }
    close_net(con);
  }

  close_net(listener);
  return 0;
}
