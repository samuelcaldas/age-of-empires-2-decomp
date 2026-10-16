#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_movement_ops.h"

static int g_func_272D10_called = 0;
static int g_func_26BDF0_called = 0;
static int g_func_1ECBF0_called = 0;
static int g_func_270530_called = 0;
static int g_func_270A20_called = 0;
static int g_func_272DD0_called = 0;
static int g_func_272E10_called = 0;
static int g_func_26AD20_ret = 0;
static unsigned short g_mock_flags = 0;

extern "C" {
    void func_00272D10(void *action) { (void)action; g_func_272D10_called++; }
    void func_0026BDF0(ActionRebind *self, void *a1, void *a2) { (void)self; (void)a1; (void)a2; g_func_26BDF0_called++; }
    void func_1ECBF0(void *field98, void *action, void *sight) {
        (void)field98; (void)action; (void)sight;
        g_func_1ECBF0_called++;
    }
    void func_00270530(void *action) { (void)action; g_func_270530_called++; }
    void func_00270A20(void *action) { (void)action; g_func_270A20_called++; }
    void func_001CF350(void *world, int a1, int a2) { (void)world; (void)a1; (void)a2; }
    void func_001CA430(void *world, int a1, int a2) { (void)world; (void)a1; (void)a2; }
    void func_00272DD0(void *action) { (void)action; g_func_272DD0_called++; }
    void func_00272E10(void *action) { (void)action; g_func_272E10_called++; }
    int func_123350(float val) { return (int)val; }
    char func_26AD20(void *action, int flag) {
        (void)action; (void)flag;
        return g_func_26AD20_ret;
    }
    void func_26AD30(void *action, int flag) {
        (void)action;
        g_mock_flags |= (unsigned short)flag;
    }
    void func_26AD60(void *action, int flag) {
        (void)action;
        g_mock_flags &= (unsigned short)~flag;
    }
    void func_00116F68(void *stream, void *data, int size) {
        (void)stream; (void)data; (void)size;
    }
}

static void* dummy_vtable[120];

struct ActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    int m_field20;
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    float m_field30;
    char m_field34;
    char m_field35;
    unsigned char m_field36;
    unsigned char m_field37;
    unsigned char m_field38;
    unsigned char m_field39;
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;
    char pad_50[0x48];
    void *m_field98;

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

// Case 0: func_0026B550 movement reset and flags
static void test_func_0026B550() {
    func_0026B550(nullptr, 0);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    g_mock_flags = 0x0F;

    g_func_272D10_called = 0;
    g_func_26BDF0_called = 0;
    g_func_1ECBF0_called = 0;
    g_func_26AD20_ret = 1;

    func_0026B550(act, 0);
    assert(g_func_272D10_called == 1);
    assert(g_func_26BDF0_called == 1);
    assert(g_func_1ECBF0_called == 1);
    assert((g_mock_flags & 0x0F) == 0);
    assert((g_mock_flags & 16) != 0);
}

// Case 1: func_0026B710 and func_0026BA00 stream update
static void test_movement_stream() {
    assert(func_0026B710(nullptr, nullptr, 0, 0, 0) == 0);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_stream[100];

    g_func_270530_called = 0;
    g_func_270A20_called = 0;
    g_func_272DD0_called = 0;
    int ok = func_0026B710(act, dummy_stream, 0, 0, 0);
    assert(ok == 1);
    assert(g_func_270530_called == 1);
    assert(g_func_270A20_called == 1);
    assert(g_func_272DD0_called == 1);

    g_func_272E10_called = 0;
    func_0026BA00(act, dummy_stream);
    assert(g_func_272E10_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026B550();
        test_movement_stream();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026B550(); break;
        case 1: test_movement_stream(); break;
        default: return 1;
    }
    return 0;
}
