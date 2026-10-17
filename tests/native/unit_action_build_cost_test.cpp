#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_cost.h"

static int g_func_2738A0_called = 0;
static int g_func_26E560_called = 0;
static int g_func_1DCF10_called = 0;
static int g_method19_called = 0;
static void *g_last_m19_arg = nullptr;

extern "C" {
    void func_2738A0(ActionRebind *self, void *arg1) { (void)self; (void)arg1; g_func_2738A0_called++; }
    void func_0026E560(ActionRebind *self, int arg1) { (void)self; (void)arg1; g_func_26E560_called++; }
    void func_1DCF10(ActionRebind *self) { (void)self; g_func_1DCF10_called++; }
}

static void mock_m19(void *action, void *arg) {
    (void)action;
    g_method19_called++;
    g_last_m19_arg = arg;
}

static void* dummy_vtable[120];

static void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[17] = (void*)mock_m19;
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x10 - 0xC];
    void *m_field10;

    ExtendedMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

struct DummyTarget {
    char pad[0x16C];
    void *m_ptr;
};

struct DummyMaster {
    char pad_00[0xE];
    short m_master_type; // 0xE
    char pad_10[0x16C - 0x10];
    void *m_field16C;
    char pad_170[0x1B0 - 0x170];
    unsigned char m_flag1B0; // 0x1B0
};

// Case 0: Guard checks on null inputs
static void test_cost_guards() {
    init_mock_vtable();
    func_0026EDF0(nullptr, nullptr);
    func_0026EE70(nullptr);
}

// Case 1: func_0026EDF0 Method19 dispatch, state notification, and frame update
static void test_func_0026EDF0_execution() {
    init_mock_vtable();
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    DummyMaster master;
    memset(&master, 0, sizeof(master));
    mock.m_field4 = &master;

    char dummy_node[16];
    master.m_field16C = dummy_node;
    mock.m_field10 = dummy_node; // matches!
    master.m_flag1B0 = 1;        // triggers func_0026E560

    DummyTarget target;
    memset(&target, 0, sizeof(target));
    char dummy_arg_node[16];
    target.m_ptr = dummy_arg_node;

    g_method19_called = 0;
    g_func_2738A0_called = 0;
    g_func_26E560_called = 0;

    func_0026EDF0(act, &target);

    assert(g_method19_called == 1);
    assert(g_last_m19_arg == (void*)dummy_arg_node);
    assert(g_func_2738A0_called == 1);
    assert(g_func_26E560_called == 1);
}

// Case 2: func_0026EE70 master type dispatch
static void test_func_0026EE70_execution() {
    init_mock_vtable();
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    DummyMaster master;
    memset(&master, 0, sizeof(master));
    mock.m_field4 = &master;

    // Type 0x1B (27) -> nothing
    master.m_master_type = 0x1B;
    g_func_1DCF10_called = 0;
    func_0026EE70(act);
    assert(g_func_1DCF10_called == 0);

    // Type != 0x1B -> calls func_1DCF10
    master.m_master_type = 0x46;
    func_0026EE70(act);
    assert(g_func_1DCF10_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_cost_guards();
        test_func_0026EDF0_execution();
        test_func_0026EE70_execution();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_cost_guards(); break;
        case 1: test_func_0026EDF0_execution(); break;
        case 2: test_func_0026EE70_execution(); break;
        default: return 1;
    }
    return 0;
}
