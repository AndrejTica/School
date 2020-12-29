// person.cpp
// ahofmann, 2015/18

#include "person.h"
#include <sstream>
#include <iostream>

Person::Person(int age, string name){
	this->age= age;
	this->name= name;
}


int Person::getAge() const{
	return age;
}

string Person::toString() const{
	ostringstream o;

	o << "NAME: " << name << endl;
	o << "AGE: " << age << endl;

	
	return o.str();
}

