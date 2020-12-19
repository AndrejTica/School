#pragma once

#include "observer.h"
#include "observable.h"


#include <string>
using namespace std;

class Presseagentur :public Observer
{
private:
    string name;

public:
    Presseagentur(string name);

    void update();
    void update(Observable* o);
};

