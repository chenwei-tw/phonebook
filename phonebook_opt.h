#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 1031

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
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

int init_hash(entry **table, int size);
int hash_function(char *str);
entry *findName(char lastName[], entry *table);
void append(char lastName[], int str, entry *table);

#endif
