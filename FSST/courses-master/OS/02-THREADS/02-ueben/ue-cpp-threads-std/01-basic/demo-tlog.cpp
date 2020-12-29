/*
g++ demo-tlog.cpp -o demo-tlog.exe
*/

#include <iostream>
using namespace std;

#include "tlog.h"

// --------------------------------------------------------
int main() {

  cout << "DEMO: Time tracking" << endl<<endl;

  TLog::reset();
  cout << TLog::log("1. start a first test ...") << endl;
  cout << TLog::log("waiting for data from FILE(simulate)") << endl;
  for (size_t i = 0; i < 1000000; i++) {
    ;
  }
  cout << TLog::log("done") << endl<<endl;

  TLog::reset();
  cout << TLog::log("2. start a second test ...") << endl;
  cout << TLog::log("waiting for data from FILE(simulate)") << endl;
  for (size_t i = 0; i < 2000000; i++) {
    ;
  }
  cout << TLog::log("done") << endl;



  cout << endl;
  return 0;
}
