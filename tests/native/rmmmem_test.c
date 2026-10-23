#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#include "rmmmem_overlay.h"

/* Mock CRT memset as used by PS2 binary (func_00117CAC) */
void func_00117CAC(void *ptr, int val, int size) {
    memset(ptr, val, size);
}

static void setup_guest_heap_memory(void) {
    /* Map 2MB starting at 0x01D90000 so RMMMEM_HEAP_BASE (0x01D98380) is valid writable RAM */
    void *addr = mmap((void *)0x01D90000, 0x00200000,
                      PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                      -1, 0);
    assert(addr == (void *)0x01D90000);
}

static void test_heap_init(void) {
    RmmBlock *head;

    rmmmem_func_01D98000();

    head = (RmmBlock *)RMMMEM_HEAP_BASE;
    assert(head->size == RMMMEM_HEAP_SIZE);
    assert(head->next == head);
}

static void test_alloc_and_free(void) {
    void *p1;
    void *p2;
    void *p3;

    rmmmem_func_01D98000();

    /* Allocate 64 bytes */
    p1 = rmmmem_func_01D98050(64);
    assert(p1 != NULL);
    assert(p1 > RMMMEM_HEAP_BASE);
    assert((char *)p1 < (char *)RMMMEM_HEAP_BASE + RMMMEM_HEAP_SIZE);

    /* Allocate 128 bytes */
    p2 = rmmmem_func_01D98050(128);
    assert(p2 != NULL);
    assert(p2 != p1);

    /* Write data to ensure memory is usable */
    memset(p1, 0xAA, 64);
    memset(p2, 0xBB, 128);

    /* Free p2, then p1 */
    rmmmem_func_01D98150(p2);
    rmmmem_func_01D98150(p1);

    /* Reallocate full heap: should succeed now that both blocks are coalesced back */
    p3 = rmmmem_func_01D98050(RMMMEM_HEAP_SIZE - sizeof(RmmBlock) - 16);
    assert(p3 != NULL);

    rmmmem_func_01D98150(p3);
}

static void test_calloc(void) {
    unsigned char *p;
    unsigned int i;
    unsigned int count = 20;
    unsigned int elem_sz = 16;

    rmmmem_func_01D98000();

    p = (unsigned char *)rmmmem_func_01D980FC(count, elem_sz);
    assert(p != NULL);

    /* Verify memory is zeroed */
    for (i = 0; i < count * elem_sz; i++) {
        assert(p[i] == 0);
    }

    rmmmem_func_01D98150(p);
}

static void test_bounds_rejection(void) {
    rmmmem_func_01D98000();

    /* Pointers outside the valid heap range must be silently rejected */
    rmmmem_func_01D98150((void *)0x01000000);
    rmmmem_func_01D98150((void *)0x02000000);
    rmmmem_func_01D98150(NULL);

    /* Oversized allocation must return NULL */
    assert(rmmmem_func_01D98050(0x00200000) == NULL);
}

static void test_stub(void) {
    /* Should execute cleanly */
    rmmmem_func_01D98284();
}

int main(void) {
    setup_guest_heap_memory();

    test_heap_init();
    test_alloc_and_free();
    test_calloc();
    test_bounds_rejection();
    test_stub();

    printf("All native rmmmem tests passed successfully.\n");
    return 0;
}
