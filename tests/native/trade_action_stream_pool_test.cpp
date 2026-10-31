#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "trade_action_stream_pool.h"

static int g_memset_called = 0;
static const char *g_last_error = 0;

extern "C" {
void func_117CAC(void *dest, int val, int size) {
    g_memset_called++;
    memset(dest, val, size);
}

void func_118de0(const char *msg) {
    g_last_error = msg;
}

extern const char D_491970[] = "ASP pool exhausted\n";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_num = atoi(argv[1]);

    if (case_num == 0) {
        AspPool *pool = (AspPool *)malloc(sizeof(AspPool));
        assert(pool != 0);
        g_memset_called = 0;
        func_00183150(pool);
        assert(g_memset_called == 1);
        assert(pool->freelist == (void *)pool);
        char *node0 = (char *)pool;
        char *node1 = *(char **)(node0 + 4);
        assert(node1 == node0 + 12);
        char *node2 = *(char **)(node1 + 4);
        assert(node2 == node0 + 24);
        free(pool);
        return 0;
    }

    if (case_num == 1) {
        AspPool *pool = (AspPool *)malloc(sizeof(AspPool));
        assert(pool != 0);
        func_00183150(pool);
        void *first = func_001831B0(pool);
        assert(first == (void *)pool);
        assert(pool->freelist == (char *)pool + 12);

        void *second = func_001831B0(pool);
        assert(second == (char *)pool + 12);
        assert(pool->freelist == (char *)pool + 24);

        pool->freelist = 0;
        g_last_error = 0;
        void *null_item = func_001831B0(pool);
        assert(null_item == 0);
        assert(g_last_error == D_491970);

        free(pool);
        return 0;
    }

    if (case_num == 2) {
        AspPool *pool = (AspPool *)malloc(sizeof(AspPool));
        assert(pool != 0);
        func_00183150(pool);

        void *a = func_001831B0(pool);
        void *b = func_001831B0(pool);
        assert(a != 0 && b != 0);

        // Free a
        func_00183210(pool, a);
        assert(pool->freelist == a);
        assert(*(void **)((char *)a + 4) == (char *)pool + 24);

        // Free b
        func_00183210(pool, b);
        assert(pool->freelist == b);
        assert(*(void **)((char *)b + 4) == a);

        // Free null should be no-op
        func_00183210(pool, 0);
        assert(pool->freelist == b);

        free(pool);
        return 0;
    }

    return 2;
}
