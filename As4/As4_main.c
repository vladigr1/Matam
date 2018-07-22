#include "As4_header.h"
#include <string.h>


//specific function
RESULT_CMP IntCompare(DATA key1, DATA key2)
{
	int result = *(int *)key1 - *(int *)key2;
	if (result > 0)return BIGGER;
	if (result < 0)return SMALLER;
	return EQUAL;
}

void IntPrint(DATA key)
{
	printf("%d", *(int *)key);
}
void IntDel(DATA key)
{
	free(key);
}


RESULT_CMP StringCompare(DATA key1, DATA key2)
{
	int result = strcmp((char *)key1,(char *)key2);
	if (result > 0)return BIGGER;
	if (result < 0)return SMALLER;
	return EQUAL;
}

void StringPrint(DATA key)
{
	printf("%s", (char *)key);
}
void StringDel(DATA key)
{
	free(key);
}


//main support functions
int *IntGenerateValue(PTManager manager,int value){
	int *new_key;
	if (NULL == (new_key = malloc(sizeof(int)))) {
		printf("No memory for malloc(new int)\n");
		FreeFullTree(manager);
		exit(1);
	}
	*new_key = value;
	return new_key;
}

char *StringGenerateValue(PTManager manager, char * value)
{
	char *new_key;
	if (NULL == (new_key = malloc(sizeof(char)*(1 + strlen(value))))) {
		printf("No memory for malloc(new string)\n");
		FreeFullTree(manager);
		exit(1);
	}
	strcpy(new_key, value);
	return new_key;
}

DATA GenerateValue(PTManager manager,int flag){	//generate int if flag 1 or char if its 2
	DATA new_key;
	int intValue;
	char buffer[BUFFER_SIZE] = { 0 };		//could be optimized by seprating char and int case
	switch (flag) {
		case 1:
			do {
				printf("Please enter a int\n");
				rewind(stdin);
			} while (scanf("%d", &intValue) != 1);
			new_key = IntGenerateValue(manager, intValue);
			break;
		case 2:
			do {
				printf("Please enter a string\n");
				rewind(stdin);
			} while (scanf("%s", buffer) != 1);
			new_key = StringGenerateValue(manager, buffer);
			break;
	}
	return new_key;
}


int main()
{
	int i, flag = 0;		//flag 0:didnt assign. 1:int. 2:string.3:finished input
	PTManager manager;
	while (flag == 0) {
		printf("please choose the work format:\n1.int\n2.char\n");
		scanf("%d", &i);
		switch (i) {
			case 1:
				manager = InitManager(IntCompare, IntPrint, IntDel);
				flag = 1;
				break;
			case 2:
				manager = InitManager(StringCompare, StringPrint, StringDel);
				flag = 2;
				break;
		}
	}

	while (flag != 3) {
		do {
			printf("\nplease choose an option:\n"
				   "1.enter new values\n"
				   "2.print in order the current values\n"
				   "3.finding the hight of single key in the tree\n"
				   "4.print the highest single key\n"
				   "5.finding the k highest value\n"
				   "0.exit\n"
			);
			rewind(stdin);
		} while ((scanf("%d", &i) != 1) || (i > 5 || i < 0));

		if (i == 1) {
			int amount, j;
			do {
				printf("please enter how many values you want to add\n");
				rewind(stdin);
			} while (scanf("%d", &amount) != 1 || (amount < 1));
			for (j = 0; j < amount; ++j) {	//its is annoying to enter one by one
				DATA new_key = GenerateValue(manager, flag);
				AddNode(manager, new_key);
			}
		}
		if (i == 2) {
			PrintInorder(manager);
		}
		if (i == 3) {
			DATA check_hight = GenerateValue(manager, flag);
			int hight = HightKey(manager, check_hight);
			if (hight > -1) {
				printf("the hight is %d\n", hight);
			}else {
				printf("their is no such key in the tree\n");
			}
		}
		if (i == 4) {
			HighestKey(manager);

		}
		if (i == 5) {
			int amount_to_print;
			do {
				printf("please enter k\n");
				rewind(stdin);
			} while (scanf("%d", &amount_to_print) != 1 || amount_to_print < 1);
			PrintKHighest(manager, amount_to_print);
		}
		if (i == 0) {
			flag = 3;
			FreeFullTree(manager);
		}
	}
	_getch();
	return 0;
}
	
