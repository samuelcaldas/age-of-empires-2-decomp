#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_load.h"

static int g_free_called = 0;
static int g_func_270530_called = 0;
static int g_func_274970_called = 0;
static int g_func_2D34A0_called = 0;
static int g_func_2E00D0_called = 0;
static int g_method61_called = 0;
static int g_method62_called = 0;

extern "C" {
    void Free__8BaseListFv(void *item) { (void)item; g_free_called++; }
    void func_00270530(void *action) { (void)action; g_func_270530_called++; }
    void func_274970(ActionRebind *self, void *stream) { (void)self; (void)stream; g_func_274970_called++; }
    void func_002D34A0(void *action) { (void)action; g_func_2D34A0_called++; }
    int func_00268530(ActionRebind *self) { (void)self; return 0; }
    ActionRebind* func_00268590(ActionRebind *self, int idx) { (void)self; (void)idx; return nullptr; }
    void func_26F590(ActionRebind *child) { (void)child; }
    int func_2E00D0(void *arg0, ActionRebind *self) { (void)arg0; (void)self; g_func_2E00D0_called++; return 1; }
}

static void mock_m61(void *action, void *world, int a2, int a3, int a4) {
    (void)action; (void)world; (void)a2; (void)a3; (void)a4;
    g_method61_called++;
}

static void mock_m62(void *action, void *world, int a2, int a3, int a4) {
    (void)action; (void)world; (void)a2; (void)a3; (void)a4;
    g_method62_called++;
}

static void* dummy_vtable[120];

static void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[59] = (void*)mock_m61;
    dummy_vtable[60] = (void*)mock_m62;
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x38 - 0xC];
    unsigned char m_field38;
    unsigned char m_field39;
    char pad_3A[2];
    short m_field3C;
    char pad_3E[0xCC - 0x3E];
    void *m_fieldCC;
    char pad_D0[0x128 - 0xD0];
    void *m_field128;
    void *m_field12C;

    ExtendedMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

// Case 0: Guard checks on null inputs
static void test_load_guards() {
    init_mock_vtable();
    char dummy_stream[16];
    func_0026DE90(nullptr, dummy_stream);

    ExtendedMock mock;
    func_0026DE90((ActionRebind*)&mock, nullptr);
}

// Case 1: Stream load calls BaseList frees, stream deserialize, and Method61 when state == 0
static void test_load_execution_flow() {
    init_mock_vtable();
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_stream[16];
    char dummy_world[100];
    char item1[16], item2[16], item3[16];

    mock.m_world = (WorldExtended*)dummy_world;
    mock.m_field39 = 0; // state 0 triggers Method61
    mock.m_field3C = 4; // triggers Method62
    mock.m_fieldCC = item1;
    mock.m_field128 = item2;
    mock.m_field12C = item3;
    mock.m_field38 = 1; // triggers func_2E00D0

    g_free_called = 0;
    g_func_270530_called = 0;
    g_func_274970_called = 0;
    g_func_2D34A0_called = 0;
    g_func_2E00D0_called = 0;
    g_method61_called = 0;
    g_method62_called = 0;

    func_0026DE90(act, dummy_stream);

    assert(g_free_called == 3);
    assert(g_func_270530_called == 1);
    assert(g_func_274970_called == 1);
    assert(g_method61_called == 1);
    assert(g_method62_called == 1);
    assert(g_func_2D34A0_called == 1);
    assert(g_func_2E00D0_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_load_guards();
        test_load_execution_flow();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_load_guards(); break;
        case 1: test_load_execution_flow(); break;
        default: return 1;
    }
    return 0;
}
