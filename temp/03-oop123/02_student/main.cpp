// ----------------------------------------------
// 1. STUDENT
// - friend class
// - static member
// - destructor (new/delete)
// -----------------------------------------------

#include "schoolclass.h"
#include "student.h"
#include <iostream>
using namespace std;

int main(){

   SchoolClass schoolclass("1AHELI");

   schoolclass.add("Max Musterman", 70.0);
   schoolclass.add("Moritz Mustermann", 60.0);

   // print class name and all associated students
   cout << schoolclass.toString() << endl;


   Student* massiest= schoolclass.getMassiest();

   // print name and weight
   cout << massiest->toString() << endl;


   return 0;
}


