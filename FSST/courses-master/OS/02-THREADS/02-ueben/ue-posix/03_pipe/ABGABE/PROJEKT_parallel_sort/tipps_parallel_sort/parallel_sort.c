// parallel_sort.c
// Beispiel fuer pipe, dup, fork, exec
// ./parallel_sort.exe daten.txt

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


#define SCHREIB 1
#define LIES 0


void child(int n);	// code f. child-prozesse


//PARENT:fdparent_out1[SCHREIB] ----> CHILD1 (sort):fdparent_out1[LIES]
//PARENT:fdparent_out2[SCHREIB] ----> CHILD2 (sort):fdparent_out2[LIES]

//PARENT:fdparent_in1[LIES] <---- CHILD1 (sort):fdparent_in1[SCHREIB]
//PARENT:fdparent_in2[LIES] <---- CHILD2 (sort):fdparent_in2[SCHREIB]

// zum Child 1
int fdparent_out1[2];
int fdparent_in1[2]; 
 
// zum Child 2
int fdparent_out2[2];
int fdparent_in2[2];  

// Streams
FILE* parent2child1;
FILE* parent2child2;
FILE* child2parent1; // child1 -> parent
FILE* child2parent2; // child2 -> parent


int main(int argc, char* argv[]) {
	int pid;
	FILE* fd;
	int  zahl1,zahl2, nread;
	char buf[10];				// Datenspeicher
	char* ret, *ret1,*ret2;
	
	
	if (argc < 2) {
		fprintf(stderr, "Aufruf: %s file\n", argv[0]);
		exit(1);
	}

 //pipes erzeugen
	if (pipe(fdparent_in1) < 0 || pipe(fdparent_out1) < 0) {
		perror("Fehler bei pipe");
		exit(1);
	}   
	if (pipe(fdparent_in2) < 0 || pipe(fdparent_out2) < 0) {
		perror("Fehler bei pipe");
		exit(1);
	}

//streams erzeugen
	if((parent2child1=fdopen(fdparent_out1[SCHREIB], "w"))==NULL){
		perror("Fehler bei fdopen");
		exit(1);
	}
			
	if((parent2child2=fdopen(fdparent_out2[SCHREIB], "w"))==NULL){
		perror("Fehler bei fdopen");
		exit(1);
	}
	
	if((child2parent1=fdopen(fdparent_in1[LIES], "r"))==NULL){
		perror("Fehler bei fdopen");
		exit(1);
	}
	
	if((child2parent2=fdopen(fdparent_in2[LIES], "r"))==NULL){
		perror("Fehler bei fdopen");
		exit(1);
	}
			
//prozesse starten
	pid=fork(); //-----------------------------------------------starte child(1)
	if (pid==0) { //1.Child   
		 child(1); exit(0); 
	}
	else if (pid>0) { 
   		pid=fork();  //------------------------------------------starte child(2)
		if (pid==0) { //2.Child   
	 		child(2);  exit(0);   
		}
		else if (pid>0) { // ------------------------------------PARENT
			//brauch ich nicht
			close(fdparent_out1[LIES]);
			close(fdparent_in1[SCHREIB]);
			close(fdparent_out2[LIES]);
			close(fdparent_in2[SCHREIB]);


			// 1. FILE öffnen
			if ((fd = fopen(argv[1], "r")) ==NULL) {
				perror("Fehler bei open");
				exit(1);
			}

			// 2. FILE zeilenweise lesen und abwechselnd an die Childs senden
			while ((ret=fgets(buf, 10, fd)) != NULL) {				
			// zum ==> 1. child
				#ifdef DEBUG
				printf("\nparent2child1>> %d", atoi(buf));fflush(stdout);
				#endif
				fputs(buf, parent2child1);

			//File
				ret=fgets(buf,10,fd);
				if (ret != NULL) {
			// zum ==> 2. child
					#ifdef DEBUG
					printf("\nparent2child2 >> %d", atoi(buf));fflush(stdout);
					#endif
					fputs(buf, parent2child2);
				}
				else {
					#ifdef DEBUG
					printf("\nFERTIG mit LESEN aus Datei ------------------\n");
					fflush(stdout);
					#endif
					;
				}
			}//while file lesen

			// 3. FILE schliessen
			fclose(fd);
			

			// 4. SCHREIB-Kanäle schliessen
			// Hinweis: fclose() schliesst auch die pipes
			fclose(parent2child1);	
			fclose(parent2child2);	//close(fdparent_out2[SCHREIB]);
			

			//5. SORTIERTE TEILE von childs lesen und MergeSort anwenden
			#ifdef DEBUG
			printf("\n....VOR  lesen von CHILD1 und CHILD2...\n"); fflush(stdout);	
			#endif

			ret1=fgets(buf,10,child2parent1);
			if(ret1!=NULL) zahl1= atoi(buf);
			ret2=fgets(buf,10,child2parent2);
			if(ret2!=NULL) zahl2= atoi(buf);			
			
			while (ret1!=NULL && ret2!=NULL){
				if (zahl1 <= zahl2){
					printf("\n(von Child1) %6d",zahl1);fflush(stdout);
					ret1=fgets(buf,10,child2parent1);					
					if(ret1!=NULL) zahl1= atoi(buf);
				}
				else {
					printf("\n(von Child2) %6d",zahl2);fflush(stdout);
					ret2=fgets(buf,10,child2parent2);					
					if(ret2!=NULL) zahl2= atoi(buf);
				}
			}
			
			while(ret1!=NULL){
			 	printf("\n(von Child1) %6d",zahl1);fflush(stdout);
				ret1=fgets(buf,10,child2parent1);					
				if(ret1!=NULL) zahl1= atoi(buf);
			 }
			 
			 while(ret2!=NULL){
			 	printf("\n(von Child2) %6d",zahl2);fflush(stdout);
				ret2=fgets(buf,10,child2parent2);					
				if(ret2!=NULL) zahl2= atoi(buf);
			 }
			
			// 6. LESE-Kanäle schliessen
			fclose(child2parent1);//close(fdparent_in1[LIES]);
			fclose(child2parent2);//close(fdparent_in2[LIES]);

		}//elseif
	}//elseif

	printf("\nDONE\n");

	return 0;
}//main




