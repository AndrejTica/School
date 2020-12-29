/*
05-thread-punkt-strich.cpp
g++ -std=c++11 05-thread-punkt-strich.cpp -o 05-thread-punkt-strich.exe -l
pthread
*/

#include <iostream>
#include <string>
#include <thread>
using namespace std;

class PunktStrich {
private:
  string s;

public:
  PunktStrich(string s) { this->s = s; }

  ===ENTER CODE=== {
    while (true) {
      cout << s;
    }
  }
};

int main() {
  PunktStrich obj1("..");
  PunktStrich obj2("||");

  // treads starten
  thread t1(obj1);
  thread t2(obj2);

  // Programm mit Ctrl-c beenden.
  while (true)
    ;

  return 0;
}
