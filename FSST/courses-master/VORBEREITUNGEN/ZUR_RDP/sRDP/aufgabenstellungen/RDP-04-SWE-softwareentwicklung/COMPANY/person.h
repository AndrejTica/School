// person.h
// ahofmann, 2015/18


#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person{
private:
    // Private member. Nobody can access this member
   int age;

   // Protected member. 
   // Only subclasses can access this member
protected:
    string name;

public:
   // cons
   Person(int age, string name);

   // getter/setter
   int getAge() const;
   
   // !!!!!!!!!!!!!!!!!!!!
   virtual double getWage()const =0;

   virtual string toString() const;
};
#endif
