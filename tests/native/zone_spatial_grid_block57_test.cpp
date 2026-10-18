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

struct ClearCallRecord {
    void *dst;
    int val;
    int size;
};
static std::vector<ClearCallRecord> g_clear_calls_log;

struct StrictNodePool {
    char pad_00[0x138810];
    void *table_138810;
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

struct ClearNodePool {
    char pad_00[0x138810];
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
    g_clear_calls_log.push_back({dst, val, size});
    memset(dst, val, size);
}
}

struct NodePool {
    char pad[0x138850];
};

int main() {
    // Test 1: func_001F1ED0 - node pool setup, offsets, helper order, and exact logger check
    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    g_call_order.clear();
    int res = func_001F1ED0((NodePool *)pool, (void *)0x5678, 5000);
    assert(res == 1);
    assert(pool->count_138818 == 0);
    assert(pool->field_13881C == 1);
    assert(pool->capacity_138834 == 5000);

    // Verify exact logger arguments: format string, file, line, in order
    assert(g_logger_called == 1);
    assert(g_logger_fmt != 0 && std::string(g_logger_fmt) == "%s(%d) make SonftOb_ArrayList.\n");
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

    // Test 3: func_001F2010 - clear pool with non-null entry table entries and strict call logging
    ClearNodePool *clear_pool = new ClearNodePool();
    memset(clear_pool, 0, sizeof(ClearNodePool));

    void *entry_buf1 = malloc(16);
    void *entry_buf2 = malloc(16);
    void *table_buf[2] = { entry_buf1, entry_buf2 };
    clear_pool->table_138810 = table_buf;
    clear_pool->table_138814 = (void *)0x1;
    clear_pool->count_138818 = 2;

    g_clear_calls_log.clear();
    func_001F2010((NodePool *)clear_pool);

    // Expecting:
    // - clear (char*)clear_pool + 0x10 (0x138800 bytes) for entry 0
    // - clear (char*)clear_pool + 0x10 (0x138800 bytes) for entry 1
    // - clear clear_pool (8 bytes)
    // - clear (char*)clear_pool + 8 (8 bytes)
    assert(g_clear_calls_log.size() >= 4);
    assert(g_clear_calls_log[0].dst == (char *)clear_pool + 0x10);
    assert(g_clear_calls_log[0].size == 0x138800);
    assert(g_clear_calls_log[1].dst == (char *)clear_pool + 0x10);
    assert(g_clear_calls_log[1].size == 0x138800);
    assert(g_clear_calls_log[2].dst == (void *)clear_pool);
    assert(g_clear_calls_log[2].size == 8);
    assert(g_clear_calls_log[3].dst == (char *)clear_pool + 8);
    assert(g_clear_calls_log[3].size == 8);

    free(entry_buf1);
    free(entry_buf2);
    delete pool;
    delete clear_pool;
    return 0;
}
