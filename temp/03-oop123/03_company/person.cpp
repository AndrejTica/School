// person.cpp

#include "person.h"
#include <sstream>
#include <iostream>

#include <algorithm>
using namespace std;


// ENTER CODE


void Person::removeFriend(string name){
	vector<Person*>::iterator it;
	
	friends.erase(remove_if(friends.begin(), friends.end(), 
		[&](Person* p){ return p->name==name;}),
		friends.end());
	
	
/*	
	for(if= friends.begin(); it != friends.auto& p:friends){
		if (p->name == name)
			
	}
*/

}


string Person::toString() const{
	ostringstream o;

	o << "NAME: " << name << endl;
	o << "AGE: " << age << endl;

	o << "FRIENDS: ";
	for(auto& p: friends){
		o << "... " << p->name;
	}
	
	o<< endl;
	return o.str();
}

