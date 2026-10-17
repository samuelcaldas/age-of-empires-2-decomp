#include "render_manager_accessors.h"
#include <cassert>
#include <cstdlib>

static int g_alloc_fail = 0;
static int g_init_called = 0;
static int g_226610_calls = 0;
static int g_1c9f00_calls = 0;
static int g_1880e0_ret = 0;
static int g_190af0_calls = 0;
static char g_dummy_alloc[0x9D94];

extern "C" {
void *func_100850(int sz) { assert(sz == 0x9D94); return g_alloc_fail ? 0 : g_dummy_alloc; }
void *func_32E8C0(void *obj) { assert(obj == g_dummy_alloc); g_init_called++; return obj; }
int func_226610(int c, int p1, int p2, int p3) { (void)c; (void)p1; (void)p2; (void)p3; g_226610_calls++; return 42; }
void func_1C9F00(void *f) { (void)f; g_1c9f00_calls++; }
int func_1880E0() { return g_1880e0_ret; }
int func_190AF0(void *f) { (void)f; g_190af0_calls++; return 100; }
}

static void test_d00() {
    g_alloc_fail = 0; g_init_called = 0;
    assert(func_00185d00() == g_dummy_alloc && g_init_called == 1);
    g_alloc_fail = 1; g_init_called = 0;
    assert(func_00185d00() == 0 && g_init_called == 0);
}

static void test_d40_d60() {
    RenderManagerAccessors mgr = {0};
    mgr.field_2C = 0x1234;
    g_226610_calls = 0;
    assert(func_00185d40(&mgr) == 42 && g_226610_calls == 1);
    func_00185d60(&mgr, 10, 20);
    assert(mgr.field_1CC == 10 && mgr.field_1D0 == 20);
}

static void test_d70() {
    RenderManagerAccessors mgr = {0};
    PlayerSub404 sub = {0};
    sub.field_50 = 5;
    mgr.field_404 = &sub;
    g_1c9f00_calls = 0;
    func_00185d70(&mgr, 3);
    assert(sub.field_98 == 3 && g_1c9f00_calls == 1);
    func_00185d70(&mgr, 5);
    assert(sub.field_98 == 3 && g_1c9f00_calls == 1);
}

static void test_dc0() {
    RenderManagerAccessors mgr = {0};
    mgr.field_1C8 = 7;
    assert(func_00185dc0(&mgr, 1) == 0);
    mgr.field_1C8 = 0;
    g_190af0_calls = 0;
    assert(func_00185dc0(&mgr, 1) == 100 && g_190af0_calls == 1);
    g_1880e0_ret = 1; g_190af0_calls = 0;
    assert(func_00185dc0(&mgr, 0) == 100 && g_190af0_calls == 1);
    g_1880e0_ret = 0; g_190af0_calls = 0;
    assert(func_00185dc0(&mgr, 0) == 0 && g_190af0_calls == 0);
}

static void test_e20() {
    RenderManagerAccessors mgr = {0};
    assert(func_00185e20(&mgr, 0) == 0);
    SurfaceEntry entries[4] = {{0}};
    mgr.field_1FC = entries;
    assert(func_00185e20(&mgr, 2) == &entries[2]);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_d00(); return 0;
    case 1: test_d40_d60(); return 0;
    case 2: test_d70(); return 0;
    case 3: test_dc0(); return 0;
    case 4: test_e20(); return 0;
    default: return 1;
    }
}
