#ifndef FUSSBALLVEREIN_H
#define FUSSBALLVEREIN_H

#include "observable.h"
#include <string>
using namespace std;

class Fussballverein:public Observable
{
private:
    string name;
    string message;
public:
    Fussballverein(string name);

    void setPresseMitteilung(string msg);

    // für die Observer (Presse, Fans, ...)
    string getPresseMitteilung() const;
};

#endif // FUSSBALLVEREIN_H
