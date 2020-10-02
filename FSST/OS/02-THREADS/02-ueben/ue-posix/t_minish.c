/*
 * Datei: t_minish.c     Hofmann Anton
 * gcc t_minish.c o_strlist.c -o t_minish
 * Nutzt die verkettete Liste (o_strlist.h o_strlist.c)
 * Implementiert eine minishell
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "o_strlist.h"

enum BOOL {false,true};
typedef enum BOOL BOOLEAN;


char help[]=
  "\nMINISHELL::HELP\n \
  hi   ............. history\n \
  !#   ............. execute #th command\n \
  !save Filename ... save history list\n \
  !load Filename ... load history list from Filename\n \
  !do  ............. execute current history list\n \
  quit ............. quit MINISHELL\n\n";

char prompt[]="\nminish-> ";


#define MAXCMD   128
char cmd[MAXCMD];           /* enthaelt eingelesenes Kommando */
SLIST_HEADER * cmdSList;    /* History Liste                  */
void do_history();


main()
{
BOOLEAN end=false;


/* --------------------------------------------
 * Liste zur Speicherung der Kommandos erzeugen
 * --------------------------------------------*/
cmdSList= createSList();
if (cmdSList == (SLIST_HEADER *) NULL)
{
  fprintf(stderr,"Not enough memory\n");
  exit(1);
}


/* ----------------------
 * Logo und help ausgeben
 * ----------------------*/
printf("\nMINISHELL:: (Hofmann Anton, C-Einfuehrungskurs) ::Demo fuer verkettete Listen\n");
printf(help);


/* -------------------------------------------
 * Hauptschleife zur Verarbeitung der Eingaben
 * -------------------------------------------*/
while (end==false){
   /* -- Prompt ausgeben und Kommando einlesen */
   printf(prompt);
   fgets(cmd,MAXCMD,stdin);
   cmd[strlen(cmd)-1]='\0';

   /* -- Kommando verarbeiten */
   if (strcmp(cmd, "hi")==0)        /* -- history ausgeben */
      pr_SList(cmdSList, stdout);

   else if (strcmp(cmd, "help")==0) /* -- Hilfe ausgeben   */
      printf(help);

   else if (cmd[0] == '!')          /* -- Kommando aus history ausfuehren */
      {
      do_history();
      }

   else if (strcmp(cmd, "quit")==0) /* -- MINISHELL beenden  */
      {
      rm_SList(cmdSList); /* Liste freigeben */
      end= true;
      }
   else                             /* -- Kommando in history eintragen u. ausfuehren */
      {
      insertLast(cmdSList, cmd);
      system(cmd);
      }
}/* end_while */
}/*end_main*/



void do_history()
{
int number;
FILE *fp;

if (strncmp(cmd+1, "save", 4) == 0)   /* -- SAVE history */
{
   fp= fopen(cmd + 6, "w");
   if (fp==(FILE *) NULL)
      perror(cmd+6);
   else
   {
      pr_SList(cmdSList, fp);
      fclose(fp);
   }
}
else if (strncmp(cmd+1, "load", 4) == 0) /* -- LOAD history list from File */
{
   fp= fopen(cmd + 6, "r");
   if (fp==(FILE *) NULL)
      perror(cmd+6);
   else
   {
      rm_SList(cmdSList);     /* remove history list and build a new one from file */
      cmdSList= createSList();
      if (cmdSList == (SLIST_HEADER *) NULL)
      {
         fprintf(stderr,"Not enough memory\n");
      }
      else
      {
	 while(fgets(cmd, MAXCMD, fp))
            { 
	      cmd[strlen(cmd)-1]='\0';  /* loesche '\n'*/
	      insertLast(cmdSList, cmd+7);
	    }
      }
   }
}
else if (strncmp(cmd+1, "do", 2) == 0) /* -- EXECUTE current history list */  
{
   int i;
   char * cmdPtr;

   for (i=1; cmdPtr=get_entrySList(cmdSList,i); i++)
   {
      printf("%s%s\n",prompt, cmdPtr);
      system(cmdPtr);
   }
}
else if (isdigit(cmd[1]))                 /* -- EXECUTE #th history command */
   {
     number= atoi(cmd+1);
     system(get_entrySList(cmdSList, number));
   }
}/* end_do_history */
