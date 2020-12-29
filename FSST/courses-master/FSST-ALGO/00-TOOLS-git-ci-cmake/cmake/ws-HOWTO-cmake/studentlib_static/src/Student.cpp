#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student (string name){
	this->name= name;
}
void Student::display(){
	cout << name << endl;
}
