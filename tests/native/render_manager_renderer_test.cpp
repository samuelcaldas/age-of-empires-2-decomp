#include "render_manager_renderer.h"
#include <cassert>
#include <cstdlib>

ScreenDesc D_00598930;

static int g_step = 0;
static ScreenDesc *g_last_desc = 0;
static void *g_last_f0c = 0;
static int g_last_f2c = 0;
static int g_last_f38 = 0;
static int g_last_c1 = 0;
static int g_last_c2 = 0;
static int g_last_t2 = 0;
static int g_last_t3 = 0;
static long long g_last_stack = -1;

extern "C" {
void func_00A80BB0() {}
void func_1F3320(void *arg) { assert(arg == (void *)func_00A80BB0); g_step = 1; }
void func_1AAB80(ScreenDesc *desc) { assert(g_step == 1 && desc == &D_00598930); g_step = 2; }
void func_1AACC0(ScreenDesc *desc, void *f0c, int f2c, int f38, char c1, char c2, int t2, int t3, long long stack_arg) {
    assert(g_step == 2);
    g_last_desc = desc;
    g_last_f0c = f0c;
    g_last_f2c = f2c;
    g_last_f38 = f38;
    g_last_c1 = c1;
    g_last_c2 = c2;
    g_last_t2 = t2;
    g_last_t3 = t3;
    g_last_stack = stack_arg;
    g_step = 3;
}
void func_1ABD90(void *f70, int zero, int ff) {
    assert(g_step == 3 && f70 == (void *)0x7777 && zero == 0 && ff == 0xFF);
    g_step = 4;
}
void func_1AB1C0(ScreenDesc *desc, int zero) {
    assert(g_step == 4 && desc == &D_00598930 && zero == 0);
    g_step = 5;
}
void func_1F3340(void *arg) {
    assert(g_step == 5 && arg == (void *)func_00A80BB0);
    g_step = 6;
}
}

static void test_renderer_init() {
    RenderManagerInit mgr = {0};
    EngineSubCtx ctx = {0};
    ctx.f0c = (void *)0x1234;
    ctx.fa4 = 444;
    ctx.fa8 = 888;
    mgr.ctx_28 = &ctx;
    mgr.field_2C = 222;
    mgr.field_38 = 333;
    D_00598930.f0c = (void *)0x7777;

    g_step = 0;
    int res = func_001854b0(&mgr);
    assert(res == 1 && g_step == 6);
    assert(mgr.field_6C == &D_00598930);
    assert(mgr.field_70 == (void *)0x7777);
    assert(g_last_f0c == (void *)0x1234 && g_last_f2c == 222 && g_last_f38 == 333);
    assert(g_last_c1 == 2 && g_last_c2 == 2 && g_last_t2 == 444 && g_last_t3 == 888 && g_last_stack == 0);
}

static void test_stub() {
    RenderManagerInit mgr = {0};
    assert(func_00185560(&mgr) == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_renderer_init(); return 0;
    case 1: test_stub(); return 0;
    default: return 1;
    }
}
