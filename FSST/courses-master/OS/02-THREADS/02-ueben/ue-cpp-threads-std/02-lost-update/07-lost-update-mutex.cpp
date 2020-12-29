/*
g++ 07-lost-update-mutex.cpp -o 07-lost-update-mutex.exe -lpthread
*/

#include <iostream>
#include <===ENTER CODE===>
#include <thread>
using namespace std;

class LostUpdate {
private:
  // shared memory
  ===ENTER CODE=== int count;
  ===ENTER CODE=== mutex m;

public:
  ===ENTER CODE=== int getCount() { return count; }

  void operator()() {
    for (int i = 1; i <= 10000000; i++) {
      m.===ENTER CODE===; //!!!!!!!!!!!!!!!!!!!!
      count++;
      m.===ENTER CODE===; // !!!!!!!!!!!!!
    }
  }
};
// init shared memory
int LostUpdate::===ENTER CODE=== = 0;
===ENTER CODE=== LostUpdate::m;

int main() {
  LostUpdate obj1;
  LostUpdate obj2;

  cout << "LostUpdate Problem: 2 threads increment shared memory (each by "
          "10000000)." << endl;
  cout << "... Result should be: " << "20000000" << endl;

  cout << "... Before incr: Shared memory= " << LostUpdate::getCount() << endl;

  thread t1(obj1);
  thread t2(obj2);

  t1.join();
  t2.join();

  cout << "... After incr: Shared memory= " << LostUpdate::getCount() << endl;

  return 0;
}
