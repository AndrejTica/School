/*
1.2.4.  Aufgabe: pipe_rate.c
Zwei Prozesse spielen "Zahlenraten" 

Parentprozess denkt sich eine Zahl zwischen 1 und 100 aus 
Dann wiederholt bis zum Treffer... 
1.Childprozess macht einen Rateversuch und schreibt die Zahl in die up-Pipe 
2.Parentprozess liest die geratene Zahl aus der up-Pipe 
3.Parentprozess bewertet die geratene Zahl mit -1 (zu tief), 0 (getroffen) oder +1 (zu hoch) 
4.Parentprozess schreibt die Bewertung in die down-Pipe 
5.Childprozess liest die Bewertung aus der down-Pipe und leitet daraus einen neuen Rateversuch ab 

Hinweis:
Verwenden Sie fdopen(), fprintf(), fscanf() zur Kommunikation
*/

//ENTER CODE