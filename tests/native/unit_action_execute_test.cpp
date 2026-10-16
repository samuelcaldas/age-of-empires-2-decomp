#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_execute.h"

static int g_func_207C30_called = 0;
static int g_func_26E9C0_called = 0;
static int g_func_26E560_called = 0;
static int g_func_1EDF20_called = 0;
static int g_func_270A20_called = 0;
static int g_func_2D34A0_called = 0;
static int g_func_25F6E0_called = 0;
static int g_func_27B700_called = 0;
static int g_func_1ECD00_called = 0;
static int g_func_273970_called = 0;
static int g_func_1EC350_called = 0;
static int g_func_2D3430_called = 0;
static int g_func_26AD20_ret = 1;
static unsigned short g_mock_flags = 0;

extern "C" {
    void func_207C30(void *world, short id, int delta) { (void)world; (void)id; (void)delta; g_func_207C30_called++; }
    void func_0026E9C0(void *action) { (void)action; g_func_26E9C0_called++; }
    void func_0026E560(void *action) { (void)action; g_func_26E560_called++; }
    void func_1EDF20(void *obj, void *action) { (void)obj; (void)action; g_func_1EDF20_called++; }
    void func_00270A20(void *action) { (void)action; g_func_270A20_called++; }
    void func_002D34A0(void *action) { (void)action; g_func_2D34A0_called++; }
    void func_25F6E0(void *field38, int a1, int a2, int a3, int a4, int a5) {
        (void)field38; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
        g_func_25F6E0_called++;
    }
    void func_0027B700(void *action) { (void)action; g_func_27B700_called++; }
    void func_1ECD00(void *field98, void *action) { (void)field98; (void)action; g_func_1ECD00_called++; }
    void func_00273970(void *action) { (void)action; g_func_273970_called++; }
    void func_001EC350(void *field98, void *action) { (void)field98; (void)action; g_func_1EC350_called++; }
    void func_002D3430(void *action) { (void)action; g_func_2D3430_called++; }
    char func_26AD20(void *action, int flag) { (void)action; (void)flag; return g_func_26AD20_ret; }
    void func_26AD30(void *action, int flag) { (void)action; g_mock_flags |= (unsigned short)flag; }
    void func_26AD60(void *action, int flag) { (void)action; g_mock_flags &= (unsigned short)~flag; }
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

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

// Case 0: func_0026C600 null check
static void test_execute_guard() {
    assert(func_0026C600(nullptr, 0, 0, 0) == 0);
}

// Case 1: func_0026C600 execution and lifecycle callbacks
static void test_execute_flow() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_world[100];
    mock.m_world = (WorldExtended*)dummy_world;
    mock.m_field24 = 33;
    g_mock_flags = 0;

    g_func_207C30_called = 0;
    g_func_26E9C0_called = 0;
    g_func_26E560_called = 0;
    g_func_1EDF20_called = 0;
    g_func_270A20_called = 0;
    g_func_25F6E0_called = 0;
    g_func_1ECD00_called = 0;
    g_func_273970_called = 0;

    int ok = func_0026C600(act, 1, 2, 3);
    assert(ok == 1);
    assert(g_func_207C30_called == 1);
    assert(g_func_26E9C0_called == 1);
    assert(g_func_26E560_called == 1);
    assert(g_func_1EDF20_called == 1);
    assert(g_func_270A20_called == 1);
    assert(g_func_25F6E0_called == 1);
    assert(g_func_1ECD00_called == 1);
    assert(g_func_273970_called == 1);
    assert((g_mock_flags & 2) == 0); // flag 2 set then cleared
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_execute_guard();
        test_execute_flow();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_execute_guard(); break;
        case 1: test_execute_flow(); break;
        default: return 1;
    }
    return 0;
}
