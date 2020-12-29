#include <stdlib.h> 
#include <stdio.h> 

#include <unistd.h>

#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

int main(){ 
	int fd; 
	char buf[128];
	int anz; 
	 
	fd=open("demo_open.c", O_RDONLY); 
	if (-1==fd){ 
		fprintf(stderr, "Error: opening demo-open.c"); 
		exit(1); 
	} 
	 
	printf("fd=%i\n", fd);


	anz= read(fd, buf, 127); 
	while (anz > 0){ 
		write (1, buf, anz);  // 1...Console

		anz= read(fd, buf, 127); 
	} 
	 
	close(fd); 
	 
	return 0; 
}
