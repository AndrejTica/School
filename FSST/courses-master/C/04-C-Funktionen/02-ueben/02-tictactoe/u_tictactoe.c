/**
 * Hausübung: Funktionen in C
 *
 * @author Vorname Nachname (Klasse: ????)
 * @file tictactoe.c
 * @date ???????
 *
 * @description
 * + Der user spielt gegen den Computer.
 * + Am Beginn wird per User-Eingabe gewählt, wer beginnen darf
 *
 * Algorithmus: TICTACTOE
	Computer wählt wie folgt:
	if (canWin())
	else if (avoidWin())
	else if (tryCenter())
	else if (tryCorner())
	else if (searchPlace())
	else
		game finished?
 *
 * Übersetzen:
 * gcc -DUNIX tictactoe.c -o tictactoe.exe
 *
 * Starten:
 * ./tictactoe.exe
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define UNIX

#ifdef UNIX
#define clrscr() system("clear")
#else
#define clrscr() system("cls")
#endif


//* --------------------------------------------------------------------------------
// some macros and glob. vars
//* --------------------------------------------------------------------------------

#define PLAYER 'x'
#define COMPUTER 'o'
#define EMPTY ' '
#define GAME_OVER 0

#define WINNER 1


// the gameboard
char TicTacToe[3][3] = {
		{EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY}
};


/**
 * --------------------------------------------------------------------------------
 * function declaration
 * --------------------------------------------------------------------------------
 */
void print_gameboard(void);

/**
 * Computer/Player sets a field
 * @return GAME-OVER or !GAME_OVER
 */
int setMove(char player_or_computer);

void playerPlays();
void computerPlays();

// strategy for the computers AI
int canWin(void);
int avoidWin(void);
int tryCenter(void);
int tryCorner(void);
int searchPlace();

int if_win(char);



/**
 * --------------------------------------------------------------------------------
 * MAIN
 * --------------------------------------------------------------------------------
 */
int main(void) {
	char who = PLAYER;
	int end= !GAME_OVER;

	// Spielfeld ausgeben
	print_gameboard();

	printf("\n\twho starts playing? (x ... player, o ... computer)? ");
	who= fgetc(stdin);
	fgetc(stdin); // wegen enter


	end= setMove(who);

	while (end != GAME_OVER){
		// change player
		if (who==PLAYER)
			who= COMPUTER;
		else
			who= PLAYER;

		end= setMove(who);
	}

	return EXIT_SUCCESS;
}



/**
 * --------------------------------------------------------------------------------
 * function implementation
 * --------------------------------------------------------------------------------
 */
void print_gameboard(void) {
	// -----------------------------------------------------------------------------
	int i;

	clrscr();

	printf("\n       0   1   2  \n");
	printf("     +---+---+---+\n");
	for(i = 0; i < 3; i++) {
		printf("  %i  | ",i);
		printf("%c",TicTacToe[i][0]);
		printf(" | ");
		printf("%c",TicTacToe[i][1]);
		printf(" | ");
		printf("%c",TicTacToe[i][2]);
		printf(" | \n");
		if(i != 2) {
			printf("     +---+---+---+\n");
		}
		else {
			printf("     +---+---+---+\n");
		}
	}
}

/*
 *does the next move for player or computer
 *
 *@param in char player_or_computer
 *@return GAME_OVER or !GAME_OVER
 */
int setMove(char player_or_computer){
	// -----------------------------------------------------------------------------
	int retIsGameOver= !GAME_OVER;

	if (player_or_computer==PLAYER){
		playerPlays();
	}else{
		computerPlays();
	}

	print_gameboard();


	if (if_win(PLAYER)){
		printf("\n*** THE WINNER IS ... PLAYER ***\n");
		retIsGameOver=GAME_OVER;
	}else if (if_win(COMPUTER)){
		printf("\n*** THE WINNER IS ... COMPUTER ***\n");
		retIsGameOver=GAME_OVER;
	}else{
		retIsGameOver= !GAME_OVER;
	}

	return retIsGameOver;
}



void playerPlays(){
	// -----------------------------------------------------------------------------
	int row, col;

	// input
	printf("\n\tX: row? ");
	scanf("%i", &row);
	printf("\tX: col? ");
	scanf("%i", &col);

	// free?
	if (TicTacToe[row][col]== EMPTY){
		TicTacToe[row][col]=PLAYER;
	}else{
		printf("\n\tERROR: Field (%i,%i) already used!\n", row,col);
		printf("\n\tCOMPUTER is the WINNER!!!\n");
		exit(0);
	}
}



void computerPlays(){
	// -----------------------------------------------------------------------------
	printf("\n*** TODO computerPlays() ***\n");
	printf("continue with enter ...");
	fgetc(stdin);fgetc(stdin);
}


int canWin(){
	// -----------------------------------------------------------------------------
		return 0;
}


int avoidWin(){
	// -----------------------------------------------------------------------------

	return 0;
}

int tryCenter(){
	// -----------------------------------------------------------------------------
	return 0;
}

int tryCorner(){
	// -----------------------------------------------------------------------------
	return 0;
}



int searchPlace(){
	// -----------------------------------------------------------------------------
	return 0;
}


int if_win(char aPlayer) {
	// -----------------------------------------------------------------------------

	if((TicTacToe[0][0] == aPlayer &&	// rows
			TicTacToe[0][1] == aPlayer &&
			TicTacToe[0][2] == aPlayer)
			||
			(TicTacToe[1][0] == aPlayer &&
					TicTacToe[1][1] == aPlayer &&
					TicTacToe[1][2] == aPlayer)
					||
					(TicTacToe[2][0] == aPlayer &&
							TicTacToe[2][1] == aPlayer &&
							TicTacToe[2][2] == aPlayer)
							||
							(TicTacToe[0][0] == aPlayer &&	// cols
									TicTacToe[1][0] == aPlayer &&
									TicTacToe[2][0] == aPlayer)
									||
									(TicTacToe[0][1] == aPlayer &&
											TicTacToe[1][1] == aPlayer &&
											TicTacToe[2][1] == aPlayer)
											||
											(TicTacToe[0][2] == aPlayer &&
													TicTacToe[1][2] == aPlayer &&
													TicTacToe[2][2] == aPlayer)
													||
													(TicTacToe[0][0] == aPlayer && // \ .
															TicTacToe[1][1] == aPlayer &&
															TicTacToe[2][2] == aPlayer)
															||
															(TicTacToe[0][2] == aPlayer && // /
																	TicTacToe[1][1] == aPlayer &&
																	TicTacToe[2][0] == aPlayer)) {
		return WINNER;
	}

	return !WINNER;
}

