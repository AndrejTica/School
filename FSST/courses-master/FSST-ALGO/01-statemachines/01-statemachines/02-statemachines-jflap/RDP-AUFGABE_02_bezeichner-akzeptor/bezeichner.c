/*
@author NN
@date 2015
@file bezeichner.c

@description
Bezeichner sind vom Programmierer gewählte Namen für Variablen bzw. Konstante. 

Bezeichner in C:
Beginnen mit _ oder Buchstaben
Folgen können 0 oder mehrere _ oder Buchstaben oder Ziffern.
Ende der Eingabe ist der ;
* 

gcc bezeichner.c -o bezeichner.exe
./bezeichner.exe 2>err-bezeichner.log

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdbool.h>
#include <assert.h>

bool bezeichner(const char* word);

int main(){	
	printf("\nSTART testing bezeichner ...\n"); system("date");fflush(stdout);

	assert( bezeichner("_111;") == true && "Testing: _111;");
	assert( bezeichner("11;") == false && "Testing: 11;");
	assert( bezeichner("x111;") == true && "Testing: x111;");
	assert( bezeichner("xxxxxx*1;") == false && "Testing: xxxxxx*1;");
	assert( bezeichner("_;") == true && "Testing: _;");
	assert( bezeichner("_xx_11;") == true && "Testing: _xx_11;");
	assert( bezeichner("xxx_111;") == true && "Testing: xxx_111;");

	printf("\nEND testing bezeichner ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n");
	
	return 0;
}


bool bezeichner(const char* word) {
	int i=0;
	char ch= word[i];

	enum state_t {/*q0*/ first, /*q1*/ second, /*q2*/ end} state;
	state=first;
	while(ch != '\0' && state!=end ){
		switch(state){
			//
			// ENTER CODE HERE
			//

		}

		// next char
		i++;
		ch= word[i];
	}

	if (state==end)
		return true;
	else
		return false;
}
