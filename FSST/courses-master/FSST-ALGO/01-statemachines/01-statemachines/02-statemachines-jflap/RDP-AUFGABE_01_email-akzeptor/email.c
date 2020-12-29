/*
@author NN
@date 2015
@file email.c

@description
Wir betrachten hier vereinfachte E-Mail-Adressen, in denen nur die 
Symbole {b, @, .} vorkommen dürfen.  Beispiel: bb@b.bbb.bb
Definition: Eine E-Mail-Adresse besteht aus
einem User-Namen gefolgt vom @-Symbol und einer Domain-Angabe. 
Der User-Name soll nur aus b´s bestehen. 
Die Domainangabe soll aus 
Subdomains mit einer Topleveldomain aufgebaut sein, die jeweils mit einem 
Punkt getrennt werden. 
Während die Subdomains aus beliebig vielen b´s besteht, soll die 
Topleveldomain aus genau zwei b´s bestehen.

gcc email.c -o email.exe
./email.exe 2>err-email.log

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool email(const char* word);

int main(){	
	printf("\nSTART testing email ...\n"); system("date");fflush(stdout);

	assert( email("b@b.bb!") == true && "Testing: b@b.bb!");
	assert( email("@b.b.bb!") == false && "Testing: @b.b.bb!");
	assert( email("bbb@bbb!") == false && "Testing: bbb@bbb!");
	assert( email("bb.b@b.bb!") == false && "Testing: bb.b@b.bb!");

	assert( email("b@bb!") == false && "Testing: b@bb!");
	assert( email("b@b..bb!") == false && "Testing: b@b..bb!");
	assert( email("b@!") == false && "Testing: b@!");
	assert( email("b@bb.b!") == false && "Testing: b@bb.b!");
	assert( email("bbb.@bb!") == false && "Testing: bbb.@bb!");
	assert( email("b@b.bb!") == true && "Testing: b@b.bb!");
	assert( email("bbbb@bb.bb.bb.b.bb!") == false && "Testing: bbbb@bb.bb.bb.b.bb!");

	printf("\nEND testing email ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n");
	
	return 0;
}


bool email(const char* word) {
	int i=0;
	char ch= word[i];

	enum state_t {
		/*q0*/ toUserName, 
		/*q1*/ inUserName, 
		/*q2*/ toSubdomain, 
		/*q3*/ inSubdomain, 
		/*q4*/ toTopdomain1, 
		/*q5*/ toTopdomain2, 
		/*q6*/ inTopdomain, 
		/*q7*/ end} state;
		
	state=toUserName;
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
