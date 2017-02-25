#ifndef _CMALLOC_H
#define _CMALLOC_H

typedef struct __POOL {
    char *next;
    char *end;
    size_t size;
} pool;

pool *pool_init(size_t size);
void pool_destroy(pool *p);
size_t pool_available(pool *p);
void *cmalloc(pool *p, size_t size);

#endif
