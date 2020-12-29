// demo-regex-match.cpp
//
// regex_match()
// liefert true, nur wenn der GESAMTE string dem Muster entspricht.
//
// http://www.cplusplus.com/reference/regex/
// g++ demo-regex.cpp -o demo-regex.exe

#include <regex> 
#include <iostream> 
using namespace std;
#include <cassert>
#include <cstdlib>
  
int main(){ 
	
	system("date");
	cout << "... testing: std::regex_match(string, regex) ..." << endl<<endl;
	
	assert(regex_match("Hello", std::regex("..ll.") ) && "error: ..ll.");
	assert(regex_match("Hello", std::regex(".*ll.*") ) && "error: .*ll.*");
	assert(regex_match("llo", std::regex(".*ll.*") ) && "error: .*ll.*");
	
//	assert(regex_match("llo", std::regex("..ll.") ) && "error: ..ll.");
	
	cout << "... all tests passed ..." << endl;
	
	return 0;
}

