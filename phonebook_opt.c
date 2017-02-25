#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], hitem *table)
{
    int key = hash_function(lastName);
    hitem *current = table[key].hNext;

    while (current != NULL) {
        if (strcasecmp(lastName, current->slot[0].lastName) == 0)
            return &current->slot[0];
        if (strcasecmp(lastName, current->slot[1].lastName) == 0)
            return &current->slot[1];
        current = current->hNext;
    }
    return NULL;
}

void append(char lastName[], int str, hitem *table, pool **p)
{
    int key = str % HASH_TABLE_SIZE;

    if (table[key].hNext && table[key].hNext->slot[1].lastName[0] == '\0') {
        strcpy(table[key].hNext->slot[1].lastName, lastName);
    } else {
        hitem *tmp = table[key].hNext;
        table[key].hNext = (hitem *) cmalloc(p[key], sizeof(hitem));
        strcpy(table[key].hNext->slot[0].lastName, lastName);
        table[key].hNext->slot[0].pDetail = NULL;
        table[key].hNext->slot[1].pDetail = NULL;
        table[key].hNext->slot[1].lastName[0] = '\0';
        table[key].hNext->hNext = tmp;
    }
}

int init_hash(hitem **table, int size)
{
    if (NULL == (*table = (hitem *) malloc(sizeof(hitem) * size))) return -1;

    for (int i = 0; i < size; i++)
        (*table)[i].hNext = NULL;

    return 1;
}

int hash_function(char *str)
{
    int value = 0;

    while (*str)
        value += *str++;

    return value %= HASH_TABLE_SIZE;
}
