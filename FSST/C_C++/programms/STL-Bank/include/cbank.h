// a.hofmann 10.06
// cbank.h
// demo: klasse und objekt und container

#ifndef CBANK_H
#define CBANK_H  CBANK_H
#include "ckonto.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CBank {
	private:
		vector<CKonto> m_konten; //in den vector kann ich jeden datentyp schreiben weil template
		vector<int> m_konten_idx;
		string m_name;

	public:
		// Konstruktoren
		CBank(string powner);

		// Methoden
		void add(const CKonto& pkonto);

		void display()const;

		// Friends
		friend ostream& operator<<(ostream& o, const CBank& e);

		// Destruktor
		~CBank();  //wenn objekt gelöscht wird
};
#endif
