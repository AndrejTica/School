# Millionenshow and Filehandling with C

## Part 1: Introduction to filehandling

1. [Listening](http://www.youtube.com/watch?v=ohKgcZaEqvc)
2. [Reading](http://www.tutorialspoint.com/cprogramming/c_file_io.htm)

### lab: filehandling

* fcat,fcp,ftar,fbmi,fnoten,fkrypto


## Part 2: Project: “millionenshow” with modern project management

**a must **
1. work in a team with 2 persons
2. use git for your project files
3. use modern project management


**project management**

1. specification: WHAT should be done?
2. design: HOW should it be done?
	1. system design
	2. module design
3. implementation:
	1. coding and white box tests
4. integration and testing
5. approval and acceptance

## Step 1: specification (WHAT should be done?)

This project is divided into two parts:

1. administrator mode 
	* Questions are grouped into 5 different levels (grouped by difficulty)
	* Questions are stored in textfiles. (level00.md, level01.md, ...)
	* Each question is assigned to one level and consists of a 
		* questiontext and 
		* answertext and
		* points for the correct answer
	* Questions can be listed, added, modified or deleted.

2. player mode. 
	* The User/player can play the millionenshow via player mode.
	* The Quiz offers 5 levels of difficulty/prizes.
		* 1.000.000
		* 500.000
		* 100.000
		* 50.000
		* 5.000
	* The user gets for each prize level a randomly selected question.
	* If the users answer is correct he gets the next levels question that is
		selected randomly.
	* If the users answer is wrong the game is over and he gets a final screen
		with his final result/prize.
	* A user has just one public joker (=answer from the floor)
	* A user has just one ‘get another question’ joker.
	* If a user fails to answer the question (500.000) he falls back to
		level 50.000 and the game is over.
	* Every game is logged into millionenshow.log
		* player name
		* date and time
		* reached level

### Lab: User Interface

1. create a first UI for administrator mode
	1. list questions
	2. del a question
	3. add a question
	4. modify a question

1. create a first UI for player mode
	???


## Step 2: design: HOW should it be done?

use top-down method:
	1. system design
	2. module design


### system design

on programm start the user can choose between administrator or player mode.

1. the **administrator module** (administrator.c/.h)
	1. displays the administratorator-user interface
	2. uses the question module (see below) for question-management 

2. the **player module** (player.c)
	1. displays the player interface
	2. uses the question module (see below) 
	3. uses the quiz module to play the quiz

3. the **quiz module** (quiz.c)
	1. register a new player (name, ...)
	2. start the quiz (date,time, ...)
	3. display the first/next question and the players prize-level
	4. get and check the answer
		1. if correct goto 3.
		2. else goto 5.
	5. store players result in the quiz-log-file (millionenshow.log)

Mybe this design does not match your thoughts. 
> **Feel free to use your design reflections.**


By the way, we got an additional module: the **question module**


### module design: QUESTION-MODULE: question.h, question.c
use module design strategy:
	1. First lets take a look at the used **data-structures**.
	2. Second find out what to do with these variables (**functionality**).


By using prototyping we focus on an example that shows how to store a question.
Questions of level 0 (easy) are stored in level00.md
...
Questions of level 4 (NOT easy) are stored in level04.md

note: lines with # are comment lines

example: level00.md
~~~
	# number of questions
	4
	# question .............................................
	What is the correct name of a well-known C header file?
		a) standard.h
		b) comein.h
		c) stdlib.h
		d) cool.h
	## answer
	c
	## points
	0
	# question .............................................
	What is not an element of the C programming language?
		a) for
		b) while
		c) foreach
		d) typedef
	## answer
	c
	## points
	0
	# question .............................................
	Which definition of a variable is incorrect?
		a) int* x;
		b) char[] w;
		c) int* (*f)();
		d) float f[1];
	## answer
	b
	## points
	0
	# question .............................................
	Which declaration of a function is incorrect?
		a) void strcpy(char*, const char*);
		b) int strlen(const char*);
		c) char* fgets(char*, int, FILE*);
		d) int getchar(void);
	## answer
	a
	## points
	0
~~~

using this example we can define the following data-types:
```c
/**
 * @author hofmann
 * @file question.c
 * @date Son Mär 29 22:31:22 CEST 2015
 * @brief millionenshow: question module
 */

#include <stdio.h>

// SIZE macros
#define QUESTION_LEN 1024
#define ANSWER_LEN 128
#define MAXLINE 128

// type decl for question - module
// -------------------------------
// ONE question
typedef struct {
	char QText[QUESTION_LEN+1];
	char AText[ANSWER_LEN+1];
	int points;
} TQUESTION;

// MANY questions
typedef struct {
	int level;
	TQUESTION* questions;
	int nQuestions;
} TLEVELS;


// func decl
// --------------------

// read/write the database
int q_open(????????????);
int q_save(???????????);

// this is for administration module


// this is for player module
// accessing data
int q_getRandomQuestionAtLevel(int level, TQUESTION*);

```


### lab: design the complete question module 

Hint: check the requirements of the other modules

### module design: PLAYERS-MODULE: player.h, player.c
????todo
### module design: ADMINISTRATOR-MODULE: administrator.h, administrator.c
????todo
### module design: QUIZ-MODULE: quiz.h, quiz.c
????todo


# conclusion

this first discussion should give you some hints to make
1. a REALLY good DESIGN and 
2. a COOL IMPLEMENTATION.

HAVE FUN and keep coding.

