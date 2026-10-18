#include <cassert>
#include <cstring>
#include "zone_spatial_grid_node_pool_setup.h"
#include "zone_spatial_grid_node_pool_destructor.h"
#include "zone_spatial_grid_node_pool_clear.h"

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;
static int g_func_117CAC_called = 0;

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
    // -------------------------------------------------------------
    // Test 1: func_001F1FD0 - deleting destructor (100% exact match)
    // -------------------------------------------------------------
    g_func_100670_called = 0;
    void *obj = (void *)0xBEEF;

    // With flag <= 0: no delete
    void *r1 = func_001F1FD0(obj, 0);
    assert(r1 == obj);
    assert(g_func_100670_called == 0);

    // With flag > 0: deletes
    void *r2 = func_001F1FD0(obj, 1);
    assert(r2 == obj);
    assert(g_func_100670_called == 1);
    assert(g_last_deleted_ptr == obj);

    // When self is NULL: does not delete
    void *r3 = func_001F1FD0(0, 1);
    assert(r3 == 0);

    return 0;
}
