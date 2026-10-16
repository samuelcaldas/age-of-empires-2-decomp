#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_update_test_support.h"

// Stubs for extern C functions
int g_func_2643C0_called = 0;
int g_func_26AD20_ret = 0;
int g_func_26A540_called = 0;
int g_func_183070_called = 0;
int g_func_262BA0_called = 0;

extern "C" {
    void func_2643C0(void *action) {
        (void)action;
        g_func_2643C0_called++;
    }
    char func_26AD20(void *action, int flag) {
        (void)action; (void)flag;
        return g_func_26AD20_ret;
    }
    void func_26A540(void *action, int flag) {
        (void)action; (void)flag;
        g_func_26A540_called++;
    }
    int func_183070(void *fieldC) {
        (void)fieldC;
        g_func_183070_called++;
        return 42;
    }
    int func_262BA0(int target, unsigned char field35) {
        (void)target; (void)field35;
        g_func_262BA0_called++;
        return 84;
    }
}

// Mock vtable for ActionRebind
int g_method29_called = 0;
int g_method30_called = 0;
int g_method61_called = 0;
int g_method62_called = 0;
void *g_last_m61_world = nullptr;
void *g_last_m62_world = nullptr;
int g_last_m61_a2 = -1;
int g_last_m61_a3 = 0;
int g_last_m61_a4 = 0;
int g_last_m62_a2 = -1;
int g_last_m62_a3 = 0;
int g_last_m62_a4 = 0;

static void mock_m29(void *self) { (void)self; g_method29_called++; }
static void mock_m30(void *self) { (void)self; g_method30_called++; }
static void mock_m61(void *self, void *w, int a2, int a3, int a4) {
    (void)self;
    g_method61_called++;
    g_last_m61_world = w;
    g_last_m61_a2 = a2;
    g_last_m61_a3 = a3;
    g_last_m61_a4 = a4;
}
static void mock_m62(void *self, void *w, int a2, int a3, int a4) {
    (void)self;
    g_method62_called++;
    g_last_m62_world = w;
    g_last_m62_a2 = a2;
    g_last_m62_a3 = a3;
    g_last_m62_a4 = a4;
}

static void* dummy_vtable[120];

void init_mock_vtable() {
    for (int i = 0; i < 120; ++i) {
        dummy_vtable[i] = (void*)0;
    }
    dummy_vtable[27] = (void*)mock_m29;
    dummy_vtable[28] = (void*)mock_m30;
    dummy_vtable[59] = (void*)mock_m61;
    dummy_vtable[60] = (void*)mock_m62;
}

ActionMock::ActionMock() {
    memset(this, 0, sizeof(*this));
    vtable = dummy_vtable;
}
