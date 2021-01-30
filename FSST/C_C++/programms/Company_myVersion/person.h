// person.h


#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>


class Person
{
private:
    int age;    //this is the only variable we need to access with base constructor from subclasses since its private
protected:
    std::string name;   //this one we can just set without the base constructor since its protected

public:
  Person(std::string n, int a);
  int getAge()const;

  virtual double calcSalary() const = 0;
  virtual std::string toString() const = 0;

};
#endif
