/*
04-thread-class.cpp
g++ -std=c++11 04-thread-class.cpp -o04-thread-class.exe -lpthread
*/

#include <iostream>
#include <thread>
using namespace std;

class MyThread {
private:
  string message;

public:
  MyThread(string s) ===ENTER CODE===
  
  ===ENTER CODE=== { cout << "Thread: " << message << endl; }
};

int main() {

  MyThread mythread("Hello World!");

  std::thread t(===ENTER CODE===);
  
  t.===ENTER CODE===();

  return 0;
}
