// u-template-association.cpp
// name: N.N.


#include "association.h"

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
	g++ test-ssociation.cpp -o test-association.exe 
	./test-association.exe

Ausgabe:
	informix1:1
	informix2:2
	informix3:3
	informix4:4
	informix5:55
	informix6:6
	....
*/
