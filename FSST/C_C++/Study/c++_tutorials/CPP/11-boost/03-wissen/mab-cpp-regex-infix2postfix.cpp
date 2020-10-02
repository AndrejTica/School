/*mab-cpp-regex-infix2postfix.cpp (10)
==============================================================================
1 (4) ------------------------------------------------------------------------
	Was suchen die folgenden Regexe?
	1.1. ".. \[[0-9]\]:"
	1.2. "[a-zA-Z]"

2 (2) ------------------------------------------------------------------------
	Gesucht sind die regex-Muster, um 
	2.1. (2) Zahlen im Hexadezimalsystem zu matchen?

3 (4) ------------------------------------------------------------------------
Erstellen Sie das Programm unten, sodass der Infix-Ausdruck in einen 
Postfix-Ausdruck umgewandelt ausgegeben wird.
Es gilt: 
Zahlen können mit mehreren Leerzeichen umgeben sein.
Der Postfix-Ausdruck darf zw. den Operanden und Operator aber nur ein
	Leerzeichen haben.
+ bzw. * können als Operatoren vorkommen.
*/
// mab-cpp-regex-infix2postfix.cpp
/*
g++ -I /media/informatik/APP/boost/include -L/media/informatik/APP/boost/lib  mab-cpp-regex-infix2postfix.cpp -o mab-cpp-regex-infix2postfix.exe -l boost_regex
*/
#include <boost/regex.hpp> 
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s1= "123+3"; 		// --> <123 3 +>
	string s2= "3 *  1234"; 	// --> <3 1234 *>
	string s3= "   3 +1234   "; // --> <3 1234 +>

	// extract the two operands and the operator
	boost::regex rgx("????????????????????????????????????????");
	
	cout <<"infix:  <" << s1 << ">" << endl;
	cout <<"postfix:<" << boost::regex_replace(???????????????)<< ">" << endl<<endl;
	?????????????????????????????????????
	return 0;
}
/*
Ausgabe:
infix:  <123+3>
postfix:<123 3 +>

infix:  <3 *  1234>
postfix:<3 1234 *>

infix:  <   3 +1234   >
postfix:<3 1234 +>
*/
