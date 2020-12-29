// out.cpp

//2. Ergänze das folgende Programm und gib die genaue Ausgabe an:

#include <iostream>

_________________________ std;

int x = 255, y = 254;    // Global variables

// Ausgabe von x und y als Hexadezimal- und Dezimalzahl
// x und y werden in der Funktion nicht geändert

void out(_____________ int x, ______________ int y = -1)
{
	cout ___________________ x << "   " ____________________ x << endl;
	if (y >= 0)
		cout _________________ y << "   " ____________________ y << endl;
	cout << endl;
}

// Der Funktionsaufruf wird durch den Programmcode ersetzt
__________________ void out() { cout << x << endl << endl; }

// a und b werden getauscht
void swap(_________________ a, _________________ b) { int h = a; a = b; b = h; }

int main()
{
	int x=127, y=128;
	out(); out(x); out(::x, y); swap(x, y); out(::x, y);
	return 0;
}


/* Ausgabe
?????

??   ???

??   ???
??   ???

??   ???
??   ???
*/


