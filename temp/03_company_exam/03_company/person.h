// person.h

#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person{
   private:
      int age;
   protected: // nur Unterklassen haben direkten Zugriff
      string name;
   public:
      Person(int age, string name);

     int getAge()const;

     virtual double getWage()const = 0;
     virtual string toString() const;
};
#endif
