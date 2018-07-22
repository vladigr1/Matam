#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char CourseName[4];
	int id;
	char StudentName[17];
}student;

void Get_Lost(char *);
void Find(FILE *in, char *course);

int main()
{
	char course[4];
	FILE *file;
	file = fopen("Stud.txt", "rt"); 
	if(file == NULL) 
          Get_Lost("Cannot open file");
	printf("\nEnter the name of course,up to 3 letters");
	scanf("%s",course);
	Find(file,course);
	fclose(file);
        return 0;
}


void Get_Lost(char *s)
{ 
   puts(s);  
   exit(1);
}

void Find(FILE *in, char *course) {
	int i= 0,j,k;
	FILE *out;
	char idhelper[4] = { 0 }, CourseData[23] = { 0 }, name[8] = { 0 };
	student *sclass = (student *)malloc(sizeof(student));
	if (sclass == NULL) Get_Lost("no memory for s_class");
	while (!feof(in)) {
		for (k = 0; k < 23; ++k) fscanf(in, "%c", CourseData + k);
		if (strncmp(course, CourseData, 3) == 0) {
			sclass = (student *)realloc(sclass, (++i) * sizeof(student));
			if (sclass == NULL) Get_Lost("no memory for s_class");
			strncpy((sclass + i - 1)->CourseName, CourseData, 3);
			(sclass + i - 1)->CourseName[3] = 0;
			//for (j = 0; j < 3; ++j) (sclass + i - 1)->CourseName[j] = CourseData[j];
			//(sclass + i - 1)->CourseName[3] = 0;
			strncpy(idhelper, CourseData+3, 4);				//idhelper dont need becouse from initiation its full with zeroes
			(sclass + i - 1)->id = atoi(idhelper);
			strncpy((sclass + i - 1)->StudentName, CourseData + 7, 16);
			(sclass + i - 1)->StudentName[16] = 0;
		}
	}
	strcpy(name, course);
	strcpy(name + 3, ".txt");
	out = fopen(name, "wt");
	for (j = 0; j < i; ++j) {
		fprintf(out, "%d ", (sclass + j)->id);
		fprintf(out, ",%16s ", (sclass + j)->StudentName);
		fprintf(out, ",%s\n", (sclass + j)->CourseName);
	}
	fclose(out);
	free(sclass);
}