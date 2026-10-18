#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_setup.h"
#include "zone_spatial_grid_node_pool_destructor.h"
#include "zone_spatial_grid_node_pool_clear.h"

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;
static std::vector<std::string> g_call_order;

static int g_logger_called = 0;
static const char *g_logger_fmt = 0;
static const char *g_logger_file = 0;
static int g_logger_line = 0;

static int g_clear_calls = 0;
static void *g_last_clear_dst = 0;
static int g_last_clear_size = 0;

struct StrictNodePool {
    char pad_00[0x138810];
    void **table_138810;
    void *table_138814;
    int count_138818;
    int flag_13881C;
    int field_138820;
    char pad_after[0x138834 - 0x138824];
    int capacity_138834;
};

extern "C" {
void func_100670(void *ptr) {
    g_func_100670_called++;
    g_last_deleted_ptr = ptr;
}

void *func_118DE0(int format, int file, int line) {
    g_logger_called++;
    g_logger_fmt = (const char *)(long)format;
    g_logger_file = (const char *)(long)file;
    g_logger_line = line;
    return (void *)0xCAFE;
}

void func_1F20E0(NodePool *self, int val) {
    g_call_order.push_back("func_1F20E0");
}

void func_1F21E0(NodePool *self, void *p1) {
    g_call_order.push_back("func_1F21E0");
}

void func_117CAC(void *dst, int val, int size) {
    g_clear_calls++;
    g_last_clear_dst = dst;
    g_last_clear_size = size;
    memset(dst, val, size);
}
}

struct NodePool {
    char pad[0x138850];
};

int main() {
    // Test 1: func_001F1ED0 - node pool setup, offsets, helper order, and strict logger check
    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    g_call_order.clear();
    int res = func_001F1ED0((NodePool *)pool, (void *)0x5678, 5000);
    assert(res == 1);
    assert(pool->count_138818 == 0);
    assert(pool->flag_13881C == 1);
    assert(pool->capacity_138834 == 5000);

    // Verify logger arguments: format, file, line
    assert(g_logger_called == 1);
    assert(g_logger_fmt != 0 && std::string(g_logger_fmt).find("SonftOb_ArrayList") != std::string::npos);
    assert(g_logger_file != 0 && std::string(g_logger_file) == "obmanager.cpp");
    assert(g_logger_line == 0x13D6);

    // Verify helper call order: func_1F20E0 then func_1F21E0
    assert(g_call_order.size() == 2);
    assert(g_call_order[0] == "func_1F20E0");
    assert(g_call_order[1] == "func_1F21E0");

    // Test 2: func_001F1FD0 - deleting destructor
    g_func_100670_called = 0;
    void *obj = (void *)0xBEEF;
    void *r1 = func_001F1FD0(obj, 1);
    assert(r1 == obj);
    assert(g_func_100670_called == 1);
    assert(g_last_deleted_ptr == obj);

    // Test 3: func_001F2010 - clear pool with non-null entry table entries
    void *entry_buf = malloc(0x138800);
    void *table_buf[2] = { entry_buf, 0 };
    pool->table_138810 = table_buf;
    pool->table_138814 = (void *)0x1;
    pool->count_138818 = 2;

    g_clear_calls = 0;
    func_001F2010((NodePool *)pool);
    // Must assert that 0x138800 was cleared per non-null entry, plus self (8 bytes) and self+8 (8 bytes)
    assert(g_clear_calls >= 3);

    free(entry_buf);
    delete pool;
    return 0;
}
