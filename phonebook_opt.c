#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *table)
{
    int key = hash_function(lastName);
    entry *current = &table[key];

    while (current != NULL) {
        if (strcasecmp(lastName, current->lastName) == 0)
            return current;
        current = current->pNext;
    }
    return NULL;
}

void append(char lastName[], int str, entry *table, pool *p)
{
    /* allocate memory for the new entry and put lastName
     * into the right location */
    int key = str % HASH_TABLE_SIZE;

    if(table[key].lastName[0] == '\0')
        strcpy(table[key].lastName, lastName);
    else {
        entry *tmp = table[key].pNext;
        table[key].pNext = (entry *) cmalloc(p, sizeof(entry));
        strcpy(table[key].pNext->lastName, lastName);
        table[key].pNext->pDetail = NULL;
        table[key].pNext->pNext = tmp;
    }
}

int init_hash(entry **table, int size, pool *p)
{
    if(NULL == (*table = (entry *) cmalloc(p, sizeof(entry) * size))) return -1;

    for(int i = 0; i < size; i++) {
        (*table)[i].lastName[0] = '\0';
        (*table)[i].pDetail = NULL;
        (*table)[i].pNext = NULL;
    }

    return 1;
}

int hash_function(char *str)
{
    int value = 0;

    while(*str)
        value += *str++;

    return value %= HASH_TABLE_SIZE;
}
