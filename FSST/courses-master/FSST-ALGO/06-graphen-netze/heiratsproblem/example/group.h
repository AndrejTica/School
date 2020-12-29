#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "person.h"

/** stores persons */
class Group {
private:
  map<string, Person *> members;
public:
  Group();
  ~Group();

  void addPerson(string name);
  // operator overloading
  Person& operator[](string name);

  Person *getPerson(string name);

  // Marry 
  void marry(Group& others);

  void printPartners();
};
