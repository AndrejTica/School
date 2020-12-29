/*
g++ async-wordsearch.cpp -o asynch-wordsearch.exe -lpthread
*/
#include <deque>
#include <fstream>
#include <iostream>
#include <vector>

#include <functional>
#include <future>
#include <regex>
using namespace std;

#include "tlog.h"

vector<string> find_matches(string pattern, deque<string> &backlog) {
  vector<string> results;

  while (backlog.size()) {
    string word = backlog.front();
    backlog.pop_front(); // remove word from dequeu

    if (regex_match(word.begin(), word.end(), regex(pattern)))
      results.push_back(word);
  }
  return results;
}

int main(int argc, char *argv[]) {
 
  TLog::reset();
  cout << TLog::log("BEGIN") << endl;
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
  string pattern = argv[1];

  // read input.txt
  string word;
  deque<string> backlog;
  while (f >> word)          // read word
    backlog.push_back(word); // store word

  // regex
  auto f1 = async(===ENTER CODE===, find_matches, pattern, ref(backlog));
  auto f2 = async(===ENTER CODE===, find_matches, pattern, ref(backlog));
  auto f3 = async(===ENTER CODE===, find_matches, pattern, ref(backlog));
  //  vector<string> words = find_matches( pattern, backlog );

  vector<string> words1 = ===ENTER CODE===;
  vector<string> words2 = ===ENTER CODE===;
  vector<string> words3 = ===ENTER CODE===;

  cout << TLog::log("find_matches() fertig")<<endl;

  // ausgabe
  cout << "Found " << words1.size() + words2.size() + words3.size()
       << " matches for " << pattern << endl;
  for (auto s : words1)
    cout << s << "\n";

  for (auto s : words2)
    cout << s << "\n";

  for (auto s : words3)
    cout << s << "\n";

  f.close();

  cout << TLog::log("END") << endl;

  return 0;
}
