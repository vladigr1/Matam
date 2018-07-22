#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 5 

typedef char general;
typedef struct Element {
	general data;
	struct Element *next;
}Element;

typedef struct Queue {
	Element *front;
	Element *rear;
	int count;
}Queue;

void init_Queue(Queue *queue);
void enqueue(Queue *queue);
general dequeue(Queue *queue);
general front(Queue *queue);
int empty(Queue *queue);
int full(Queue *queue);
void Get_lost(char *str);

int main()
{
	int i;
	Queue *pt_queue, queue;		//*queue doest really generate stack object
	pt_queue = &queue;
	init_Queue(pt_queue);
	for (i = 0; i < MAXSTACK; ++i) {
		enqueue(pt_queue);
	}
	printf("first full %d\n",full(pt_queue));
	printf("full: %d front: %c dequeue: %c empty: %d \n", full(pt_queue), front(pt_queue), dequeue(pt_queue), empty(pt_queue));
	while (pt_queue->front != NULL) dequeue(pt_queue);
	printf("empty %d", empty(pt_queue));
	_getch();
	return 0;
}



void init_Queue(Queue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

void enqueue(Queue *queue)
{
	Element *New_Element;
	if (full(queue)) return;
	New_Element = (Element *)malloc(sizeof(Element));
	if (New_Element == NULL) Get_lost("Couldn't allocate no memory");
	puts("please enter general type input:");
	New_Element->data=getch();
	New_Element->next = NULL;
	if (empty(queue)) queue->front = queue->rear = New_Element;
	else {
		queue->rear->next = New_Element;
		queue->rear = New_Element;
	}
	queue->count++;
}

general dequeue(Queue *queue)
{
	Element *Getting_out = queue->front;
	general data = queue->front->data;
	queue->front = queue->front->next;
	queue->count--;
	free(Getting_out);
	return data;
}
general front(Queue *queue)
{
	return queue->front->data;
}
int empty(Queue *queue)
{
	return queue->count == 0;
}
int full(Queue *queue)
{
	return queue->count == MAXSTACK;
}
void Get_lost(char *str)
{
	puts(str);
	exit(1);
}