/* 
 * Demo: pipe, fork, fdopen 
 * 
 * Parent 
 * - liest Shell-Befehle von tastatur
 * - sendet diese zum Logging an den Child-Prozess
 * - führt den Befehl mit system() aus
 * - ende mit exit als Eingabe
 * 
 * PARENT: 
 *    fgets(stdin) 
 *    fputs(pipe_out)
 * CHILD: 
 *    fgets(pipe_in) 
 *    fputs(newfile_out) 
 *
 * gcc demo_pipe_fdopen.c -o demo_pipe_fdopen.exe
 * ./demo_pipe_fdopen.exe default.msh 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define USAGE printf("usage : %s default.msh\n", argv[0]);
#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
	int fd[2], i, n;
	pid_t pid;
	char buf[BUF_SIZE];

	FILE *child_in, *parent_out, *newfile_out;

	if (argc != 2)
	{
		USAGE;
		exit(0);
	}

	// PIPE
	if (pipe(fd) < 0)
	{
		perror("pipe()");
		exit(0);
	}

	// FORK
	if ((pid = fork()) < 0)
	{
		perror("pipe : ");
		exit(0);
	}

	// PARENT ====================================
	else if (pid > 0)
	{
		close(fd[0]); /*Leseseite schliessen*/

		// Stream erzeugen
		parent_out = fdopen(fd[1], "w");
		if (parent_out == NULL)
		{
			perror(" fdopen : ");
			exit(0);
		}

		// user eingabe und senden an client (zum Logging)
		do
		{
			fputs("\nBitte einen Befehl (or exit) > ", stdout);
			fgets(buf, BUF_SIZE, stdin);
			//buf[strlen(buf) - 1] = '\0'; // del EOL

			// zum Child
			fputs(buf, parent_out); 

			// execute command
			system(buf);
		} while (strncmp(buf, "exit" , 4) !=0);

		fclose(parent_out);
		wait(NULL);
	}
	// CHILD ====================================
	else
	{
		close(fd[1]); /*Schreibseite schliessen*/
		int line = 0;

		child_in = fdopen(fd[0], "r");
		if (child_in == NULL)
		{
			perror("fdopen : ");
			exit(0);
		}

		newfile_out = fopen(argv[1], "a+");
		if (newfile_out == NULL)
		{
			perror("fopen : ");
			exit(0);
		}

		do
		{
			// read command from parent
			fgets(buf, BUF_SIZE, child_in);

			// log command to file
			line++;
			fprintf(newfile_out, "%6d\t%s", line, buf);
		} while (strncmp(buf, "exit" , 4) != 0);

		fclose(newfile_out);
		fclose(child_in);

		exit(EXIT_SUCCESS);
	}

	return 0;
}
