#include "rmmmem_overlay.h"

/* External CRT memset provided by game binary */
void func_00117CAC(void *ptr, int val, int size);

/* Circular free list head pointer for Random Map heap allocator */
static RmmBlock *s_free_list = NULL;

/*
 * rmmmem_func_01D98000 (rmm_heap_init):
 * Clears the 1 MB heap at 0x01DA8380 and initializes the circular free list.
 */
void rmmmem_func_01D98000(void) {
    func_00117CAC(RMMMEM_HEAP_BASE, 0, RMMMEM_HEAP_SIZE);
    s_free_list = (RmmBlock *)RMMMEM_HEAP_BASE;
    s_free_list->size = RMMMEM_HEAP_SIZE;
    s_free_list->next = s_free_list;
}

/*
 * rmmmem_func_01D98050 (rmm_alloc):
 * Traverses circular free list and allocates memory aligned to 4 bytes.
 * If block is larger than needed + sizeof(RmmBlock), splits block from tail.
 */
void *rmmmem_func_01D98050(unsigned int size) {
    unsigned int total_size;
    RmmBlock *curr;
    RmmBlock *prev;
    RmmBlock *start;
    RmmBlock *allocated;
    RmmBlock *next;

    if (s_free_list == NULL) {
        return NULL;
    }

    total_size = ((size + 3) & ~3) + sizeof(RmmBlock);
    start = s_free_list;
    prev = s_free_list;
    curr = s_free_list->next;

    while (1) {
        if (curr->size >= total_size) {
            if (curr->size > total_size + sizeof(RmmBlock)) {
                curr->size -= total_size;
                allocated = (RmmBlock *)((char *)curr + curr->size);
                allocated->size = total_size;
                return (void *)((char *)allocated + sizeof(RmmBlock));
            } else {
                next = curr->next;
                if (next == curr) {
                    s_free_list = NULL;
                    curr->next = NULL;
                } else {
                    prev->next = next;
                }
                return (void *)((char *)curr + sizeof(RmmBlock));
            }
        }

        if (curr == start) {
            return NULL;
        }
        prev = curr;
        curr = curr->next;
    }
}

/*
 * rmmmem_func_01D980FC (rmm_calloc):
 * Allocates count * sz bytes and zeros the allocated memory.
 */
void *rmmmem_func_01D980FC(unsigned int count, unsigned int sz) {
    unsigned int total;
    void *ptr;

    total = count * sz;
    ptr = rmmmem_func_01D98050(total);
    if (ptr != NULL) {
        func_00117CAC(ptr, 0, total);
    }
    return ptr;
}

/*
 * rmmmem_func_01D98150 (rmm_free):
 * Verifies pointer bounds [0x01DA8380, 0x01E96380], returns block to circular
 * free list and coalesces with adjacent left/right free blocks.
 */
void rmmmem_func_01D98150(void *ptr) {
    RmmBlock *block;
    RmmBlock *curr;
    RmmBlock *prev;

    if (ptr == NULL) {
        return;
    }

    block = (RmmBlock *)((char *)ptr - sizeof(RmmBlock));
    if ((void *)block < RMMMEM_HEAP_BASE || (void *)block > RMMMEM_HEAP_MAX) {
        return;
    }

    prev = s_free_list;
    curr = s_free_list->next;

    if (prev == curr) {
        /* Single block currently in free list */
        if ((char *)block + block->size == (char *)prev) {
            block->size += prev->size;
            block->next = block;
            s_free_list = block;
            return;
        }
        if ((char *)prev + prev->size == (char *)block) {
            prev->size += block->size;
            return;
        }
        prev->next = block;
        block->next = prev;
        return;
    }

    /* Multiple blocks in circular free list: locate insertion point */
    while (curr != s_free_list) {
        if (curr >= (RmmBlock *)((char *)block + block->size)) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    /* Coalesce with right neighbor */
    if (curr == (RmmBlock *)((char *)block + block->size)) {
        block->size += curr->size;
        block->next = curr->next;
        prev->next = block;
    } else {
        block->next = curr;
        prev->next = block;
    }

    /* Coalesce with left neighbor */
    if (block == (RmmBlock *)((char *)prev + prev->size)) {
        prev->size += block->size;
        prev->next = block->next;
    }
}

/*
 * rmmmem_func_01D98284:
 * Section padding / alignment function.
 * In the original RMMMEMCD.BIN overlay binary (offset 0x284, 124 bytes),
 * this routine consists of 31 consecutive 0x00000000 (nop) words emitted
 * by the PS2 linker to align the overlay payload to sector boundary.
 */
void rmmmem_func_01D98284(void) {
}
