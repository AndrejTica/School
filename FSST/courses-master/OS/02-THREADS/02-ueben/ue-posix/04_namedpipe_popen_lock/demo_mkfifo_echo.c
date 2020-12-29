// demo_mkfifo_echo.c 

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <signal.h> 

#define FIFO_NAME "/tmp/myFIFO-echo" 

int main(){ 
	int fd, ret; 
	char c; 

	ret=mkfifo(FIFO_NAME, S_IRUSR | S_IWUSR); 
	if (ret==-1){ perror(FIFO_NAME); exit(0); } 
 
	fd=open(FIFO_NAME,O_RDONLY); 
	if (fd<0 ) { perror(FIFO_NAME); exit(0); } 

	while (read(fd,&c,1)==1) 
		fputc(c, stdout); 

	close(fd); 
	 
	unlink(FIFO_NAME); 
 	return 0; 
 } 
 // gcc demo_mkfifo_echo.c -o demo_mkfifo_echo.exe 
 // ./demo_mkfifo_echo.exe 
 // 
 // in 2 anderen Terminals 
 // cat > /tmp/myFIFO-echo 
 