#ifndef _CMALLOC_H
#define _CMALLOC_H

typedef struct __POOL_LIST {
    char *start;
    struct __POOL_LIST *link;
} plist;

typedef struct __POOL {
    char *next;
    char *end;
    size_t size;
    int count;
    struct __POOL_LIST *mlist;
} pool;

pool *pool_init(size_t size);
void pool_destroy(pool *p);
size_t pool_available(pool *p);
void *cmalloc(pool *p, size_t size);
void pool_allocate(pool *p);

#endif
