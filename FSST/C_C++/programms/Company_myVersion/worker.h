
// worker.h

#ifndef CWORKER_H
#define CWORKER_H
#include "person.h"

class Worker : public Person
{
private:
    int hours;
    double wage;
public:
    Worker(int a, std::string n, int h, double w);

    double calcSalary() const;     //die get wage methode brauchen wir nur für die unterklasse von worker damit sie aufs wage kommt
    double getWage() const;
    int getHours() const;       //eigentlich brauchen wir auch die get hours methode, weil datenkapselung
    std::string toString() const;



};



#endif
