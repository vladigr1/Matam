/*------------database.h-----------------*/

#ifndef _DATABASE_H_
#define _DATABASE_H_

/* Some necessary type definitions */
typedef struct  DATA_BASE* PDATA_BASE;
typedef void* PKEY;
typedef void* PELEMENT;
typedef enum  BOOL { FALSE = 0, TRUE } BOOL;

/* Function types */
typedef PKEY(*GET_KEY)(PELEMENT);
typedef void(*DEL_ELEMENT)(PELEMENT);
typedef BOOL(*COMPARE_KEYS)(PKEY, PKEY);
typedef void(*PRINT_ELEMENT)(PELEMENT);

/* Interface functions */
PDATA_BASE CreateDB(GET_KEY, DEL_ELEMENT, COMPARE_KEYS, PRINT_ELEMENT);
BOOL       AddDB(PDATA_BASE, PELEMENT);
PELEMENT   GetDB(PDATA_BASE, PKEY);
BOOL       RemoveDB(PDATA_BASE, PKEY);
void       PrintDB(PDATA_BASE);
void       DeleteDB(PDATA_BASE);

#endif _DATABASE_H_

