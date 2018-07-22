#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DATA_LEN 23


void Get_Lost(char *);
void Sort(FILE *in);


int main()
{
	
	FILE *file;
	file = fopen("Students.txt", "r+");
	if (file == NULL)Get_Lost("didnt found the file");
    Sort(file);

	fclose(file);
        return 0;
}


void Get_Lost(char *s)
{ 
  puts(s); 
  _getch();
  exit(1);
}

void Sort(FILE *in) {
	int i,j=0, size,sortted = 0;
	char Student1_Data[17] = { 0 }, Student2_Data[17] = { 0 };
	fseek(in, 0, SEEK_END);
	size = ftell(in);
	rewind(in);
	while (j <= size-32 && sortted != 1) {
		sortted = 1;
		rewind(in);
		for (i = 0; i < size - 16; i += 16) {
			fscanf(in, "%16s%16s", Student1_Data, Student2_Data);
			if (strncmp(Student1_Data + 10, Student2_Data + 10, 6) > 0) {
				char temp[17] = { 0 };
				sortted = 0;
				strcpy(temp, Student1_Data);
				strcpy(Student1_Data, Student2_Data);
				strcpy(Student2_Data, temp);
				fseek(in, -32, SEEK_CUR);
				fprintf(in, "%16s%16s", Student1_Data, Student2_Data);
			}
			fseek(in, -16, SEEK_CUR);
		}
		j += 16;
	}

}