#ifndef CMANAGER_H
#define CMANAGER_H

#include "cperson.h"
#include <string>
using namespace std;

class CManager : public CPerson
{

private:
        double fixum;
public:
    CManager(int alter, string name, double fixum);

    double getGehalt() const;

    string toString() const;

};

#endif // CMANAGER_H
