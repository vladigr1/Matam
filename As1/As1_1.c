#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct SimpleDivded
	{
	int a;
	int b;
	}SimpleDivded;

int gcd(int m, int n);//common divider function define 
int EnterDivdedToArr(SimpleDivded *arr,int size);//entering number to arr
void SumDivdedFromArr(SimpleDivded *arr, int size);//calculator the sum and then call to print in request format
void PrintFormat(SimpleDivded *arr, int size, SimpleDivded sum);//the print format 

int main( )
	{
	int i, EnterAmount;
	SimpleDivded arr[ SIZE ];
	EnterAmount = EnterDivdedToArr(&arr, SIZE);
	SumDivdedFromArr(&arr, EnterAmount);
	_getch( );
	return 0;
	}

int gcd(int m, int n)//find smallest divider its imported to send a then b
	{
	while(m != n && m!= 0) (m > n) ? (m= m - n) : (n =n - m);
	return n;
	}

int EnterDivdedToArr(SimpleDivded *arr,int size)
	{
	int i;
	printf("Enter fraction(max 9) by pairs of integers(0 0):\n");
	for(i = 0; i < size; ++i){
		int a, b;
		printf("%d ", i+1);
		if(scanf("%d%d", &a, &b) < 2){//check scan
			printf("error in the scan");
			_getch( );
			exit(1);
			}
		if(a == 0 && b == 0) return i;
		if(b == 0){//check 0 divider
			printf("Cant divide by 0 enter again\n");
			} else{
			if(b <= 0){
				b= -1 * b;
				a = -1 *a;
				};
			if(a >= 0){
				(arr + i)->a = a / gcd(a, b);//divide by common divider
				(arr + i)->b = b / gcd(a, b);
				} else{
				(arr + i)->a = a / gcd(-1 *a, b);//divide by common divider when negative
				(arr + i)->b = b / gcd(-1 *a, b);
				}
			}
		}
	}

void SumDivdedFromArr(SimpleDivded *arr, int size)
	{
	int i;
	SimpleDivded sum;
	sum.a = arr[ 0 ].a;
	sum.b = arr[ 0 ].b;
	for(i = 1; i < size; ++i){
		int  Divider=sum.b * (arr + i)->b , gcdR;
		sum.a = (Divider / sum.b)*sum.a + (Divider / (arr+ i)->b)*(arr +i) ->a;
		sum.b = Divider;
		if(sum.a >= 0){
			gcdR = gcd(sum.a, sum.b);
			} else{
			gcdR = gcd(-1*sum.a, sum.b);
			}
		sum.a /= gcdR;//set it to most reduced fracture
		sum.b /= gcdR;
		}
	PrintFormat(arr, size, sum);//call for print
	}

void PrintFormat(SimpleDivded *arr, int size, SimpleDivded sum)
	{
	int i;
	printf("%d/%d", arr->a, arr->b);
	for(i = 1; i < size; ++i){
		printf("%+ d/%d", (arr+i)->a, (arr+i)->b);
		}
	printf(" = %d/%d", sum.a,sum.b);
	printf(" = %d", sum.a / sum.b);
	if(sum.a >= 0) printf(" and %d/%d\n", sum.a%sum.b, sum.b);
	else printf(" and %d/%d\n", (-1*sum.a)%sum.b, sum.b);	//print reminder for negative number  
	}
