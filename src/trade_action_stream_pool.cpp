#pragma exceptions off

extern "C" {
void func_00117CAC(void *dest, int val, int size);
void func_118de0(const char *msg);

struct AspPool {
    char nodes[120000];
    void *freelist;
};

void func_00183150(AspPool *pool) {
    func_00117CAC(pool, 0, sizeof(pool->nodes));
    pool->freelist = pool;
    char *cur = (char *)pool;
    for (int i = 0; i < 9999; i++) {
        char *next = cur + 12;
        *(void **)(cur + 4) = next;
        cur += 12;
    }
}

void *func_001831b0(AspPool *pool) {
    void *item = pool->freelist;
    if (item != 0) {
        pool->freelist = *(void **)((char *)item + 4);
    }
    if (item == 0) {
        func_118de0((const char *)0x491970);
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
