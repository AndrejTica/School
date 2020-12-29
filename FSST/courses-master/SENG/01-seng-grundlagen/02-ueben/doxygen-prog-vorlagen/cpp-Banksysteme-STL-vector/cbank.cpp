// a.hofmann 10.06
// cbank.cpp
// demo: klasse und objekt

#include "ckonto.h"
#include "cbank.h"

#include <iostream>
#include <string>
using namespace std;

// Konstruktoren
CBank::CBank(string pname){
	m_name= pname;
}

// Methoden
void CBank::addKonto(const CKonto& akonto){
	m_konten.push_back(akonto);
}

void CBank::removeKonto(const int kontoNR){
	vector<CKonto>::iterator it;
	
	for (it= m_konten.begin(); it != m_konten.end(); it++){
		if (it->getNR() == kontoNR){
			m_konten.erase(it);
			return;
		}
	}
}



void CBank::addBetrag(double pBetrag){
    vector<CKonto>::iterator it;
    
    for (it= m_konten.begin(); it != m_konten.end(); it++)
		it->setBetrag(it->getBetrag() + pBetrag);

}

void CBank::minBetrag(double pBetrag){
    vector<CKonto>::iterator it;

    for (it= m_konten.begin(); it != m_konten.end(); it++)
		it->setBetrag(it->getBetrag() - pBetrag);
}

// Destruktor
CBank::~CBank(){
}

// friends
ostream& operator<<(ostream& o, const CBank& e) {
	double gesamt=0.0;
    vector<CKonto>::const_iterator it;
    
    for (it= e.m_konten.begin(); it != e.m_konten.end(); it++)
		gesamt += it->getBetrag();
        	
	o<< "... BANK " << e.m_name << " ..." << endl;
	o<< "... hat " << e.m_konten.size() << " Konten mit einem Gesamtbetrag von " << gesamt << " Euro." << endl;

	o<< "Hier nun eine Liste der einzelnen Konten:" <<endl;
    for (it= e.m_konten.begin(); it != e.m_konten.end(); it++)
       o<< *(it);	//Hier wird genutzt, dass CKonto den operator << überschrieben hat

	return o;
}
