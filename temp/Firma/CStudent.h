#pragma once
#include "cperson.h"
class CStudent :
    public CPerson
{
private:
    int lines;
    double price_per_line;
public:
    CStudent(int alter, string name, int lines, double price_per_line);
    string toString()const;
    double getGehalt() const;
};

