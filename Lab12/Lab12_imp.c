#include "Lab12_hdr.h"

typedef struct  ListNode
{
	void* data;
	struct  ListNode *next;
} ListNode;

BOOL insertEntry(PNode* head, PNode* tail, void *data, compare_func func)
{
	PNode temp, travel = *head;
	while (travel != NULL) {
		if (TRUE == func(data, travel->data)) return FALSE;
		travel = travel->next;
	}
	if (NULL == (temp = (PNode)malloc(sizeof(ListNode))) ) return FALSE;
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL) {
		*head = temp;
	} else {
		(*tail)->next = temp;
	}
	*tail = temp;
	return TRUE;
}

BOOL deleteNode(PNode* head, PNode* tail, void *todel, compare_func func1, free_func func2)
{
	PNode travel=*head, prev = NULL;
	while (travel != NULL) {
		if (TRUE == func1(todel, travel->data)) {
			func2(travel->data);
			if (prev == NULL) {
				*head = travel->next;						//travel is head
			} else {
				prev->next = travel->next;
			}
			if (*tail == travel) *tail = prev;			//in case we fully delete the list 
			return TRUE;								//prev never enter its NULL										
		}
		prev = travel;
		travel = travel->next;
	}
	return FALSE;
}

void printAll(PNode head,PNode tail, print_func func)
{
	if (head != NULL) {	
		printf("head: ");
		func(head->data);
		printf("tail: ");		//tail cant be NULL if head isnt NULL
		func(tail->data);
	}
	putch('\n');
	while (head != NULL) {
		func(head->data);
		head = head->next;
	}
}

void freeAll(PNode* head, free_func func)
{
	PNode temp;
	while (*head != NULL) {
		temp = *head;
		*head = temp->next;
		func(temp->data);
		free(temp);
	}
}