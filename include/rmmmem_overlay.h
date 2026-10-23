#ifndef RMMMEM_OVERLAY_H
#define RMMMEM_OVERLAY_H

#include "common.h"

#define RMMMEM_HEAP_BASE ((void *)0x01D98380)
#define RMMMEM_HEAP_SIZE 0x000FE000
#define RMMMEM_HEAP_MAX  ((void *)0x01E96380)

typedef struct RmmBlock {
    struct RmmBlock *next;
    unsigned int size;
} RmmBlock;

/* Function Prototypes */
void rmmmem_func_01D98000(void);                                 /* rmm_heap_init */
void *rmmmem_func_01D98050(unsigned int size);                    /* rmm_alloc */
void *rmmmem_func_01D980FC(unsigned int count, unsigned int sz); /* rmm_calloc */
void rmmmem_func_01D98150(void *ptr);                             /* rmm_free */
void rmmmem_func_01D98284(void);                                 /* rmm_stub */

#endif /* RMMMEM_OVERLAY_H */
