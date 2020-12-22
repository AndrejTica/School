// worker.h

#ifndef CWORKER_H
#define CWORKER_H

#include "person.h"

class Worker : public Person {// ENTER CODE
    private : 
        int hours;
        double wage;
    public:
    Worker(int age, string name, int hours, double hoursWage);

    string toString()const;

    double getWage() const;

};
#endif
