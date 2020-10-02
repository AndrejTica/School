// ahofmann, 2015
// HANGMAN.H

void newGame(void);


void getWord2show(char word[]);
void getWord2guess(char word[]);
int getBadTries();
int getMaxTries();

int tryChar(char ch);
int tryWord(char word[]);


int success();
int gameOver();





