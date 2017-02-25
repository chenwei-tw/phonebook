#include <stdlib.h>
#include <stdio.h>

#include "cmalloc.h"

pool *pool_init(size_t size)
{
    pool *p = (pool *) malloc(size + sizeof(pool));
    p->next = (char *) &p[1];
    p->end = p->next + size;
    p->size = size;

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

void *cmalloc(pool *p, size_t size)
{
    if(pool_available(p) < size) {
        printf("pool is not available\n");
        return NULL;
    }

    void *mem = (void *) p->next;
    p->next += size;

    return mem;
}
