

#ifndef ANGESTELLTER_H
#define ANGESTELLTER_H

#include "simplebank.h"
#include <iostream>
using namespace std;


class Angestellter{
private:
	SimpleBank* bank;
	int von, nach, betrag;

public:
	Angestellter(SimpleBank* bank, int von, int nach, int betrag) {
		this->bank = bank;
		this->von = von;
		this->nach = nach;
		this->betrag = betrag;
	}

	void operator()(){
		// Überweisung vornehmen
		bank->ueberweisung(von, nach, betrag);

		// Kontostand ausgeben
		cout << "Nachher:...."<<endl;
		bank->kontostand();
	}
};
#endif
