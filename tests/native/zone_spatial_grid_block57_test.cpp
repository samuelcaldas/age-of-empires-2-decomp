#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_setup.h"
#include "zone_spatial_grid_node_pool_destructor.h"
#include "zone_spatial_grid_node_pool_clear.h"

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;

struct HelperCallRecord {
    std::string name;
    NodePool *self;
    int int_arg;
    void *ptr_arg;
};
static std::vector<HelperCallRecord> g_helper_calls;

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
    g_helper_calls.push_back({"func_1F20E0", self, val, 0});
}

void func_1F21E0(NodePool *self, void *p1) {
    g_helper_calls.push_back({"func_1F21E0", self, 0, p1});
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
    // Test 1: func_001F1ED0 - node pool setup, offsets, helper arguments, and exact logger check
    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    g_helper_calls.clear();
    int res = func_001F1ED0((NodePool *)pool, (void *)0x5678, 5000);
    assert(res == 1);
    assert(pool->table_138810 == 0);
    assert(pool->table_138814 == 0);
    assert(pool->count_138818 == 0);
    assert(pool->field_13881C == 1);
    assert(pool->field_138820 == 0);
    assert(pool->field_138824 == -1);
    assert(pool->field_138828 == -1);
    assert(pool->field_13882C == 0);
    assert(pool->field_138830 == 0);
    assert(pool->capacity_138834 == 5000);

    // Verify exact logger arguments: format string, file, line, in order
    assert(g_logger_called == 1);
    assert(g_logger_fmt != 0 && std::string(g_logger_fmt) == "%s(%d) make SonftOb_ArrayList.\n");
    assert(g_logger_file != 0 && std::string(g_logger_file) == "obmanager.cpp");
    assert(g_logger_line == 0x13D6);

    // Verify helper call order and exact arguments:
    // - func_1F20E0 gets self and value at self+0x13881C (1)
    // - func_1F21E0 gets self and p1 (0x5678)
    assert(g_helper_calls.size() == 2);
    assert(g_helper_calls[0].name == "func_1F20E0");
    assert(g_helper_calls[0].self == (NodePool *)pool);
    assert(g_helper_calls[0].int_arg == 1);

    assert(g_helper_calls[1].name == "func_1F21E0");
    assert(g_helper_calls[1].self == (NodePool *)pool);
    assert(g_helper_calls[1].ptr_arg == (void *)0x5678);

    // Test 2: func_001F1FD0 - deleting destructor
    g_func_100670_called = 0;
    void *obj = (void *)0xBEEF;
    void *r1 = func_001F1FD0(obj, 1);
    assert(r1 == obj);
    assert(g_func_100670_called == 1);
    assert(g_last_deleted_ptr == obj);

    // Test 3A: func_001F2010 - clear pool with table_138814 non-null (expects self+8 clear)
    ClearNodePool *clear_pool1 = new ClearNodePool();
    memset(clear_pool1, 0, sizeof(ClearNodePool));
    void *entry_buf1 = malloc(16);
    void **table_buf1 = (void **)malloc(sizeof(void *));
    table_buf1[0] = entry_buf1;
    clear_pool1->table_138810 = table_buf1;
    clear_pool1->table_138814 = (void *)0x1;
    clear_pool1->count_138818 = 1;

    g_clear_calls_log.clear();
    func_001F2010((NodePool *)clear_pool1);

    assert(g_clear_calls_log.size() == 3);
    assert(g_clear_calls_log[0].dst == (char *)clear_pool1 + 0x10);
    assert(g_clear_calls_log[0].size == 0x138800);
    assert(g_clear_calls_log[1].dst == (void *)clear_pool1);
    assert(g_clear_calls_log[1].size == 8);
    assert(g_clear_calls_log[2].dst == (char *)clear_pool1 + 8);
    assert(g_clear_calls_log[2].size == 8);

    free(entry_buf1);
    free(table_buf1);
    delete clear_pool1;

    // Test 3B: func_001F2010 - clear pool with table_138814 NULL (expects NO self+8 clear)
    ClearNodePool *clear_pool2 = new ClearNodePool();
    memset(clear_pool2, 0, sizeof(ClearNodePool));
    void *entry_buf2 = malloc(16);
    void **table_buf2 = (void **)malloc(sizeof(void *));
    table_buf2[0] = entry_buf2;
    clear_pool2->table_138810 = table_buf2;
    clear_pool2->table_138814 = 0; // NULL!
    clear_pool2->count_138818 = 1;

    g_clear_calls_log.clear();
    func_001F2010((NodePool *)clear_pool2);

    assert(g_clear_calls_log.size() == 2);
    assert(g_clear_calls_log[0].dst == (char *)clear_pool2 + 0x10);
    assert(g_clear_calls_log[0].size == 0x138800);
    assert(g_clear_calls_log[1].dst == (void *)clear_pool2);
    assert(g_clear_calls_log[1].size == 8);
    // Verify no clear at clear_pool2 + 8 was performed

    free(entry_buf2);
    free(table_buf2);
    delete clear_pool2;
    delete pool;
    return 0;
}
