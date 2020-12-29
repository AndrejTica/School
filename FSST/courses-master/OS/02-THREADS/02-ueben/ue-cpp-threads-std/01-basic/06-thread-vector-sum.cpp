/*
06-thread-vector-sum.cpp
g++ -std=c++11 06-thread-vector-sum.cpp -o 06-thread-vector-sum.exe -lpthread
*/

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#include "tlog.h"

#define SIZE 1000000

static vector<int> vdata(SIZE);
static long long sum1 = 0;
static long long sum2 = 0;
static long long sum = 0;

void thread_function1(int x, int y) {
===ENTER CODE===
}

void thread_function2(int x, int y) {
===ENTER CODE===
}

int main() {

  for (size_t i = 0; i < SIZE; i++) {
    vdata[i] = i;
  }

  TLog::reset();
  cout << TLog::log("starting 2 threads") << endl;

  thread t1(===ENTER CODE===);
  thread t2(===ENTER CODE===);
  t1.join();
  t2.join();

  sum = sum1 + sum2;
  cout << TLog::log("done") << endl;
  cout << "Summe= " << sum << endl;

  cout << endl << endl;
  
  TLog::reset();
  cout << TLog::log("starting only main thread") << endl;
  sum = 0;
  for (size_t i = 0; i < SIZE; i++) {
    sum += vdata[i];
  }

  cout << TLog::log("done") << endl;
  cout << "Summe= " << sum << endl;

  return 0;
}
