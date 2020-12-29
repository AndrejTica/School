/**
* spiel.c
* ahofmann, 2013
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "spiel.h"


/**
* nur hier sichtbare Variablen
* */
#define EMPTY ' '
#define WATER '.'
#define MIST '-'
#define HIT 'x'
#define TOTAL_HIT 'X'

#define BOAT 'B'


#define UNIX

#ifdef UNIX
#define clrscr() system("clear")
#else
#define clrscr() system("cls")
#endif


#define DIM 10
static char gameBoard[DIM][DIM];
static int points=0;
static char name[128];


/**
* lokale Hilfsfunktionen
*/
// x,y,with, height,value 
static void fillGameBoard(int x, int y, int w, int h, char value); 
static void printGameBoard(void);
static void newBoat(int length);
static int finished(void);
static int setBoat(int x, int y, int length);

/**
------------------------------------------------------------------------
* global sichtbare Funktionen
------------------------------------------------------------------------
* */

void newGame(const char pname[]){
	int i,j;
	
	fillGameBoard(0,0,10,10, EMPTY); // x,y,with, height,value

	points=0;
	strcpy(name, pname);


	newBoat(4);
	
	newBoat(3);
	newBoat(3);

	newBoat(2);
	newBoat(2);
	newBoat(2);

	printGameBoard();
}


static int finished(){
	int x, y;

	for (y = 0; y < DIM; y++){
		for (x = 0; x < DIM; x++){
			if (gameBoard[x][y]==BOAT)
				return 0;
		}
	}
	
	return 1;
}



int doLogic(){
	int x, y;

	do{
		printf("\n%s:%3i point(s): x,y: ", name, points);
		scanf("%d,%d", &x, &y);
	}while (x < 0 || x >=DIM || y<0 || y>=DIM);

	points++;

	if(gameBoard[x][y]==EMPTY)
		gameBoard[x][y]=WATER;
	else if(gameBoard[x][y]==BOAT)
		gameBoard[x][y]= HIT;
	
		printGameBoard();

	if (finished())
		return 1;

	return 0;
}



/**
* lokale Hilfsfunktionen
*/

static void fillGameBoard(int x, int y, int w, int h, char value){ 
// x,y,with, height,value
	int i,j;
	
	for (i=x; i< w; i++){
		for (j=y; j< h; j++){
			gameBoard[i][j]= value;
		}
	}
}

static void printGameBoard(void){
	int x,y;

	clrscr();

	printf("\nx->    0   1   2   3   4   5   6   7   8   9\n");
	printf("     +---+---+---+---+---+---+---+---+---+---+\n");
	for(y = 0; y < DIM; y++) {
		printf("  %i  | ",y);
		for (x=0; x < DIM; x++){
			if (gameBoard[x][y] != BOAT)
				printf("%c",gameBoard[x][y]);
			else
				printf("%c", ' ');

			printf(" | ");
		}
		printf("\n     +---+---+---+---+---+---+---+---+---+---+\n");

	}
}


static void newBoat(int length){
	int x,y;
	int done=0;

	srand(time(NULL));
	while (!done){
		x= rand() % (DIM - length);
		y= rand() % (DIM - length);
	
		done= setBoat(x,y,length);
	}
}

static  int setBoat(int x, int y, int length){
	int i;
	int ok=1;

	// check row
	// -----------------------------------------
	for (i=0; i < length; i++){
		if (gameBoard[i+x][y] != EMPTY)
			ok=0;
	}
	// row ist ok, so check boarder
	// upper border: y-1
	if (y==0)
		;
	else{
		for (i=0; i < length; i++){
			if (gameBoard[i+x][y-1] != EMPTY)
				ok= 0;
		}
	}
	// lower border: y+1
	if (y==DIM-1)
		;
	else{
		for (i=0; i < length; i++){
			if (gameBoard[i+x][y+1] != EMPTY)
				ok= 0;
		}
	}

	// left
	if (x==0)
		;
	else if(gameBoard[x-1][y] != EMPTY)
		ok= 0;

	//right
	if (x==0)
		;
	else if(gameBoard[x-1][y] != EMPTY)
		ok= 0;


	// row is ok, so set the BOAT
	if(ok){
		for (i=0; i < length; i++){
				gameBoard[i+x][y] = BOAT;
			}

		return ok;
	}

	// check col
	// -----------------------------------------
	for (i=0; i < length; i++){
		if (gameBoard[x][i+y] != EMPTY)
			ok=0;
	}
	// col ist ok, so check boarder
	// left border: x-1
	if (x==0)
		;
	else{
		for (i=0; i < length; i++){
			if (gameBoard[x-1][i+y] != EMPTY)
				ok= 0;
		}
	}
	// right border: x+1
	if (x==DIM-1)
		;
	else{
		for (i=0; i < length; i++){
			if (gameBoard[x+1][i+y] != EMPTY)
				ok= 0;
		}
	}

	// upper
	if (y==0)
		;
	else if(gameBoard[x][y-1] != EMPTY)
		ok= 0;

	//lower
	if (y==DIM-1)
		;
	else if(gameBoard[x][y+1] != EMPTY)
		ok= 0;


	// col is ok, so set the BOAT
	if(ok){
		for (i=0; i < length; i++){
				gameBoard[x][y+i] = BOAT;
			}

		return ok;
	}

	// cannot find a place:
	// 		left of x,y
	//		down of x,y
	return 0;
}
