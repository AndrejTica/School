#ifndef FANCLUB_H_INCLUDED
#define FANCLUB_H_INCLUDED

#include "observer.h"
#include "observable.h"


#include <string>
using namespace std;

class Fanclub:public Observer
{
private:
    string name;

public:
    Fanclub(string name);

    void update();
    void update(Observable* o);
};



#endif // FANCLUB_H_INCLUDED
