#include "Lab8_3_H.h"


int main()
{
	Queue ArrToQueue, *PToQueue;
	int arr[] = { 1,2,3,4,5 }
		, i
		, FullArr[] = { 0,1,2,3,4,5 };	//testing while size bigger then NUM
	PToQueue = &ArrToQueue;				//setting stack and the pointer
	ArrToQueue.size = 0;
	PToQueue->head = PToQueue->tail = NULL;
	for (i = 0; i < 5; ++i)Enqueue(PToQueue, arr[i]);
	for (i = 0; i < 3; ++i) {
		int temp;
		if (Dequeue(PToQueue, &temp) == 1)printf("int that Dequeue : %d\n", temp);
	}

	for (i = 0; i < 3; ++i)Enqueue(PToQueue, arr[i]);

	printf("\n\t\tempty left over\n\n");
	 while(PToQueue->size!= 0){
		int temp;
		if (Dequeue(PToQueue, &temp) == 1)printf("\t\tint that Dequeue : %d\n", temp);
	}
	_getch();
	return 0;
}