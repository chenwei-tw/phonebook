#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 1031

#include "cmalloc.h"

// #define OPT 1

typedef struct __PHONE_BOOK_ENTRY_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY_DETAIL *pDetail;
} entry;

typedef struct __HASH_ITEM {
    struct __PHONE_BOOK_ENTRY slot[2];
    struct __HASH_ITEM *hNext;
} hitem;

int init_hash(hitem **table, int size, pool *p);
int hash_function(char *str);
entry *findName(char lastName[], hitem *table);
void append(char lastName[], int str, hitem *table, pool *p);

#endif
