//1 separate main
//2 when entering data check full and message
//3 when deleting data check empty and message
//4 function that erase data will return 1 else 0 for success or faller


#ifndef _Lab8_H
#define _Lab8_H
#include <stdio.h>
#include <stdlib.h>
#define NUM 5



typedef struct Item {
	int num;
	struct Item* next;
}Item;

typedef struct Stack {
	Item* head;
	int size;         //a current number of items
}Stack, *PStack;


void Push(PStack s, int   new_elem);    //add a new member to list of the stack
int Pop(PStack s, int * del_value);       //delete member from the stack and  return the deleted value  using  int * del_value
void get_lost(char *s);

#endif