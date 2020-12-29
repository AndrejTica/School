// demo-regex-search.cpp
//
// http://www.cplusplus.com/reference/regex/

#include <regex> 
#include <iostream> 
using namespace std;

int main ()
{
    std::string s ("we have 10 students working for 11 companies using 12 computers");
    std::smatch m;   // holds the founded match-result object
    std::regex e ("[0-9]+"); // search digits

	
	// search all matches
    while (std::regex_search ( s, m, e ) ){
		cout << "found: " << m[0] <<endl;

		// prepare next sub-string
		s = m.suffix().str();
	}

    return 0;
}

/*
Output:
found: 10
found: 11
found: 12
*/
