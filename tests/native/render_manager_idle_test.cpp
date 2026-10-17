#include "render_manager_idle.h"
#include <cassert>
#include <cstdlib>

int D_004E8940 = 0x40, D_004E8958 = 0, D_004E89C0 = 0xC0;
static int g_screen_avail = 0, g_m54_called = 0, g_m128_called = 0, g_m12c_called = 0;
static int g_mc8_called = 0, g_4b60_last_timer = 0, g_80e0_ret = 1;
static int g_tick = 1000;

static int mock_tick() { g_tick += 50; return g_tick; }
static void mock_m54(void *) { g_m54_called++; }
static int mock_mc8(void *, int a1, int, int, int) { g_mc8_called = a1; return 1; }
static void mock_m128(void *) { g_m128_called++; }
static void mock_m12c(void *) { g_m12c_called++; }

static void *g_screen_vt[64] = {0}, *g_mgr_vt[80] = {0};
static struct { void *vt; } g_screen_obj = {g_screen_vt};

struct FakeMgr {
    void *vt; char p1[0x18]; int f1c; char p2[0xC]; int f2c, f30, f34;
    char p3[0x34]; SubObj6C *f6c; char p4[0x18]; int f88; char p5[0x120];
    void *f1ac; char p6[0x18]; int f1c8; char p7[0x734]; int f900, f904;
};

extern "C" {
void func_00A80BB0() {}
ActiveScreen *func_1F26C0(void *) { return g_screen_avail ? (ActiveScreen *)&g_screen_obj : 0; }
int func_2261C0() { return mock_tick(); }
void func_00184b60(int, int t, int) { g_4b60_last_timer = t; }
int func_1880E0(void *) { return g_80e0_ret; }
int func_18AFE0(void *) { return 20; }
}

static void init_vt() {
    g_screen_vt[19] = g_screen_vt[21] = (void *)mock_m54;
    g_mgr_vt[48] = g_mgr_vt[50] = (void *)mock_mc8;
    g_mgr_vt[72] = g_mgr_vt[74] = (void *)mock_m128;
    g_mgr_vt[73] = g_mgr_vt[75] = (void *)mock_m12c;
}

static void test_can_idle() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f30 = 0; assert(func_00186930((RenderManagerIdle *)&mgr) == 1);
    mgr.f30 = 1; assert(func_00186930((RenderManagerIdle *)&mgr) == 0);
}

static void test_idle_guards() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f30 = 0; mgr.f2c = 1; assert(func_00186770((RenderManagerIdle *)&mgr) == 0);
    mgr.f30 = 1; mgr.f2c = 0; assert(func_00186770((RenderManagerIdle *)&mgr) == 0);
    mgr.f30 = 1; mgr.f2c = 1; mgr.f1c = 1; assert(func_00186770((RenderManagerIdle *)&mgr) == 1);
}

static void test_idle_paint_and_stats() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f30 = 1; mgr.f2c = 1; mgr.f1c = 0;
    mgr.f34 = 1; mgr.f1c8 = 0; SubObj6C sub = {}; mgr.f6c = &sub;
    D_004E8958 = 0; g_mc8_called = 0; mgr.f88 = 1;
    assert(func_00186770((RenderManagerIdle *)&mgr) == 1);
    assert(mgr.f1c == 1 && g_mc8_called == D_004E8940 && D_004E8958 > 0);
    assert(g_4b60_last_timer == 16);
}

static void test_idle_screen_and_subsystems() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f30 = 1; mgr.f2c = 1; mgr.f1c = 0;
    g_screen_avail = 1; g_m54_called = g_m128_called = g_m12c_called = 0;
    mgr.f1ac = (void *)0x999; g_80e0_ret = 1;
    mgr.f900 = 1; mgr.f904 = 1;
    assert(func_00186770((RenderManagerIdle *)&mgr) == 1);
    assert(g_m54_called == 1 && g_4b60_last_timer == 14);
    assert(g_m128_called == 1 && g_m12c_called == 1);
    g_screen_avail = 0;
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_can_idle(); return 0;
    case 1: test_idle_guards(); return 0;
    case 2: test_idle_paint_and_stats(); return 0;
    case 3: test_idle_screen_and_subsystems(); return 0;
    default: return 1;
    }
}
