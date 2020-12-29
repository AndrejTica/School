#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// -------------------------
class Person {
private:
  string name;
  Person *partner;
  vector<string> positionList;  // stores name of Person

public:
  Person(string name);

  // operator overloading
  Person& operator<< (string name);

  // hochzeitsproblem lösung
  vector<string> getPositionList();

  bool isNotMarried();
  void divorce();
  void marry(Person *p);
  bool lovesMeMore(Person *p); // is p a better partner?

  string toString();
};
