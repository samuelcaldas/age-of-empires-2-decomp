#include <cassert>
#include <cstdlib>
#include <cstring>

struct AspPool {
    char nodes[120000];
    void *freelist;
};

static int g_overflow_called = 0;
extern "C" {
void func_00117CAC(void *dest, int val, int size) {
    memset(dest, val, size);
}
void func_118de0(const char *msg) {
    (void)msg;
    g_overflow_called++;
}

void func_00183150(AspPool *pool);
void *func_001831b0(AspPool *pool);
void func_00183210(AspPool *pool, void *item);
}

static void test_pool_init_alloc_free() {
    AspPool pool;
    func_00183150(&pool);
    assert(pool.freelist == &pool);

    void *item1 = func_001831b0(&pool);
    assert(item1 == &pool);
    assert(pool.freelist == (char *)&pool + 12);

    void *item2 = func_001831b0(&pool);
    assert(item2 == (char *)&pool + 12);
    assert(pool.freelist == (char *)&pool + 24);

    func_00183210(&pool, item1);
    assert(pool.freelist == item1);
    assert(*(void **)((char *)item1 + 4) == (char *)&pool + 24);
}

static void test_pool_overflow() {
    AspPool pool;
    pool.freelist = 0;
    g_overflow_called = 0;
    void *res = func_001831b0(&pool);
    assert(res == 0);
    assert(g_overflow_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_pool_init_alloc_free();
    else if (c == 1) test_pool_overflow();
    else return 1;
    return 0;
}
