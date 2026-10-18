#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_add_zone.h"

static int g_logger_called = 0;
static std::string g_logger_fmt = "";
static std::string g_logger_file = "";
static int g_logger_line = 0;
static int g_logger_max_zones = 0;

static int g_memset_called = 0;
static void *g_last_memset_dst = 0;
static int g_last_memset_size = 0;

struct StrictNodePool {
    char pad_00[0x10];
    char buffer_10[0x138800];
    void **table_138810;
    void **table_138814;
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
    g_last_memset_dst = dst;
    g_last_memset_size = size;
    if (dst != 0 && size > 0) {
        memset(dst, val, size);
    }
    return dst;
}

void *func_118de0(const char *format, const char *file, int line, int max_zones) {
    g_logger_called++;
    g_logger_fmt = format ? format : "";
    g_logger_file = file ? file : "";
    g_logger_line = line;
    g_logger_max_zones = max_zones;
    return (void *)0xCAFE;
}
}

int main() {
    // ABI verification
    assert(sizeof(StrictNodePool) >= 0x138838);
    assert(offsetof(StrictNodePool, buffer_10) == 0x10);
    assert(offsetof(StrictNodePool, table_138810) == 0x138810);
    assert(offsetof(StrictNodePool, table_138814) == 0x138814);
    assert(offsetof(StrictNodePool, count_138818) == 0x138818);
    assert(offsetof(StrictNodePool, field_13881C) == 0x13881C);
    assert(offsetof(StrictNodePool, field_138824) == 0x138824);
    assert(offsetof(StrictNodePool, field_138828) == 0x138828);
    assert(offsetof(StrictNodePool, field_13882C) == 0x13882C);
    assert(offsetof(StrictNodePool, field_138830) == 0x138830);

    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    void *tables0[10];
    void *tables1[10];
    memset(tables0, 0, sizeof(tables0));
    memset(tables1, 0, sizeof(tables1));
    pool->table_138810 = tables0;
    pool->table_138814 = tables1;
    pool->count_138818 = 0;
    pool->field_13881C = 5;
    pool->field_138824 = -1;
    pool->field_138828 = -1;
    pool->field_13882C = 0;
    pool->field_138830 = 0;

    // Case 1: First zone addition (count < field_13881C)
    g_memset_called = 0;
    g_logger_called = 0;
    func_001F21E0((NodePool *)pool, 100);

    assert(pool->count_138818 == 1);
    assert(tables1[0] == (void *)100);
    assert(tables0[0] == (void *)pool->buffer_10);
    assert(pool->field_13882C == 100);
    assert(pool->field_138830 == 100);
    assert(pool->field_138824 == 0);
    assert(pool->field_138828 == 0);
    assert(g_memset_called == 1);
    assert(g_last_memset_dst == (void *)pool->buffer_10);
    assert(g_last_memset_size == 0x138800);
    assert(g_logger_called == 0);

    // Case 2: Second zone addition (head index field_138824 preserved)
    func_001F21E0((NodePool *)pool, 50);
    assert(pool->count_138818 == 2);
    assert(tables1[1] == (void *)50);
    assert(tables0[1] == (void *)pool->buffer_10);
    assert(pool->field_13882C == 150);
    assert(pool->field_138830 == 150);
    assert(pool->field_138824 == 0);
    assert(pool->field_138828 == 0);
    assert(g_logger_called == 0);

    // Case 3: Used_Zones == Max_Zones warning
    pool->count_138818 = 5;
    pool->field_13881C = 5;
    g_logger_called = 0;
    g_logger_fmt = "";

    func_001F21E0((NodePool *)pool, 25);
    assert(pool->count_138818 == 6);
    assert(g_logger_called == 1);
    assert(g_logger_fmt == "%s(%d) Used_Zones == Max_Zones(%d)\n");
    assert(g_logger_file == "obmanager.cpp");
    assert(g_logger_line == 0x1481);
    assert(g_logger_max_zones == 5);

    delete pool;
    return 0;
}
