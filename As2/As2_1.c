#include <stdio.h>
#include <Stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Student {
	char *name;
	long idnum;
	float grade;
	char work[5];
	char endwork;
}Student;

typedef struct University {
	Student *studin;
	int count;
}University;


void get_lost(char *str);
void init_University(University *uni);
void input(FILE *in, University *uni);
void output(FILE *out, University *uni);
void final_grade(FILE *out, University *uni);
void exam_statistic(FILE *out, University *uni);
void fix_grade(FILE *out, University *uni);
void finish_menu(FILE *out);


int main()
{
	University uniOb, *uni;
	FILE *in, *out;
	int i, stage = 0;
	char menu_button;
	uni = &uniOb;
	while (stage != 5) {
		printf("\t\t==Menu==\na. enter input\nb. grade output\nc. end result\nd. statistic\ne. fix work grade\nf. end of program\n\nPlease choose one of the options: ");
		scanf("%c", &menu_button);
		menu_button-= 'a';
		switch (menu_button) {		//stage 0-4 is for first loop 5 for exit 6 regenrate output because we reset input with a
			case 0:	
					
					if ((in = fopen("input.txt", "r")) == NULL) get_lost("Their is no input file");
					if (stage == 0)stage = 1;
					else {
						for (i = 0; i < uni->count; ++i) free((uni->studin + i)->name);
						free(uni->studin);
					}
					input(in, uni);
					fclose(in);
					printf("\n just finished with input");
				break;
			case 1:
				if (stage == 1) {		//we are getting to stage 4 only after we press on all the button once
					if ((out = fopen("output.txt", "w")) == NULL) get_lost("Their is no output file");
					output(out, uni);
					fclose(out);
					printf("\n just finished with output");
				} else {		//if their was special case rather then only you must run first we could control and see
					printf("you still didn't finish the loop you are on stage == %c ==\n please choose this button", stage + 'a');
				}
				break;
			case 2:
				if (stage == 1) {		//we are getting to stage 4 only after we press on all the button once
					if ((out = fopen("output.txt", "w")) == NULL) get_lost("Their is no output file");
					final_grade(out, uni);
					fclose(out);
				} else {//if their was special case rather then only you must run first we could control and see
					printf("you still didn't finish the loop you are on stage == %c ==\n please choose this button", stage + 'a');
				}
				break;
			case 3:
				if (stage == 1) {		//we are getting to stage 4 only after we press on all the button once
					if ((out = fopen("output.txt", "w")) == NULL) get_lost("Their is no output file");
					exam_statistic(out, uni);
					fclose(out);
					printf("\n just finished with exam statistic");
				} else {//if their was special case rather then only you must run first we could control and see
					printf("you still didn't finish the loop you are on stage == %c ==\n please choose this button", stage + 'a');
				}
				break;
			case 4:
				if (stage == 1) {		//we are getting to stage 4 only after we press on all the button once
					if ((out = fopen("output.txt", "w")) == NULL) get_lost("Their is no output file");
					fix_grade(out, uni);
					fclose(out);
					printf("\n just finished with fixing grades");
				} else {//if their was special case rather then only you must run first we could control and see
					printf("you still didn't finish the loop you are on stage == %c ==\n please choose this button", stage + 'a');
				}
				break;
			case 5:
				if ((out = fopen("output.txt", "w")) == NULL) get_lost("Their is no output file");
				finish_menu(out, uni);
				fclose(out);
				printf("\n just finishing the menu");
				if (stage != 0) {//in case you just exited and never pushed the input to the struct
					for (i = 0; i < uni->count; ++i) free((uni->studin + i)->name);
					free(uni->studin);
				}
				stage = 5;
				break;
			default:
				printf("\nyou didn't enter a legitimate button\n(please enter lowercase letter that are shown in the menu)\n");
		}
		putch('\n');
		putch('\n');
		rewind(stdin);		//clear text for each input
	}
	return 0;
}


void get_lost(char *str)
{
	printf(str);
	exit(1);
}

void init_University(University *uni)
{
	uni->count = 0;
	uni->studin = (Student *)malloc(sizeof(Student));
	if (uni->studin == NULL) get_lost("No memory (init_university)\n");
}

