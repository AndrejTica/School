#ifndef TEST_H
#define TEST_H

#include <string>
using namespace std;

class Test
{
public:
    Test(string line);
    ~Test();

    int getMaxPkte() const;
    int getHatPkte() const;
	 
	 double getProzent() const;

    string getLine() const;

private:
    string wann;
    int max_pkte;
    int hat_pkte;
    string bezeichnung;

    string line;
};

#endif // TEST_H
