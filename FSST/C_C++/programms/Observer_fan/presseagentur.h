#ifndef PRESSEAGENTUR_H_INCLUDED
#define PRESSEAGENTUR_H_INCLUDED

#include "observer.h"
#include "observable.h"


#include <string>
using namespace std;

class Presseagentur:public Observer
{
private:
    string name;

public:
    Presseagentur(string name);

    void update();
    void update(Observable* o);
};


#endif // PRESSEAGENTUR_H_INCLUDED
