/*
01-thread-func.cpp
g++ -std=c++11 01-thread-func.cpp -o01-thread-func.exe -lpthread
*/
#include <iostream>
#include <===ENTER CODE===>

static void ===ENTER CODE=== { std::cout << "Thread: Hello World" << std::endl; }

int main() {
  std::thread t(===ENTER CODE===);

  t.===ENTER CODE===; // Main-Thread waits until t is finished

  return 0;
}
