#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_worker.h"

static int g_ecbf0_called = 0;
static int g_eda80_called = 0;
static int g_271220_called = 0;
static unsigned short g_mock_flags = 0;
static int g_eab0_recurse_called = 0;

extern "C" {
    int func_123350(float val) { return (int)val; }
    char func_26AD20(void *action, int flag) { (void)action; return (g_mock_flags & flag) != 0; }
    void func_26AD30(void *action, int flag) { (void)action; g_mock_flags |= (unsigned short)flag; }
    void func_26AD60(void *action, int flag) { (void)action; g_mock_flags &= (unsigned short)~flag; }
    void func_1ecbf0(void *world, int tx, int ty, void *action) {
        (void)world; (void)tx; (void)ty; (void)action;
        g_ecbf0_called++;
    }
    void func_1EDA80(void *obj, void *action) {
        (void)obj; (void)action;
        g_eda80_called++;
    }
    void func_271220(ActionRebind *self, int arg) {
        (void)self; (void)arg;
        g_271220_called++;
    }
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x30 - 0xC];
    float m_field30;
    char pad_34[5];
    unsigned char m_field39;
    char pad_3A[0x44 - 0x3A];
    float m_x;
    float m_y;
    char pad_4C[0x134 - 0x4C];
    void *m_sub_actions[4]; // 0x134
};

struct DummyMaster {
    char pad[0xE];
    short m_master_type; // 0xE
};

// Case 0: Guard checks on null inputs
static void test_worker_guards() {
    func_0026E9C0(nullptr);
    func_0026EAB0(nullptr, 1.0f);
}

// Case 1: func_0026E9C0 tile queries and flag mutations
static void test_func_0026E9C0_execution() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    ActionRebind *act = (ActionRebind*)&mock;
    DummyMaster master;
    memset(&master, 0, sizeof(master));
    master.m_master_type = 0x33;
    mock.m_field4 = &master;

    char dummy_world[100];
    mock.m_world = (WorldExtended*)dummy_world;
    mock.m_x = 15.0f;
    mock.m_y = 25.0f;

    // Flag 0x800 clear -> nothing
    g_mock_flags = 0;
    g_ecbf0_called = 0;
    func_0026E9C0(act);
    assert(g_ecbf0_called == 0);

    // Flag 0x800 set -> dispatches and mutates flags
    g_mock_flags = 0x800;
    func_0026E9C0(act);
    assert(g_ecbf0_called == 1);
    assert(g_eda80_called == 1);
    assert((g_mock_flags & 0x800) == 0);
    assert((g_mock_flags & 0x8000) != 0);
}

// Case 2: func_0026EAB0 recursion across subactions and completion check
static void test_func_0026EAB0_execution() {
    ExtendedMock parent, child;
    memset(&parent, 0, sizeof(parent));
    memset(&child, 0, sizeof(child));

    parent.m_sub_actions[0] = &child;
    parent.m_field39 = 0;
    parent.m_field30 = 1.0f;
    g_mock_flags = 0x800;

    g_271220_called = 0;
    func_0026EAB0((ActionRebind*)&parent, 5.0f);

    assert(g_271220_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_worker_guards();
        test_func_0026E9C0_execution();
        test_func_0026EAB0_execution();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_worker_guards(); break;
        case 1: test_func_0026E9C0_execution(); break;
        case 2: test_func_0026EAB0_execution(); break;
        default: return 1;
    }
    return 0;
}
