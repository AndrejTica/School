// cpp10.cpp
// Linkage specification
// !! advanced

#include <iostream>
#include <stdlib>
#include <string>
using namespace std;

// -- Prototype for a C function
extern "C" int comp( const void *a, const void *b);

int main()
{
// -- Array of string pointers to be stored
static char *brothers[]= {
  "Frederick William",
  "Joseph Jensen",
  "Harry Alan",
  "Walter Elsworth",
  "Julian Paul"
};

// -- sort the strings 
qsort (brothers, 5, sizeof (char *), comp);

// -- display the brothers
for (int i=0; i< 5; i++)
   cout << '\n' << brothers[i];
return 0;
}


// ------------------- A function compiles with C linkage
extern x"C"x
{
   int comp (const void *a, const void *b)
   {
      return strcmp( *(char **)a, *(char **)b);
   }
}
