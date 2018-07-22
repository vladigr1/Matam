#include "Lab12_hdr.h"

//specific function
BOOL cmp_char(void *ch1, void*ch2)
{
	return (BOOL)(*(char *)ch1 == *(char *)ch2);
}
void prnt_char(void *ch)
{
	printf("%c ", *(char *)ch);
}
void free_char(void *ch)
{
	free(ch);
}

  







  int main()
  {
    char ch,*temp;
    int n,i;
    BOOL res;
    PNode head=NULL,tail=NULL;
	
    printf("Enter number of characters ");
    scanf("%d",&n);            
    printf("\nEnter %d characters,separated by enter\n",n);
    for(i=0;i<n;i++) 
    {
        temp=(char*)malloc(sizeof(char));
        if (NULL==temp)
	{
	    printf("\nCan't allocate data memory");
	    freeAll(&head,free_char);
	    return 1;
        } 
        scanf(" %c",temp);
        res=insertEntry(&head,&tail,temp,cmp_char);
	if(FALSE==res)  /* if FALSE==res than there is something wrong with malloc */
	{							
	    printf("\nCan't allocate node memory or data is allready exists");
	    freeAll(&head,free_char);
	    return 1;
	}
     }  
     printAll(head, tail, prnt_char);

     printf("\nEnter an element for deleting\n");
     scanf(" %c",&ch);
     res=deleteNode(&head,&tail,&ch,cmp_char,free_char);
     if(FALSE==res)   
        printf("%c don't exists in list\n",ch);

     printAll(head,tail,prnt_char);
	 
     freeAll(&head,free_char);
     printf("\nYour list was destroyed\n");
	 _getch();
     return 0;
}
  
