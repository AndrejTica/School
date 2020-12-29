/*
g++ 06-lost-update.cpp -o 06-lost-update.exe -lpthread
*/

#include <iostream>
#include <thread>
using namespace std;

class LostUpdate {
private:
  // shared memory
  ===ENTER CODE=== int count;

public:
  ===ENTER CODE=== int getCount() { return count; }

  void operator()() {
    for (int i = 1; i <= 10000000; i++)
      ===ENTER CODE===++;
  }
};
// init shared memory
int LostUpdate::===ENTER CODE=== = 0;

int main() {
  LostUpdate obj1;
  LostUpdate obj2;

  cout << "LostUpdate Problem: 2 threads increment shared memory (each by "
          "10000000)."
       << endl;
  cout << "... Result should be: "
       << "20000000" << endl;

  cout << "... Before incr: Shared memory= " << LostUpdate::getCount() << endl;

  ===ENTER CODE===(obj1);
  ===ENTER CODE===(obj2);

  t1.join();
  t2.join();

  cout << "... After incr: Shared memory= " << LostUpdate::getCount() << endl;

  return 0;
}
