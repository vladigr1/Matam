#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud
{
	char *name;
	int marks[ 4 ];
	float avg;
}student;


student* Create_Class(int);
void Avg_Mark(student*);
void Print_One(student*);


int main()
{
	int size, i;
	student *arr;
	printf("Enter the number of students:");
	scanf("%d", &size);
	arr = Create_Class(size);
	for(i = 0; i < size; ++i) if(arr[ i ].avg > 85){
		Print_One(arr + i);
		putch('\n');
	}

	for(i = 0; i < size; ++i) free(arr[ i ].name);
	free(arr);
	_getch();
	return 0;


}

student* Create_Class(int size)
{
	student *Class = (student *)malloc(sizeof(student)*size);
	int i, j, amountsbj = 4;
	char buffer[ 51 ];
	if(Class == NULL) exit(1);
	for(i = 0; i < size; ++i){
		char *name;
		printf("Enter your name:");
		rewind(stdin);
		gets(buffer);
		name = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
		if(name == NULL) exit(1);
		strcpy(name, buffer);
		Class[ i ].name = name;
		printf("Enter your marks:");
		for(j = 0; j < amountsbj; ++j) scanf("%d", &Class[ i ].marks[ j ]);
		Avg_Mark(Class + i);
	}
	return Class;
}


void Avg_Mark(student* s)
{
	int i, sum = 0, amount = 4;
	for(i = 0; i < amount; ++i) sum += s->marks[ i ];
	s->avg = (double)sum / amount;
}


void Print_One(student* s)
{
	printf("The average of %s is %.1f", s->name, s->avg);
}

