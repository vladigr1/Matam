#include "Lab11_1_H.h"

typedef struct node
{
	KEY data;                        /* Store the keystroke by the user */
	struct node *next;                /* Pointer to the next node */
} STACKNODE;


KEY top(NODE stack)
{
	return stack->data;
}

void push(KEY key, NODE *stack)
{
	NODE newnode;
	newnode = (NODE *)malloc(sizeof(STACKNODE));
	newnode->data = key;
	newnode->next = (*stack);
	(*stack) = newnode;
}

void pop(NODE *stack,FREE_DATA FREE)
{
	NODE oldnode;
	oldnode = *stack;
	(*stack) = (*stack)->next;
	FREE(oldnode->data);
	free(oldnode);
}

int isempty(NODE stack)
{
	return (stack == NULL);
}
