#include "person.h"


Person::Person(string v, string n){
    forename= v;
    surname = n;
}

string Person::getSurname() const{
    return surname;
}

string Person::getForename() const{
    return forename;
}
