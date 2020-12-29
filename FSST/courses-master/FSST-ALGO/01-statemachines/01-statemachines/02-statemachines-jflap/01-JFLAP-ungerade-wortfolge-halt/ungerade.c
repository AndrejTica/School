/*
@author  NN
@date 2015
@file ungerade.c
@description
 
Lies eine Folge von Ziffern (0 oder 1) ein.
Ermittle, ob die eingegebene Dualzahl gerade oder ungerade ist.
EOS(Stringende) beendet die Eingabe.


gcc ungerade.c -o ungerade.exe
./ungerade.exe 2>err-ungerade.log

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


bool ungerade(const char* word);

int main(){
	
	printf("\nSTART testing ungerade ...\n"); system("date");fflush(stdout);

	assert( ungerade("1001") == true && "Testing: 1001");
	
	assert( ungerade("0011") == true && "Testing: 0011");
	assert( ungerade("101010") == false && "Testing: 101010");
	assert( ungerade("1110") == false && "Testing: 1110");
	assert( ungerade("0001") == true && "Testing: 0001");
	assert( ungerade("0110") == false && "Testing: 0110");
	assert( ungerade("101001") == true && "Testing: 101001");
	assert( ungerade("11111") == true && "Testing: 11111");
	

	printf("\nEND testing ungerade ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n"); 
	
	return 0;
}


bool ungerade(const char* word){
	int i=0;
	int ch= word[i];
	
	enum state_t { /*q0*/ gerade, /*q1*/ ungerade} state;
	state=gerade;
	while(ch != '\0' ){
		switch(state){
			case gerade:
				if (ch == '1')
					state=ungerade;
				else if (ch=='0')
					state= gerade;
				break;

			case ungerade:
				if (ch == '1')
					state=ungerade;
				else if (ch=='0')
					state= gerade;
				break;
        }
		i++;
		ch= word[i];
	}

    if (state==gerade)
        return false;
    else
        return true;
}

