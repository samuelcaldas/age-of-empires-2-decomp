#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_lifecycle.h"

static int g_func_207C30_called = 0;
static int g_func_1ECD00_called = 0;
static int g_func_272E80_called = 0;
static int g_func_26E560_called = 0;
static int g_func_270A20_called = 0;
static int g_func_26E940_called = 0;
static int g_func_30FF80_called = 0;
static int g_func_273130_called = 0;
static int g_func_226D90_called = 0;
static int g_func_138BA0_called = 0;
static int g_func_1143F8_called = 0;
static unsigned short g_mock_flags = 0;

extern "C" {
    void func_207C30(void *world, short id, int delta) { (void)world; (void)id; (void)delta; g_func_207C30_called++; }
    void func_1ECD00(void *field98, void *action) { (void)field98; (void)action; g_func_1ECD00_called++; }
    void func_00272E80(void *action) { (void)action; g_func_272E80_called++; }
    void func_0026E560(void *action) { (void)action; g_func_26E560_called++; }
    void func_00270A20(void *action) { (void)action; g_func_270A20_called++; }
    void func_0026E940(void *action) { (void)action; g_func_26E940_called++; }
    void func_0030FF80(void *action) { (void)action; g_func_30FF80_called++; }
    void func_00273130(void *action) { (void)action; g_func_273130_called++; }
    void func_00226D90(void *action) { (void)action; g_func_226D90_called++; }
    void func_00138BA0(void *list, void *action) { (void)list; (void)action; g_func_138BA0_called++; }
    void func_001143F8(void *action) { (void)action; g_func_1143F8_called++; }
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

// Case 0: func_0026BA70 lifecycle teardown
static void test_func_0026BA70() {
    func_0026BA70(nullptr);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_world[100];
    mock.m_world = (WorldExtended*)dummy_world;
    mock.m_field24 = 15;
    g_mock_flags = 1;

    g_func_272E80_called = 0;
    g_func_207C30_called = 0;
    g_func_1ECD00_called = 0;

    func_0026BA70(act);
    assert(g_func_272E80_called == 1);
    assert(g_func_207C30_called == 1);
    assert(g_func_1ECD00_called == 1);
    assert((g_mock_flags & 1) == 0); // cleared flag 1
    assert((g_mock_flags & 2) == 0); // cleared flag 2
}

// Case 1: func_0026BDF0 lifecycle initialization
static void test_func_0026BDF0() {
    func_0026BDF0(nullptr, nullptr);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_world[100];
    mock.m_world = (WorldExtended*)dummy_world;
    g_mock_flags = 0;

    g_func_273130_called = 0;
    g_func_226D90_called = 0;
    g_func_138BA0_called = 0;

    func_0026BDF0(act, dummy_world);
    assert(g_func_273130_called == 1);
    assert(g_func_226D90_called == 2);
    assert(g_func_138BA0_called == 1);
    assert((g_mock_flags & 4) != 0); // flag 4 set
    assert((g_mock_flags & 8) != 0); // flag 8 set
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026BA70();
        test_func_0026BDF0();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026BA70(); break;
        case 1: test_func_0026BDF0(); break;
        default: return 1;
    }
    return 0;
}
