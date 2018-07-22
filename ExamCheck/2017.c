#include<stdio.h>
#include<stdlib.h>

#define N1 5
#define N2 3

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

int length(Node *head)
{
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

Node* f1(Node *A, Node *B)
{
	int m, n, d, i;
	m = length(A);
	n = length(B);
	d = n - m;
	if (m > n) {
		Node* temp = A;
		A = B;
		B = temp;
		d = m - n;
	}
	for (i = 0; i<d; i++)
		B = B->next;
	while (A != NULL && B != NULL) {
		if (A == B)
			return A;
		A = A->next;
		B = B->next;
	}
	return NULL;
}

Node* create(int data, Node* next)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node != NULL) {
		new_node->data = data;
		new_node->next = next;
	}
	return new_node;
}


Node* prepend(Node* head, int data)
{
	Node* new_node;
	new_node = create(data, head);
	head = new_node;
	return head;
}


Node* f3(Node* pHead)
{
	Node* r = NULL;
	Node* pNode = pHead;
	Node* pPrev = NULL;
	while (pNode != NULL) {
		Node* pNext = pNode->next;

		if (pNext == NULL)
			r = pNode;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return r;
}

void printList(Node* head)
{
	printf("\nLinked list");
	while (head) {
		printf(" -> %d", head->data);
		head = head->next;
	}
}

int main()
{
	int data, n, i;
	Node *head1 = NULL, *head2 = NULL, *t1, *t2, *C;
	printf("Enter List1:");
	for (i = 0; i < N1; i++) {
		scanf("%d", &data);
		head1 = prepend(head1, data);
	}
	printf("\nEnter List2:");
	for (i = 0; i < N2; i++) {
		scanf("%d", &data);
		head2 = prepend(head2, data);
	}

	t1 = head1;
	t2 = head2;


	printList(head1);
	printf("\n");
	printList(head2);
	printf("\n");
	for (i = 0; i < 2; i++)
		t1 = t1->next;

	while (t2->next != NULL)
		t2 = t2->next;
	t2->next = t1;

	printList(head2);
	printf("\n");

	C = f1(head1, head2);
	printf(" %d", C->data);          //(1)

	printList(f3(C));                      //(2)
		return 0;
}
