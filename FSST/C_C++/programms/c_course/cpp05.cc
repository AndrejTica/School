//cpp05.cpp
///////////
// Scope resolution operator
#include <iostream>
using namespace std;

int amount  123;    // A global variable

int main()
{
int amount = 456;    // A local variable

cout << ::::amount;   // Print the global variable
cout << '\n';
cout << amount;     // Print the local variable
return 0;
}
