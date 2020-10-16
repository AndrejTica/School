/********************************************************************************************************
 Class: OsTaskManager.h
 Autor: Andrej Tica
 Description:
	This module organizes backround and timer tasks. Backround tasks are
	executed after each other, timer tasks are executed once or repeatedly after a specified time interwall.
	No priority is supportedm each task must finish on its own
********************************************************************************************************/

#ifndef OSTASKMANAGER_H
#define OSTASKMANAGER_H

#include "HtlStddef.h"
#include "OsBgTask.h"


typedef void (*TOsFunction)(void* aUserData); //function pointer

/*******************************************************************************************************
 Function: OsTaskManagerInit
 Description:
	Initiliases the OsTaskManager.
 Return:
	ETRUE if memory can be allocated
********************************************************************************************************/
TBool OsTaskManagerInit(void);

/*******************************************************************************************************
 Function: OsTaskManagerAddingTask
 Description:
	Add a backround task to the OsTaskManager. These task are executed during the spare time and every
	task must finish by its own and is not interrupted

 Restrictions:
	The same backround function with the same user data should not be added.

 Parameters:
	aBgFunction - A function pointer to the backround function
	aUserData	- The user data for the function

 Return:
	ETRUE if the memory can be allocated for internal usage otherwise EFALSE

********************************************************************************************************/
TBool OsTaskManagerAddingTask(TOsBgFunction aBgFunction, void* aUserData);


TBool OsTaskManagerRemoveBgTask(TOsBgFunction aBgFunction, void* aUserData);

void OsTaskManagerExecuteBgTasks(void);

void OsTaskManagerDone(void);

#endif