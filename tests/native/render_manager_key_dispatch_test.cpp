#include "render_manager_key_dispatch.h"
#include <cassert>
#include <cstdlib>

int D_004E89CC = 0, D_004E89D0 = 0, D_004E89D4 = 0, D_004E89D8 = 0, D_004E89DC = 0;
const char D_00491A28[] = "Status Screen", D_00491A38[] = "Comm Cancel";
static int g_screen_avail = 0, g_1908_called = 0, g_18bf_called = 0, g_1fb8_called = 0, g_1f29_called = 0;
static int g_mf4_ret = 1, g_f4_called = 0;

static int mock_mf4(void *, int, int, int, int, int) { g_f4_called++; return g_mf4_ret; }
static void *g_screen_obj = 0;
static void *g_mgr_vt[80] = {0};

struct FakeMgr {
    void *vt; char p1[0x24]; SubObj28 *f28; int f2c, f30;
    char p2[0x178]; void *f1ac;
};

extern "C" {
void func_00A80BB0() {}
ActiveScreen *func_1F26C0(void *) { return g_screen_avail ? (ActiveScreen *)&g_screen_obj : 0; }
void *func_1F2700(void *, const char *) { return &g_screen_obj; }
void func_1908B0(void *, int) { g_1908_called++; }
void func_18BFA0(void *, int) { g_18bf_called++; }
void func_1FB860(void *, int, const char *, int, int, int, int) { g_1fb8_called++; }
void func_1F2900(void *, const char *, int) { g_1f29_called++; }
short func_225590(int vkey) { return (vkey == 17) ? (short)0x8000 : 0; }
}

static void init_vt() {
    g_mgr_vt[59] = g_mgr_vt[61] = (void *)mock_mf4; // MethodF4
}

static void test_stub_6c10() {
    assert(func_00186c10() == 1);
}

static void test_inactive_guard() {
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 0;
    g_f4_called = 0;
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 0, 0, 0, 0) == 1);
    assert(g_f4_called == 0);
}

static void test_syskeydown_suppression() {
    SubObj28 sub = {}; sub.field_54 = 1;
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 1; mgr.f2c = 42; mgr.f28 = &sub;
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 42, 260, 18, 0) == 0);
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 42, 260, 32, 0) == 0);
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 42, 260, 121, 0) == 0);
    sub.field_54 = 0;
    g_mf4_ret = 1;
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 42, 260, 18, 0) == 1);
}

static void test_escape_cancel_and_f4() {
    SubObj28 sub = {};
    FakeMgr mgr = {g_mgr_vt}; mgr.f30 = 1; mgr.f28 = &sub; mgr.f1ac = (void *)0x888;
    g_screen_avail = 1; g_1908_called = g_18bf_called = g_1fb8_called = g_1f29_called = 0;
    g_mf4_ret = 1;
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 0, 0, 27, 0x1234) == 1);
    assert(g_1908_called == 1 && g_18bf_called == 2 && g_1fb8_called == 1 && g_1f29_called == 1);
    assert(D_004E89CC == 27 && D_004E89D0 == 0x1234 && D_004E89D4 == 1 && D_004E89D8 == 0);
    g_mf4_ret = 0;
    assert(func_00186a30((RenderManagerKeyDispatch *)&mgr, 0, 0, 99, 0) == 0);
    g_screen_avail = 0;
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stub_6c10(); return 0;
    case 1: test_inactive_guard(); return 0;
    case 2: test_syskeydown_suppression(); return 0;
    case 3: test_escape_cancel_and_f4(); return 0;
    default: return 1;
    }
}
