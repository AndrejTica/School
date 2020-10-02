#ifndef NOTENMANAGER_H
#define NOTENMANAGER_H

#include <string>
#include <vector>
using namespace std;
#include "test.h"

class Notenmanager
{
public:
    Notenmanager(string name);
    ~Notenmanager();

    void readFromFile(string fn);
    void printResult();

private:
	int getNote(double prozent);
    string name;
    vector<Test*> tests;
    double grades[5]; // [1]..1er...[4]...4er
};

#endif // NOTENMANAGER_H
