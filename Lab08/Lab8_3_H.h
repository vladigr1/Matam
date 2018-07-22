//1 separate main
//2 when entering data check full and message
//3 when deleting data check empty and message
//4 function that erase data will return 1 else 0 for success or faller


#ifndef _Lab8_3_H
#define _Lab8_3_h
#include <stdio.h>
#include <stdlib.h>
#define NUM 5		//max size of the queue

typedef struct Item {
	int num;
	struct Item* next;
}Item;

typedef struct Que {
	Item* head, *tail;
	int size;      //a current number of items
}Queue, *PQue;


void Enqueue(PQue Q, int   new_elem);   //add a new member to list of the queue 
int Dequeue(PQue Q, int * del_value);     //delete member from the queue and  return the deleted value  using int *del_value
void get_lost(char *s);


#endif
