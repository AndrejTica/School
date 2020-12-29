# Project: hangman

## Specification: WHAT todo

* First the screen should display dashes for each character of the word that
should be guessed.
* Afterwards ask the user for a character and
* display the word with dashes and that characters if they match characters in the word.
* if the user enters # he wants to finish guessing and enters the whole word.
* if the word is equal to the ‘guess word’ the game is successfully over.
* otherwise the game continues in carachter-guessing mode.


## Example: the guess word is ‘hangman’

```
	- - - - - - -	Enter (a)
	- a - - - a -	Enter (g)
	- a - g - a -	Enter (e)
	- a - g - a -	Enter (n)
	- a n g - a n	Enter (#) ~ end of character-guessing-mode

Enter: hangman →  correct / or back to character-guessing-mode
```

> Note: 
You should improve the game by using a table of guess-words. 
So the guess-word can be chossen randomly from that table.


## Design

### 1. design your data/datatypes
Some variables that should be given in one module (hangman.c/.h)
	* wordlist (hangman, star, coding, ...)
	* word2guess (hangman)
	* word2display (-a---a-)
	* goodtries (0)
	* badtries (0)
	* maxtries (9)
	* ....


### 2. Design your functions/operations

Some functions that work with that variables and should be in the module
hangman.c/.h
	* newGame()
	* tryCharacter(character): bool
	* tryWord(word): bool
	* getWord2display(): word
	* isGameOver(): bool 
	* success() (badtries==maxtries)
	* ....


### 3. How to use hangman module

	```c
	int main(){

		newGame();
		do {

			getWord2show(word2show);
			printf(“\n%s” , word2show);
			printf(“ your choice (#wrong: %i/%i)? “, getBadTries(),getMaxTries());
			inputChar= fgetc(stdin);

			if (inputChar==’#’){
				printf(“=> enter your word? “);
				gets(inputWord);
				tryWord(inputWord);
			}else{
				tryChar(inputChar);
			}

		}while (!gameOver());


		if (success()){
			printf(“\n<%s> YOU MADE IT !!!\n”, word2guess);
		}else{
			printf(“\nBETTER YOU TRY AGAIN\n”);
		}
	```
# have fun and keep coding

