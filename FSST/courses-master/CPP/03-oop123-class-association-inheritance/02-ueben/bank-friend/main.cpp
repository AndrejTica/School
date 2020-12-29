//============================================================================
// Name        : oop1-banksysteme-STLVector-static.cpp
// Author      : NAME
// Version     :
// Copyright   : open source
// Description : Bank, Konto, private cons, friend class
//============================================================================
// g++ main.cpp Konto.cpp Bank.cpp -o main.exe


// AUFGABE:
// ----------------------------------------------------------------------------
// Bringen Sie dieses Programm zum Laufen
// Klassen: Bank, Konto

#include "Konto.h"
#include "Bank.h"
#include <iostream>
using namespace std;

int main(){

	Bank *meineBank;
	meineBank = new Bank("Hofmann unlimited");


	cout << "\n\n"<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " DEMO: STATIC members "<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " DEMO: Die KontoNummer werden als static member "<<endl;
	cout << " DEMO: in der Klasse Konto gehalten "<<endl;
	cout << " DEMO: "<<endl;
	cout << " DEMO: Dadurch werden beim Hinzufügen, immer neue KontoNummern erzeugt"<<endl;
	cout << " DEMO: "<<endl;
	cout << " DEMO: Testen Sie, ob IMMER eine neue KontoNummer erzeugt wird????"<<endl;
	cout << " ------------------------------------------------"<<endl;


	cout << "\n\nDIE BANK -----------------"<<endl;
	cout << ">>> hier noch mit allen 3 Konten: BEACHTE die KontoNummer!!!"<<endl;

	meineBank->addKonto("Anton Hofmann", 100.0);
	meineBank->addKonto("Beta Hofmann", 200.0);
	meineBank->addKonto("Gamma Hofmann",300.0);

	cout << meineBank->toString() << endl;



	cout << "\n\nDIE BANK -----------------"<<endl;
	cout << ">>> nach dem Löschen v. Konto Anton Hofmann: : BEACHTE die KontoNummer!!!"<<endl;
	meineBank->delKonto("Anton Hofmann");

	cout << meineBank->toString() << endl;
	cout << endl;

	cout << "\n\nDIE BANK -----------------"<<endl;
	cout << ">>> nach dem Einfügen v. Konto Omega Hofmann: BEACHTE die KontoNummer!!!"<<endl;
	meineBank->addKonto("Omega Hofmann", 900.0);

	cout << meineBank->toString() << endl;
	cout << endl;


	cout << "\n\n"<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " DEMO: FRIEND class "<<endl;
	cout << "-------------------------------------------------"<<endl;
	cout << " DEMO: Der Konstruktor der Klasse Konto ist private "<<endl;
	cout << " DEMO: Nur die Bank kann diesen verwenden: siehe FRIEND CLASS"<<endl;

	//Konto k1("Anton Hofmann", 123.0); 	// error, because cons is private
	
	int kontoNr= meineBank->addKonto("Anton Hofmann", 100.0);
	meineBank->getKonto(kontoNr).einlegen(9000.0);

	cout << meineBank->toString() << endl;
	cout << endl;


	delete meineBank;

    return 0;
}
