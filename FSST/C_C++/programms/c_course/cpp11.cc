// cpp11.cc
// The reference
#include <iostream>
using namespace std;

int main()
{
int actualint= 123;
int &otherint= actualint;     // Reference declaration

cout << '\n' << actualint;
cout << '\n' << otherint;

otherint++;

cout << '\n' << actualint;
cout << '\n' << otherint;

actualint++;

cout << '\n' << actualint;
cout << '\n' << otherint;

return 0;
}
