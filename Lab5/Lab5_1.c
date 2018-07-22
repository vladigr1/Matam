#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void Error_Msg(char* str);
void Student_File(FILE *in, FILE *out, char *Course_Name);


int main()
{
	

	FILE *in,*out;
	

	if(!(in=fopen("Students.txt","r")))Error_Msg("The input file is wrong");
	if(!(out=fopen("StudentsNew.txt","w")))Error_Msg("The output file is wrong");
	Student_File(in, out, "Mech");
	

	fclose(in);
    fclose(out);
	return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s",str);
	_getch();
        exit(1);
}

void Student_File(FILE *in, FILE *out, char *Course_Name) {
	int Amnt_Grades = 2,i;
	char S_grade[4] = {0};
	fprintf(out, "Course name: %s\n", Course_Name);
	while (feof(in)==0) {
		char Student_Data[17] = {0};
		fscanf(in, "%16s", Student_Data);
		if (strncmp(Student_Data + 6, Course_Name, 3) == 0) {
			int sum = 0;
			for (i = 0; i < Amnt_Grades; ++i) {
				strncpy( S_grade, Student_Data + 10 + 3 * i, 3);
				sum += atoi(S_grade);
			}
			fprintf(out, "%-7s, %.2f\n", Student_Data, ((double)sum / Amnt_Grades));
		}
	}
}

