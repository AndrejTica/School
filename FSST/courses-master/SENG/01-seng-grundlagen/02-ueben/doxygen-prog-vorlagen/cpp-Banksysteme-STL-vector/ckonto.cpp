// a.hofmann 10.06
// ckonto.cpp
// demo: klasse und objekt

#include "ckonto.h"
#include <iostream>
#include <string>
using namespace std;

// Konstruktoren
CKonto::CKonto() { 	// default Konstruktor
	m_nr=1;
	m_owner= "Max Mustermann";
	m_betrag= 123.0;
}

CKonto::CKonto(int nr, string powner, double pbetrag){
	m_nr= nr;
	m_owner= powner;
	m_betrag= pbetrag;
}

CKonto::CKonto(string powner){
	m_nr=1;
	m_owner= powner;
	m_betrag= 123.0;
}

// Methoden
void CKonto::setBetrag(double pbetrag){
	m_betrag= pbetrag;
}

void CKonto::setOwner(string powner){
	m_owner= powner;
}

double CKonto::getBetrag() const{
	return m_betrag;
}

int CKonto::getNR() const{
	return m_nr;
}
		

//void CKonto::display(){
//	cout << "\nKonto: " << m_owner << " (" << m_betrag << " )" << endl;
//}

// Destruktor
CKonto::~CKonto(){

}


// -------------------- FRIENDS
ostream& operator<<(ostream& o, const CKonto& e){

	o << "Konto: " << e.m_nr << ":" << e.m_owner<< " (" << e.m_betrag << " )" << endl;
	return o;
}

