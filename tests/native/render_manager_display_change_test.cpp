#include "render_manager_display_change.h"
#include <cassert>
#include <cstdlib>

static int g_screen_avail = 0, g_m58_called = 0, g_m58_a1 = 0, g_m58_a2 = 0;
static int g_m114_called = 0, g_1ab120_called = 0;

static void mock_m58(void *, int a1, int a2) { g_m58_called++; g_m58_a1 = a1; g_m58_a2 = a2; }
static void mock_m114(void *) { g_m114_called++; }

static void *g_screen_vt[64] = {0}, *g_mgr_vt[80] = {0};
static struct { void *vt; } g_screen_obj = {g_screen_vt};

struct FakeMgr {
    void *vt; char p1[0x24]; SubObj28 *f28; char p2[0x40]; SubObj6C *f6c;
};

extern "C" {
void func_00A80BB0() {}
ActiveScreen *func_1F26C0(void *) { return g_screen_avail ? (ActiveScreen *)&g_screen_obj : 0; }
void func_1AB120(void *) { g_1ab120_called++; }
}

static void init_vt() {
    g_screen_vt[20] = g_screen_vt[22] = (void *)mock_m58;
    g_mgr_vt[67] = g_mgr_vt[69] = (void *)mock_m114;
}

static void test_stub() {
    assert(func_00187470() == 1);
}

static void test_early_exit_flag1() {
    FakeMgr mgr = {g_mgr_vt};
    g_m114_called = 0;
    assert(func_001873a0((RenderManagerDisplayChange *)&mgr, 0, 0, 1) == 1);
    assert(g_m114_called == 0);
}

static void test_display_change_field6c_null() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f6c = 0; g_m114_called = 0; g_1ab120_called = 0;
    assert(func_001873a0((RenderManagerDisplayChange *)&mgr, 0, 0, 0) == 1);
    assert(g_1ab120_called == 0 && g_m114_called == 1);
}

static void test_display_change_full() {
    FakeMgr mgr = {g_mgr_vt};
    SubObj28 s28 = {}; SubObj6C s6c = {};
    s6c.field_34 = 1024; s6c.field_38 = 768;
    mgr.f28 = &s28; mgr.f6c = &s6c;
    g_screen_avail = 1; g_m58_called = 0; g_m114_called = 0; g_1ab120_called = 0;
    assert(func_001873a0((RenderManagerDisplayChange *)&mgr, 0, 0, 0) == 1);
    assert(g_1ab120_called == 1 && s28.field_A4 == 1024 && s28.field_A8 == 768);
    assert(g_m58_called == 1 && g_m58_a1 == 1024 && g_m58_a2 == 768 && g_m114_called == 1);
    g_screen_avail = 0;
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stub(); return 0;
    case 1: test_early_exit_flag1(); return 0;
    case 2: test_display_change_field6c_null(); return 0;
    case 3: test_display_change_full(); return 0;
    default: return 1;
    }
}
