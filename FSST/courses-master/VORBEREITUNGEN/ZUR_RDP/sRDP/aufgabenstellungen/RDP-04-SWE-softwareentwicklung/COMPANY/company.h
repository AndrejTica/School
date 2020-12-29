// company.h
// ahofmann, 2015


#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
using namespace std;
#include "person.h"

class Company {

private:
    vector<Person*>  employee;  // BASE CLASS Pointer !!!!!!!
    string name;

public:
    Company (string name);

    void addEmployee(Person* p);
 
    double getPayroll() const;

    string toString() const;
};
#endif

