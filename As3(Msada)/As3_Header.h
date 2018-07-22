#ifndef _Header
#define _Header


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


//constant number
#define NUM_TABLE 15
#define BUFFER_SIZE 257


//structures
typedef enum { N, Y } Boolean;

typedef struct {
	char *ProductName;	//must check if the name is free
	int Price;			//maybe it will be changed to unsigned
	int Quantity;		//must keep it positive
	Boolean Premium;
}Data_Manot;
typedef struct Manot {
	Data_Manot Data;
	struct Manot *next;
}Manot;



//function declaration
Manot* ScoutInList(Manot *l, char *productName); // looks for node in list with a given name
void freeList(Manot **head);

Boolean CreateProducts(FILE *in, Manot **head);					//*return is for only full list fail*
void AddItems(Manot *head, char *ProductName, int Quantity);	//*need to check the quantity and 
																//my change
Boolean OrderItem(Manot** tables, Manot** kitchen, int TableNumber, char *ProductName, int Quantity);//order an Item for a table
void RemoveItem(Manot **tables, int TableNumber, char *ProductName, int Quantity);//removes an item from the List in a table
void RemoveTable(Manot **tables, int TableNumber);//clears the table's list and gives a pay check

#endif