#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_progress.h"

static int g_get_head_called = 0;
static void *g_mock_head_item = nullptr;
static int g_func_347880_called = 0;
static int g_func_202B10_called = 0;
static int g_func_202B10_ret = 1;
static int g_func_270900_called = 0;
static int g_func_270900_ret = 1;
static int g_func_2794A0_called = 0;

extern "C" {
    int func_123350(float val) { return (int)val; }
    void *GetHeadItem__8BaseListFv(void *list) {
        (void)list;
        g_get_head_called++;
        return g_mock_head_item;
    }
    int func_347880(void *item, short *out_val1, short *out_val2, int a3, int a4) {
        (void)item; (void)out_val1; (void)out_val2; (void)a3; (void)a4;
        g_func_347880_called++;
        return 1;
    }
    int func_00202B10(void *world) {
        (void)world;
        g_func_202B10_called++;
        return g_func_202B10_ret;
    }
    int func_270900(ActionRebind *self, short *out_val1, short *out_val2) {
        (void)self; (void)out_val1; (void)out_val2;
        g_func_270900_called++;
        return g_func_270900_ret;
    }
    void func_2794A0(ActionRebind *self, int code) {
        (void)self; (void)code;
        g_func_2794A0_called++;
    }
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x39 - 0xC];
    unsigned char m_field39;
    char pad_3A[0x12C - 0x3A];
    void *m_field12C;
    char pad_130[0x170 - 0x130];
    float m_field170;
};

struct DummyItem {
    char pad[4];
    short m_type;
};

struct DummyMaster {
    char pad[0x13E];
    short m_max_work;
};

// Case 0: Guard checks on null inputs
static void test_progress_guards() {
    short t = 0, v1 = 0, v2 = 0;
    assert(func_0026EC90(nullptr, &t, &v1, &v2, 0) == 0);
    assert(func_0026ED90(nullptr) == 100);
}

// Case 1: func_0026EC90 execution with item 0x67 vs standard
static void test_func_0026EC90_flow() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_world[100];
    mock.m_world = (WorldExtended*)dummy_world;

    DummyItem item;
    item.m_type = 0x67;
    g_mock_head_item = &item;
    short t = 0, v1 = 0, v2 = 0;

    g_func_347880_called = 0;
    int ok = func_0026EC90(act, &t, &v1, &v2, 0);
    assert(ok == 1);
    assert(t == 0x67);
    assert(g_func_347880_called == 1);

    // Standard item type
    item.m_type = 0x10;
    g_func_202B10_called = 0;
    g_func_270900_called = 0;
    g_func_2794A0_called = 0;

    ok = func_0026EC90(act, &t, &v1, &v2, 1);
    assert(ok == 1);
    assert(t == 0x10);
    assert(g_func_202B10_called == 1);
    assert(g_func_270900_called == 1);
    assert(g_func_2794A0_called == 1);
}

// Case 2: func_0026ED90 percentage calculation
static void test_func_0026ED90_percentage() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    ActionRebind *act = (ActionRebind*)&mock;

    DummyMaster master;
    master.m_max_work = 100;
    mock.m_field4 = &master;

    // State != 0 -> 100
    mock.m_field39 = 1;
    assert(func_0026ED90(act) == 100);

    // State == 0, work = 50 -> 50%
    mock.m_field39 = 0;
    mock.m_field170 = 50.0f;
    assert(func_0026ED90(act) == 50);

    // Work = 75 -> 75%
    mock.m_field170 = 75.0f;
    assert(func_0026ED90(act) == 75);

    // max_work == 0 -> 100
    master.m_max_work = 0;
    assert(func_0026ED90(act) == 100);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_progress_guards();
        test_func_0026EC90_flow();
        test_func_0026ED90_percentage();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_progress_guards(); break;
        case 1: test_func_0026EC90_flow(); break;
        case 2: test_func_0026ED90_percentage(); break;
        default: return 1;
    }
    return 0;
}
