// Tests for func_00272D10 — Milestone 68 (192B)
// Verifies base class constructor (func_00194D00), field initialization,
// memory zeroing, and conditional dispatch to func_00273130.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_d10.h"

static int g_base_d00_calls = 0;
static void *g_base_d00_self = nullptr;
static int g_flags_calls = 0;
static int g_last_flag = 0;
static int g_memset_calls = 0;
static int g_dispatch_calls = 0;

extern "C" void func_00194D00(void *self, void *, int, int) {
    g_base_d00_calls++;
    g_base_d00_self = self;
}

extern "C" void func_0026AD60(void *, int flag) {
    g_flags_calls++;
    g_last_flag = flag;
}

extern "C" void func_00117CAC(void *dst, int val, int size) {
    g_memset_calls++;
    std::memset(dst, val, size);
}

extern "C" void func_00273130(void *, void *, int) {
    g_dispatch_calls++;
}

static void test_initialization_and_dispatch() {
    g_base_d00_calls = 0;
    g_flags_calls = 0;
    g_memset_calls = 0;
    g_dispatch_calls = 0;

    unsigned char self[512] = {};
    unsigned char target[64] = {};

    func_00272D10(self, target, 5, 1);

    assert(g_base_d00_calls == 1);
    assert(g_base_d00_self == self);
    assert(g_flags_calls == 2);
    assert(g_last_flag == 0x400);
    assert(g_memset_calls == 1);
    assert(g_dispatch_calls == 1);

    assert(*(short *)(self + 0x10C) == 0);
    assert(*(char *)(self + 0x118) == 0);
    assert(*(short *)(self + 0x10E) == -1);
    assert(*(float *)(self + 0x110) == -1.0f);
    assert(*(float *)(self + 0x114) == -1.0f);
    assert(*(int *)(self + 0x120) == 0);
    assert(*(char *)(self + 0x11A) == 0);
    assert(*(short *)(self + 0x124) == 0);
    assert(*(char *)(self + 0x119) == 0);

    printf("PASS test_initialization_and_dispatch\n");
}

static void test_flag2_zero_skips_dispatch() {
    g_base_d00_calls = 0;
    g_dispatch_calls = 0;

    unsigned char self[512] = {};
    unsigned char target[64] = {};

    func_00272D10(self, target, 5, 0);
    assert(g_base_d00_calls == 1);
    assert(g_dispatch_calls == 0);

    printf("PASS test_flag2_zero_skips_dispatch\n");
}

int main() {
    test_initialization_and_dispatch();
    test_flag2_zero_skips_dispatch();
    printf("All unit_action_build_d10 tests passed!\n");
    return 0;
}
