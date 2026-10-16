#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_update.h"

static int g_func_1C9E00_called = 0;
static int g_func_2734F0_called = 0;
static int g_func_26F590_called = 0;
static int g_free_called = 0;
static int g_method28_called = 0;
static int g_last_m28_state = 0;

extern "C" {
    int func_123350(float val) { return (int)val; }
    int func_1233E0(float val) { return (int)val; }
    int func_00268500(ActionRebind *self) { (void)self; return 0; }
    int func_00268530(ActionRebind *self) { (void)self; return 0; }
    ActionRebind* func_00268590(ActionRebind *self, int idx) { (void)self; (void)idx; return nullptr; }
    void func_00270530(void *action) { (void)action; }
    void func_2734F0(ActionRebind *self) { (void)self; g_func_2734F0_called++; }
    void func_271640(ActionRebind *self, int arg) { (void)self; (void)arg; }
    void func_26F590(ActionRebind *child) { (void)child; g_func_26F590_called++; }
    void func_280680(ActionRebind *self, int flag) { (void)self; (void)flag; }
    void func_270660(ActionRebind *self) { (void)self; }
    void Free__8BaseListFv(void *item) { (void)item; g_free_called++; }
    void func_1C9E00(void *arg0, int a1, int a2, int a3, int a4, int a5) {
        (void)arg0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
        g_func_1C9E00_called++;
    }
}

static void mock_m28(void *self, int state) {
    (void)self;
    g_method28_called++;
    g_last_m28_state = state;
}

static void* dummy_vtable[120];

static void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[26] = (void*)mock_m28;
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    void *m_field10;
    char pad_14[0x39 - 0x14];
    unsigned char m_field39;
    char pad_3A[0x44 - 0x3A];
    float m_x;
    float m_y;
    float m_z;
    char pad_50[0x128 - 0x50];
    void *m_field128;
    void *m_field12C;
    char pad_130[0x170 - 0x130];
    float m_field170;

    ExtendedMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

struct DummyTarget {
    char pad[0x39];
    unsigned char m_state;
};

struct DummyMasterUnit {
    char pad_00[8];
    short m_unit_class; // 0x8
    char pad_0A[4];
    short m_master_type; // 0xE
    char pad_10[16];
    float m_ext_x; // 0x20
    float m_ext_y; // 0x24
    char pad_28[0x13E - 0x28];
    short m_max_work; // 0x13E
};

// Case 0: Guard checks on null inputs
static void test_build_guards() {
    init_mock_vtable();
    func_0026D010(nullptr);

    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    mock.m_field4 = nullptr;
    func_0026D010(act);
}

// Case 1: Active construction updates footprint and signals completion
static void test_build_execution_flow() {
    init_mock_vtable();
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    DummyMasterUnit master;
    memset(&master, 0, sizeof(master));
    master.m_master_type = 10; // != 0x1B
    master.m_unit_class = 0x46; // == 70 (building)
    master.m_max_work = 100;
    master.m_ext_x = 2.0f;
    master.m_ext_y = 2.0f;

    DummyTarget target;
    memset(&target, 0, sizeof(target));
    target.m_state = 10;

    char dummy_zone[32];
    mock.m_field4 = &master;
    mock.m_fieldC = dummy_zone;
    mock.m_field10 = &target;
    mock.m_field39 = 0;
    mock.m_field170 = 100.0f; // completed!

    g_func_1C9E00_called = 0;
    g_func_2734F0_called = 0;
    g_method28_called = 0;

    func_0026D010(act);

    assert(g_method28_called == 1);
    assert(g_last_m28_state == 2);
    assert(g_func_2734F0_called == 1);
}

// Case 2: Teardown cleanup and notification callbacks
static void test_cleanup_and_notification() {
    init_mock_vtable();
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    DummyMasterUnit master;
    memset(&master, 0, sizeof(master));
    mock.m_field4 = &master;

    char dummy_item1[16];
    char dummy_item2[16];
    mock.m_field128 = dummy_item1;
    mock.m_field12C = dummy_item2;

    g_free_called = 0;
    func_0026D010(act);
    assert(g_free_called == 2);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_build_guards();
        test_build_execution_flow();
        test_cleanup_and_notification();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_build_guards(); break;
        case 1: test_build_execution_flow(); break;
        case 2: test_cleanup_and_notification(); break;
        default: return 1;
    }
    return 0;
}
