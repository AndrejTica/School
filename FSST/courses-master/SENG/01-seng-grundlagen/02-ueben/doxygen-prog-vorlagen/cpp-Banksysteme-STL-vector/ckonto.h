// a.hofmann 10.06
// ckonto.h
// demo: klasse und objekt
// g++ ckonto_main.cpp -o ckonto_main.exe


#ifndef CKONTO_H
#define CKONTO_H  CKONTO_H

#include <string>
#include <iostream>
using namespace std;

class CKonto {
	private:
		int m_nr;
		double m_betrag;
		string m_owner;
		
	public:
		// Konstruktoren
		CKonto();	// default Konstruktor
		CKonto(int nr, string powner, double pbetrag);
		CKonto(string powner);

		// Methoden
		void setBetrag(double pbetrag);
		void setOwner(string powner);
		
		double getBetrag()const;
		int getNR() const;
		
		
		//void display();
		friend ostream& operator<<(ostream& o,const CKonto& e);

		// Destruktor
		~CKonto();

};

#endif

