// demo-regex.cpp
//
// regex_match()
// liefert true, nur wenn der GESAMTE string dem Muster entspricht.
//
// 	g++ demo-regex.cpp -o demo-regex.exe


#include <regex> 
#include <iostream> 
using namespace std;
  
  
int main(){ 
	bool ret;
		
	string str = "Hello"; 
	regex muster("..ll."); 

	ret= regex_match(str.begin(), str.end(), muster);
	if (ret){
		cout <<endl;
		cout <<__FILE__ <<":"<<__LINE__<< " ..."<< endl;
		cout << "string= " << str <<endl;
		cout << "muster= " << "..ll." <<endl;
		cout << "regex_match(str.begin(), str.end(), muster); liefert true" << endl;		
	}
	
	return 0;
}
