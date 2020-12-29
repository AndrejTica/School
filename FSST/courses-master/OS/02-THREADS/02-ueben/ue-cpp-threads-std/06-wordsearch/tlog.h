// Hilfsklasse zur Zeitmessung ------------------------------
// usage:
// TLog::reset();
// TLog::log("start a thread");
//  ....
// TLog::log("done starting a thread");
// ....

#pragma once

#include <chrono>
#include <string>
using namespace std;


class TLog {
private:
  static chrono::steady_clock::time_point start;

  static string getTime() {
    chrono::duration<double> d = chrono::steady_clock::now() - start;
    return "[" + std::to_string(d.count()) + " s] ... ";
  }

public:
  static void reset() { start = chrono::steady_clock::now(); }
  static string log(string message) { return TLog::getTime() + message; }
};
chrono::steady_clock::time_point TLog::start = chrono::steady_clock::now();