void child(int n){
/* Child-Prozess richtet eine pipe zw. parent und standard-unix utility sort ein*/
//schliesst stdin, stdout
//dupliziert die beiden Kanäle, die mit Parent verbunden sind
//schliesst seine (Child) Parentkanale (die duplizierten bleiben davon unberührt)
//verwandelt sich vom child-prozesse in den externen sort-prozess, der
//mit den zuvor duplizierten Kanälen arbeitet. d.h.
//die standardkanäle des sort-prozesses sind mit den zuvor duplizierten Kanälen
//verbunden. d.h.
//ein read(0,buf,len) des sort-prozesses liest tatsächlich vom
//     fdparent_out[LIES]
//ein write(1,buf,len) des sort-prozesses schreibt tatsächlich nach
//     fdparent_in[SCHREIB]
//Auf diese Weise kommuniziert der Parent direkt mit dem externen Programm


	// IO-Kanäle f. Child1
	if (n==1){

		// std-eingabe schliessen
		??????????????????

		// dupliziere LIES-Kanäle mit parent
		??????????????????

		//std-ausgabe schliessen
		??????????????????

		// dupliziere SCHREIB-Kanäle mit parent
		??????????????????
	}
	else {
		// IO-Kanäle f. Child2

		//std-eingabe schliessen
		??????????????????

		// dupliziere LIES-Kanäle mit parent
		??????????????????

		//std-ausgabe schliessen
		??????????????????


		// dupliziere SCHREIB-Kanäle mit parent
		??????????????????
	}


	// schliesse alle pipe
		??????????????????


	// SORTIEREN numerisch mit execlp
		??????????????????

} //end child

