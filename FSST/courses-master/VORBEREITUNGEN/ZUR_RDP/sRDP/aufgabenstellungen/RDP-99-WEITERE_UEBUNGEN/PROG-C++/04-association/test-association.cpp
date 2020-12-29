/// test-association.cpp
/// ahofmann, 2015
/// -------------------------------------------------
 
// ...........

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


/*	
g++ test-association.cpp association.cpp -o test-association.exe

./test-association.exe

Ausgabe:
	informix1:1
	informix2:2
	informix3:3
	informix4:4
	informix5:55
	informix6:6 
*/

