#pragma exceptions off
#include "trade_action_stream_pool.h"

extern "C" {
void func_117CAC(void *dest, int val, int size);
void func_118de0(const char *msg);
extern const char D_491970[];

void func_00183150(AspPool *pool) {
    func_117CAC(pool, 0, sizeof(pool->nodes));
    pool->freelist = pool;
    char *cur = (char *)pool;
    for (int i = 0; i < 9999; cur += 12) {
        char *next = cur + 12;
        *(void **)(cur + 4) = next;
        i++;
    }
}

void *func_001831B0(AspPool *pool) {
    void *item = pool->freelist;
    if (item != 0) {
        pool->freelist = *(void **)((char *)item + 4);
    }
    if (item == 0) {
        func_118de0(D_491970);
    }
    return item;
}

void func_00183210(AspPool *pool, void *item) {
    if (item != 0) {
        *(void **)((char *)item + 4) = pool->freelist;
        pool->freelist = item;
    }
}
}
