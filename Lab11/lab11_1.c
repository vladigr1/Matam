#include "Lab11_1_H.h"


void free_char(KEY elem)
{
	free(elem);
}




int main()
{
	NODE stack = NULL;
	char key;
     puts("Enter characters, separated by space. Press enter to stop\n");
    do
    {
		char *result =(char *)malloc(sizeof(char));
	   key = getchar();
	   *result = key;
	   _flushall();
	   push(result, &stack);
    } while (key != '\n');
    puts("Here are the characters in reverse order:\n");

    while (!isempty(stack))
    {
	  printf(" %c ",*(char *)top(stack));
      pop(&stack,free_char);
    }
	_getch();
   return 0;
}