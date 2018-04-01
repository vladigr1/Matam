#include <stdio.h>
#include <conio.h>

int main ()
{
	struct sbooks{
		int serial;
		char *name;
		int rate;
	}sbook1 = { 1,"besti",5 };

	typedef struct tbooks{//called as structier
		int serial;
		char *name;//called as field
		int rate;
		int test[ 2 ];
		}tbooks; //cant create variable in genrate like sbook1


	struct sbooks sbook2 = { 2,"boki",4 };
	tbooks tbook1, *ptlooki;
	ptlooki = &tbook1;
	tbook1.serial = 1;
	tbook1.name = "booki";
	tbook1.rate = 4;

	tbooks shelf[ 3 ];//					ARR and structiers
	shelf[ 1 ].name = "Harry";//			good way to move in the for is with for(i=0;i<num;++i,++pstruct)
	shelf[ 1 ].test[ 0 ] = 1;//				you can do it with stuct + i

	printf ("struct: serial %d name: %s rate %d\n", sbook1.serial, sbook1.name, sbook1.rate);
	printf ("struct: serial %d name: %s rate %d\n", tbook1.serial, tbook1.name, tbook1.rate);
	ptlooki->name = "loki";
	ptlooki->rate = 5;
	printf ("typedef: serial %d name: %s rate %d\n", tbook1.serial, tbook1.name, tbook1.rate);
	printf("typedef:  name: %s test %d\n", shelf[1].name, shelf[1].test[0]);

	_getch ();
	return 0;
}