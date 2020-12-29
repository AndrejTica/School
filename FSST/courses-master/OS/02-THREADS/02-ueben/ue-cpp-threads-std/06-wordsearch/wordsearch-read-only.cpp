/*
g++ wordsearch-read-only.cpp -o wordsearch-read-only.exe
*/
#include <deque>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#include "tlog.h"


int main(int argc, char *argv[]) {
  TLog::reset();
  cout << TLog::log("BEGIN") <<endl;

  //...
  ===ENTER CODE=== f("input.txt");

  if (!f) {
    cerr << "Cannot open input.txt in the current directory\n";
    return -1;
  }
  if (argc < 2) {
    cerr << "Usage: ./wordsearch.exe pattern\n\n"
            " ... pattern contains lower case letters and periods.\n"
            " ... The periods will match any character\n"
            " ... example: ....n\n";
    return -2;
  }

  // get pattern
  string pattern= argv[1];

  // read input.txt
  string word;
  deque<string> backlog;
  while (f >> word)          // read word
    backlog.===ENTER CODE===(word); // store word


  cout << TLog::log("Nach dem Einlesen in die deque") <<endl;
  
  // output
  for ( auto s : backlog )
    cout << s << "\n";


  f.close();
  //...
  cout << TLog::log("END") <<endl;

  return 0;
}
