#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};



void fun1(struct node* head)
{
	if (head == NULL)
		return;

	fun1(head->next);
	printf("%d ", head->data);
}



void fun2(struct node* start)
{
	if (start == NULL)
		return;
	printf("%d ", start->data);

	if (start->next != NULL)
		fun2(start->next->next);
	printf("%d ", start->data);
}



void func3(struct node** head_ref)
{
	struct node* first;
	struct node* rest;

	if ((*head_ref) == NULL)
		return;

	first = (*head_ref);
	rest = first->next;

	if (rest == NULL)
		return;

	func3(&rest);
	first->next->next = first;

	first->next = NULL;

	(*head_ref) = rest;
}



void push(struct node** head_ref, int new_data)
{
	struct node* new_node;

	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


int main()
{

	struct node* head = NULL;

	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("\nfunc1:   ");
	fun1(head);

	printf("\nfunc2:   ");

	fun2(head);

	push(&head, 7);

	func3(&head);
	printf("\nfunc3:   ");
	fun2(head);

	return 0;
}
