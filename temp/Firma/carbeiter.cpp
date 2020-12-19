#include "carbeiter.h"

#include <string>
#include <sstream>
using namespace std;

// Konstruktor
CArbeiter::CArbeiter(  int alter, string name,
                       int stunden, double stundenLohn )
          // !!!!!!!!Kunstruktor der Oberklasse aufrufen
          : CPerson(alter, name)
{
    this->stunden= stunden;	// this ist hier notwendig
    this->stundenLohn = stundenLohn;
}



// Zugriffsmethoden
/*int CArbeiter::getAlter() const
{
        // return alter;
        // ist NICHT möglich, weil in Oberklasse private

        // return getAlter();
        // FEHLER; rekursiver Aufruf

        return CPerson::getAlter();
}
*/

string CArbeiter::toString()const
{
    ostringstream out;

    out << CPerson::toString();

    out << "   Stunden: ";
    out <<  stunden;
    out << "\n   Stundenlohn: " ;
    out << stundenLohn;
    out << "\n   Gehalt:";
    out << getGehalt();
    out << endl;

    return out.str();
}


double CArbeiter::getGehalt() const
{
    return stunden * stundenLohn;
}
