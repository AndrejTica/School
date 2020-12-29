/*
* limits.cpp
*/

#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;
 
int main (){
        cout << "type \t\tsize \tmin \t\t\tmax" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "bool\t\t" << sizeof(bool) << endl;
        cout << "char\t\t" << sizeof(char) << "\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;
        cout << "unsigned char\t" << sizeof(unsigned char) << "\t\t\t\t" << UCHAR_MAX << endl;
        cout << "short\t\t" << sizeof(short) << "\t" << INT_MIN << "\t\t" << INT_MAX << endl;
        cout << "int\t\t" << sizeof(int) << "\t" << INT_MIN << "\t\t" << INT_MAX << endl;
        cout << "unsigned int\t" << sizeof(unsigned int) << "\t\t\t\t" << UINT_MAX << endl;
        cout << "float\t\t" << sizeof(float) << "\t" << FLT_MIN << "\t\t" << FLT_MAX << endl;
        cout << "long\t\t" << sizeof(long) << "\t" << LONG_MIN << "\t" << LONG_MAX << endl;
        cout << "double\t\t" << sizeof(double) << "\t" << DBL_MIN << "\t\t" << DBL_MAX << endl;
        return 0;
}

