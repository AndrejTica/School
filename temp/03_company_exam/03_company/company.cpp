// company.cpp

#include "company.h"

#include <iostream>
#include <sstream>
using namespace std;

Company::Company(string n) : name(n){

   


};

void Company::addEmployee(Person* p){
    employee.push_back(p);

}

double Company::computePayroll()const{
    double sum=0.0;

    for(Person* p : employee){
        sum += p->getWage();
    }


}

string Company::toString()const{
    vector<Person*>::iterator it;
    ostringstream out;

    out << endl<<endl;
    out << "****************************"<<endl;
    out << "*** Company / Employees ***"<<endl;
    out << "****************************"<<endl;
    out<< "Abteilung:" << name <<endl;
    for(auto it= employee.begin(); it!= employee.end(); it++){
        out << (*it)->toString();
    }
    return out.str();

}