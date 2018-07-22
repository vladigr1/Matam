/*--------------main_database.c-----------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT_header.h"

/*Define an element we can use with the database ADT */
typedef struct  BOOK
{
	char szCode[11]; /* It is assumed codes are at most 10 chars long */
	char* pszTitle;
} BOOK, *PBOOK;

/* Functions required by the database ADT */
PKEY  BookGetCode(PELEMENT pElem)
{
	PBOOK pBook = (PBOOK)pElem;
	return pBook->szCode;
}

void  BookDel(PELEMENT pElem)
{
	PBOOK pBook = (PBOOK)pElem;
	free(pBook->pszTitle);
	free(pBook);
}

void  BookPrint(PELEMENT pElem)
{
	PBOOK pBook = (PBOOK)pElem;
	printf("Title:%s Code:%s\n", pBook->pszTitle, pBook->szCode);
}

BOOL CodeCompare(PKEY pKey1, PKEY pKey2)
{
	return (BOOL)!(strcmp((char*)pKey1, (char*)pKey2));
}

PBOOK CreateBook(char* szTitle, char* szCode)
{
	PBOOK pBook;

	if (pBook = (PBOOK)malloc(sizeof(BOOK))) {
		strcpy(pBook->szCode, szCode);
		if (!(pBook->pszTitle = (char*)malloc(1 + strlen(szTitle)))) {
			free(pBook);
			return NULL;
		}
		strcpy(pBook->pszTitle, szTitle);
	}
	return pBook;
}


/* The person element */
typedef struct  PERSON
{
	char szName[100];
	int iID;
} PERSON, *PPERSON;

/* Functions required by the database ADT */
PKEY  PersonGetID(PELEMENT pElem)
{
	PPERSON pPerson = (PPERSON)pElem;
	return &(pPerson->iID);
}

void  PersonDel(PELEMENT pElem)
{
	free(pElem);
}


void PersonPrint(PELEMENT pElem)
{
	PPERSON pPerson = (PPERSON)pElem;
	printf("ID:%d Name:%s\n", pPerson->iID,
		   pPerson->szName);
}

BOOL IDCompare(PKEY pKey1, PKEY pKey2)
{
	return (BOOL)(*(int*)pKey1 == *(int*)pKey2);
}




PPERSON  CreatePerson(int iID, char* szName)
{
	PPERSON pPerson;

	if (pPerson = (PPERSON)malloc(sizeof(PERSON))) {
		strcpy(pPerson->szName, szName);
		pPerson->iID = iID;
	}
	return pPerson;
}


int main()
{
	PDATA_BASE BookStore;

	if (NULL != (BookStore = CreateDB(BookGetCode, BookDel, CodeCompare, BookPrint))) {

		AddDB(BookStore, CreateBook("Harry Potter 13", "ABC-24U-QA"));
		AddDB(BookStore, CreateBook("Introduction to C", "ABC-34W-YT"));
		AddDB(BookStore, CreateBook("Debt of Honor", "ABC-78S-KP"));
		BookPrint(GetDB(BookStore, "ABC-24U-QA"));

		PrintDB(BookStore);
		DeleteDB(BookStore);
	}

	/*
	PDATA_BASE pDB;
	PPERSON pPerson;
	int iID;

	if (NULL == (pDB = CreateDB(PersonGetID, PersonDel, IDCompare, PersonPrint)))
	{
	exit(-1);
	}
	AddDB(BookStore, CreateBook("Harry Potter 13", "ABC-24U-QA"));
	AddDB(BookStore, CreateBook("Introduction to C", "ABC-34W-YT"));
	AddDB(BookStore, CreateBook("Debt of Honor", "ABC-78S-KP"));
	BookPrint(GetDB(BookStore, "ABC-24U-QA"));

	PrintDB(BookStore);
	DeleteDB(BookStore);
	}

	/*
	PDATA_BASE pDB;
	PPERSON pPerson;
	int iID;

	if (NULL == (pDB = CreateDB(PersonGetID, PersonDel, IDCompare, PersonPrint)))
	{
	exit(-1);
	}
	if (pPerson = (PPERSON) malloc(sizeof(PERSON)))
	{
	strcpy(pPerson->szName, "Yossi");
	pPerson->iID = 1234;
	AddDB(pDB, pPerson);
	}
	if (pPerson = (PPERSON) malloc(sizeof(PERSON)))
	{
	strcpy(pPerson->szName, "Dina");
	pPerson->iID = 4321;
	AddDB(pDB, pPerson);
	}
	iID = 1234;
	if (pPerson = (PPERSON) GetDB(pDB, &iID))
	printf("Name:%s ID:%d\n", pPerson->szName, pPerson->iID);

	PrintDB(pDB);
	DeleteDB(pDB);
	*/
	_getch();
	return 0;
}

