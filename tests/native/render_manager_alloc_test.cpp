#include "render_manager_alloc.h"
#include <cassert>
#include <cstdlib>

void *D_004E8944 = 0;

static int g_alloc_fail = 0;
static int g_sub_step = 0;
static void *g_last_obj = 0;
static int g_last_f2c = 0;

extern "C" {
void *func_100850(int size) {
    if (g_alloc_fail == 1) return 0;
    return (void *)(size == 0x14C ? 0x14C0 : 0x12C0);
}
void func_1DB460(void *obj, int zero) {
    assert(obj == (void *)0x14C0 && zero == 0);
    g_sub_step = 1;
}
int func_1DB500(void *obj, void *f7c, void *f70, void *ctx_arg, int argc738, int arg13) {
    assert(obj == (void *)0x14C0 && f7c == (void *)0x7C7C && f70 == (void *)0x7070);
    assert(argc738 == 0xC738 && arg13 == 0x13);
    g_sub_step = 2;
    return (g_alloc_fail == 2) ? 0 : 1;
}
void func_1860D0(RenderManagerAlloc *self) {
    assert(self != 0 && g_sub_step == 2);
    g_sub_step = 3;
}
void func_188DF0(void *obj, int f2c) {
    g_last_obj = obj;
    g_last_f2c = f2c;
}
}

static void test_alloc_success() {
    RenderManagerAlloc mgr = {0};
    char ctx_buf[0x40] = {0};
    mgr.ctx_28 = ctx_buf;
    mgr.field_7C = (void *)0x7C7C;
    mgr.field_70 = (void *)0x7070;
    g_alloc_fail = 0;
    g_sub_step = 0;
    int res = func_00185570(&mgr);
    assert(res == 1 && g_sub_step == 3 && mgr.field_1D8 == (void *)0x14C0);
}

static void test_alloc_fail() {
    RenderManagerAlloc mgr = {0};
    g_alloc_fail = 1;
    g_sub_step = 0;
    int res = func_00185570(&mgr);
    assert(res == 0 && mgr.field_1D8 == 0);
}

static void test_db500_fail() {
    RenderManagerAlloc mgr = {0};
    char ctx_buf[0x40] = {0};
    mgr.ctx_28 = ctx_buf;
    mgr.field_7C = (void *)0x7C7C;
    mgr.field_70 = (void *)0x7070;
    g_alloc_fail = 2;
    g_sub_step = 0;
    int res = func_00185570(&mgr);
    assert(res == 0 && g_sub_step == 2);
}

static void test_alloc12c_success() {
    RenderManagerAlloc mgr = {0};
    mgr.field_2C = 42;
    g_alloc_fail = 0;
    g_last_obj = 0;
    D_004E8944 = 0;
    int res = func_00185610(&mgr);
    assert(res == 1 && D_004E8944 == (void *)0x12C0 && g_last_obj == (void *)0x12C0 && g_last_f2c == 42);
}

static void test_alloc12c_fail() {
    RenderManagerAlloc mgr = {0};
    g_alloc_fail = 1;
    D_004E8944 = (void *)0x9999;
    int res = func_00185610(&mgr);
    assert(res == 0 && D_004E8944 == 0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_alloc_success(); return 0;
    case 1: test_alloc_fail(); return 0;
    case 2: test_db500_fail(); return 0;
    case 3: test_alloc12c_success(); return 0;
    case 4: test_alloc12c_fail(); return 0;
    default: return 1;
    }
}
