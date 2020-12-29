/*
1.3.2.  Aufgabe: fork_fileserver.c
Schreiben Sie das Programm t_fileserver.c derart um, dass das Filehandling durch einen Child-Prozess realisiert wird. Dadurch kann der Server bereits den nächsten Request eines Client-Programmes t_fileclient.c annehmen. Es können demnach mehrere Clients gleichzeitig bedient werden.

Hinweis:
Um keine sog. Zombie-Prozesse zu erzeugen, vergessen Sie für den Parent-Prozess nicht auf die Funtkion waitpid(-1,NULL,WNOHANG).

*/

