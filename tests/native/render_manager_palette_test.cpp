#include "render_manager_palette.h"
#include <cassert>
#include <cstdlib>

static int g_me0_called = 0, g_m118_ret = 1;
static int g_1ab180_calls = 0, g_1ab370_calls = 0, g_1ab1b0_calls = 0;
static int g_1abd90_calls = 0, g_1ab1c0_calls = 0;

static void mock_me0(void *, int, int, int, int) { g_me0_called++; }
static int  mock_m118(void *) { return g_m118_ret; }

static void *g_mgr_vt[80] = {0};

struct FakeMgr {
    void *vt; char p1[0x68]; SubObj6C *f6c; void *f70;
    char p2[0x154]; int f1c8;
};

extern "C" {
void func_1AB180(void *) { g_1ab180_calls++; }
void func_1AB370(void *, int, int, void *) { g_1ab370_calls++; }
int  func_1AB1B0(void *) { g_1ab1b0_calls++; return 42; }
void func_1ABD90(void *, int, int) { g_1abd90_calls++; }
void func_1AB1C0(void *, int) { g_1ab1c0_calls++; }
}

static void init_vt() {
    g_mgr_vt[54] = g_mgr_vt[56] = (void *)mock_me0;
    g_mgr_vt[68] = g_mgr_vt[70] = (void *)mock_m118;
}

static void test_stub_and_early_exit() {
    FakeMgr mgr = {g_mgr_vt};
    assert(func_00187650() == 1);
    g_me0_called = 0;
    assert(func_00187480((RenderManagerPalette *)&mgr, 10, 0, 10, 0) == 1);
    assert(g_me0_called == 0);
}

static void test_palette_handler_branches() {
    FakeMgr mgr = {g_mgr_vt};
    SubObj6C sub = {};
    mgr.f6c = &sub; mgr.f1c8 = 0;
    sub.field_44 = 1; g_me0_called = 0;
    assert(func_00187480((RenderManagerPalette *)&mgr, 5, 0, 10, 0) == 1);
    assert(g_me0_called == 1);
    sub.field_44 = 0; sub.field_45 = 0; g_1ab370_calls = 0;
    assert(func_00187480((RenderManagerPalette *)&mgr, 5, 0, 10, 0) == 1);
    assert(g_1ab370_calls == 1);
}

static void test_palette_query_560() {
    FakeMgr mgr = {g_mgr_vt};
    mgr.f6c = 0;
    assert(func_00187560((RenderManagerPalette *)&mgr) == 1);
    SubObj6C sub = {}; sub.field_44 = 1; mgr.f6c = &sub;
    g_1ab1b0_calls = 0;
    assert(func_00187560((RenderManagerPalette *)&mgr) == 42 && g_1ab1b0_calls == 1);
}

static void test_palette_update_5d0() {
    FakeMgr mgr = {g_mgr_vt};
    g_m118_ret = 0;
    assert(func_001875d0((RenderManagerPalette *)&mgr) == 0);
    g_m118_ret = 1; mgr.f70 = (void *)0x70; SubObj6C sub = {}; mgr.f6c = &sub;
    g_1abd90_calls = g_1ab1c0_calls = 0;
    assert(func_001875d0((RenderManagerPalette *)&mgr) == 1);
    assert(g_1abd90_calls == 1 && g_1ab1c0_calls == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    init_vt();
    switch (std::atoi(args[1])) {
    case 0: test_stub_and_early_exit(); return 0;
    case 1: test_palette_handler_branches(); return 0;
    case 2: test_palette_query_560(); return 0;
    case 3: test_palette_update_5d0(); return 0;
    default: return 1;
    }
}
