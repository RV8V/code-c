#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <unistd.h>

using namespace std;

struct Line;

void change(vector<Line>&, mutex&);
void rollback(vector<Line>&, mutex&);
void view(vector<Line>&, mutex&);
void start(void);

#endif /* _TRANSACTION_H */
