#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_state_handlers.h"

static int g_func_272C20_called = 0;
static int g_func_26BA70_called = 0;
static int g_func_1ECBF0_called = 0;
static int g_func_26AD20_ret = 0;
static unsigned short g_mock_flags = 0;

extern "C" {
    void func_00272C20(void *action) { (void)action; g_func_272C20_called++; }
    void func_0026BA70(ActionRebind *self) { (void)self; g_func_26BA70_called++; }
    void func_1ECBF0(void *field98, void *action, void *sight) {
        (void)field98; (void)action; (void)sight;
        g_func_1ECBF0_called++;
    }
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
    void *m_field98; // 0x98

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

// Case 0: func_0026B130 state transition dispatch and flag resets
static void test_func_0026B130() {
    func_0026B130(nullptr, 0);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    g_mock_flags = 0x0F; // flags 1, 2, 4, 8 set

    g_func_272C20_called = 0;
    g_func_26BA70_called = 0;
    g_func_1ECBF0_called = 0;
    g_func_26AD20_ret = 1; // flag 16 active

    func_0026B130(act, 0);
    assert(g_func_272C20_called == 1);
    assert(g_func_26BA70_called == 1);
    assert(g_func_1ECBF0_called == 1);
    // Flags 1, 2, 4, 8 cleared, 16 set
    assert((g_mock_flags & 0x0F) == 0);
    assert((g_mock_flags & 16) != 0);
}

// Case 1: func_0026B360 state exit handler
static void test_func_0026B360() {
    func_0026B360(nullptr, 0);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    g_mock_flags = 0x0F;

    g_func_272C20_called = 0;
    g_func_26BA70_called = 0;
    g_func_1ECBF0_called = 0;
    g_func_26AD20_ret = 0; // flag 16 inactive

    func_0026B360(act, 0);
    assert(g_func_272C20_called == 1);
    assert(g_func_26BA70_called == 1);
    assert(g_func_1ECBF0_called == 0);
    assert((g_mock_flags & 0x0F) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026B130();
        test_func_0026B360();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026B130(); break;
        case 1: test_func_0026B360(); break;
        default: return 1;
    }
    return 0;
}
