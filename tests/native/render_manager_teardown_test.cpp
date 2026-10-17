#include "render_manager_teardown.h"
#include <cassert>
#include <cstdlib>

void *D_004E8944 = 0;
void *D_004E894C = (void *)0x894C;

static int g_189210_calls = 0;
static int g_1f33d0_calls = 0;
static int g_f6c0_calls = 0;
static int g_f860_calls = 0;
static int g_free_calls = 0;
static int g_f810_calls = 0;

extern "C" {
void func_00A80BB0() {}
void func_189210(void *arg) { assert(arg == (void *)0x8944); g_189210_calls++; }
void func_1F33D0(void *arg) { assert(arg == (void *)func_00A80BB0); g_1f33d0_calls++; }
void func_25F6C0(void *item, int zero) { assert(item != 0 && zero == 0); g_f6c0_calls++; }
void func_25F860(void *item, int one) { assert(item != 0 && one == 1); g_f860_calls++; }
void func_116F68(void *ptr) { assert(ptr != 0); g_free_calls++; }
void func_25F810(void *item, int one) { assert(item == (void *)0x8888 && one == 1); g_f810_calls++; }
}

static void test_full_teardown() {
    RenderManagerTeardown mgr = {0};
    D_004E8944 = (void *)0x8944;
    D_004E894C = (void *)0x894C;
    mgr.field_88 = (void *)0x8888;
    mgr.field_8C = 2;
    void *items90[2] = {(void *)0x9001, (void *)0x9002};
    mgr.field_90 = items90;

    SubObj404 sub = {0};
    sub.count = 2;
    void *items404[2] = {(void *)0x4041, (void *)0x4042};
    sub.items = items404;
    mgr.field_404 = &sub;

    g_189210_calls = 0; g_1f33d0_calls = 0; g_f6c0_calls = 0;
    g_f860_calls = 0; g_free_calls = 0; g_f810_calls = 0;

    func_00185a80(&mgr);

    assert(g_189210_calls == 1 && g_1f33d0_calls == 1);
    assert(g_f6c0_calls == 2 && g_f860_calls == 2 && g_free_calls == 1);
    assert(g_f810_calls == 1 && mgr.field_88 == 0 && D_004E894C == 0);
    assert(mgr.field_90 == 0);
    for (int i = 0; i < 5; i++) assert(mgr.field_08[i] == -1);
}

static void test_null_teardown() {
    RenderManagerTeardown mgr = {0};
    D_004E8944 = 0;
    D_004E894C = (void *)0x894C;

    g_189210_calls = 0; g_1f33d0_calls = 0; g_f6c0_calls = 0;
    g_f860_calls = 0; g_free_calls = 0; g_f810_calls = 0;

    func_00185a80(&mgr);

    assert(g_189210_calls == 0 && g_1f33d0_calls == 1);
    assert(g_f6c0_calls == 0 && g_f860_calls == 0 && g_free_calls == 0 && g_f810_calls == 0);
    assert(D_004E894C == (void *)0x894C); // not cleared when field_88 is null
    for (int i = 0; i < 5; i++) assert(mgr.field_08[i] == -1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_full_teardown(); return 0;
    case 1: test_null_teardown(); return 0;
    default: return 1;
    }
}
