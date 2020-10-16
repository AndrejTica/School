/****************************************************************************

	This module handles the object of a backround task.
	No priority is supported, each task must finish on its own

*****************************************************************************/
#include "OsBgTask.h"
#include "HTLStddef.h"

typedef struct TOsBgTaskNodeStruct {
	TOsBgTaskNode Next;
	TOsBgFunction BgFunction;
	void* UserData;

};

TBool OsBgTaskCreate(TOsBgFunction BgFunction, void * UserData);
TBool OsBgTaskDestroy(TOsBgTaskNodeStruct aBgTask);