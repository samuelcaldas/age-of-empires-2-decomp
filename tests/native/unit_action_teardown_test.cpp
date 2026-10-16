#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_teardown.h"

static int g_method29_called = 0;
static int g_method34_called = 0;
static int g_last_method34_arg = 0;
static int g_func_139E10_called = 0;
static int g_func_1ECD00_called = 0;
static unsigned short g_mock_flags = 0;

static void mock_m29(void *self) { (void)self; g_method29_called++; }
static void mock_m34(void *self, int code) { (void)self; g_method34_called++; g_last_method34_arg = code; }

extern "C" {
    void func_00139E10(void *sublist) { (void)sublist; g_func_139E10_called++; }
    void func_1ECD00(void *field98, void *action) { (void)field98; (void)action; g_func_1ECD00_called++; }
    void func_26AD60(void *action, int flag) { (void)action; g_mock_flags &= (unsigned short)~flag; }
}

static void* dummy_vtable[120];

static void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[27] = (void*)mock_m29;
    dummy_vtable[34] = (void*)mock_m34;
}

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

// Case 0: func_0026C1F0 calls Method29 and Method34(-1)
static void test_func_0026C1F0() {
    init_mock_vtable();
    func_0026C1F0(nullptr);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    g_method29_called = 0;
    g_method34_called = 0;

    func_0026C1F0(act);
    assert(g_method29_called == 1);
    assert(g_method34_called == 1);
    assert(g_last_method34_arg == -1);
}

// Case 1: func_0026C2D0 calls Method29
static void test_func_0026C2D0() {
    init_mock_vtable();
    func_0026C2D0(nullptr);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    g_method29_called = 0;

    func_0026C2D0(act);
    assert(g_method29_called == 1);
}

// Case 2: func_0026C360 teardown and guard on state 2
static void test_func_0026C360() {
    func_0026C360(nullptr);

    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    // Guard on m_field39 == 2
    mock.m_field39 = 2;
    g_func_139E10_called = 0;
    func_0026C360(act);
    assert(g_func_139E10_called == 0);

    // When state != 2, proceeds
    mock.m_field39 = 1;
    g_mock_flags = 8;
    g_func_139E10_called = 0;
    g_func_1ECD00_called = 0;

    func_0026C360(act);
    assert(g_func_139E10_called == 1);
    assert(g_func_1ECD00_called == 1);
    assert((g_mock_flags & 8) == 0); // flag 8 cleared
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026C1F0();
        test_func_0026C2D0();
        test_func_0026C360();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026C1F0(); break;
        case 1: test_func_0026C2D0(); break;
        case 2: test_func_0026C360(); break;
        default: return 1;
    }
    return 0;
}
