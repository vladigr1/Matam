#include<stdio.h>
#include<stdlib.h>


typedef struct Item
{
	int num;
	struct Item* next;
}Item;

typedef struct List
{
	Item *head;
	Item *tail;
	int count;
}List;


void Error_Msg(char*);
void AddAsFirst(Item* ,List* );
void AddAsLast(Item* ,List* );
void MoveToAnotherList(List* ,List* ,List* );
void CreateList(List* ,FILE *);
void PrintItem(Item* );
void PrintList(List* ,char*);
void DeleteList(List*);


int main()
{
    List L,Posit,Negat;
    FILE *in=fopen("ThreeLists.txt","rt");
    if(in == NULL)
    Error_Msg("input file is wrong");
    L.head=NULL;
    L.tail=NULL;
    L.count=0;
	
    Posit.head=NULL;
    Posit.tail=NULL;
    Posit.count=0;

    Negat.head=NULL;
    Negat.tail=NULL;
    Negat.count=0;

    CreateList(&L,in);
    PrintList(&L,"\nMy List:\n");
    MoveToAnotherList(&L,&Posit,&Negat);
    PrintList(&Posit,"\n\nThe Positive List:\n");
    PrintList(&Negat,"\n\nThe Negative List:\n\n");

    fclose(in);
    DeleteList(&Posit);
    DeleteList(&Negat);
	_getch();
    return 0;
}



void Error_Msg(char* msg)
{
	printf("\n%s",msg);
	exit(1);
}

void CreateList(List* L, FILE *f)
{
	int value;
	Item *temp;
	while(fscanf(f,"%d",&value)==1)
        {
		temp=(Item*)malloc(sizeof(struct Item));
		if(temp == NULL)
                {
                   DeleteList(L);
                   Error_Msg("Memmory!");
		}

		temp->num=value;
		temp->next=NULL;
		if(L->head==NULL)
			L->head=temp;
		else
			L->tail->next=temp;
		L->tail=temp;
		L->count++;
	}
}


void PrintItem(Item* node)
{
	printf("%d--> ",node->num);
}


void PrintList(List* L,char* title)
{
	Item* temp=L->head;
	printf("%s",title);
	while(temp)
        {
		PrintItem(temp);
		temp=temp->next;
	}
	printf("\nThere are %d items in the list",L->count);
}


void AddAsFirst(Item *to_add, List *list)
{
	if(list->head != NULL)to_add->next = list->head;
	list->head = to_add;
	list->count++;
}


void AddAsLast(Item *to_add, List *list)				//we must get to_add with NULL at the end
{
	if (list->head == NULL) list->head = to_add;		//I don't have to add null because when generate it created by default
	else list->tail->next = to_add;
	list->tail = to_add;
	list->count++;
	//to_add->next = NULL								//in case we would like to make sure its NULL
}


void DeleteList(List *list)
{
	Item *temp;
	while (list->head != NULL) {
		temp = list->head;
		list->head = list->head->next;
		list->count--;
		free(temp);
	}
}

void MoveToAnotherList(List *origin, List *posi, List *nega)
{
	while (origin->head != NULL) {	//don't forget to move to the next, at the count is 0 and tail is NULL
		Item *cur = origin->head;
		origin->head = origin->head->next;
		cur->next = NULL;
		if (cur->num >= 0) AddAsLast(cur, posi);
		else AddAsFirst(cur, nega);
	}
	origin->tail = NULL;
	origin->count = 0;
}