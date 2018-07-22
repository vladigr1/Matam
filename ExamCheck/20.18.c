#include <stdio.h>
#include <stdlib.h>

void  Func1(FILE* in1, FILE* in2)
{
	char data1[10], data2[10];
	FILE* F = fopen("mytext.txt", "w");
	while (fscanf(in1, "%s", data1) == 1 && fgets(data2, 3, in2)) {
		strcat(data1, data2);
		fprintf(F, "%s", data1);
	}
	fclose(F);
}


void Func2(FILE* in1, FILE* in2, FILE* in3)
{
	char data1[3] = { 0 }, data2[4] = { 0 };
	int x, i = 0;
	fseek(in1, 0, 0);
	fseek(in2, 0, 0);
	fseek(in3, 0, 2);
	fputc('\n', in3);
	fgets(data1, 3, in1);
	x = fgetc(in2);
	while (x != EOF) {
		while (x >= '0' && x <= '9') {
			data2[i] = x;
			i++;
			x = fgetc(in2);
			fprintf(in3, "%s..", data2);
		}
		if (atoi(data2) == atoi(data1))
			fprintf(in3, "\nGood luck!\n");
		for (i = 0; i<4; i++)
			data2[i] = 0;
		i = 0;
		x = fgetc(in2);
	}
}

int main()
{
	FILE* Fi1, *Fi2, *Fi3;
	Fi1 = fopen("input1.txt", "r+");
	Fi2 = fopen("input2.txt", "r+");
	Func1(Fi1, Fi2);
	Fi3 = fopen("input3.txt", "r+");
	Func2(Fi2, Fi3, Fi1);
	fclose(Fi3);
	fclose(Fi1);
	fclose(Fi2);
		return 0;
}
