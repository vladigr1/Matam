#include "Lab8_3_H.h"

void Enqueue(PQue Q, int   new_elem)   //add a new member to list of the queue 
{
	if (Q->size >= NUM) {
		printf("the queue is full\n");
		return;
	} else {
		Item *new_item;
		if ((new_item = (Item *)malloc(sizeof(Item))) == NULL)get_lost("the malloc to the item failed");
		new_item->num = new_elem;
		new_item->next = NULL;
		if (Q->size == 0) { 
			Q->head = Q->tail = new_item; 
		} else {
			Q->tail->next = new_item;
			Q->tail = new_item;
		}
		Q->size++;
	}
}

int Dequeue(PQue Q, int * del_value)     //delete member from the queue and  return the deleted value  using int *del_value
{
	if (Q->size <= 0) {
		printf("the queue is empty\n");
		return 0;
	} else {
		Item *temp = Q->head;

		*del_value = temp->num;

		Q->head = temp->next;
		free(temp);

		Q->size--;
		if (Q->size == 0) Q->tail = NULL;
		return 1;
	}
}

void get_lost(char *s)
{
	printf("%s", s);
	exit(1);
}