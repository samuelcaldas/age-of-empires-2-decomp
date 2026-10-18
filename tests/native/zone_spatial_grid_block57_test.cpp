#include <cassert>
#include <cstring>
#include "zone_spatial_grid_node_pool_setup.h"
#include "zone_spatial_grid_node_pool_destructor.h"
#include "zone_spatial_grid_node_pool_clear.h"

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;
static int g_func_117CAC_called = 0;
static int g_func_1F20E0_called = 0;
static int g_func_1F21E0_called = 0;
static int g_last_1F20E0_val = 0;
static void *g_last_1F21E0_arg = 0;

struct StrictNodePool {
    char pad_00[0x138810];
    int field_138810;
    int field_138814;
    int field_138818;
    int field_13881C;
    int field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" {
void func_100670(void *ptr) {
    g_func_100670_called++;
    g_last_deleted_ptr = ptr;
}

void *func_118DE0(int file, int msg, int line) {
    return (void *)0xCAFE;
}

void func_1F20E0(NodePool *self, int val) {
    g_func_1F20E0_called++;
    g_last_1F20E0_val = val;
}

void func_1F21E0(NodePool *self, void *p1) {
    g_func_1F21E0_called++;
    g_last_1F21E0_arg = p1;
}

void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_called++;
    memset(dst, val, size);
}
}

int main() {
    // Test 1: func_001F1ED0 / func_001F1EE0 - node pool setup & exact offsets
    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    int res = func_001F1ED0((NodePool *)pool, (void *)0x5678, 5000);
    assert(res == 1);
    assert(pool->field_138810 == 0);
    assert(pool->field_138814 == 0);
    assert(pool->field_138818 == 0);
    assert(pool->field_13881C == 1);
    assert(pool->field_138820 == 0);
    assert(pool->field_138824 == -1);
    assert(pool->field_138828 == -1);
    assert(pool->field_13882C == 0);
    assert(pool->field_138830 == 0);
    assert(pool->capacity_138834 == 5000);
    assert(g_func_1F20E0_called == 1);
    assert(g_last_1F20E0_val == 1);
    assert(g_func_1F21E0_called == 1);
    assert(g_last_1F21E0_arg == (void *)0x5678);

    // Test 2: func_001F1FD0 - deleting destructor
    g_func_100670_called = 0;
    void *obj = (void *)0xBEEF;
    void *r1 = func_001F1FD0(obj, 1);
    assert(r1 == obj);
    assert(g_func_100670_called == 1);
    assert(g_last_deleted_ptr == obj);

    // Test 3: func_001F2010 / func_001F2020 - clear pool
    g_func_117CAC_called = 0;
    func_001F2010((NodePool *)pool);
    assert(g_func_117CAC_called > 0);

    delete pool;
    return 0;
}
