#ifndef _ROUTES_H_
#define _ROUTES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "../extclib/http.h"

void index_page(int con, HTTPreq* req);
void about_page(int con, HTTPreq* req);

#endif /* _ROUTES_H_ */
