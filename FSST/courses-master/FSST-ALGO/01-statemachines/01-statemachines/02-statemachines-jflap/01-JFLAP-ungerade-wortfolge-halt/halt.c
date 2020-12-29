/*
@author  NN
@date 2015
@file halt.c
@description

Es werden Buchstaben akzeptiert.
Die gelesenen Buchstaben werden ausgegeben bis das Wort HALT eingegeben wurde. 
Dabei muss das Wort HALT nicht als zusammenhängendes Wort eingegeben worden sein.

Bsp.:
abhahluzatngt
abhahluzat


gcc halt.c -o halt.exe
./halt.exe 2>err-halt.log

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <assert.h>


bool halt(const char* word, const char* result);

int main(){	
	printf("\nSTART testing halt ...\n"); system("date");fflush(stdout);

	assert( halt("halt", "halt") == true && "Testing: halt");
	assert( halt("xxhxxxaxxxlxxxxtxxxxx", "xxhxxxaxxxlxxxxt") == true && "Testing: xxhxxxaxxxlxxxxt");
	assert( halt("xxxxx", "xxxxx") == true && "Testing: xxxxx");
	assert( halt("abhahluzatngt", "abhahluzat") == true && "Testing: abhahluzatngt");
	
	

	printf("\nEND testing halt ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n"); 
	
	return 0;
}


bool halt(const char* word, const char* result){
	int i=0;
	int ch= word[i];
	char word_out[strlen(word)+1];		
	
	enum state_t {q0, /*q1*/ h, /*q2*/ a, /*q3*/ l, /*q4*/t} state;
	state=q0;
	while(ch != '\0' && state!= t){
		switch(state){
			//
			// ENTER CODE HERE
			//
		}
				
		i++;
		ch= word[i];
	}

	if (strcmp(word_out, result)==0)
		return true;
	else
		return false;
		
}
