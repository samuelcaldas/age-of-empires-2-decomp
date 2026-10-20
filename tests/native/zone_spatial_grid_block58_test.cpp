#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_expand.h"

struct HelperCallRecord {
    std::string name;
    void *ptr;
    int int_arg;
};

static int g_logger_called = 0;
static std::string g_logger_fmt = "";
static std::string g_logger_file = "";
static int g_logger_line = 0;
static int g_logger_max_val = 0;

static int g_memset_called = 0;

struct StrictNodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void *table_138814;
    int count_138818;
    int field_13881C;
    int field_138820;
    int field_138824;
    int field_138828;
    int field_13882C;
    int field_138830;
    int capacity_138834;
};

extern "C" {
void *func_117CAC(void *dst, int val, int size) {
    g_memset_called++;
    if (dst != 0 && size > 0) {
        memset(dst, val, size);
    }
    return dst;
}

void *func_118de0(const char *format, const char *file, int line, int max_val) {
    g_logger_called++;
    g_logger_fmt = format ? format : "";
    g_logger_file = file ? file : "";
    g_logger_line = line;
    g_logger_max_val = max_val;
    return (void *)0xCAFE;
}
}

int main() {
    // Compile-time & runtime ABI checks
    assert(sizeof(StrictNodePool) >= 0x138838);
    assert(offsetof(StrictNodePool, buffer_10) == 0x10);
    assert(offsetof(StrictNodePool, table_138810) == 0x138810);
    assert(offsetof(StrictNodePool, table_138814) == 0x138814);
    assert(offsetof(StrictNodePool, count_138818) == 0x138818);
    assert(offsetof(StrictNodePool, field_13881C) == 0x13881C);
    assert(offsetof(StrictNodePool, capacity_138834) == 0x138834);

    // Case 1: new_cap < field_13881C -> No-op
    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));
    pool->field_13881C = 10;
    pool->table_138810 = (void **)0x1234;
    pool->table_138814 = (void *)0x5678;

    g_memset_called = 0;
    g_logger_called = 0;
    func_001F20E0((NodePool *)pool, 5);

    assert(pool->field_13881C == 10);
    assert(pool->table_138810 == (void **)0x1234);
    assert(pool->table_138814 == (void *)0x5678);
    assert(g_memset_called == 0);
    assert(g_logger_called == 0);

    // Case 2: new_cap >= field_13881C with initial table_138810 == 0 -> Expand without error log
    pool->field_13881C = 1;
    pool->table_138810 = 0;
    pool->table_138814 = 0;

    g_memset_called = 0;
    g_logger_called = 0;
    func_001F20E0((NodePool *)pool, 2);

    assert(pool->field_13881C == 2);
    assert(pool->table_138810 == (void **)pool);
    assert(pool->table_138814 == (void *)((char *)pool + 8));
    assert(((void **)pool)[0] == 0);
    assert(((void **)pool)[1] == 0);
    assert(((void **)((char *)pool + 8))[0] == 0);
    assert(((void **)((char *)pool + 8))[1] == 0);
    assert(g_logger_called == 0);

    // Case 3: new_cap >= field_13881C with initial table_138810 != 0 -> Expand WITH error log
    g_logger_called = 0;
    g_logger_fmt = "";
    func_001F20E0((NodePool *)pool, 4);

    assert(pool->field_13881C == 4);
    assert(g_logger_called == 1);
    assert(g_logger_fmt == "!!!err!!!(%s,%d)Zone_Ptrs > PS2_MAX_ZONE_SIZE_M(=%d)\n");
    assert(g_logger_file == "obmanager.cpp");
    assert(g_logger_line == 0x145F);
    assert(g_logger_max_val == 10000);

    delete pool;
    return 0;
}
