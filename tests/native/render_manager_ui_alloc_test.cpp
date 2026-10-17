#include "render_manager_ui_alloc.h"
#include <cassert>
#include <cstdlib>

void *D_004E8944 = (void *)0x8944;
void *D_004E8948 = 0;
void *D_004E8984 = (void *)0x8984;
void *D_004E8988 = (void *)0x8988;

static int g_alloc_fail = 0;
static int g_ctor_called = 0;
static int g_dtor_called = 0;
static int g_slot88_called = 0;

class TestUiAllocManager : public RenderManagerUiAlloc {
public:
    void slot_88() { g_slot88_called++; }
};

extern "C" {
void *func_100850(int size) {
    if (g_alloc_fail) return 0;
    return (void *)(size == 0x47C0 ? 0x47C00 : 0);
}
void func_18A010(void *obj, int f2c, unsigned char f38, void *d8944, void *fbc) {
    assert(obj == (void *)0x47C00 && f2c == 42 && f38 == 7 && d8944 == (void *)0x8944);
    (void)fbc;
    g_ctor_called = 1;
}
void func_189F20(void *, void *) {}
void func_189E00(void *, void *) {}
void func_189E40(void *, void *) {}
void func_189E60(void *, void *) {}
void func_189E70(void *, void *) {}
void func_189E50(void *, void *) {}
void func_32FBC0(void *f404, void *obj) { assert(f404 == (void *)0x4040 && obj == (void *)0x47C00); }
void func_192CD0(void *obj, void *arg) { assert(obj == (void *)0x47C00 && (arg == (void *)0x8984 || arg == (void *)0x8988)); }
void func_18A570(void *obj, int one) { assert(obj == (void *)0x47C00 && one == 1); g_dtor_called = 1; }
}

static void test_alloc_success() {
    TestUiAllocManager mgr;
    EngineCtx47C0 ctx = {0};
    ctx.f38 = 7;
    mgr.ctx_28 = &ctx;
    mgr.field_2C = 42;
    mgr.field_404 = (void *)0x4040;
    g_alloc_fail = 0;
    g_ctor_called = 0;
    D_004E8948 = 0;
    int res = func_00185660(&mgr);
    assert(res == 1 && g_ctor_called == 1 && mgr.field_1AC == (void *)0x47C00 && D_004E8948 == (void *)0x47C00);
}

static void test_alloc_fail() {
    TestUiAllocManager mgr;
    g_alloc_fail = 1;
    int res = func_00185660(&mgr);
    assert(res == 0 && mgr.field_1AC == 0);
}

static void test_teardown_active() {
    TestUiAllocManager mgr;
    mgr.field_1AC = (void *)0x47C00;
    D_004E8948 = (void *)0x47C00;
    g_dtor_called = 0;
    g_slot88_called = 0;
    func_00185760(&mgr);
    assert(g_dtor_called == 1 && g_slot88_called == 1);
    assert(mgr.field_1AC == 0 && D_004E8948 == 0);
}

static void test_teardown_empty() {
    TestUiAllocManager mgr;
    mgr.field_1AC = 0;
    g_dtor_called = 0;
    g_slot88_called = 0;
    func_00185760(&mgr);
    assert(g_dtor_called == 0 && g_slot88_called == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_alloc_success(); return 0;
    case 1: test_alloc_fail(); return 0;
    case 2: test_teardown_active(); return 0;
    case 3: test_teardown_empty(); return 0;
    default: return 1;
    }
}
