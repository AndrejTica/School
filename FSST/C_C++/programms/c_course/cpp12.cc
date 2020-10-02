// cpp12.cc
// Adresses of references

#include <iostream>
using namespace std;

int main()
{
int actualint= 123;
int &otherint= actualint;     // Reference declaration

cout << &actualint << ' ' << &otherint;
return 0;
}
