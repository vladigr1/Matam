#ifndef _LAB11H
#define _LAB11H


#include <stdio.h>
#include <stdlib.h>

//function that must have
typedef struct node *NODE;
typedef void *KEY;
typedef void(*FREE_DATA)(void*);

void push(KEY key, NODE *stack);
void pop(NODE *stack, FREE_DATA);
int isempty(NODE stack);
KEY top(NODE stack);


#endif 

