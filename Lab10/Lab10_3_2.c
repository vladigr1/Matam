#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  N  5
#define  LENGTH 30

typedef enum { FALSE, TRUE } BOOL;


int CurrentCount = 0;   /*global variable - only for the first ADT lab!Please,don't use!*/


void Insert( BOOL(*f)(void *, void *), void *Element, void ** Parray);
BOOL Str_Comp(void *FirstElement, void *SecondElement);
BOOL IsFull();


int main()
{
  char* Array[N];
  void* PArray[N];
  int i;
  char TempStr[LENGTH];

  printf("Enter strings with space between them,'end' to finish  ");
  scanf("%s", TempStr);

  while( strcmp(TempStr,"end"))  
  {
    
    if(!IsFull()) 
    {
      Array[CurrentCount] = (char*)malloc(strlen(TempStr)+1); /*allocate the string memory*/
      strcpy(Array[CurrentCount], TempStr);   
      Insert(Str_Comp, Array[CurrentCount], PArray);    /*call the general function*/
      scanf("%s", TempStr);
    }
    else  
    {
      printf("The array is full");
      break;
    }
 }
 printf("\nYour sorted array is:\n");
 for(i = 0; i < CurrentCount; i++)
   printf(" %s " , (char*)PArray[i]);

 for(i = 0; i < CurrentCount; i++)
    free(Array[i]);
 _getch();
  return 0;
}


BOOL IsFull()
{
 if (CurrentCount == N)
  return TRUE;
 return FALSE;
}
	

BOOL Str_Comp(void *FirstElement, void *SecondElement)
{
  if( strcmp( (char*)FirstElement, (char*)SecondElement) > 0 )
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