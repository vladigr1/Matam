#include<stdio.h>
#include<stdlib.h>

#define N 5

typedef struct Item
{
	int num;
	struct Item* next;
}*PItem;

void Error_Msg(char*);
void CreateListFromArray(PItem*,PItem*,int *);
void DeleteList(PItem *);
void ListDisplay(PItem );
int ListLength(PItem);

int main()
{
	int Arr[N]={3,4,1,0,8};

	PItem list=NULL,tail=NULL;

	CreateListFromArray(&list,&tail,Arr);
	printf("The length of the list is %d members\n",ListLength(list));
	printf("\nThe list is:\n");
	ListDisplay(list);
		
	DeleteList(&list);
        tail=NULL;
		_getch();
	return 0;
}

void Error_Msg(char*msg)
{
	printf("\n%s",msg);
	exit(1);
}


void CreateListFromArray(PItem* head,PItem* tail,int *Arr)
{
	int i;
	PItem temp;
	for(i=0;i<N;i++)
	{
		temp=(PItem)malloc(sizeof(struct Item));
		if(temp == NULL)
                {
                  DeleteList(head);
                  Error_Msg("Memmory!");
		}
		temp->num=Arr[i];
		temp->next=NULL;
		if(*head==NULL)
			*head=temp;
		else
			(*tail)->next=temp;
		*tail=temp;
	}
}


void DeleteList(PItem *head)
{
	PItem tmp=*head;
	while(*head)
        {
		tmp=*head;
		*head=(*head)->next;
		free(tmp);
	}
}


int ListLength(PItem head)
{
	if (head == NULL) return 0;
	return 1 + ListLength(head->next);
}


void ListDisplay(PItem head)
{
	if (head == NULL)return;
	printf("-( %d )--> ", head->num);
	ListDisplay(head->next);
}