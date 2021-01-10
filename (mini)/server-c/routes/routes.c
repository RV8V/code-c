#include "routes.h"

void index_page(int con, HTTPreq* req) {
  printf("%s - %s - %s\n", req->method, req->path, req->proto);
  if (strcmp(req->path, "/") != 0) {
    parsehtml_http(con, "static/page404.html");
    return;
  }
  parsehtml_http(con, "static/index.html");
}

void about_page(int con, HTTPreq* req) {
  if (strcmp(req->path, "/about") != 0) {
    parsehtml_http(con, "static/page404.html");
    return;
  }
  parsehtml_http(con, "static/about.html");
}
