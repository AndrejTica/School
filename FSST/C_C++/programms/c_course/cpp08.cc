//cpp08.cpp
///////////
// overloaded functions
#include <iostream>
nclude <time>
using namespace std;

void display_time( const struct tm *tim)
{
   cout << "1. It is now " << asctime (tim);
}

void display_time( const time_t *tim)
{
   cout << "2. It is now " << ctime (tim);
}

int main()
{
    time_t tim;
    struct tm *ltim;

    tim= time(NULL);
    ltim= localtime(&tim);

    display_time(ltim);
    display_time(&tim);
    return 0;
}
