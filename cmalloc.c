#include <stdlib.h>
#include <stdio.h>

#include "cmalloc.h"

pool *pool_init(size_t size)
{
    pool *p = (pool *) malloc(sizeof(pool) + size);
    p->next = (char *) &p[1];
    p->end = p->next + size;
    p->size = size;
    p->count = 1;
    p->mlist = (plist *) malloc(sizeof(plist));
    p->mlist->start = p->next;
    p->mlist->link = NULL;

    return p;
}

void pool_destroy(pool *p)
{
    free(p);
}

size_t pool_available(pool *p)
{
    return p->end - p->next;
}

void pool_allocate(pool *p)
{
    plist *current = p->mlist;

    while (current->link)
        current = current->link;

    current->link = (plist *) malloc(sizeof(plist));
    current->link->link = NULL;
    p->next = current->link->start = (char *) malloc(p->size);
    p->end = p->next + p->size;
    p->count++;
}

void *cmalloc(pool *p, size_t size)
{
    if(pool_available(p) < size) {
        pool_allocate(p);
    }

    void *mem = (void *) p->next;
    p->next += size;

    return mem;
}
