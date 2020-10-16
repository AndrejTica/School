/******************************
This module handles backround tasks which are executed after each other.
No priority is supported, each task must finish by its own
*/



#ifndef OSBGTASK_H
#define OSBGTASK_H

typedef struct TOsBgTaskNodeStruct* TOsBgTaskNode;

typedef void (*TOsBgFunction)(void* aUserData); //function pointer

typedef struct TOsBgTaskNodeStruct {
	TOsBgTaskNode Next;
	TOsBgFunction BgFunction;
	void* UserData;

};

#endif