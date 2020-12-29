// a.hofmann 10.06
// main.cpp
// demo: klasse und objekt und container
// g++ main.cpp ckonto.cpp cbank.cpp-o main.exe

#include "ckonto.h"
#include "cbank.h"
#include <iostream>
using namespace std;

int main(){
	CKonto* konto1= new CKonto(1, "Anton Hofmann", 100.0);
	CKonto* konto2= new CKonto(2, "Beta Hofmann",  200.0);
	CKonto* konto3= new CKonto(3, "Gamma Hofmann", 300.0);

	cout << "\nDIE KONTEN -----------------"<<endl;
/*	konto1->display();
	konto2->display();
	konto3->display();
*/
	cout << *konto1 << *konto2 << *konto3;

	cout << "\n\nDIE BANK -----------------"<<endl;

	CBank *meinBank;
	meinBank = new CBank("Hofmann unlimited");

	meinBank->addKonto(*konto1);
	meinBank->addKonto(*konto2);
	meinBank->addKonto(*konto3);

//	meinBank->display();
	cout << *meinBank;
	
	cout << "\n\nDIE BANK nach dem Abzug ------------"<<endl;
	meinBank->minBetrag(10.0);
	
	cout << *meinBank;
	
	cout << "\n\nDIE BANK nach dem Löschen v. Konto Hofmann-----"<<endl;
	meinBank->removeKonto(1);
	
	
	cout << *meinBank;
	
	
	
	cout << endl;

    return 0;
}

