#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float func1(int x) 
{
	return 1.0 / x;
}

float func2(int x) 
{
	return x / 5.0;
}

double sum_square(int m, int n, float(*f)(int a))
{
	double result=0;
	for (; m <= n; m++) {
		result += pow(f(m), 2);
	}
	return result;
}

int main()
{
	int a, b;
	printf("Please enter the border points for the sum.\n");
	scanf("%d%d", &a, &b);
	printf("The sum of func2: %.5lf\n", sum_square(a,b,&func2));
	printf("The sum of func1: %.5lf\n ", sum_square(a,b,&func1));
	_getch();
	return 0;
}