#include "Lab8_H.h"


void Push(PStack s, int   new_elem)		    //add a new member to list of the stack
{
	if (s->size >= NUM) {
		printf("the stack is full\n");
	} else {
		Item *new_item;
		if ((new_item = (Item *)malloc(sizeof(Item))) == NULL)
			get_lost("Malloc for new_item failed");
		new_item->num = new_elem;
		new_item->next = s->head;
		s->head = new_item;
		s->size++;
	}
}
	
	
int Pop(PStack s, int * del_value)	      //delete member from the stack and  return the deleted value  using  int * del_value
{
	if (s->size <= 0) {
		printf("the stack is empty\n");
		return 0;
	} else {
		Item *temp = s->head;
		s->head = s->head->next;
		s->size--;
		*del_value = temp->num;
		free(temp);
		return 1;
	}
}

void get_lost(char *s)
{
	printf("%s",s);
	_getch();//the console want close on you
	exit(1);
}
