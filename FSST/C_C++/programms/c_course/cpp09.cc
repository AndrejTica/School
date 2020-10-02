//cpp09.cpp
///////////
// overloaded functions
#include <iostream>
#include <string>
using namespace std;

inline void string_copy char *dest, const char *src
{
   strcpy (dest, src);
}

inline void string_copy char *dest, const char *src, int len
{
   strncpy (dest, src, len);
}

static char stringa[20], stringb[20];

int main()
{
    string_copy( stringa, "That");
    string_copy( stringb, "This is a string", 4);

    cout << stringb << " and " << stringa;

    return 0;
}
