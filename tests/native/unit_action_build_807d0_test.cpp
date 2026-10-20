#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>

#include "unit_action_build_807d0.h"

// Structures matching D_4E3418 and D_4E3420 layout
struct Table1 {
    char pad_0[80];
    short count;          // offset 80 (0x50)
    char pad_52[2];
    void **items;         // offset 84 (0x54)
};

struct Table2 {
    char pad_0[2976];
    int active_id;        // offset 2976 (0xBA0)
    char pad_BA4[56];
    unsigned char *bytes; // offset 3032 (0xBD8) accessed by func_205920
};

// Global mock instances
Table1 g_table1_mock;
Table2 g_table2_mock;

extern "C" {
void *D_4E3418 = &g_table1_mock;
void *D_4E3420 = &g_table2_mock;

int func_202B10(void *item) {
    if (item == 0) return 0;
    return *(int *)item;
}

unsigned char func_205920(void *table, int index) {
    Table2 *t = (Table2 *)table;
    if (t == 0 || t->bytes == 0) return 0;
    return t->bytes[index];
}
}

// Callback recording structure
struct CallbackRecord {
    int id;
    void *param;
};

static std::vector<CallbackRecord> g_callback_calls;

static void test_callback(int id, void *param) {
    CallbackRecord rec;
    rec.id = id;
    rec.param = param;
    g_callback_calls.push_back(rec);
}

static void setup_tables(int count, int active_id) {
    g_callback_calls.clear();
    std::memset(&g_table1_mock, 0, sizeof(g_table1_mock));
    std::memset(&g_table2_mock, 0, sizeof(g_table2_mock));

    g_table1_mock.count = (short)count;
    g_table2_mock.active_id = active_id;

    static void *item_ptrs[10];
    static int item_values[10];
    static unsigned char byte_array[10];

    for (int i = 0; i < 10; ++i) {
        item_values[i] = 0;
        item_ptrs[i] = &item_values[i];
        byte_array[i] = 0;
    }

    g_table1_mock.items = item_ptrs;
    g_table2_mock.bytes = byte_array;
}

static void test_default_case_does_nothing() {
    setup_tables(5, 0);
    int dummy = 42;
    func_002807D0(0, test_callback, &dummy);
    assert(g_callback_calls.empty());

    func_002807D0(100, test_callback, &dummy);
    assert(g_callback_calls.empty());

    func_002807D0(-999, test_callback, &dummy);
    assert(g_callback_calls.empty());
    std::printf("PASS test_default_case_does_nothing\n");
}

static void test_all_16_action_codes() {
    int dummy = 0x1234;
    short codes[16] = {
        -101, -102, -103, -104, -105, -106, -107, -108,
        -109, -110, -111, -201, -202, -203, -204, -205
    };

    for (int c = 0; c < 16; ++c) {
        setup_tables(5, 0);
        short code = codes[c];

        // Setup condition specifically for item 2
        int *items = (int *)g_table1_mock.items; // will cast appropriately
        int **item_ptrs = (int **)g_table1_mock.items;
        unsigned char *bytes = g_table2_mock.bytes;

        switch (code) {
        case -101:
        case -201:
            g_table2_mock.active_id = 1; // == 1, so index 1 doesn't match
            bytes[1] = 1; // != 0
            bytes[2] = 0; // func_205920 == 0 matches index 2
            break;
        case -102:
        case -202:
            *item_ptrs[1] = 0; // func_202B10 == 0 (no match for 1)
            *item_ptrs[2] = 1; // func_202B10 != 0 matches index 2
            break;
        case -103:
            g_table2_mock.active_id = 1; // index 1 doesn't match
            *item_ptrs[1] = 0;
            *item_ptrs[2] = 1; // func_202B10 != 0
            bytes[2] = 0;      // func_205920 == 0
            break;
        case -104:
            *item_ptrs[1] = 0;
            *item_ptrs[2] = 1; // func_202B10 != 0
            bytes[1] = 0;
            bytes[2] = 3;      // func_205920 == 3
            break;
        case -105:
            *item_ptrs[1] = 0;
            *item_ptrs[2] = 1; // func_202B10 != 0
            bytes[1] = 0;
            bytes[2] = 1;      // func_205920 == 1
            break;
        case -106:
        case -203:
            bytes[1] = 0;      // != 3
            bytes[2] = 3;      // func_205920 == 3
            break;
        case -107:
        case -204:
            *item_ptrs[1] = 1; // != 0 (no match for 1)
            *item_ptrs[2] = 0; // func_202B10 == 0 matches index 2
            break;
        case -108:
            g_table2_mock.active_id = 1;
            *item_ptrs[1] = 1;
            *item_ptrs[2] = 0; // func_202B10 == 0
            bytes[2] = 0;      // func_205920 == 0
            break;
        case -109:
            *item_ptrs[1] = 1; // != 0
            *item_ptrs[2] = 0; // func_202B10 == 0
            bytes[1] = 0;
            bytes[2] = 3;      // func_205920 == 3
            break;
        case -110:
            *item_ptrs[1] = 1; // != 0
            *item_ptrs[2] = 0; // func_202B10 == 0
            bytes[1] = 0;
            bytes[2] = 1;      // func_205920 == 1
            break;
        case -111:
        case -205:
            bytes[1] = 0;      // != 1
            bytes[2] = 1;      // func_205920 == 1
            break;
        }

        func_002807D0(code, test_callback, &dummy);
        assert(g_callback_calls.size() >= 1);
        assert(g_callback_calls[0].id == 2);
        assert(g_callback_calls[0].param == &dummy);
    }
    std::printf("PASS test_all_16_action_codes\n");
}

