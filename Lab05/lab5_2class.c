#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DATA_LEN 23

typedef struct student{
	char course[4], id[5], name[17];
} student;

void Get_Lost(char *);
void Sort(FILE *);
int BubbleFlag(int arr[], int size);
void BubbleFlagSort(int arr[], int size);

int main()
{
	
	FILE *file;
	file = fopen("stud.txt", "r+");
	if (file == NULL)Get_Lost("didnt found the file");
    Sort(file);
	fclose(file);
        return 0;
}


void Get_Lost(char *s)
{ 
  puts(s); 
  exit(1);
}

void Sort(FILE *file)
{
	int swapped = 1, Student_Amount,i;
	student stud1, stud2;
	fseek(file, 0, 2);
	Student_Amount =ftell(file)/23;
	fseek(file, 0, 0);
	while (swapped == 1)
	{
		swapped = 0;
		for (i = 0; i < Student_Amount-1; ++i) {

			fgets(stud1.course, 4, file); fgets(stud1.id, 5, file); fgets(stud1.name, 17, file);
			fgets(stud2.course, 4, file); fgets(stud2.id, 5, file); fgets(stud2.name, 17, file);
			if (strcmp(stud1.id, stud2.id) > 0)
			{
				swapped = 1;
				fseek(file, -46, 1);
				fputs(stud2.course, file); fputs(stud2.id, file); fputs(stud2.name, file);
				fputs(stud1.course, file); fputs(stud1.id, file); fputs(stud1.name, file);
			}
				fseek(file, -23, SEEK_CUR);
		}
		rewind(file);
	}
}