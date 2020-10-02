// cpp13.cc
// Reference parameters for reducing overhead
// and eleminating pointer notation

#include <iostream>
using namespace std;

// -------- A big structure
struct bigone{
  int serno;
  char text[1000];    // A lot of chars
}bo= {123, "This is a BIG structure"};


// -- Three functions that have the structure as a parameter
void valfunc( bigone v1);           // call by value
void ptrfunc( const bigone *p1);    // call by pointer
void reffunc( const bigone &r1);    // call by reference

int main()
{
   valfunc( bo);   // Passing the variable itself
   ptrfunc(&bo);   // Passing the address of the variable
   reffunc( bo);   // Passing a reference to the variable

   return 0;
}

// -- call by value
void valfunc( bigone v1)
{
  cout << '\n' << v1.serno;
  cout << '\n' << v1.text;
}

// -- call by pointer
void ptrfunc( const bigone *p1)
{
  cout << '\n' << p1->serno;     // pointer notation
  cout << '\n' << p1->text;
}

// -- call by reference
void reffunc( const bigone &r1)
{
  cout << '\n' << r1.serno;     // reference notation
  cout << '\n' << r1.text;
}