static void test_single_match_vs_all_matches() {
    int dummy = 0x5678;

    // Test code -101 (find first: must break after first match)
    setup_tables(5, 99);
    g_table2_mock.bytes[1] = 0;
    g_table2_mock.bytes[2] = 0;
    g_table2_mock.bytes[3] = 0;
    func_002807D0(-101, test_callback, &dummy);
    assert(g_callback_calls.size() == 1);
    assert(g_callback_calls[0].id == 1);

    // Test code -201 (broadcast all: must iterate all matches in order)
    setup_tables(5, 99);
    g_table2_mock.bytes[1] = 0;
    g_table2_mock.bytes[2] = 0;
    g_table2_mock.bytes[3] = 0;
    g_table2_mock.bytes[4] = 1; // does not match
    func_002807D0(-201, test_callback, &dummy);
    assert(g_callback_calls.size() == 3);
    assert(g_callback_calls[0].id == 1);
    assert(g_callback_calls[1].id == 2);
    assert(g_callback_calls[2].id == 3);

    // Test code -202 (broadcast func_202B10 != 0 in order)
    setup_tables(5, 99);
    int **item_ptrs = (int **)g_table1_mock.items;
    *item_ptrs[1] = 1;
    *item_ptrs[2] = 0;
    *item_ptrs[3] = 1;
    *item_ptrs[4] = 1;
    func_002807D0(-202, test_callback, &dummy);
    assert(g_callback_calls.size() == 3);
    assert(g_callback_calls[0].id == 1);
    assert(g_callback_calls[1].id == 3);
    assert(g_callback_calls[2].id == 4);

    // Test code -203 (broadcast func_205920 == 3 in order)
    setup_tables(5, 99);
    g_table2_mock.bytes[1] = 3;
    g_table2_mock.bytes[2] = 0;
    g_table2_mock.bytes[3] = 3;
    g_table2_mock.bytes[4] = 0;
    func_002807D0(-203, test_callback, &dummy);
    assert(g_callback_calls.size() == 2);
    assert(g_callback_calls[0].id == 1);
    assert(g_callback_calls[1].id == 3);

    // Test code -204 (broadcast func_202B10 == 0 in order)
    setup_tables(5, 99);
    *item_ptrs[1] = 1;
    *item_ptrs[2] = 0;
    *item_ptrs[3] = 0;
    *item_ptrs[4] = 1;
    func_002807D0(-204, test_callback, &dummy);
    assert(g_callback_calls.size() == 2);
    assert(g_callback_calls[0].id == 2);
    assert(g_callback_calls[1].id == 3);

    // Test code -205 (broadcast func_205920 == 1 in order)
    setup_tables(5, 99);
    g_table2_mock.bytes[1] = 1;
    g_table2_mock.bytes[2] = 1;
    g_table2_mock.bytes[3] = 0;
    g_table2_mock.bytes[4] = 1;
    func_002807D0(-205, test_callback, &dummy);
    assert(g_callback_calls.size() == 3);
    assert(g_callback_calls[0].id == 1);
    assert(g_callback_calls[1].id == 2);
    assert(g_callback_calls[2].id == 4);

    std::printf("PASS test_single_match_vs_all_matches\n");
}

static void test_alias() {
    setup_tables(5, 99);
    int dummy = 0x9999;
    g_table2_mock.bytes[2] = 1;
    func_2807D0(-111, test_callback, &dummy);
    assert(g_callback_calls.size() == 1);
    assert(g_callback_calls[0].id == 2);
    assert(g_callback_calls[0].param == &dummy);
    std::printf("PASS test_alias\n");
}

int main() {
    test_default_case_does_nothing();
    test_all_16_action_codes();
    test_single_match_vs_all_matches();
    test_alias();
    std::printf("All unit_action_build_807d0 tests passed!\n");
    return 0;
}
