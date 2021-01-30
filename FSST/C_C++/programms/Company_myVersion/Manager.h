#ifndef MANAGER_H
#define MANAGER_H
#include "person.h"


class Manager : public Person
{
private:
    double fixum;
public:
    Manager(int a, std::string n, double f);

    double getFixum()const;
    double calcSalary() const;
    std::string toString() const;

};


#endif // MANAGER_H_INCLUDED
