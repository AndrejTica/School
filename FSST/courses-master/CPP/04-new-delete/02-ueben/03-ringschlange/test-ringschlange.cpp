// test-ringschlange.cpp
// A.Hofmann , 2017
// g++ test-ringschlange.cpp ringschlange.cpp -o test-ringschlange.exe
// ./test-ringschlange.exe
 
#include <iostream>
using namespace std;

#include "ringschlange.h"

int main(int argc, char *argv[]){
    Ringschlange rs(10);
  	
  	cout << "Ringschlange: Test-Programm ..." << endl<<endl;
    rs.enqueue(1);
    rs.enqueue(2);
    rs.enqueue(3);
    rs.enqueue(4);
	cout << "1,2,3,4 in die Ringschlange eingefuegt ..." << endl<<endl;
//	cout << rs;

	cout << "1. Wert wieder rausgenommen ...";
	cout << rs.dequeue() << endl;
	
	cout << "2. Wert wieder rausgenommen ...";
	cout << rs.dequeue() << endl;

	cout << "3. Wert wieder rausgenommen ...";
	cout << rs.dequeue() << endl;

	cout << "4. Wert wieder rausgenommen ...";
	cout << rs.dequeue() << endl;

	
    return 0;
}
/* Ausgabe:
Ringschlange: Test-Programm ...

1,2,3,4 in die Ringschlange eingefuegt ...

1. Wert wieder rausgenommen ...1
2. Wert wieder rausgenommen ...2
3. Wert wieder rausgenommen ...3
4. Wert wieder rausgenommen ...4
*/
