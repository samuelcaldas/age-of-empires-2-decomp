// Tests for func_002729D0 — Milestone 64 (164B)
// Verifies target vtable query call (vtable[15]), argument forwarding,
// and output coordinate assignment on success vs failure.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_9d0.h"

static int g_called = 0;
static void *g_target = nullptr;
static void *g_owner = nullptr;
static void *g_self = nullptr;
static int g_return_val = 1;

static int mock_query(void *target, void *owner, int, int, int, int, int, void *self) {
    g_called++;
    g_target = target;
    g_owner = owner;
    g_self = self;
    return g_return_val;
}

static void test_success_sets_coordinates() {
    g_called = 0;
    g_target = nullptr;
    g_owner = nullptr;
    g_self = nullptr;
    g_return_val = 1;

    unsigned char self[64] = {};
    unsigned char target[256] = {};
    void *vtbl[16] = {};
    vtbl[15] = (void *)mock_query;

    void *vtbl_ptr = vtbl;
    std::memcpy(target + 0xA0, &vtbl_ptr, sizeof(void *));

    void *owner_ptr = (void *)0x12345678;
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));

    float out_x = 0.0f, out_y = 0.0f;
    int ok = func_002729D0(self, target, &out_x, &out_y, 42.5f, 84.5f);

    assert(ok == 1);
    assert(out_x == 42.5f);
    assert(out_y == 84.5f);
    assert(g_called == 1);
    assert(g_target == target);
    assert(g_owner == owner_ptr);
    assert(g_self == self);
    printf("PASS test_success_sets_coordinates\n");
}

static void test_failure_preserves_coordinates() {
    g_called = 0;
    g_return_val = 0;

    unsigned char self[64] = {};
    unsigned char target[256] = {};
    void *vtbl[16] = {};
    vtbl[15] = (void *)mock_query;

    void *vtbl_ptr = vtbl;
    std::memcpy(target + 0xA0, &vtbl_ptr, sizeof(void *));

    void *owner_ptr = (void *)0x12345678;
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));

    float out_x = -1.0f, out_y = -1.0f;
    int fail = func_002729D0(self, target, &out_x, &out_y, 42.5f, 84.5f);

    assert(fail == 0);
    assert(out_x == -1.0f);
    assert(out_y == -1.0f);
    assert(g_called == 1);
    printf("PASS test_failure_preserves_coordinates\n");
}

int main() {
    test_success_sets_coordinates();
    test_failure_preserves_coordinates();
    printf("All unit_action_build_9d0 tests passed!\n");
    return 0;
}
