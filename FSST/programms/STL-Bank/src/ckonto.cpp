#include "ckonto.h"
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

CKonto::CKonto(){

    m_betrag = 0;
    m_owner = "unkown";

}

CKonto::CKonto(string powner, double pbetrag){

    m_betrag = pbetrag;
    m_owner = powner;

}

CKonto::CKonto(string powner){

    m_betrag = 0;
    m_owner = powner;
}

void CKonto::setBetrag(double pbetrag){

    m_betrag = pbetrag;

}
void CKonto::setOwner(string powner){

    m_owner = powner;

}

void CKonto::display() const{

    cout << "Besitzer:\t" << m_owner << endl;
    cout << "Betrag:\t\t" << m_betrag << endl;

}

ostream& operator<<(ostream& o,const CKonto& e){


    o << "Besitzer:\t" << e.m_owner << endl;
    o << "Betrag:\t\t" << e.m_betrag << endl;

    return o;
}

CKonto::~CKonto(){

}
