#ifndef CVERKAEUFER_H
#define CVERKAEUFER_H

#include "carbeiter.h"

class CVerkaeufer:public CArbeiter
{
private:
    double kommission;
    int anz_verkaeufe;

public:
    CVerkaeufer(int alter, string name,
                int stunden, double stundenlohn,
                int anz_verkaeufe, double kommission);


    double getGehalt() const;

    string toString()const;

};

#endif // CVERKAEUFER_H
