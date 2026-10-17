#include "render_manager_mouse_dispatch.h"
#include <cassert>
#include <cstdlib>

static int g_790_called = 0, g_7f0_called = 0, g_5f80_called = 0, g_mf0_called = 0, g_mac_called = 0;
static int g_f0_args[6] = {0};

static void mock_mac(void *) { g_mac_called++; }
static void mock_mf0(void *, int a1, int a2, int a3, int a4, int a5, int a6) {
    g_mf0_called++;
    g_f0_args[0] = a1; g_f0_args[1] = a2; g_f0_args[2] = a3;
    g_f0_args[3] = a4; g_f0_args[4] = a5; g_f0_args[5] = a6;
}

static void *g_mgr_vt[80] = {0};

struct FakeMgr {
    void *vt; char p1[0x28]; int f2c, f30;
    char p2[0x1A4]; void *f1d8; char p3[0xC]; int f1e8;
};

extern "C" {
void func_1DB790(void *, int) { g_790_called++; }
void func_1DB7F0(void *) { g_7f0_called++; }
void func_00185f80(void *, int flags, unsigned int coords, POINT *pt, int *b1, int *b2, int *b3, int *b4) {
    (void)flags; (void)coords; g_5f80_called++;
    pt->x = 100; pt->y = 200; *b1 = 1; *b2 = 2; *b3 = 3; *b4 = 4;
}
}

static void init_vt() {
    g_mgr_vt[41] = g_mgr_vt[43] = (void *)mock_mac; // MethodAC
    g_mgr_vt[58] = g_mgr_vt[60] = (void *)mock_mf0; // MethodF0
}

static void test_stub_6a20() {
    assert(func_00186a20() == 1);
}

static void test_inactive_guard() {
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 0;
    g_790_called = g_5f80_called = g_mf0_called = g_mac_called = 0;
    assert(func_00186950((RenderManagerMouseDispatch *)&mgr, 0, 0, 1, 2) == 1);
    assert(g_790_called == 0 && g_5f80_called == 0 && g_mf0_called == 0 && g_mac_called == 0);
}

static void test_active_with_1e8() {
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 1; mgr.f1e8 = 1;
    g_790_called = g_7f0_called = g_5f80_called = g_mf0_called = g_mac_called = 0;
    assert(func_00186950((RenderManagerMouseDispatch *)&mgr, 0, 0, 1, 2) == 1);
    assert(g_790_called == 1 && g_7f0_called == 1 && g_5f80_called == 1);
    assert(g_mf0_called == 1 && g_mac_called == 1);
}

static void test_active_without_1e8_params() {
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 1; mgr.f1e8 = 0;
    g_790_called = g_7f0_called = g_5f80_called = g_mf0_called = g_mac_called = 0;
    assert(func_00186950((RenderManagerMouseDispatch *)&mgr, 0, 0, 1, 2) == 1);
    assert(g_790_called == 0 && g_7f0_called == 0 && g_5f80_called == 1);
    assert(g_mf0_called == 1 && g_mac_called == 1);
    assert(g_f0_args[0] == 100 && g_f0_args[1] == 200 && g_f0_args[2] == 1);
    assert(g_f0_args[3] == 2 && g_f0_args[4] == 3 && g_f0_args[5] == 4);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stub_6a20(); return 0;
    case 1: test_inactive_guard(); return 0;
    case 2: test_active_with_1e8(); return 0;
    case 3: test_active_without_1e8_params(); return 0;
    default: return 1;
    }
}
