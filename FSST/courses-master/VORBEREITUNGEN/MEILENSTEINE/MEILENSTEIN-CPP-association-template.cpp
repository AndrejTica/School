/*
 MEILENSTEIN-CPP-association-template.cpp
-------------------------------------------------------------*/
// TODO: bringen Sie das Programm zum Laufen
// 1. ersetzen Sie die ?????????????
// 2. verwenden Sie templates

#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <cstring>
#include <string>
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
		??????????????? operator[] (const char*);
		void print_all() const;
	};
#endif

Association::Association (int anz){
	max= anz;
	current=0;
	vect= ?????????????;
}

???????? Association::operator[] (const char* s){
	// überschreiben?
	for (int i = 0; i < current; i++){
		???????????????
	}
	
	// einfügen? oder anhängen?
	
	// hier anhaengen: also platz vergroessern
	if (current>= max){
		// neuen grösseren Speicher
		pair* help;

		max= max* 1.50;
		help= new ??????????????????????;
		
		for (int i = 0; i < current; i++){
			???????????????
		}
		delete[] ???????????????????;
		vect= help;
	}

	// beim index current einfügen, dann current erhöhen
	???????????????????????
	strcpy(vect[current].key, s);
	current++;
	return vect[current-1].value;

	
}

void Association::print_all() const{

}

int main(){
	Association<int> assoc(5);	
// einfügen
	assoc["informix1"]= 1;
  	assoc["informix2"]= 2;
	assoc["informix3"]= 3;
	assoc["informix4"]= 4;

// überschreiben
	assoc["informix5"]= 5;
	assoc["informix5"]= 55;
	
// anhängen
	assoc["informix6"]= 6;

cout <<endl<< __FILE__ << ":" << "Association<int> assoc(5);" << endl;
	assoc.print_all();



	Association<double> assocDBL(5);	
	assocDBL["informix1"]= 1.1;
  	assocDBL["informix2"]= 2.2;
	assocDBL["informix3"]= 3.3;
	assocDBL["informix4"]= 4.4;
	assocDBL["informix5"]= 5.5;
	assocDBL["informix5"]= 55.55;
	assocDBL["informix6"]= 6.6;

cout <<endl<< __FILE__ << ":" << "Association<double> assocDBL(5);" << endl;
	assocDBL.print_all();


	Association<string> assocString(5);	
	assocString["informix1"]= "str1.1";
  	assocString["informix2"]= "str2.2";
	assocString["informix3"]= "str3.3";
	assocString["informix4"]= "str4.4";
	assocString["informix5"]= "str5.5";
	assocString["informix5"]= "str55.55";
	assocString["informix6"]= "str6.6";

cout <<endl<< __FILE__ << ":" << "Association<string> assocString(5);" << endl;
	assocString.print_all();

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

usw.....
*/
