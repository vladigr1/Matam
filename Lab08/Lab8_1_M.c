#include "Lab8_H.h"



int main()
{
	Stack ArrToStack,*PToStack;
	int arr[] = { 1,2,3,4,5 }
		, i
		, FullArr[] = { 0,1,2,3,4,5};	//testing while size bigger then NUM
	PToStack = &ArrToStack;				//setting stack and the pointer
	ArrToStack.size = 0;
	PToStack->head = NULL;
	for (i = 0; i < 6; ++i)Push(PToStack, FullArr[i]);
	for (i = 0; i < 6; ++i) {
		int temp;
		temp = -404;
		if(Pop(PToStack, &temp) == 1)printf("int that pop : %d\n", temp);
	}
	_getch();
	return 0;
}