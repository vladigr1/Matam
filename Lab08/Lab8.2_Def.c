#include "Lab8.2_H.h"


void InitStack(PStack s, int size)    //initialization of a new stack with capacity of size elements
{
	int *arr;
	if ((arr = (int *)malloc(sizeof(int)*size)) == NULL) get_lost("the malloc failed");
	s->Array = arr;
	s->size = size;
	s->count = 0;
	s->top = -1;
}

void Push(PStack s, int   new_elem)  //add a new member to array of the stack 
{
	if (s->count >= s->size) {
		printf("the Stack is full\n");
		return;
	} else {
		*(s->Array + s->count) = new_elem;		//later will test with the [] operator
		s->count++;
		s->top++;
	}
}

int Pop(PStack s, int * del_value) //delete member from the array of the stack and  return the deleted value  using  int * del_value
{
	if (s->count <= 0) {
		printf("the Stack is empty\n");
		return 0;
	} else {
		*del_value = *(s->Array + s->top);
		s->count--;
		s->top--;
		return 1;
	}
}

void get_lost(char *s)
{
	printf("%s", s);
	exit(1);
}