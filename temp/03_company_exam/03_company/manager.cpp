
#include "manager.h"

#include <iostream>
#include <sstream>
using namespace std;


 Manager::Manager(int age, string n, double f) : Person(age, name){ //constructor of the baseclass, we give him manager age and name
     this->fixum=f;
   

 };

 double Manager::getWage() const{
     return fixum;
 }

 string Manager::toString()const{
     ostringstream out;

     out << Person::toString();         //????

     out << " Wage: " << this->fixum << endl;

     return out.str();

 }
