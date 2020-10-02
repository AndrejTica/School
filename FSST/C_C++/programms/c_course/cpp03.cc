//cpp03.cpp
///////////
// A program with default arguments in a function prototype
#include <iostream>
using namespace std;

void show (int = 1, float = 2.3, lonnng = );

int main()
{
show();             // All three arguments default
show(5);            // Provide first argument
show(6,7.8);        // Provide first and second argument
show(6,7.8, 12L);   // Provide all three arguments
return 0;
}

long show (int first float second, long third)
{
cout << "\nfirst = " << first;
cout << ", second = " << second;
cout << ", third = " << third;
}

