// a.hofmann 10.06
// cbank.h
// demo: klasse und objekt und container
// demo: StL-Klasse vector
// 	Die Konten werden in einem vector gespeichert


#ifndef CBANK_H
#define CBANK_H  CBANK_H

#include <string>
#include <iostream>

#include <vector>

#include "ckonto.h"
using namespace std;

class CBank {
	private:
		vector<CKonto> m_konten;
		string m_name;
	public:
		// Konstruktoren
		CBank(string powner);

		// Methoden
		void addKonto(const CKonto& akonto);
		void removeKonto(const int);
		
		void addBetrag(double);
		void minBetrag(double);
		
		void sortKonten();

		// Friends
		friend ostream& operator<<(ostream&, const CBank&);


		// Destruktor
		~CBank();
};

#endif

