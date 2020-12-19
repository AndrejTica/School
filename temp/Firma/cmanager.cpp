#include "cmanager.h"
#include <sstream>


CManager::CManager(int alter, string name, double fixum) : CPerson(alter,name) {
    this->fixum= fixum;
}


double CManager::getGehalt() const{
    return this->fixum;
}

string CManager::toString() const{
    ostringstream out;

    out << CPerson::toString();

    out << "  Gehalt: " << this->fixum << endl;

    return out.str();
}
