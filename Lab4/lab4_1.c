#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 256
typedef struct Book
	{
	char bookcode[ 11 ];
	char *bookname;
	}Book;

typedef struct Library
	{
	char libraryname[ MAX ];
	int bookamount;
	Book *bookarr;
	} Library;

void Get_Lost(char* str);
void input_book(Book* B,FILE *in);
void input_library(Library *L,FILE *in);
void output_book(Book* B,FILE *out);
void output_library(Library* L,FILE *out);

int main()
{
	FILE *in,*out;
	Library Libr;
	int i;
	in = fopen("input.txt", "r");
	if(in == NULL) Get_Lost("their is no file name like this");
	input_library(&Libr,in);
	fclose(in);
	out = fopen("ouput.txt", "w");
	output_library(&Libr,out);
	fclose(out);
	for(i = 0; i < Libr.bookamount; i++) free((Libr.bookarr + i)->bookname);
	free(Libr.bookarr);
    return 0;
}

void Get_Lost(char* str)
{
	printf("\n%s",str);
        exit(1);
}

void input_book(Book* B, FILE *in)
	{
	int i;
	char buffer[MAX];
	fscanf(in, "%s",B->bookcode);
	fscanf(in, "%s",buffer);
	B->bookname = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
	if(B->bookname == NULL) Get_Lost("No memory for the book name");
	strcpy(B->bookname, buffer);
	}

void input_library(Library *L, FILE *in)
	{
	int i;
	fscanf(in, "%s", L->libraryname);
	fscanf(in, "%d", &L->bookamount);
	L->bookarr = (Book *)malloc(sizeof(Book) * L->bookamount);
	if(L->bookarr == NULL) Get_Lost("No memory for creating book arr");
	for(i = 0; i < L->bookamount; ++i) input_book((L->bookarr + i), in);
	}

void output_book(Book* B, FILE *out)
	{
	fprintf(out, "%s\t%s\n", B->bookcode, B->bookname);
	}

void output_library(Library* L, FILE *out)
	{
	int i;
	fprintf(out, "%s\n", L->libraryname);
	for(i = 0; i < L->bookamount; ++i) output_book(L->bookarr + i, out);
	}