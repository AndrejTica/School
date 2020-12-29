/*
g++ wordsearch.cpp -o wordsearch.exe
*/
#include <deque>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#include <regex>


#include "tlog.h"


vector<string> find_matches( string pattern, deque<string> &backlog ){
  vector<string> results;

  while ( ===ENTER CODE===.size() ) {
    string word = ===ENTER CODE===.front();
    ===ENTER CODE===.pop_front();   // remove word from dequeu

    if ( regex_match( word.begin(), word.end(), regex(pattern) ) )
      results.===ENTER CODE===( word );
  }
  return results;
}



int main(int argc, char *argv[]) {
  TLog::reset();
  cout << TLog::log("BEGIN") <<endl;

  //...
  ifstream f("input.txt");

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
    backlog.push_back(word); // store word

  
  // find matches

  vector<string> words = find_matches( pattern, backlog );
  
  cout << "Found " << words.size()
       << " matches for " << pattern
       << endl;
  
  // output
  for ( auto s : ===ENTER CODE=== )
    cout << s << "\n";


  f.close();
  //...
  cout << TLog::log("END") <<endl;

  return 0;
}
