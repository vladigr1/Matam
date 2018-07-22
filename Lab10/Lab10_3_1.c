#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  N  5
typedef enum { FALSE, TRUE } BOOL;

void Insert( BOOL(*f)(void *, void *), void *Element, void ** Parray);
BOOL Int_Comp(void *FirstElement, void *SecondElement);
BOOL IsFull();


int CurrentCount = 0;  /*global variable - only for the first ADT lab!Please,don't use!*/ 


int main()
{
  int Array[N], Value, i;
  void* PArray[N];                        /*pointers array*/

  printf("Enter numbers, -999 to stop");
  scanf("%d", &Value);

  while( Value != -999)  
  {           
    if(!IsFull()) 
    {
        Array[CurrentCount] = Value;
        Insert(Int_Comp, &Array[CurrentCount], PArray);  /*call the general function*/
        scanf("%d", &Value);
    }
    else  
    {
      printf("The array is full");
      break;
    }
 }
 printf("\n Your sorted array is:\n");             /*print the array in sorted order*/
 for(i=0; i < CurrentCount; i++)
    printf(" %d " ,*(int*)PArray[i]);
 _getch();
 return 0;
}



BOOL IsFull()
{
 if (CurrentCount == N)
  return TRUE;
 return FALSE;
}


BOOL Int_Comp(void *FirstElement, void *SecondElement)
{
  if( *(int*)FirstElement > *(int*)SecondElement)
    return TRUE;
  return FALSE;
}


void Insert(BOOL(*f)(void *, void *), void *Element, void ** Parray)
{
	int i;
	void *temp;
	for (i = 0; i < CurrentCount && f(Element, Parray[i]); ++i);
	++CurrentCount;
	while (i < CurrentCount && i < N) {
		temp = Parray[i];
		Parray[i] = Element;
		Element = temp;
		++i;
	}
}