/********************************************************************************************************
 Class: OsTaskManager.c
 Autor: Andrej Tica
 Description:
	This module organizes backround and timer tasks. Backround tasks are
	executed after each other, timer tasks are executed once or repeatedly after a specified time interwall.
	No priority is supportedm each task must finish on its own
********************************************************************************************************/

#include "OsTaskManager.h"
#include "OsBgTask.h"
#include <stdlib.h>

typedef struct TOsBgTaskListHead {
	TOsBgTask firstHead;
	TOsBgTask current;
} *TOsBgTaskListHead;

typedef struct TOsTaskManagerStruct {
	TOsBgTaskListHead bgTaskListHead;
} *TOsTaskManager;

TOsTaskManager OsTaskManager = 0;

/***********************************************************************************
Function: OsTaskmanagerInit
Description:
   Initialises the OsTaskManager.
Return:
   ETRUE if the memory can be allocated.
***********************************************************************************/
TBool OsTaskManagerInit(void) {
	OsTaskManager = calloc(sizeof(struct TOsTaskManagerStruct), 1);
	if (!OsTaskManager)
		return EFALSE;

	OsTaskManager->bgTaskListHead = calloc(sizeof(struct TOsTaskManagerStruct), 1);
	if (!OsTaskManager->bgTaskListHead)
	{
#ifndef OS_MEMORY_OPTIMIZED
		OsTaskManagerDone();
#endif
		return EFALSE;
	}
	return ETRUE;
}

/***********************************************************************************
Function: OsTaskManagerAddBgTask
Description:
   Adds background tasks to the OsTaskmanager. These tasks are executed during the
   spare time and every task must finish by it own and is not interrupted.
Restrictions:
	The same background function with the same user data should not be added.
Parameters:
	aBgFunction - A function pointer to the background function.
	aUserData   - The user data for the function.
Return:
	ETRUE if the memory can be allocated for internal usage otherwise EFALSE.
***********************************************************************************/
TBool OsTaskManagerAddBgTask(TOsBgFunction bgFunction, void* userData) {
	TOsBgTask next = OsTaskManager->bgTaskListHead->first;
	TOsBgTask tmp = next;
	next = OsBgTaskCreate(bgFunction, userData);
	next->next = tmp;
	if (!OsTaskManager->bgTaskListHead->first) {
		OsTaskManager->bgTaskListHead->first = next;
		OsTaskManager->bgTaskListHead->current = next;
	}
	else {
		OsTaskManager->bgTaskListHead->first = next;
	}
}

/***********************************************************************************
Function: OsTaskManagerRemoveBgTask
Description:
   Removes background tasks from the OsTaskmanager.
Parameters:
	aBgFunction - A function pointer to the background function.
	aUserData   - The user data for the function.
Return:
	ETRUE if the memory can be allocated for internal usage otherwise EFALSE.
***********************************************************************************/
TBool OsTaskManagerRemoveBgTask(TOsBgFunction aBgFunction, void* aUserData) {
	TOsBgTask current = OsTaskManager->bgTaskListHead->first;
	TOsBgTask prev = current;
	while (current)
	{
		if (current->bgFunction == aBgFunction && current->userData == aUserData)
		{
			if (OsTaskManager->bgTaskListHead->current == current)
				OsTaskManager->bgTaskListHead->current = prev;

			prev->next = current->next;
			OsBgTaskDestroy(current);
			return;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

/***********************************************************************************
Function: OsTaskmanagerExecuteBgTasks
Description:
   Executes background tasks.
***********************************************************************************/
void OsTaskManagerExecuteBgTasks(void) {
	OsTaskManager->bgTaskListHead->current = OsTaskManager->bgTaskListHead->current->next;
	if (!OsTaskManager->bgTaskListHead->current)
		OsTaskManager->bgTaskListHead->current = OsTaskManager->bgTaskListHead->first;
	if (OsTaskManager->bgTaskListHead->current) {
		OsTaskManager->bgTaskListHead->current->bgFunction(OsTaskManager->bgTaskListHead->current->userData);
	}
}

#ifndef OS_MEMORY_OPTIMIZED
/***********************************************************************************
Function: OsTaskmanagerInit
Description:
   Initialises the OsTaskManager.
Return:
   ETRUE if the memory can be allocated.
***********************************************************************************/
TBool OsTaskManagerDone(void) {
	if (OsTaskManager->bgTaskListHead)
		free(OsTaskManager->bgTaskListHead);
	if (OsTaskManager)
		free(OsTaskManager);
}
#endif