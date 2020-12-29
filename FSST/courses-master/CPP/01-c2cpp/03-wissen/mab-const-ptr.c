// mab-const-ptr.c
// gcc mab-const-ptr.c -o mab-const-ptr.exe

#include <stdio.h>

int main(void){
	char* const p1 = "John";	// p1 ist const, wert ist nicht const
	*p1='A';					// erlaubt
	//p1= "abc"; 				// verboten, weil p1 const ist



	const char* p2 = "Mary";	// p2 ist nicht const, wert ist const
	//*p2 = 'C'; 				// verboten, weil wert const
	p2 = "Margareth";  			// erlaubt, weil p2 nicht const ist



	return 0;
}
