#include <cassert>
#include <cstring>
#include "zone_spatial_grid_node_pool_setup.h"
#include "zone_spatial_grid_node_pool_destructor.h"
#include "zone_spatial_grid_node_pool_clear.h"

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;
static int g_func_117CAC_called = 0;

struct NodePool {
    char pad[0x138840];
};

extern "C" {
void func_100670(void *ptr) {
    g_func_100670_called++;
    g_last_deleted_ptr = ptr;
}

void *func_118DE0(int size) {
    return (void *)0xCAFE;
}

void func_1F20E0(NodePool *self) {}
void func_1F21E0(NodePool *self) {}

void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_called++;
    memset(dst, val, size);
}
}

int main() {
    // Test 1: func_001F1ED0 - node pool setup
    NodePool *pool = new NodePool();
    memset(pool, 0, sizeof(NodePool));
    int res = func_001F1ED0(pool, (void *)0x1234, 10000);
    assert(res == 1);

    // Test 2: func_001F1FD0 - deleting destructor
    g_func_100670_called = 0;
    void *obj = (void *)0xBEEF;
    void *r1 = func_001F1FD0(obj, 1);
    assert(r1 == obj);
    assert(g_func_100670_called == 1);
    assert(g_last_deleted_ptr == obj);

    // Test 3: func_001F2010 - clear pool
    func_001F2010(pool);

    delete pool;
    return 0;
}
