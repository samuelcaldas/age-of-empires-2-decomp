#include "render_manager_state.h"
#include <cassert>
#include <cstdlib>

int D_004E8624 = 0;
int D_004E8940 = 0;

static void (*g_last_fn)() = 0;
static void *g_last_arg = 0;

extern "C" {
void func_001842f0() {}
void func_2264A0(void (*fn)()) { g_last_fn = fn; }
void func_00A80BB0() {}
void func_1F32D0(void *arg) { g_last_arg = arg; }
}

static void test_stub() {
    RenderManagerState mgr;
    assert(func_001853e0(&mgr) == 1);
}

static void test_engine_flags(int f5c, int f54, bool expect_set) {
    RenderManagerState mgr = {0};
    EngineCtx ctx = {0};
    ctx.field_5C = f5c;
    ctx.field_54 = f54;
    mgr.ctx_28 = &ctx;
    mgr.field_7C = 0;
    D_004E8624 = 0;
    int res = func_001853f0(&mgr);
    assert(res == 1 && D_004E8624 == 1);
    assert(mgr.field_7C == (expect_set ? 1 : 0));
}

static void test_factory_callback() {
    RenderManagerState mgr;
    g_last_fn = 0;
    int res = func_00185430(&mgr);
    assert(res == 1 && g_last_fn == func_001842f0);
}

static void test_renderer_setup() {
    RenderManagerState mgr = {0};
    D_004E8940 = 0;
    g_last_arg = 0;
    int res = func_00185460(&mgr);
    assert(res == 1 && mgr.field_2C == 1 && D_004E8940 == 1);
    assert(g_last_arg == (void *)func_00A80BB0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_stub(); return 0;
    case 1: test_engine_flags(1, 1, true); return 0;
    case 2: test_engine_flags(0, 1, false); return 0;
    case 3: test_engine_flags(1, 0, false); return 0;
    case 4: test_factory_callback(); return 0;
    case 5: test_renderer_setup(); return 0;
    default: return 1;
    }
}
