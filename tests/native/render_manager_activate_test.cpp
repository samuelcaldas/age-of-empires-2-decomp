#include "render_manager_activate.h"
#include <cassert>
#include <cstdlib>

static int g_screen_avail = 0, g_mf8_called = 0, g_m104_called = 0, g_m108_called = 0;
static int g_m10c_called = 0, g_m110_called = 0, g_185f00_calls = 0, g_1880d0_ret = 1, g_185dc0_ret = 0;

static void mock_mf8(void *) { g_mf8_called++; }
static void mock_m104(void *) { g_m104_called++; }
static void mock_m108(void *) { g_m108_called++; }
static int  mock_m10c(void *) { g_m10c_called++; return 1; }
static int  mock_m110(void *) { g_m110_called++; return 0; }

static void *g_screen_vt[64] = {0}, *g_mgr_vt[80] = {0};
static struct { void *vt; } g_screen_obj = {g_screen_vt};

struct FakeMgr {
    void *vt; char p1[0x30]; int f34; char p2[0x190]; int f1c8;
    char p3[0x950]; int fb1c;
};

extern "C" {
void func_00A80BB0() {}
ActiveScreen *func_1F26C0(void *) { return g_screen_avail ? (ActiveScreen *)&g_screen_obj : 0; }
void func_185F00(void *, int, int) { g_185f00_calls++; }
int func_1880D0(void *) { return g_1880d0_ret; }
int func_185DC0(void *, int) { return g_185dc0_ret; }
}

static void init_vt() {
    g_screen_vt[60] = g_screen_vt[62] = (void *)mock_mf8;
    g_mgr_vt[63] = g_mgr_vt[65] = (void *)mock_m104;
    g_mgr_vt[64] = g_mgr_vt[66] = (void *)mock_m108;
    g_mgr_vt[65] = g_mgr_vt[67] = (void *)mock_m10c;
    g_mgr_vt[66] = g_mgr_vt[68] = (void *)mock_m110;
}

static void test_stubs() {
    assert(func_00187300() == 1 && func_00187310() == 1);
    assert(func_00187350() == 1 && func_00187390() == 1);
}

static void test_method_10c_and_110() {
    FakeMgr mgr = {g_mgr_vt};
    g_m10c_called = g_m110_called = 0;
    assert(func_00187320((RenderManagerActivate *)&mgr) == 1 && g_m10c_called == 1);
    assert(func_00187360((RenderManagerActivate *)&mgr) == 0 && g_m110_called == 1);
}

static void test_activate_window() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f1c8 = 4; mgr.fb1c = 1; g_screen_avail = 1;
    g_mf8_called = g_m104_called = g_185f00_calls = 0;
    assert(func_00187170((RenderManagerActivate *)&mgr, 0, 0, 1) == 1);
    assert(mgr.f34 == 1 && mgr.fb1c == 0 && g_185f00_calls == 1);
    assert(g_mf8_called == 1 && g_m104_called == 1);
    g_screen_avail = 0;
}

static void test_deactivate_window() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f1c8 = 6; mgr.fb1c = 0; g_1880d0_ret = 1; g_185dc0_ret = 0;
    g_m108_called = g_185f00_calls = 0;
    assert(func_00187170((RenderManagerActivate *)&mgr, 0, 0, 0) == 1);
    assert(mgr.f34 == 0 && mgr.fb1c == 1 && g_185f00_calls == 1 && g_m108_called == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stubs(); return 0;
    case 1: test_method_10c_and_110(); return 0;
    case 2: test_activate_window(); return 0;
    case 3: test_deactivate_window(); return 0;
    default: return 1;
    }
}
