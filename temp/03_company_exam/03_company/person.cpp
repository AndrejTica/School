// person.cpp

#include "person.h"
#include <sstream>
#include <iostream>

#include <algorithm>
using namespace std;


Person::Person(int age, string name) : age(age), name(name) {


};

int Person::getAge()const{

	return age;
}




string Person::toString() const {
	ostringstream o;

	o << "NAME: " << name << endl;
	o << "AGE: " << age << endl;

	return o.str();
}

