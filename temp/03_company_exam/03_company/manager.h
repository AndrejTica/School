// manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include "person.h"

class Manager : public Person{
private: 
    double fixum;
public:
    Manager(int age, string n, double f);

    double getWage()const;

    string toString() const;

};

#endif
