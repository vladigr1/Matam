#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MARKAMNT 3

typedef struct node
{
	char code[11];
	char *name;
	char Dep[4];
	int marks[3];
	float avg;
	struct node* next;
}std;

void Error_Msg(char* str);
std* FromFileToList(std* head,FILE *in);
std* Delete_Stud(std* toDel,std* head);
void DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);

int main()
{
	int i;
	FILE *f;
	std *Head=NULL, *temp;
	if((f=fopen("List1.txt","rt")) == NULL)
           Error_Msg("input error");
	Head=FromFileToList(Head,f);

	printf("\nThe list is:");
	PrintList(Head);
	
	temp = FindMax(Head);
        printf("\n\nthe student with max average:\n");
	printf("%s %s %s ",temp->code,temp->name,temp->Dep);
        for(i=0;i<3;i++)
          printf(" %d ",temp->marks[i]);

	printf("\n\nThe list after change:");
	Head=Delete_Stud(FindMax(Head),Head);
	PrintList(Head);
	DeleteList(Head);
        Head = NULL;
		_getch();
        return 0;
}

void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}

std* FromFileToList(std* head, FILE *in)
{
	int i, end;
	double sum;
	fseek(in, 0, SEEK_END);
	end = ftell(in);
	fseek(in, 0, SEEK_SET);
	while (ftell(in)< end) {
		sum = 0;
		char buffer[256] = { 0 }, *name;
		std *student = (std *)malloc(sizeof(std));
		if (student == NULL)Error_Msg("No memory for creating student");
		fscanf(in, "%s %s %s", student->code, buffer, student->Dep);
		name = (char *)malloc((sizeof(char))*(strlen(buffer)+1));
		if (name == NULL)Error_Msg("No memory for creating student name");
		strcpy(name, buffer);
		student->code[10] = 0; student->Dep[3] = 0,name[strlen(buffer)]=0;
		student->name = name;
		for (i = 0; i < MARKAMNT; ++i) {
			fscanf(in, "%d", (student->marks) + i);	//later check with []
			sum += (student->marks)[i];
		}
		student->avg = sum / MARKAMNT;
										//setting the list
		student->next = head;
		head = student;
	}
	return head;
}

void PrintList(std* head)
{
	std *temp=head;
	while (temp != NULL) {
		printf("\n%s %s %s %d %d %d", temp->code, temp->name, temp->Dep , temp->marks[0], temp->marks[1], temp->marks[2]);
		temp = temp->next;
	}
}

std* Delete_Stud(std* toDel,std* head)
{
  if(head == NULL)
    return NULL;

  if(toDel==head)
  {
	  head = head->next;
	  free(toDel->name);
	  free(toDel);
  }
  else
  {
	  std *temp = head;
	  while (temp->next != toDel)temp = temp->next;
	  temp->next = toDel->next;
	  free(toDel->name);
	  free(toDel);
  }
  return head;
}
void DeleteList(std* head)
{
	while (head != NULL) {
		std *temp = head;
		head = head->next;
		free(temp->name);
		free(temp);
	}
}

std* FindMax(std* head)
{
	std *cur_max, *temp;
		cur_max = temp= head;
	while (temp != NULL) {
		if (cur_max->avg < temp->avg)cur_max = temp;
		temp = temp->next;
	}
	return cur_max;
}