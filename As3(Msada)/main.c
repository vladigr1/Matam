#include "As3_Header.h"

int main()
{
	Manot *Kitchen = NULL, *temp,*Table[NUM_TABLE] = { 0 };
	FILE *in_inst, *in_manot;
	Boolean flag_run = Y;
	char buffer[BUFFER_SIZE] = { 0 };//we dont save the buffer on the node so we can just addto him
	int button, tablenum, quantity,i;
	if ((in_inst = fopen("Instructions.txt", "r")) == NULL) {
		printf("couldnt open the file Instructions\n");
		flag_run == N;
	}
	while (flag_run == Y && (fscanf(in_inst,"%d",&button)==1))		//we run with int becuase it easy way to filter \n
	{
		switch (button)
		{
			case 1:
				if ((in_manot = fopen("Manot.txt", "r")) == NULL) {
					flag_run = N;
					break;
				}
				flag_run=CreateProducts(in_manot, &Kitchen);		//*need to free name and the nodes*
				fclose(in_manot);
				break;
			case 2:
				fscanf(in_inst, "%s%d", buffer, &quantity);
				AddItems(Kitchen, buffer, quantity);	//the only one we dont need to send it as pointer of a pointer
				break;
			case 3:
				fscanf(in_inst, "%d%s%d", &tablenum, buffer, &quantity);
				flag_run=OrderItem(&Kitchen, Table, tablenum, buffer, quantity);
				break;
			case 4:
				fscanf(in_inst, "%d%s%d", &tablenum, buffer, &quantity);
				RemoveItem(Table, tablenum, buffer, quantity);
				break;
			case 5:
				fscanf(in_inst, "%d", &tablenum);
				RemoveTable(Table, &tablenum);
				break;
			default:
				flag_run = N;
				break;
		}
		do {
			printf("Please enter the char 0 too continue:\n");
		}while ((button = getch()) != '0');	//keep it on the same loop
		rewind(stdin);	// who knows how many button he pressed
	}
	fclose(in_inst);
	/*
	for (i = 0; i < NUM_TABLE; ++i) {
		freeList(Table+i);
	}
	*/
	freeList(&Kitchen);
	printf("\nPress any key to close cli...");
	_getch();
	return 0;
}