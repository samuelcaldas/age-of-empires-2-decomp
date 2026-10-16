#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "unit_action_advance_fixture.h"

int g_func_26A540_called = 0;
int g_func_1AAB30_called = 0;
int g_func_26A700_called = 0;
int g_func_25F6E0_called = 0;
int g_func_1AAB70_called = 0;
int g_func_26A680_called = 0;
unsigned char g_last_frame = 0;

static void* dummy_vtable[120];

ActionMock::ActionMock() {
    memset(this, 0, sizeof(*this));
    vtable = dummy_vtable;
}

float mock_method32_ret = 0.5f;
static float mock_m32(void *self) {
    (void)self;
    return mock_method32_ret;
}

void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[32] = (void*)mock_m32;
}

extern "C" {
    void func_0026A540(void *action, int flag) {
        (void)action; (void)flag;
        g_func_26A540_called++;
    }
    int func_001AAB30() {
        g_func_1AAB30_called++;
        return 0x1234;
    }
    int func_26A700(void *action, int *out1, int *out2) {
        (void)action;
        *out1 = 11;
        *out2 = 22;
        g_func_26A700_called++;
        return 1;
    }
    void func_25F6E0(void *field38, int a1, int a2, int a3, int a4, int a5) {
        (void)field38; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
        g_func_25F6E0_called++;
    }
    void func_001AAB70(int obj) {
        (void)obj;
        g_func_1AAB70_called++;
    }
    void func_26A680(void *action, unsigned char frame) {
        (void)action;
        g_func_26A680_called++;
        g_last_frame = frame;
    }
}

static void test_func_00268EB0() {
    assert(func_00268EB0(0, nullptr, 2.0f) == 0.0f);
    struct Entry { short pad; short val; } entries[3];
    entries[0].pad = 0; entries[0].val = 10;
    entries[1].pad = 0; entries[1].val = 20;
    entries[2].pad = 0; entries[2].val = -5;
    float res = func_00268EB0(3, entries, 0.5f);
    assert(std::fabs(res - 12.5f) < 0.001f);
}

static void test_func_00268F00() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_field10[100];
    dummy_field10[0x3A] = 10;
    mock.m_field10 = (int)dummy_field10;

    mock.m_field35 = 2;
    g_func_26A680_called = 0;
    func_00268F00(act, 5);
    assert(g_func_26A680_called == 1 && g_last_frame == 7);
    mock.m_field35 = 8;
    func_00268F00(act, 4);
    assert(g_last_frame == 2);
    mock.m_field35 = 1;
    func_00268F00(act, -3);
    assert(g_last_frame == 8);
}

static void test_setters() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    func_00268F40(act, 42, 3.14f);
    assert(mock.m_field3C == 42);
    assert(std::fabs(*(float*)((char*)act + 0x40) - 3.14f) < 0.001f);

    char dummy_field4[100];
    *(short*)&dummy_field4[0x54] = 10;
    mock.m_field4 = dummy_field4;
    func_00268F50(act, 1, 0, 1.0f);
    assert(std::fabs(*(float*)((char*)act + 0x40) - 4.14f) < 0.001f);
    func_00268F50(act, 0, 1, 15.0f);
    assert(std::fabs(*(float*)((char*)act + 0x40) - 10.0f) < 0.001f);
}

static void test_func_00268FB0() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_field4[100];
    *(short*)&dummy_field4[0x3E] = 5;
    mock.m_field4 = dummy_field4;
    mock.m_field30 = 2.0f;

    int done = func_00268FB0(act, 1.5f);
    assert(done == 0 && std::fabs(mock.m_field30 - 3.5f) < 0.001f);
    done = func_00268FB0(act, 2.0f);
    assert(done == 1 && std::fabs(mock.m_field30 - 5.0f) < 0.001f);
    mock.m_field30 = 0.5f;
    done = func_00268FB0(act, -1.0f);
    assert(done == 0 && std::fabs(mock.m_field30 - 1.0f) < 0.001f);
}

static void test_func_00268DE0() {
    init_mock_vtable();
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_field4[100] = {0};
    *(void**)&dummy_field4[0x38] = (void*)0x9999;
    mock.m_field4 = dummy_field4;
    mock.m_field30 = 1.2f;
    mock_method32_ret = 0.5f;

    g_func_26A540_called = g_func_25F6E0_called = 0;
    func_00268DE0(act);
    assert(g_func_26A540_called == 1 && mock.m_field30 == 0.0f && g_func_25F6E0_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_00268EB0();
        test_func_00268F00();
        test_setters();
        test_func_00268FB0();
        test_func_00268DE0();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_00268EB0(); break;
        case 1: test_func_00268F00(); break;
        case 2: test_setters(); break;
        case 3: test_func_00268FB0(); break;
        case 4: test_func_00268DE0(); break;
        default: return 1;
    }
    return 0;
}
