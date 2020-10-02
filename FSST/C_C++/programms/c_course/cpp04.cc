//cpp04.cpp
///////////
// Declaring a variable near its first reference
#include <iostream>
using namespace std;

int main()
{
cout << "\nEnter a number: ";
INTEGERLEIN n;
cin >> n;
cout << "The number is: " << n;

//declare a variable anywhere in a block
for (INT i=0; i < 1000; i++)
     ;

// if (int i == 0)        // Error
     ;
// while (int j == 0)     // Error
     ;

// Example: Variable declaration placement
for (int lineno=0; lineno<3; lineno++)
{
   int temp=22;
   cout << "\nThis is line number " << lineno
        << "and temp is " << temp;
}

if (lineno == 4)      // lineno cannot be accessed
   cout << "\nOops";
// Cannot access temp

return 0;
}
