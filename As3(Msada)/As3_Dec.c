#include "As3_Header.h"


Manot* ScoutInList(Manot* p, char *ProductName)
{
	int flag;
	while (p != NULL && !(flag = strcmp(p->Data.ProductName, ProductName) == 0))
		p = p->next;

	return p;
}

void freeList(Manot **head)
{
	while ((*head) != NULL) {
		Manot *temp = *head;
		*head = (*head)->next;
		free(temp->Data.ProductName);
	}
}

Boolean CreateProducts(FILE *in, Manot **head) //retrun N only if malloc failed if the oreder placed wrong will jump to the next one
{
	char  buffer[BUFFER_SIZE] = { 0 }, premium_letter;
	int temp_quantity = 0, temp_price = 0;;
	while (fscanf(in, "%s%d%d %c",buffer, &temp_quantity, &temp_price, &premium_letter)==4){ //we must have all items set correctly if their issue with the way it placed in the manot.txt we dont really care we just use what we get if he want to add because it not full he can do it
		Boolean flag = N;	//flag to check if their is no such name or negative or float
		Manot *temp = NULL, *travel;
		if (temp_price <= 0 || temp_quantity <= 0) {	//checking input bigger not equal to zero*
			printf(((temp_price <= 0) ? "the %s that enter had a negeative price value\n" : "the %s that enter had a negeative quantity value\n"), buffer);
			flag = Y;
		}
		if (flag == N) {//we dont want to compute if arugments are falsy set
			travel = ScoutInList(*head, buffer);
			if (travel == NULL) {	//their is no such name we 
				char *name;			//we want specif name in each loop a new
				if (NULL == (temp = (Manot *)malloc(sizeof(Manot)))) {
					printf("No memory to allocate this much of Manot\n");
					return N;
				}
				if (NULL == (name = (char *)malloc(sizeof(char)*(strlen(buffer) + 1)))) {
					printf("No memory to allocate this much of Manot\n");
					return N;
				}
										//the Data is correct enter data to temp
				strcpy(name, buffer);
				switch (premium_letter) {
					case 'Y':
						temp->Data.Premium = Y;
						break;
					case 'N':
						temp->Data.Premium = N;
						break;
				}
				temp->Data.Quantity = temp_quantity;
				temp->Data.Price = (int)temp_price;
				temp->Data.ProductName = name;
				temp->next = *head;
				*head = temp;
			} else {	//if we did find a similar name 
				printf("the name %s was set before adding item too the kitchen is diffrent function\n", buffer);
			}
		}
	}
	printf("the item created in the kitchen\n");
	return Y;
}

void AddItems(Manot *head, char *ProductName, int Quantity)	//*need to check the quantity and 
{
	if (Quantity <= 0) {
		printf("the quantity most be positive number\n");
	}
	if ((head = ScoutInList(head,ProductName)) != NULL) {
		head->Data.Quantity += Quantity;
		printf("\t\t\t%s: added %d, now their is %d items\n", ProductName, Quantity, head->Data.Quantity);
		return;
	}
	printf("Couldn't find %s\n", ProductName);
}

Boolean OrderItem(Manot** tables, Manot** kitchen, int TableNumber, char *ProductName, int Quantity)
{
	Manot** table;
	Manot* mana;
	//============table number============//
	if (TableNumber - 1 > NUM_TABLE && TableNumber - 1 < 0) {
		printf("table number was too high\n");
		return ;
	}

	//============name============//
	mana = ScoutInList(*kitchen, ProductName);
	if (!mana) {
		printf("the dish \"%s\" doesn't exist .\n", ProductName);
		return;
	}
	//============quantity============//
	if (Quantity <= 0 && mana->Data.Quantity < Quantity) {
		printf("Quantity isn't acceptable\n");
		return;
	}

	table = &(tables[TableNumber - 1]); // the place of table in the correct spot
	Manot *Tmana;
	if (Tmana = ScoutInList(*table, ProductName) != NULL) {
		Tmana->Data.Quantity += Quantity;
	} else {
		if (Tmana = (Manot*)malloc(sizeof(Manot)) == NULL) {
			printf("memory wasn't allocated\n");
			return N;
		}
		*Tmana = *mana;
		Tmana->Data.Quantity = Quantity;
		Tmana->next = *table; // adds the item the start of the list
		tables[TableNumber - 1] = Tmana; // puts the pointer as the head of the list
	}
	mana->Data.Quantity -= Quantity; // lower the quantity
	return Y;
}

void RemoveItem(Manot **tables, int TableNumber, char *ProductName, int Quantity)
{

	Manot* mana;
	//====================== Table Number ======================//
	if (TableNumber - 1 > NUM_TABLE && TableNumber - 1 < 0) {
		printf("table number was too high\n");
		return;
	}
	//============name============//
	mana = ScoutInList(tables[TableNumber - 1], ProductName);
	if (!mana) {
		printf("the dish \"%s\" doesn't exist .\n", ProductName);
		return;
	}

	//============quantity============//
	if (Quantity <= 0 && mana->Data.Quantity < Quantity) {
		printf("Quantity isn't acceptable\n");
		return;
	}

	if (Quantity == mana->Data.Quantity) { // in case we need to delete the node
		Manot* todel, *prev;
		if (tables[TableNumber - 1] == mana) { // the node is the first one
			todel = mana;
			tables[TableNumber - 1] = tables[TableNumber - 1]->next;
		} else {
			while (!(prev->next) && !(strcmp((prev->next)->Data.ProductName, ProductName) == 0)) // the node is somewhere in the list
				prev = prev->next;
			todel = mana;
			prev->next = mana->next;
		}
		free(todel);//free the needed to delete node
		return;
	} else
		mana->Data.Quantity -= Quantity;
}


void RemoveTable(Manot **tables, int TableNumber)
{
	double paycheck = 0;
	Boolean premium = N;

	//====================== Table Number ======================//
	if (TableNumber - 1 > NUM_TABLE && TableNumber - 1 < 0) {
		printf("table number was too high\n");
		return;
	}
	printf("Table %d's bill : \n", TableNumber);
	int index = 1;
	Manot *table = tables[TableNumber - 1];
	while (table != NULL) {
		paycheck += table->Data.Price * table->Data.Quantity;
		if (premium != Y) {
			premium = table->Data.Premium;
		}
		printf("%d)%s #quantity: #price of each:%d #total price:%d \n", table->Data.ProductName, table->Data.Quantity, table->Data.Price, table->Data.Quantity*table->Data.Price);
		index++;
		table = table->next;
	}
	if (premium == Y)
		paycheck *= 1.2;
	printf("final price: %.2lf", paycheck);
	Manot *todel;
	table = tables[TableNumber - 1]->next;
	free(tables[TableNumber - 1]);
	while (table != NULL) {
		todel = table;
		table = table->next;
		free(todel);
	}
}

