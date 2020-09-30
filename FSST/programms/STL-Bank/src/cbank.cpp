#include "cbank.h"
#include <string>
#include <vector>
#include <iterator>

using namespace std;

CBank::CBank(string powner){

    m_name = powner;

}


void CBank::add(const CKonto& pkonto){ //ein object von konto wird übergeben

    m_konten.push_back(pkonto); //push_back an dem vektor wird hinten was dranngefügt

}

void CBank::display()const{


    vector<CKonto>::iterator it; //iterator deklaration, pointer auf ein vektor element,


    for(it = m_konten.begin(); it < m_konten.end(); it++){ //in der schleife wird pointer verschoben, m_konten.begin ist pointer auf erste element, .end ist pointer auf letzte element +1

      it->display(); //für jedes element des vektors display funkt aufrufen

    }


}

ostream& operator<<(ostream& o, const CBank& e){ //damit cout weiß, was es ausgeben soll in unserer klasse




}


CBank::~CBank(){

    vector<CKonto>::iterator it;

    it = m_konten.begin();

    for(int i = 0; i < m_konten.size(); i++){

        m_konten.erase(it);

    }
}
