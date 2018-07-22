#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 5 

typedef char general;
typedef struct Element {
	general data;
	struct Element *next;
}Element;

typedef struct Stack {
	Element *top;
	int count;
}Stack;

void init_Stack(Stack *stack);
void push(Stack *stack);
general pop(Stack *stack);
general top(Stack *stack);
int empty(Stack *stack);
int full(Stack *stack);
void Get_lost(char *str);

int main()
{
	int i;
	Stack *pt_stack,stack;		//*ptstack doest really generate stack object
	pt_stack =&stack;
	init_Stack(pt_stack);
	for (i = 0; i < MAXSTACK; ++i) {
		push(pt_stack);
	}
	printf("%d full %c pop %c top %d empty\n", full(pt_stack), pop(pt_stack),top(pt_stack), empty(pt_stack));
	while (pt_stack->top != NULL) pop(pt_stack);
	printf("empty %d", empty(pt_stack));
	_getch();
	return 0;
}



void init_Stack(Stack *stack)
{
	stack->top = NULL;
	stack->count = 0;
}

void push(Stack *stack)
{
	Element *New_Element;
	if (full(stack)) return;
	New_Element = (Element *)malloc(sizeof(Element));
	if (New_Element == NULL) Get_lost("Couldn't allocate no memory");
	New_Element->data = '1';
	New_Element->next = stack->top;
	stack->top = New_Element;
	stack->count++;
}

general pop(Stack *stack)
{
	Element *Getting_pop = stack->top;
	general data = stack->top->data;
	stack->top = stack->top->next;
	stack->count--;
	free(Getting_pop);
	return data;
}
general top(Stack *stack)
{
	return stack->top->data;
}
int empty(Stack *stack)
{
	return stack->count== 0;
}
int full(Stack *stack)
{
	return stack->count == MAXSTACK;
}
void Get_lost(char *str)
{
	puts(str);
	exit(1);
}