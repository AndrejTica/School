#include "company.h"

    Company::Company(std::string n) : name(n)
    {

    }

    void Company::addEmployee(Person* p) //bei socialnetwork haben wir hier objekt direkt per referenz übergeben und dann die addresse von p (&P) an vektor weil ja der vektor von typ pointer ist
    {                               //Jetzt haben wir wieder ein vektor von pointer typ, aber bekommen direkt den pointer rein (addresse) die wir gleich ins vektor pushen weil wir ja das
                                    //objekt dynamisch angelegt haben (pointer vom objekt)
        employee.push_back(p); //für arraylist gilt das auch
    }

    //social network Person&   &p
    double Company::computePayroll()const
    {
        double ret;
        for(Person* p : employee)

            ret += p->calcSalary();

        return ret;
    }
    std::string Company::toString() const
    {

        std::string ret;
        for(Person* p : employee)

            ret += p->toString() + "\n";


        return ret;
    }
