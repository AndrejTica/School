/*
03-thread-lambda.cpp

g++ -std=c++11  03-thread-lambda.cpp -o 03-thread-lambda.exe -lpthread
*/

#include <iostream>
#include <thread>
using namespace std;

int main() {

  thread t1(===ENTER CODE=== { cout << "Thread: Hello world!" << endl; });

  t1.===ENTER CODE===;

  return 0;
}
