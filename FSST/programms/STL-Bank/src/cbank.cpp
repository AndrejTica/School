#include "cbank.h"
#include <string>
#include <vector>
#include <iterator>

using namespace std;

CBank::CBank(string powner){

    m_name = powner;

}


void CBank::add(const CKonto& pkonto){

    m_konten.push_back(pkonto);

}

void CBank::display()const{


    for(int i = 0; i < m_konten.size(); i++){

        m_konten[i].display();

    }

}

ostream& operator<<(ostream& o, const CBank& e){

    for(int i = 0; i < e.m_konten.size(); i++){


        o << "Bank Konto " << i+1 << ":\n" << e.m_konten[i];

    }

    return o;
}


CBank::~CBank(){

    vector<CKonto>::iterator it;

    it = m_konten.begin();

    for(int i = 0; i < m_konten.size(); i++){

        m_konten.erase(it);

    }
}
