#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int i;
	struct node *next;
}node;

typedef struct list {

	node *head;
	node *tail;		//for adding both side will update tail when needed only 
	int size;

}list;


node* GenerateNode();
void GenerateData(node *NodeData, int num);
list *GenerateList();
//while we adding we assume that the list generate correctly which mean the first node set next to NULL
void Adding_NodeToList_Head(list *ptlist, node *ptnode);
void Adding_NodeToList_Tail(list *ptlist, node *ptnode);
void Deleting_TheHead_Head(list *ptlist);
void Deleting_NodeToList(list *ptlist, node *PtPrevNodeDelete);
void Insert_Node_Sorted(list *ptlist, node *ptnode);
void printList(list *ptlist);
void FreeList(list *ptlist);

int main() {
	int arr[] = { 1,3,0,4,9,5,7,2,6,8 },i;
	list *mainlist = GenerateList();
	list *sortlist = GenerateList();
	for (i = 0; i < 10; ++i) {
		node *newnode_m, *newnode_s;
		 newnode_m = GenerateNode();		//(*)its not possible to have the same node it 2 list because we change the next
		 newnode_s = GenerateNode();
		GenerateData(newnode_m, arr[i]);
		GenerateData(newnode_s, arr[i]);
		Adding_NodeToList_Head(mainlist, newnode_m);
		Insert_Node_Sorted(sortlist, newnode_s);
	}
	printList(mainlist);
	putch('\n');
	printList(sortlist);
	FreeList(mainlist); //because it is the same node but in diffrent list
	free(mainlist);
	free(sortlist);
	_getch();
	return 0;
}

node* GenerateNode() {
	node *new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL) exit(1);	//can set get_Lost
	new_node->next = NULL;
	return new_node;
}

void GenerateData(node *NodeData, int num) {
	NodeData->i = num;
}

list *GenerateList() {
	list *PtList = (list *)malloc(sizeof(list));
	if (PtList == NULL) exit(1);	//can set get_Lost
	PtList->head = NULL;
	PtList->tail = PtList->head;
	PtList->size = 0;
	return PtList;
}

void Adding_NodeToList_Head(list *ptlist, node *ptnode)
{
	ptnode->next = ptlist->head;
	ptlist->head = ptnode;
	++(ptlist->size);
}

void Adding_NodeToList_Tail(list *ptlist, node *ptnode) 
{
	if (ptlist->head == NULL) ptlist->head = ptnode;
	else ptlist->tail->next = ptnode;
	ptlist->tail = ptnode;							//if we didnt init the node we must set his next to null
	++(ptlist->size);
}

void Deleting_TheHead_Head(list *ptlist)
{
	node *temp = ptlist->head;
	ptlist->head = ptlist->head->next;
	free(temp);
}

void Deleting_NodeToList(list *ptlist, node *PtPrevNodeDelete)
{
	node *temp = PtPrevNodeDelete->next;
	PtPrevNodeDelete->next = temp->next;
	//if (ptlist->tail == temp)ptlist->tail = PtPrevNodeDelete;		//only if we insert from the end
	free(temp);
}

void Insert_Node_Sorted(list *ptlist, node *ptnode)
{
	node *PtPrev, *PtCur;
	PtPrev = PtCur = ptlist->head;
	++(ptlist->size);
	while (PtCur != NULL) {
		if (PtCur->i >= ptnode->i) break;
		PtPrev = PtCur;
		PtCur = PtCur->next;
	}
	ptnode->next = PtCur;
	if (PtCur == ptlist->head) ptlist->head = ptnode;		//if we didnt enter to the while
	else PtPrev->next = ptnode;
}

void printList(list *ptlist)
{
	printf("the size of the listis %d\n", ptlist->size);
	while (ptlist->head != NULL) {
		printf("%d ", ptlist->head->i);
		ptlist->head = ptlist->head->next;
	}
}

void FreeList(list *ptlist)
{
	node *temp = ptlist->head;
	while (ptlist->head != NULL) {
		temp = ptlist->head->next;
		free(ptlist->head);
		ptlist->head = temp;
	}
}