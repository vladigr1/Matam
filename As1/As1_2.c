#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define N 5

typedef struct Class_Stct							//creating structure class
	{
	char Code_C[11];
	char *Name_c;
	int Num_in_C;
	int Price_in_C;
	}Class_Stct;

void InputToShop(Class_Stct *ptShop, int size);	//function calls
void PrintClass(Class_Stct Class_p);
int Bubbling(Class_Stct **ptShop,int size);	//we have chosen using bubble because the ability to control the amount 
void BubbleSort(Class_Stct **ptShop, int size,int bubbleamount);//we control the sort amount by bubbleamount

int main( )
	{
	int i,ToPrint=2;
	Class_Stct shop[ N ] ,*ptshop[N];
	InputToShop(&shop, N);
	for(i = 0; i < N; ++i) ptshop[ i ] = &shop[ i ];
	BubbleSort(ptshop, N, ToPrint);
	printf("\nBest %d sellers are:\n",ToPrint);
	for(i=0 ; i < ToPrint; ++i) PrintClass(*(ptshop[ i ]));
	for(i = 0; i < N; ++i) free(shop[ i ].Name_c);
	_getch( );
	return 0;
	}

void InputToShop(Class_Stct *ptShop, int size)
	{
	int i;
	char buffer[ 20 ];
	for(i = 0; i < size; ++i){
		char *name;
		printf("we are start setting to enter the %d class:\nPlease enter class code: ",i+1);
		scanf("%s", &(ptShop + i)->Code_C);
		printf("Please enter Class name: ");
		scanf("%s", buffer);
		name = (char*)malloc(sizeof(char) * (strlen(buffer)+1));	//setting it exact to the amount of char 
		if(name == NULL){
			printf("No memory for buffer");
			_getch( );
			exit(1);
			}
		strcpy(name,buffer);
		(ptShop + i)->Name_c = name;							//setting buffer pointer on the pointer in class
		printf("Please enter Class number of supplement: ");
		scanf("%d",&(ptShop + i)->Num_in_C);
		printf("Please enter Class selling price: ");
		scanf("%d", &(ptShop + i)->Price_in_C);
		}
	}

void PrintClass(Class_Stct Class_p)
	{
	printf("The class named: %s\n", Class_p.Name_c);
	printf("With code number: %s\n", Class_p.Code_C);
	printf("With a %d supplies ", Class_p.Num_in_C);
	printf("that their price is %d", Class_p.Price_in_C);
	putch('\n');
	}

int Bubbling(Class_Stct **ptShop, int size)
	{
	int i, swapped=0;
	Class_Stct *temp;
	for(i = 0; i < size-1; ++i){
		int Totali = (*(ptShop + i))->Num_in_C*(*(ptShop + i))->Price_in_C;			//naming each arr[i] & arr[i+1]
		int TotalIplus = (*(ptShop + i+1))->Num_in_C*(*(ptShop + i+1))->Price_in_C;
		if(Totali < TotalIplus){
			swapped = 1;
			temp = *(ptShop + i);
			*(ptShop + i) = *(ptShop + i + 1);
			*(ptShop + i + 1) = temp;
			}
		}
	return swapped;
	}

void BubbleSort(Class_Stct **ptShop, int size, int bubbleamount)
	{
	int swapped = 1;
	while(bubbleamount > 1 && swapped){
		swapped = Bubbling(ptShop, size--);
		}
	}

