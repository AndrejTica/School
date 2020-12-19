#include "cverkaeufer.h"
#include "carbeiter.h"
#include <sstream>


CVerkaeufer::CVerkaeufer(int alter, string name,
                         int stunden, double stundenlohn,
                         int anz_verkaeufe, double kommission)

                             :CArbeiter(alter,name,stunden,stundenlohn){
    this->kommission= kommission;
    this->anz_verkaeufe= anz_verkaeufe;
}



double CVerkaeufer::getGehalt() const{
    return CArbeiter::getGehalt() + kommission*anz_verkaeufe;
}



string CVerkaeufer::toString()const{
    ostringstream out;

    out << CArbeiter::toString();
    out << "   ANZ.d.Verkaeufe: " << anz_verkaeufe<<endl;
    out << "   Kommission: " << kommission<<endl;
    out << "   Grundgehalt: " << CArbeiter::getGehalt()<<endl;
    out << "   Gehalt: " << this->getGehalt() << endl;

    return out.str();
}
