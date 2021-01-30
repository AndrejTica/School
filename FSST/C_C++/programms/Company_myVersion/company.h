#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include "person.h"

class Company
{
private:
    std::string name;
    std::vector<Person*> employee;
public:
    Company(std::string n);
    void addEmployee(Person* p);
    double computePayroll()const;
    std::string toString() const;





};





#endif // COMPANY_H_INCLUDED
