// ahofmann, 2015
// hangman.c

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hangman.h"

#define WORDS 10

// STATIC VAR
// -----------------------------------------------------------------------------
static char wordlist[WORDS][80+1]= {
	"hangman",
	"double",
	"pointer",
	"documents",
	"kontruktor",
	"klausthaler",
	"handy",
	"library",
	"malloc",
	"codingforfun"
};

// 
static char word2guess[80+1];	// for example:   handy
static char word2show[80+1];	// contains only: -----
static int badtries=0;
static int goodtries=0;
static int maxtries=9;
static int end=0;

// GLOBAL FUNCTIONS
// -----------------------------------------------------------------------------
void newGame(void){

	// init above variables to start a new game
	
}

void getWord2show(char word[]){
	// copies word2show to parameter word;
}

void getWord2guess(char word[]){

	
}

int getBadTries(){
	
}

int getMaxTries(){

}

int tryChar(char ch){

	// is ch a character in word2guess ?
	
	// set goodtries and badtries
	
	
	// check if we have got the word and set variable end

	// check if we have to many tries and set variable end

}


int tryWord(char word[]){
	// set end or badtries if word mathes or not
	
}


int success(){
	return badtries<maxtries;
}

int gameOver(){
	return end;
}



