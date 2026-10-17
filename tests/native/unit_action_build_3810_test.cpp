// Tests for func_273810 — Milestone 75 (352B)
// Verifies property setters (SetParam, AddParam, MulParam)
// and prototype rebind logic (UpdateProto).
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_3810.h"

static int g_f750_calls = 0;
static int g_f8a0_calls = 0;
static int g_f9a0_calls = 0;
static int g_f8530_calls = 0;
static int g_f27b0_calls = 0;
static int g_f2610_calls = 0;
static int g_f4c7f0_calls = 0;
static int g_f96a60_calls = 0;

extern "C" void func_00267750(void *, int, float) { g_f750_calls++; }
extern "C" void func_002678A0(void *, int, float) { g_f8a0_calls++; }
extern "C" void func_002679A0(void *, int, float) { g_f9a0_calls++; }
extern "C" int func_00268530(void *) { g_f8530_calls++; return 1; }
extern "C" void func_001827B0(void *, void *) { g_f27b0_calls++; }
extern "C" void func_00182610(void *, void *, int, int, int, int) { g_f2610_calls++; }
extern "C" void func_0014C7F0(void *, int) { g_f4c7f0_calls++; }
extern "C" void func_00196A60(void *, void *) { g_f96a60_calls++; }

static void test_param_setters() {
    unsigned char self[512] = {};
    g_f750_calls = 0; g_f8a0_calls = 0; g_f9a0_calls = 0;

    func_00273810(self, 0x66, 10.0f);
    assert(*(float *)(self + 0x120) == 10.0f);
    assert(g_f750_calls == 1);

    func_00273840(self, 0x66, 5.0f);
    assert(*(float *)(self + 0x120) == 15.0f);
    assert(g_f8a0_calls == 1);

    func_00273870(self, 0x66, 2.0f);
    assert(*(float *)(self + 0x120) == 30.0f);
    assert(g_f9a0_calls == 1);

    printf("PASS test_param_setters\n");
}

static void test_proto_rebind() {
    unsigned char self[512] = {};
    unsigned char old_proto[512] = {};
    unsigned char new_proto[512] = {};

    void *dummy_164 = (void *)0xABCD;
    std::memcpy(old_proto + 0x164, &dummy_164, sizeof(void *));
    std::memcpy(new_proto + 0x164, &dummy_164, sizeof(void *));

    void *old_proto_ptr = old_proto;
    void *c_ptr = (void *)0x1234;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &old_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x18, &c_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &old_proto_ptr, sizeof(void *));
    std::memcpy(self + 0xC, &c_ptr, sizeof(void *));
#endif

    g_f8530_calls = 0; g_f27b0_calls = 0; g_f2610_calls = 0; g_f96a60_calls = 0;

    func_002738A0(self, new_proto);
    assert(g_f8530_calls == 1);
    assert(g_f27b0_calls == 1);
    assert(g_f2610_calls == 1);
    assert(g_f96a60_calls == 1);

    printf("PASS test_proto_rebind\n");
}

int main() {
    test_param_setters();
    test_proto_rebind();
    printf("All unit_action_build_3810 tests passed!\n");
    return 0;
}
