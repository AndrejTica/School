#include "cabteilung.h"
#include <sstream>

CAbteilung::CAbteilung(string name){
    this->name= name;
    mitarbeiter= new vector<CPerson*>();
}


void CAbteilung::addMitarbeiter( CPerson* p){
    mitarbeiter->push_back(p);
}

void CAbteilung::removeMitarbeiter(int alter){
    vector<CPerson*>::iterator it;

    for(it= mitarbeiter->begin(); it!= mitarbeiter->end(); it++){
        if (alter == (*it)->getAlter()){
            mitarbeiter->erase(it);
            return;
        }
    }
}

double CAbteilung::getGesamtGehalt() const{
    double summe=0.0;

    for each(CPerson* p in *mitarbeiter)
    {
        summe += p->getGehalt();
    }

    return summe;
}


string CAbteilung::toString() const{
    vector<CPerson*>::iterator it;
    ostringstream out;

    out << endl<<endl;
    out << "****************************"<<endl;
    out << "*** CFIRMA / MITARBEITER ***"<<endl;
    out << "****************************"<<endl;
    out<< "Abteilung:" << name <<endl;
    for(it= mitarbeiter->begin(); it!= mitarbeiter->end(); it++){
        out << (*it)->toString(); // !!!!!POLYMORPHISMUS
    }

    return out.str();
}

CAbteilung::~CAbteilung(){
    delete mitarbeiter;
}
