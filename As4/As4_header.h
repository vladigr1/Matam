#ifndef _HEADER
#define _HEADER

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 255

//necessary define
typedef enum{SMALLER = -1,EQUAL, BIGGER} RESULT_CMP;
typedef void* DATA;
typedef struct TreeManager *PTManager;


//function type
typedef RESULT_CMP(*COMPARE_KEYS)(DATA, DATA);	//return BIIGER : key1 > key2. EQUAL:key1 = key2. SMALLER: key1 < key2.
typedef void(*PRINT_KEY)(DATA);
typedef void(*DEL_KEY)(DATA);


//public interface
PTManager InitManager(COMPARE_KEYS, PRINT_KEY, DEL_KEY);
void AddNode(PTManager manager, DATA key);
void PrintInorder(PTManager manager);
int HightKey(PTManager manager, DATA key);		//return -2 if failed
void HighestKey(PTManager manager);
void PrintKHighest(PTManager manager, int k);
void FreeFullTree(PTManager manager);


#endif

