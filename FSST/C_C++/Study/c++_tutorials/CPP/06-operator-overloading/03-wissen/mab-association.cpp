/*mab-association.cpp
-------------------------------------------------------------*/
#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <cstring>
#include <iostream>
using namespace std;

class Association {
	private:
		struct pair {char* key; int value; };
		pair* vect;
		int max;
		int current;
	public:
		Association (int);

		// search for aKey
		// return a reference to the integer part of its "pair"
		// if aKey has not been seen --> make a new pair
		//    but check for overflow: if so , grow the assoc-vector
		//...
		int& operator[] (const char*);
		void print_all() const;
	};
#endif

Association::Association (int anz){

}

int& Association::operator[] (const char* s){

}

void Association::print_all() const{

}

int main(){
	Association assoc(5);	
	assoc["informix1"]= 1;
	assoc["informix2"]= 2;
	assoc["informix3"]= 3;
	assoc["informix4"]= 4;
	assoc["informix5"]= 5;
	assoc["informix5"]= 55;
	
	assoc["informix6"]= 6;

	assoc.print_all();

	return 0;
}
/* Übersetzen:
	g++ Association.cpp 
	./a.out 
Ausgabe:
	informix1:1
	informix2:2
	informix3:3
	informix4:4
	informix5:55
	informix6:6
*/
