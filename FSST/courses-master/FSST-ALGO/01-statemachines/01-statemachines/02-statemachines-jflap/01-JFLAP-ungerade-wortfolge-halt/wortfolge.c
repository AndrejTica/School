/*
@author NN
@date 2015
@file wortfolge.c

@description
Es werden Worte akzeptiert, die mit einem 'h' beginnen, mit einem 'a' 
fortgesetzt werden und danach eine endliche Anzahl an 'ha' folgen lassen. 
Um in den Endzustand (akzeptieren) zu gelangen muss am Ende des Wortes 
ein '!' folgen.
Es werden also 'ha!', 'haha!', 'hahaha!' etc. akzeptiert.


gcc wortfolge.c -o wortfolge.exe
./wortfolge.exe 2>err-wortfolge.log

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool wortfolge(const char* word);

int main(){	
	printf("\nSTART testing wortfolge ...\n"); system("date");fflush(stdout);

	assert( wortfolge("ha!") == true && "Testing: ha!");
	assert( wortfolge("hahaha!") == true && "Testing: hahaha!");
	assert( wortfolge("haah!") == false && "Testing: haah!");
	assert( wortfolge("ahaha!") == false && "Testing: ahaha!");
	assert( wortfolge("haaha!") == false && "Testing: haaha!");
	assert( wortfolge("hahahahahaha!") == true && "Testing: hahahahahaha!");
	assert( wortfolge("!") == false && "Testing: !");

	printf("\nEND testing wortfolge ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n");
	
	return 0;
}


bool wortfolge(	const char* word) {
	int i=0;
	char ch= word[i];

	enum state_t {q0, q1 /*h*/ ,q2 /*a*/ ,q3} state;
	state=q0;
	while(ch != '\0' && state!=q3 ){
		switch(state){
			//
			// ENTER CODE HERE
			//
		}

		// next char
		i++;
		ch= word[i];
	}

	if (state==q3)
		return true;
	else
		return false;
}
