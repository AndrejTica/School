#include "test.h"
#include <sstream>

Test::Test(string line)
{
    this->line= line;
    // todo

    // 2013.05.01:25:5:C-Strukturen
    istringstream is(line);
    string s;

    std::getline(is, this->wann, ':');
    std::getline(is, s, ':');
    max_pkte= stoi(s);

    std::getline(is, s, ':');
    hat_pkte= stoi(s);

    std::getline(is, this->bezeichnung, ':');
}

Test::~Test()
{
    // todo

}

int Test::getMaxPkte() const
{
    return max_pkte;
}

int Test::getHatPkte() const
{
    return hat_pkte;
}


double Test::getProzent() const{
	return (hat_pkte/(double)max_pkte) *100.0;
}

string Test::getLine() const
{
    return this->line;
}
