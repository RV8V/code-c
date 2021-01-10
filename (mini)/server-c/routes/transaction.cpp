#include "transaction.h"

struct Line {
  Line(const char* name, const char* lastname, int year): name(name), lastname(lastname), year(year) {}
  int year;
  const char* name;
  const char* lastname;
};

void start(void) {
  vector<Line> db;
  db.push_back(Line("Nikola", "Tesla", 1856));
  db.push_back(Line("Albert", "Einstein", 1879));
  db.push_back(Line("Bill", "Gates", 1955));
  db.push_back(Line("Stive", "Jobs", 1955));
  db.push_back(Line("Mark", "Zuckerberg", 1984));

  mutex mtx;

  thread tr1(change, ref(db), ref(mtx));
  thread tr2(rollback, ref(db), ref(mtx));
  thread tr3(view, ref(db), ref(mtx));

  tr1.join();
  tr2.detach();
  tr3.join();
}

void change(vector<Line>& db, mutex& mtx) {
  int i = 0;
  usleep(10000);
  while("mutex& mtx and & vector<Line>& db") {
    mtx.lock();
    int j = 0;
    while("records is changing") {
      cout << "value k is: " << j << endl;
      db.at(j).year = 2000;
      if (j++ == 4) break;
    }
    cout << "value i is: " << i << endl;
    if (i++ == 4) return;
    mtx.unlock();
  }
  return;
}

void rollback(vector<Line>& db, mutex& mtx) {
  int i = 0;
  usleep(10000);
  while("mutex& mtx and & vector<Line>& db") {
    mtx.lock();
    //db.at(i).year = 1900 + i;
    db.at(0).year = 1856;
    db.at(1).year = 1879;
    db.at(2).year = 1955;
    db.at(3).year = 1955;
    db.at(4).year = 1984;

    if (i++ == 4) return;
    mtx.unlock();
  }
  return;
}

void view(vector<Line>& db, mutex& mtx) {
  while("mutex& mtx and & vector<Line>& db") {
    lock_guard<mutex> lock(mtx);
    cout << "view: " << endl;
    for (auto& row : db) cout << row.year << ", ";
    cout << endl;
    usleep(100000);
  }
  return;
}

int main(int, const char**) {
  start();
  return 0;
}
