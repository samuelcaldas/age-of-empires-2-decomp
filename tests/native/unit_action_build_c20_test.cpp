// Tests for func_00272C20 — Milestone 67 (240B)
// Verifies base class constructor call, state field initialization,
// memory zeroing at +0x100, and conditional dispatch to func_00272E80.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_c20.h"

static int g_base_ctor_calls = 0;
static void *g_base_ctor_self = nullptr;
static int g_flags_calls = 0;
static int g_last_flag = 0;
static int g_memset_calls = 0;
static int g_dispatch_calls = 0;
static float g_disp_x = 0.0f;
static float g_disp_y = 0.0f;
static float g_disp_z = 0.0f;

extern "C" void func_00194C60(void *self, void *target, int flag1, int zero) {
    g_base_ctor_calls++;
    g_base_ctor_self = self;
}

extern "C" void func_0026AD60(void *, int flag) {
    g_flags_calls++;
    g_last_flag = flag;
}

extern "C" void func_00117CAC(void *dst, int val, int size) {
    g_memset_calls++;
    std::memset(dst, val, size);
}

extern "C" void func_00272E80(void *, void *, int, float x, float y, float z) {
    g_dispatch_calls++;
    g_disp_x = x;
    g_disp_y = y;
    g_disp_z = z;
}

static void test_initialization_fields_and_conditional_dispatch() {
    g_base_ctor_calls = 0;
    g_flags_calls = 0;
    g_memset_calls = 0;
    g_dispatch_calls = 0;

    unsigned char self[512] = {};
    unsigned char target[64] = {};

    // Run with flag2 != 0 -> dispatch called
    func_00272C20(self, target, 12, 1, 10.0f, 20.0f, 30.0f);

    assert(g_base_ctor_calls == 1);
    assert(g_base_ctor_self == self);
    assert(g_flags_calls == 2);
    assert(g_last_flag == 0x400);
    assert(g_memset_calls == 1);
    assert(g_dispatch_calls == 1);
    assert(g_disp_x == 10.0f);
    assert(g_disp_y == 20.0f);
    assert(g_disp_z == 30.0f);

    // Verify fields
    assert(*(short *)(self + 0x10C) == 0);
    assert(*(char *)(self + 0x118) == 0);
    assert(*(short *)(self + 0x10E) == -1);
    assert(*(float *)(self + 0x110) == -1.0f);
    assert(*(float *)(self + 0x114) == -1.0f);
    assert(*(int *)(self + 0x120) == 0);
    assert(*(char *)(self + 0x11A) == 0);
    assert(*(short *)(self + 0x124) == 0);
    assert(*(char *)(self + 0x119) == 0);

    printf("PASS test_initialization_fields_and_conditional_dispatch\n");
}

static void test_flag2_zero_skips_dispatch() {
    g_base_ctor_calls = 0;
    g_dispatch_calls = 0;

    unsigned char self[512] = {};
    unsigned char target[64] = {};

    func_00272C20(self, target, 12, 0, 10.0f, 20.0f, 30.0f);
    assert(g_base_ctor_calls == 1);
    assert(g_dispatch_calls == 0);

    printf("PASS test_flag2_zero_skips_dispatch\n");
}

int main() {
    test_initialization_fields_and_conditional_dispatch();
    test_flag2_zero_skips_dispatch();
    printf("All unit_action_build_c20 tests passed!\n");
    return 0;
}
