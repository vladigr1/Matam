#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
	char ID[10];
	char F_name[11];
	char L_name[16];
	int Age;
	char Addr[51];
}Person;

void Error_Msg(char*msg);

int main()
{
	int SpCount = 0,i=0;
	Person temp;
	FILE *in,*out;
	in = fopen("the_first.txt", "r");
	if(in == NULL)Error_Msg("No file");
	temp.Age = 0;
	while(feof(in)== 0){
		int ch = fgetc(in);
		if(ch == (char)' '){
			++SpCount;
			i = 0;
			}else switch(SpCount){
					case 0:
						temp.ID[ i++ ] =(char)ch;
						temp.ID[ i ] = 0;
						break;
					case 1:
						temp.F_name[ i++ ] = (char)ch;
						temp.F_name[ i ] = 0;
						break;
					case 2:
						temp.L_name[ i++ ] = (char)ch;
						temp.L_name[ i ] = 0;
						break;
					case 3:
						temp.Age *= 10;
						temp.Age += (ch - '0');
						break;
					case 4:
						temp.Addr[ i++ ] = (char)ch;
						temp.Addr[ i ] = 0;
						break;
			}
		}
	temp.Addr[ i-1 ] = 0;
	fclose(in);
	out = fopen("the_second.txt", "w");
	fputs("ID: ",out);
	fputs(temp.ID, out);
	fputs("\nF_name: ", out);
	fputs(temp.F_name, out);
	fputs("\nL_name: ", out);
	fputs(temp.L_name, out);
	fputs("\nage: ", out);
	fprintf(out, "%d", temp.Age);
	fputs("\nadder: ", out);
	fputs(temp.Addr, out);
	fclose(out);
	_getch( );
	return 0;	
}



void Error_Msg(char* msg)
{
	printf("\n%s",msg);
	exit(1);
}