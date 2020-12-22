// company.h

#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
using namespace std;

#include "person.h"

class Company
{
private:
    string name;
    vector<Person*> employee;
public:
    Company(string n);

    void addEmployee(Person* p);

    double computePayroll()const;

    string toString()const;


};
#endif
