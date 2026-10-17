// Tests for func_278590 & func_002785A0 — Milestone 111 (200B)
// Verifies target owner check and action clearance callbacks.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_78590.h"

static int g_func_26F590_called = 0;
static int g_callback_e8_called = 0;
static int g_callback_7c_called = 0;

extern "C" {
    void func_139E40() {}
    void func_26F590(void *, void *, float, float) {
        g_func_26F590_called++;
    }
}

static void mock_callback_e8(void *) {
    g_callback_e8_called++;
}

static void mock_callback_7c(void *) {
    g_callback_7c_called++;
}

static void test_stub() {
    func_278590(nullptr);
    printf("PASS test_stub\n");
}

static void test_action_target_callback() {
    unsigned char self[256], target[256], target_proto[64], target_owner[0x2000];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(target_proto, 0, sizeof(target_proto));
    std::memset(target_owner, 0, sizeof(target_owner));

    void *self_vtbl[100];
    self_vtbl[58] = (void *)mock_callback_e8;
    self_vtbl[31] = (void *)mock_callback_7c;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *target_ptr = target;
    void *target_proto_ptr = target_proto;
    void *target_owner_ptr = target_owner;

    void *owner_data = (void *)0x12345678;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x38, &target_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_proto_ptr, sizeof(void *));
    std::memcpy(target + 0x10, &target_owner_ptr, sizeof(void *));
    std::memcpy(target_owner + 0x1740, &owner_data, sizeof(void *));
#else
    std::memcpy(self + 0x1C, &target_ptr, sizeof(void *));
    std::memcpy(target + 0x4, &target_proto_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_owner_ptr, sizeof(void *));
    std::memcpy(target_owner + 0xBA0, &owner_data, sizeof(void *));
#endif

    target_proto[0] = 0x50; // Required proto type

    g_func_26F590_called = 0;
    g_callback_e8_called = 0;
    g_callback_7c_called = 0;

    func_002785A0(self, owner_data, 1);

    assert(g_func_26F590_called == 1);
    assert(g_callback_e8_called == 1);
    assert(g_callback_7c_called == 1);
    printf("PASS test_action_target_callback\n");
}

int main() {
    test_stub();
    test_action_target_callback();
    printf("All unit_action_build_78590 tests passed!\n");
    return 0;
}
