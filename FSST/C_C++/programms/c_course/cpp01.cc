//cpp01.cpp
///////////
#include <iostream.h>

int main()
{

cout << "Hello, world\n";

int amount=123;
cout << amount;                             //ausgabe operator

cout << "The value of amount is " << amount << "." << endl; //endl -> neue zeile

//fromatted output
cout << dec << amount << ' '; //schlüsselworter für formatierte ausgabe
cout << oct << amount << ' ';
cout << hex << amount << endl;

//standard error stream
cerr << "the standard error stream "cerr\"";

//standard input stream
char name[20];
cout << "Enter your name ...\n";
cin >> name; //eingabe operator >>
cout << "the name you entered was " << name;
return 0;
}

