// a.hofmann, 2007
// cperson.cpp
// Vererbung

#include <iostream>
#include <sstream>  // um int, double, .. in strings umzuwandeln

#include "cperson.h"
using namespace std;

// cons
CPerson::CPerson(int alter, string name){
    this->alter= alter;
    this->name= name;
}

int CPerson::getAlter() const{
        return this->alter;
}

string CPerson::toString() const{
    ostringstream out;

    out<< endl;
    out << "NAME: " << name << "\nAlter: " << alter << "\n";

    return out.str();
}
