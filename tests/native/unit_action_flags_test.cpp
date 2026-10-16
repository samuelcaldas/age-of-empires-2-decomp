#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "unit_action_flags.h"

static int g_func_268530_called = 0;

extern "C" {
    int func_00268530(ActionRebind *self) {
        (void)self;
        g_func_268530_called++;
        return 7;
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
    unsigned short m_field3E; // flags
    int m_field40;
    float m_x;
    float m_y;
    float m_z;

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

// Case 0: func_0026AD80 returns 0.0f (100% exact match)
static void test_func_0026AD80() {
    float val = func_0026AD80();
    assert(val == 0.0f);
}

// Case 1: Bitfield flags manipulation (func_26AD20, func_26AD30, func_26AD60)
static void test_flag_manipulation() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    mock.m_field3E = 0;

    // Test initially clear
    assert(func_26AD20(act, 1) == 0);
    assert(func_26AD20(act, 2) == 0);

    // Set bit 1
    func_26AD30(act, 1);
    assert(func_26AD20(act, 1) != 0);
    assert(func_26AD20(act, 2) == 0);

    // Set bit 2
    func_26AD30(act, 2);
    assert(func_26AD20(act, 1) != 0);
    assert(func_26AD20(act, 2) != 0);

    // Clear bit 1
    func_26AD60(act, 1);
    assert(func_26AD20(act, 1) == 0);
    assert(func_26AD20(act, 2) != 0);
}

// Case 2: func_0026AC40 guard and func_0026AD10 forwarder
static void test_guards_and_forwarders() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    mock.m_field3E = 0;

    // arg1 == 2 does not set bit 1
    func_0026AC40(act, 2);
    assert(func_26AD20(act, 1) == 0);

    // arg1 != 2 sets bit 1
    func_0026AC40(act, 1);
    assert(func_26AD20(act, 1) != 0);

    g_func_268530_called = 0;
    int count = func_0026AD10(act);
    assert(count == 7);
    assert(g_func_268530_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026AD80();
        test_flag_manipulation();
        test_guards_and_forwarders();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026AD80(); break;
        case 1: test_flag_manipulation(); break;
        case 2: test_guards_and_forwarders(); break;
        default: return 1;
    }
    return 0;
}
