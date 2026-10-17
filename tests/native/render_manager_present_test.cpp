#include "render_manager_present.h"
#include <cassert>
#include <cstdlib>

void *D_004E8944 = 0;

static int g_f6c0_calls = 0;
static int g_1f3440_calls = 0;
static int g_189220_calls = 0;
static int g_185cf0_calls = 0;
static int g_225f80_calls = 0;
static int g_1ab1c0_calls = 0;

extern "C" {
void func_00A80BB0() {}
void func_25F6C0(void *item, void *field_88) { (void)item; (void)field_88; g_f6c0_calls++; }
void func_1F3440(void *arg) { assert(arg == (void *)func_00A80BB0); g_1f3440_calls++; }
void func_189220(void *d44, void *field_88) { (void)d44; (void)field_88; g_189220_calls++; }
void func_185CF0() { g_185cf0_calls++; }
int func_225F80(int f2c, RECT *rect, int zero) { (void)f2c; (void)rect; (void)zero; g_225f80_calls++; return 1; }
void func_1AB1C0(void *f6c, RECT *rect) { (void)f6c; (void)rect; g_1ab1c0_calls++; }
}

static void test_bc0_inactive() {
    RenderManagerPresent mgr = {0};
    mgr.field_88 = (void *)0x8888;
    g_f6c0_calls = 0;
    assert(func_00185bc0(&mgr) == 1 && g_f6c0_calls == 0);
}

static void test_bc0_active() {
    RenderManagerPresent mgr = {0};
    mgr.field_88 = 0;
    D_004E8944 = (void *)0x9999;
    SubObj404B sub = {0};
    sub.count = 2;
    void *items[2] = {(void *)0x1, (void *)0x2};
    sub.items = items;
    mgr.field_404 = &sub;

    g_f6c0_calls = 0; g_1f3440_calls = 0; g_189220_calls = 0;
    assert(func_00185bc0(&mgr) == 1);
    assert(g_f6c0_calls == 2 && g_1f3440_calls == 1 && g_189220_calls == 1);
}

static void test_c60_stub() {
    RenderManagerPresent mgr = {0};
    assert(func_00185c60(&mgr) == 1);
}

static void test_c70_unready() {
    RenderManagerPresent mgr = {0};
    mgr.field_30 = 0;
    g_185cf0_calls = 0;
    assert(func_00185c70(&mgr) == 0 && g_185cf0_calls == 1);
}

static void test_c70_skip_refresh() {
    RenderManagerPresent mgr = {0};
    mgr.field_30 = 1;
    mgr.field_34 = 1;
    g_225f80_calls = 0;
    assert(func_00185c70(&mgr) == 1 && g_225f80_calls == 0);
}

static void test_c70_refresh() {
    RenderManagerPresent mgr = {0};
    mgr.field_30 = 1;
    mgr.field_34 = 0;
    g_225f80_calls = 0;
    g_1ab1c0_calls = 0;
    assert(func_00185c70(&mgr) == 0);
    assert(g_225f80_calls == 1 && g_1ab1c0_calls == 1);
}

static void test_cf0_stub() {
    func_00185cf0();
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_bc0_inactive(); return 0;
    case 1: test_bc0_active(); return 0;
    case 2: test_c60_stub(); return 0;
    case 3: test_c70_unready(); return 0;
    case 4: test_c70_skip_refresh(); return 0;
    case 5: test_c70_refresh(); return 0;
    case 6: test_cf0_stub(); return 0;
    default: return 1;
    }
}
