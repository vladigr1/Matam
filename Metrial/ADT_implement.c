/*---------------database.c-----------------*/

#include <stdio.h>
#include <stdlib.h>
#include "ADT_header.h"

#define MAX_ELEMENTS    10

typedef struct  DATA_BASE
{
	PELEMENT     ArrElements[MAX_ELEMENTS];
	int           iNum;

	/* Function Pointers */
	GET_KEY       GetKeyFunc;
	DEL_ELEMENT   DelElementFunc;
	COMPARE_KEYS  CompareKeysFunc;
	PRINT_ELEMENT PrintElementFunc;
} DATA_BASE;
/*Private helper functions*/

int  InternalFindDB(PDATA_BASE pDB, PKEY pKey)
{
	int i;
	PKEY pElemKey;

	for (i = 0; i < MAX_ELEMENTS; i++) {
		if (pDB->ArrElements[i]) {
			pElemKey = pDB->GetKeyFunc(pDB ->ArrElements[i]);
			if (pDB->CompareKeysFunc(pKey, pElemKey))
				return i;
		}
	}
	return -1;
}
/* Interface implementation */

PDATA_BASE  CreateDB(
	GET_KEY GetKeyFunc,
	DEL_ELEMENT DelElementFunc,
	COMPARE_KEYS CompareKeysFunc,
	PRINT_ELEMENT PrintElementFunc)
{
	PDATA_BASE pDB;

	if (pDB = (PDATA_BASE)malloc(sizeof(DATA_BASE))) {
		int i;
		for (i = 0; i<MAX_ELEMENTS; i++)
			pDB->ArrElements[i] = NULL;
		pDB->iNum = 0;
		pDB->CompareKeysFunc = CompareKeysFunc;
		pDB->DelElementFunc = DelElementFunc;
		pDB->GetKeyFunc = GetKeyFunc;
		pDB->PrintElementFunc = PrintElementFunc;
	}
	return pDB;
}
BOOL  AddDB(PDATA_BASE pDB, PELEMENT pElem)
{
	int i;

	if (pDB->iNum == MAX_ELEMENTS || NULL == pElem) {
		return FALSE;
	}

	for (i = 0; i < MAX_ELEMENTS; i++) {
		if (NULL == pDB->ArrElements[i])
			break;
	}
	pDB->ArrElements[i] = pElem;
	pDB->iNum++;
	return TRUE;
}
PELEMENT  GetDB(PDATA_BASE pDB, PKEY pKey)
{
	int i;
	i = InternalFindDB(pDB, pKey);
	return (i >= 0) ? pDB->ArrElements[i] : NULL;
}

BOOL  RemoveDB(PDATA_BASE pDB, PKEY pKey)
{
	int i;
	i = InternalFindDB(pDB, pKey);
	if (i >= 0) {
		pDB->DelElementFunc(pDB->ArrElements[i]);
		pDB->ArrElements[i] = NULL;
		pDB->iNum--;
		return TRUE;
	}
	return FALSE;
}
void  PrintDB(PDATA_BASE pDB)
{
	int i;

	printf("The Database contains the following:\n");
	for (i = 0; i < MAX_ELEMENTS; i++)
		if (pDB->ArrElements[i])
			pDB->PrintElementFunc(pDB->ArrElements[i]);
}

void  DeleteDB(PDATA_BASE pDB)
{
	int i;
	for (i = 0; i < MAX_ELEMENTS; i++)
		if (pDB->ArrElements[i])
			pDB->DelElementFunc(pDB->ArrElements[i]);
	free(pDB);
}

