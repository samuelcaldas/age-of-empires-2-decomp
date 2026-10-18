#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include "zone_spatial_grid_node_pool_setup.h"
#include "zone_spatial_grid_node_pool_destructor.h"
#include "zone_spatial_grid_node_pool_clear.h"

static int g_func_100670_called = 0;
static void *g_last_deleted_ptr = 0;
static std::vector<std::string> g_event_timeline;

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
    char trailing_padding[64];
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
    g_event_timeline.push_back("logger");
    return (void *)0xCAFE;
}

void func_1F20E0(NodePool *self, int val) {
    HelperCallRecord rec;
    rec.name = "func_1F20E0";
    rec.self = self;
    rec.int_arg = val;
    rec.ptr_arg = 0;
    g_helper_calls.push_back(rec);
    g_event_timeline.push_back("func_1F20E0");
}

void func_1F21E0(NodePool *self, void *p1) {
    HelperCallRecord rec;
    rec.name = "func_1F21E0";
    rec.self = self;
    rec.int_arg = 0;
    rec.ptr_arg = p1;
    g_helper_calls.push_back(rec);
    g_event_timeline.push_back("func_1F21E0");
}

void func_117CAC(void *dst, int val, int size) {
    ClearCallRecord rec;
    rec.dst = dst;
    rec.val = val;
    rec.size = size;
    g_clear_calls_log.push_back(rec);
    memset(dst, val, size);
}
}

struct NodePool {
    char pad[0x138850];
};

int main() {
    // ABI offsetof and sizeof assertions
    assert(sizeof(StrictNodePool) >= 0x138838);
    assert(offsetof(StrictNodePool, table_138810) == 0x138810);
    assert(offsetof(StrictNodePool, table_138814) == 0x138814);
    assert(offsetof(StrictNodePool, count_138818) == 0x138818);
    assert(offsetof(StrictNodePool, capacity_138834) == 0x138834);

    // Test 1: func_001F1EE0 - node pool setup, offsets, helper arguments, and exact logger check
    StrictNodePool *pool = new StrictNodePool();
    memset(pool, 0, sizeof(StrictNodePool));

    g_event_timeline.clear();
    g_helper_calls.clear();
    int res = func_001F1EE0((NodePool *)pool, (void *)0x5678, 5000);
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

    // Verify timeline: logger must run BEFORE helpers
    assert(g_event_timeline.size() == 3);
    assert(g_event_timeline[0] == "logger");
    assert(g_event_timeline[1] == "func_1F20E0");
    assert(g_event_timeline[2] == "func_1F21E0");

    // Verify helper arguments: func_1F20E0 gets self and value at self+0x13881C (1); func_1F21E0 gets self and p1 (0x5678)
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

    // Test 3A: func_001F2020 - clear pool with table_138814 non-null (expects self+8 clear)
    const size_t guard_size = 64;
    const size_t total_buf_size = guard_size + sizeof(ClearNodePool) + guard_size;
    char *raw_buf = (char *)malloc(total_buf_size);
    memset(raw_buf, 0xAA, total_buf_size); // Fill everything with sentinel 0xAA

    ClearNodePool *clear_pool1 = (ClearNodePool *)(raw_buf + guard_size);
    memset(clear_pool1, 0, sizeof(ClearNodePool));
    void *entry_buf1 = malloc(16);
    void **table_buf1 = (void **)malloc(sizeof(void *));
    table_buf1[0] = entry_buf1;
    clear_pool1->table_138810 = table_buf1;
    clear_pool1->table_138814 = (void *)0x1;
    clear_pool1->count_138818 = 1;

    g_clear_calls_log.clear();
    func_001F2020((NodePool *)clear_pool1);

    assert(g_clear_calls_log.size() == 3);
    assert(g_clear_calls_log[0].dst == (char *)clear_pool1 + 0x10);
    assert(g_clear_calls_log[0].val == 0);
    assert(g_clear_calls_log[0].size == 0x138800);

    assert(g_clear_calls_log[1].dst == (void *)clear_pool1);
    assert(g_clear_calls_log[1].val == 0);
    assert(g_clear_calls_log[1].size == 8);

    assert(g_clear_calls_log[2].dst == (char *)clear_pool1 + 8);
    assert(g_clear_calls_log[2].val == 0);
    assert(g_clear_calls_log[2].size == 8);

    // Verify repeated calls maintain zero-filled cleared state after intentional full-region contamination
    char *clear_start1 = (char *)clear_pool1 + 0x10;
    memset(clear_start1, 0xFF, 0x138800);
    memset(clear_pool1, 0xFF, 16);

    // Set valid table_138810 and count_138818, and fill trailing padding with 0xAA guard
    clear_pool1->table_138810 = table_buf1;
    clear_pool1->table_138814 = (void *)0x1;
    clear_pool1->count_138818 = 1;
    memset(clear_pool1->trailing_padding, 0xAA, sizeof(clear_pool1->trailing_padding));

    g_clear_calls_log.clear();
    func_001F2020((NodePool *)clear_pool1);
    assert(g_clear_calls_log.size() == 3);

    // Assert EVERY SINGLE BYTE in the full 0x138800-byte clear region is strictly zeroed out
    for (size_t i = 0; i < 0x138800; ++i) {
        assert(clear_start1[i] == 0);
    }
    for (int i = 0; i < 16; ++i) {
        assert(((char *)clear_pool1)[i] == 0);
    }

    // Verify table boundary and count remain valid (untouched by clear ending at 0x138810)
    assert(clear_pool1->table_138810 == table_buf1);
    assert(clear_pool1->count_138818 == 1);

    // Verify every single byte of trailing padding remains untouched (0xAA)
    for (size_t i = 0; i < sizeof(clear_pool1->trailing_padding); ++i) {
        assert(clear_pool1->trailing_padding[i] == (char)0xAA);
    }

    free(entry_buf1);
    free(table_buf1);
    free(raw_buf);

    // Test 3B: func_001F2020 - clear pool with table_138814 NULL (expects NO self+8 clear)
    ClearNodePool *clear_pool2 = new ClearNodePool();
    memset(clear_pool2, 0, sizeof(ClearNodePool));
    void *entry_buf2 = malloc(16);
    void **table_buf2 = (void **)malloc(sizeof(void *));
    table_buf2[0] = entry_buf2;
    clear_pool2->table_138810 = table_buf2;
    clear_pool2->table_138814 = 0; // NULL!
    clear_pool2->count_138818 = 1;

    g_clear_calls_log.clear();
    func_001F2020((NodePool *)clear_pool2);

    assert(g_clear_calls_log.size() == 2);
    assert(g_clear_calls_log[0].dst == (char *)clear_pool2 + 0x10);
    assert(g_clear_calls_log[0].val == 0);
    assert(g_clear_calls_log[0].size == 0x138800);

    assert(g_clear_calls_log[1].dst == (void *)clear_pool2);
    assert(g_clear_calls_log[1].val == 0);
    assert(g_clear_calls_log[1].size == 8);
    // Verify no clear at clear_pool2 + 8 was performed

    free(entry_buf2);
    free(table_buf2);
    delete clear_pool2;
    delete pool;
    return 0;
}
