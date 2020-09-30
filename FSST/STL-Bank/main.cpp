// a.hofmann 10.06
// main.cpp
// demo: klasse und objekt und container
// g++ main.cpp ckonto.cpp cbank.cpp-o main.exe

#include "ckonto.h"
#include "cbank.h"
#include <iostream>
using namespace std;

int main(){
	CKonto konto1("Anton Hofmann", 100.0);
	CKonto konto2("Beta Hofmann",  200.0);
	CKonto konto3("Gamma Hofmann", 300.0);

	cout << "\nDIE KONTEN ----------------------------------\n"<<endl;
/*	konto1.display();
	konto2.display();
	konto3.display();
*/
	cout << konto1 << konto2 << konto3 << endl;


	cout << "\n\nDIE BANK ---------------------------------\n"<<endl;

	CBank *meinBank;
	meinBank = new CBank("Bank unlimited");

	meinBank->add(konto1);
	meinBank->add(konto2);
	meinBank->add(konto3);

//	meinBank->display();
	cout << *meinBank;

	cout << endl;

	return 0;
}
