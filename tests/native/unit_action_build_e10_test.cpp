// Tests for func_00272E10 — Milestone 70 (112B)
// Verifies deleting destructor logic: null check guard, vtable setup (0x4E8CE0),
// destructor invocations, and conditional operator delete dispatch.
#include <cassert>
#include <cstdio>
#include "unit_action_build_e10.h"

static int g_dd0_calls = 0;
static void *g_dd0_self = nullptr;
static int g_e20_calls = 0;
static int g_delete_calls = 0;
static void *g_delete_ptr = nullptr;

extern "C" void func_00272DD0(void *self, void *) {
    g_dd0_calls++;
    g_dd0_self = self;
}

extern "C" void func_00194E20(void *, void *) {
    g_e20_calls++;
}

extern "C" void func_00100670(void *ptr) {
    g_delete_calls++;
    g_delete_ptr = ptr;
}

static void test_null_self_returns_null() {
    g_dd0_calls = 0;
    assert(func_00272E10(nullptr, 1) == nullptr);
    assert(g_dd0_calls == 0);
    printf("PASS test_null_self_returns_null\n");
}

static void test_flags_positive_invokes_delete() {
    g_dd0_calls = 0;
    g_e20_calls = 0;
    g_delete_calls = 0;

    void *vtable_slot = nullptr;
    void *obj = &vtable_slot;
    void *res = func_00272E10(obj, 1);

    assert(res == obj);
    assert(g_dd0_calls == 1);
    assert(g_dd0_self == obj);
    assert(g_e20_calls == 1);
    assert(g_delete_calls == 1);
    assert(g_delete_ptr == obj);
    assert(vtable_slot == (void *)0x4E8CE0);
    printf("PASS test_flags_positive_invokes_delete\n");
}

static void test_flags_zero_skips_delete() {
    g_dd0_calls = 0;
    g_e20_calls = 0;
    g_delete_calls = 0;

    void *vtable_slot = nullptr;
    void *obj = &vtable_slot;
    void *res = func_00272E10(obj, 0);

    assert(res == obj);
    assert(g_dd0_calls == 1);
    assert(g_e20_calls == 1);
    assert(g_delete_calls == 0);
    printf("PASS test_flags_zero_skips_delete\n");
}

int main() {
    test_null_self_returns_null();
    test_flags_positive_invokes_delete();
    test_flags_zero_skips_delete();
    printf("All unit_action_build_e10 tests passed!\n");
    return 0;
}
