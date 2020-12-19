#include "CStudent.h"
#include <sstream>

CStudent::CStudent(int alter, string name, int lines, double price_per_line):CPerson(alter, name), lines(lines), price_per_line(price_per_line)
{

}

string CStudent::toString() const
{
    ostringstream out;

    out << CPerson::toString();

    out << "   Lines: ";
    out << lines;
    out << "\n   Price per Lines: ";
    out << price_per_line;
    out << "\n   Gehalt:";
    out << getGehalt();
    out << endl;

    return out.str();
}

double CStudent::getGehalt() const
{
    return lines * price_per_line;
}
