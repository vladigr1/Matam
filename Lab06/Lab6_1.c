#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct Item {
	int code;
	char name[11];
	struct Item *next;
}Item;

void Get_lost(char *text);

int main()
{
	int i;
	Item *Head=NULL, *temp;
	for(i=1;i<=N;i++){		
		temp = (Item *)malloc(sizeof(Item));
		if (temp == NULL) Get_lost("\nNo memeory for malloc");
		temp->next = Head;
		printf("Enter a new code and name: ");
		scanf("%d %s", &temp->code, temp->name);
		putch('\n');
		Head = temp;
	}
	
	temp = Head;
	printf("\n\nThe List is:  ");
	while(temp != NULL){
		printf("%d,%s --> ",temp->code,temp->name);
		temp = temp->next;
	}

	while(temp != NULL){
		temp = Head;
		Head = Head->next;
		free(Head);
	}
	_getch();
        return 0;
}

void Get_lost(char *text)
{
	printf(text);
	exit(1);
}


