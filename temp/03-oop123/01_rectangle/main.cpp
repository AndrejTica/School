#include <iostream>
using namespace std;

#include "rectangle.h"

int main(){
   Rectangle a(5, 3);   // length, width
   Rectangle b(a);
   Rectangle c;

   c= a.getMaxRect(b);	// max length and width

   cout << "c= " << c.toString() << endl;

/*
   The output should be:
       c= [15]
       *****
       *****
       *****
*/
       return 0;
}
