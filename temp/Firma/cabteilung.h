#ifndef CABTEILUNG_H
#define CABTEILUNG_H

#include "cperson.h"
#include <vector>
using namespace std;

class CAbteilung
{

private:
    vector<CPerson*> * mitarbeiter;
    string name;

public:
    CAbteilung(string name);

    void addMitarbeiter(CPerson* p);
    void removeMitarbeiter(int alter);

    double getGesamtGehalt() const;

    string toString() const;

    ~CAbteilung();
};


#endif // CABTEILUNG_H
