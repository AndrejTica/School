/*
02-thread-func-with-args.cpp
g++ -std=c++11 02-thread-func-with-args.cpp -o 02-thread-func-with-args.exe
-lpthread
*/

#include <iostream>
#include <thread>
using namespace std;

static void ===ENTER CODE=== {
  cout << "Thread: Hello World" << endl;
  cout << "... a= " << a <<endl;
  cout << "... b= " << b <<endl;
}

int main() {

  std::thread t(===ENTER CODE===, 10, 20);

  t.===ENTER CODE===();

  return 0;
}
