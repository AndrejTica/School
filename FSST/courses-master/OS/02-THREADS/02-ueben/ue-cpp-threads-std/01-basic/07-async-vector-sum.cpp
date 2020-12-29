/*
07-async-vector-sum.cpp
g++ -std=c++11 07-async-vector-sum.cpp -o 07-async-vector-sum.exe -lpthread
*/
#include <===ENTER CODE===>
#include <iostream>
#include <vector>
using namespace std;

#include "tlog.h"

#define SIZE 1000000

static vector<int> vdata(SIZE);
static long long sum1 = 0;
static long long sum2 = 0;
static long long sum = 0;

long long async_function(int x, int y) {
  ===ENTER CODE===
}

int main() {

  for (size_t i = 0; i < SIZE; i++) {
    vdata[i] = i;
  }

  TLog::reset();
  cout << TLog::log("starting 2 async futures") << endl;

  ===ENTER CODE=== future_sum1 =
      async(===ENTER CODE===);
  ===ENTER CODE=== future_sum2 =
      async(===ENTER CODE===);

  sum1 = future_sum1.===ENTER CODE===;
  sum2 = future_sum2.===ENTER CODE===;

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
/*
output:
[0.000025 s] ... starting 2 async futures
[0.003558 s] ... done
Summe= 499999500000


[0.000002 s] ... starting only main thread
[0.006163 s] ... done
Summe= 499999500000
*/