void input(FILE *in, University *uni)
{
	int i,end,std_in = 0;
	char buffer[100] = { 0 };
	init_University(uni);
	fseek(in, 0, SEEK_END);
	end = ftell(in);
	rewind(in);
	while (ftell(in)<end) {
		Student *temp_uni;
		char *std_name;
		int work_grade = 0;
		temp_uni = (Student *)realloc(uni->studin,(std_in+1)*sizeof(Student));		//setting temp uni in case their will be no memory for setting new uni we can state what to do with the current data we dont destroy the old uni (its more module)
		if (temp_uni == NULL) get_lost("No memory (input)\n");
		uni->studin = temp_uni;
		fscanf(in, "%s %ld %f ", buffer, &(uni->studin + std_in)->idnum, &(uni->studin + std_in)->grade);//setting part1
		std_name = (char *)malloc(sizeof(char)*(strlen(buffer) + 1));
		if (std_name == NULL)get_lost("no memory for name (input)\n");
		strcpy(std_name, buffer);					//moving from buffer to structure
		(uni->studin + std_in)->name = std_name;
		for (i = 0; i < 5; ++i)fscanf(in, "%c ", &(uni->studin + std_in)->work[i]);	//;setting works and drop a line recognize that each data has a line different
		for (i = 0; i < 5; ++i)if ((uni->studin + std_in)->work[i] == '1') work_grade++;//setting the end work 
		(uni->studin + std_in)->endwork = work_grade / 3;				//;calculate the end work
		++std_in;
	}
	if (std_in == 0) get_lost("Their was no student in the file\n");
	uni->count = std_in;
}

void output(FILE *out, University *uni)
{
	int i,j;
	for (i = 0; i < uni->count; ++i) {
		int work_grade = 0;			//we most regenerate the end works grade because we updated by button e
		for (j = 0; j < 5; ++j)if ((uni->studin + i)->work[j] == '1') work_grade++;
		(uni->studin + i)->endwork = work_grade / 3;
		fprintf(out, "Student %d: %s %ld %.2f %d\n", i+1, (uni->studin + i)->name, (uni->studin + i)->idnum, (uni->studin + i)->grade, (uni->studin + i)->endwork);
	}
}

void final_grade(FILE *out, University *uni)
{
	int i, j,end;
	char search_ch= 0;
	for (i = 0; i < uni->count; ++i) {
		float final_g;
		final_g = ((uni->studin + i)->grade >= 55) ? (uni->studin + i)->endwork*15 + (uni->studin + i)->grade*0.85 : (uni->studin + i)->grade;
		fprintf(out, "Student %d: %s %ld %.2f %d %.2f\n", i + 1, (uni->studin + i)->name, (uni->studin + i)->idnum, (uni->studin + i)->grade, (uni->studin + i)->endwork, final_g);
			//doesn't exactly give you the same result for some reason
	}
}

void exam_statistic(FILE *out, University *uni)
{
	int i;		//biggest result and their is in the input test if their are student so the result cant be miss leading  
	float avg=0,sd=0, min = 100, max = 0;
	for (i = 0; i < uni->count; ++i)avg += (uni->studin + i)->grade;
	avg /= uni->count;
	for (i = 0; i < uni->count; ++i) {
		sd += pow(((uni->studin + i)->grade - avg), 2);							//calculate the sd sum first
		if (min > (uni->studin + i)->grade) min = (uni->studin + i)->grade;
		if (max <(uni->studin + i)->grade) max = (uni->studin + i)->grade;
	}
	sd /= uni->count;															//divide the n in sd
	sd = sqrt(sd);
	fprintf(out, "1. avg: %.2f\n2. sd: %.2f\n3. student amount: %d\n4. range: %.2f - %.2f", avg, sd, uni->count,min,max);
}

void fix_grade(FILE *out, University *uni)
{
	int i,student_num,flag =0,choosen_grade;
	long student_id;
	Student *choosen;
	for (i = 0; i < uni->count; ++i)printf("%d %s id: %d\n", i + 1, (uni->studin + i)->name,(uni->studin+i)->idnum);
	while (flag == 0) {
		printf("Please choose a student number that his you want to update: ");
		while (!(scanf("%ld", &student_id))) {
			printf("please enter a legitimate id: ");
			rewind(stdin);		//in case their more in input
		}
		for (i = 0; i < uni->count && flag == 0; ++i)if (student_id == (uni->studin + i)->idnum) flag = 1;	//;finding student the flag turn 1
		if(flag ==0 )printf("their wasn't any student with this id\n");
	}
	choosen = uni->studin + i -1;													//;because the for add 1 at the end
	printf("Please enter which work to redo for %s from 1-5: ",choosen->name);
	rewind(stdin);			//clear the added input from getting student id
		while (!(scanf("%d", &choosen_grade) && (choosen_grade >= 1 && choosen_grade <= 5))){
			rewind(stdin);
			printf("their was an issue with the input please renter %s the work you want to change: ",choosen->name);
		}
		choosen->work[choosen_grade - 1] = (choosen->work[choosen_grade - 1] == '1') ? '0' : '1';	//swapping with ternary
	output(out, uni);	//reran the function because we don't really work with the out file its clear and we can send it like it is
}

void finish_menu(FILE *out)
{
	fprintf(out, "End Of Program");
}