#include "render_manager_render.h"
#include <cassert>
#include <cstdlib>

int D_004E89E0 = 0; char D_004E89E4 = 0; int D_004E89E8 = 0; char D_004E89EC = 0;
static int g_screen_avail = 0, g_m28_called = 0, g_m5c_called = 0;
static int g_m11c_called = 0, g_m124_called = 0, g_5cf0_called = 0;
static int g_tick = 500, g_5c70_ret = 1;

static int mock_tick() { g_tick += 100; return g_tick; }
static void mock_m28(void *, int a1) { g_m28_called = a1; }
static void mock_m5c(void *) { g_m5c_called++; }
static void mock_m11c(void *) { g_m11c_called++; }
static void mock_m124(void *) { g_m124_called++; }

static void *g_screen_vt[64] = {0}, *g_mgr_vt[80] = {0};
static struct { void *vt; } g_screen_obj = {g_screen_vt};

struct FakeMgr {
    void *vt; char p1[0x30]; int f34; char p2[0x34]; SubObj6C *f6c;
    char p3[0xC]; int f7c; char p4[0x148]; int f1c8; char p5[0xC];
    void *f1d8; char p6[4]; int f1e0; char p7[0x224]; int f408;
    char p8[0x10C]; int f518; char p9[0x3E0]; int f8fc;
};

extern "C" {
void func_00A80BB0() {}
ActiveScreen *func_1F26C0(void *) { return g_screen_avail ? (ActiveScreen *)&g_screen_obj : 0; }
int func_2261C0() { return mock_tick(); }
int func_00185c70(void *) { return g_5c70_ret; }
void func_00184b60(void *, int, int) {}
void func_00185cf0(void *) { g_5cf0_called++; }
void func_1DB6B0(void *) {}
void func_1AB1C0(void *, int) {}
}

static void init_vt() {
    g_screen_vt[8] = g_screen_vt[10] = (void *)mock_m28;
    g_screen_vt[21] = g_screen_vt[23] = (void *)mock_m5c;
    g_mgr_vt[69] = g_mgr_vt[71] = (void *)mock_m11c;
    g_mgr_vt[71] = g_mgr_vt[73] = (void *)mock_m124;
}

static void test_early_exit_mode1() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f1c8 = 1; mgr.f34 = 1;
    assert(func_00186e50((RenderManagerRender *)&mgr) == 1);
    mgr.f34 = 0;
    assert(func_00186e50((RenderManagerRender *)&mgr) == 0);
}

static void test_c70_failure() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f1c8 = 0; g_5c70_ret = 0;
    assert(func_00186e50((RenderManagerRender *)&mgr) == 0);
    g_5c70_ret = 1;
}

static void test_render_screen_active() {
    FakeMgr mgr = {g_mgr_vt};
    SubObj6C sub = {}; sub.field_44 = 1; mgr.f6c = &sub;
    mgr.f1c8 = 4; mgr.f408 = 1; mgr.f518 = 10;
    g_screen_avail = 1; g_m28_called = 0; g_m5c_called = 0;
    assert(func_00186e50((RenderManagerRender *)&mgr) == 1);
    assert(g_m28_called == 2 && g_m5c_called == 1 && mgr.f408 == 0 && mgr.f518 == 11);
    g_screen_avail = 0;
}

static void test_screen_fallback_and_timers() {
    FakeMgr mgr = {g_mgr_vt};
    SubObj6C sub = {}; sub.field_44 = 1; mgr.f6c = &sub;
    mgr.f1c8 = 4; mgr.f8fc = 1; D_004E89E8 = 1; g_5cf0_called = 0;
    g_tick = 5000; D_004E89E0 = 0; g_m11c_called = 0;
    assert(func_00186e50((RenderManagerRender *)&mgr) == 1);
    assert(g_5cf0_called == 1 && g_m11c_called == 1 && D_004E89E8 == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_early_exit_mode1(); return 0;
    case 1: test_c70_failure(); return 0;
    case 2: test_render_screen_active(); return 0;
    case 3: test_screen_fallback_and_timers(); return 0;
    default: return 1;
    }
}
