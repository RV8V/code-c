#include <string.h>
#include <stdio.h>

#include "routes/routes.h"

int main(void) {
  HTTP* serve = new_http("127.0.0.1:7545");

  handle_http(serve, "/", index_page);
  handle_http(serve, "/about", about_page);

  listen_http(serve);
  free_http(serve);
  return 0;
}
