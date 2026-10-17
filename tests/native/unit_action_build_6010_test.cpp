// Tests for func_276010 — Milestone 89 (112B)
// Verifies ActionBuild target interaction notification callback.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_6010.h"

static void *g_last_target = nullptr;
static void *g_last_owner = nullptr;
static int g_last_arg2 = -1;
static int g_last_arg3 = -1;
static int g_last_arg4 = -1;
static int g_vtable_called = 0;
static int g_func_196570_called = 0;

extern "C" void func_196570(void *, void *) {
    g_func_196570_called++;
}

static void mock_vtable_callback(void *target, void *owner, int a2, int a3, int a4) {
    g_vtable_called++;
    g_last_target = target;
    g_last_owner = owner;
    g_last_arg2 = a2;
    g_last_arg3 = a3;
    g_last_arg4 = a4;
}

static void test_mismatch_target() {
    unsigned char self[256];
    unsigned char target[256];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));

    g_func_196570_called = 0;
    g_vtable_called = 0;

    void *other_target = (void *)0x1234;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x38, &other_target, sizeof(void *));
#else
    std::memcpy(self + 0x1C, &other_target, sizeof(void *));
#endif

    func_276010(self, target);
    assert(g_func_196570_called == 1);
    assert(g_vtable_called == 0);
    printf("PASS test_mismatch_target\n");
}

static void test_proto_type_not_50() {
    unsigned char self[256];
    unsigned char target[256];
    unsigned char proto[256];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(proto, 0, sizeof(proto));

    g_func_196570_called = 0;
    g_vtable_called = 0;

    void *target_ptr = target;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x38, &target_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x1C, &target_ptr, sizeof(void *));
#endif

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(target + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(target + 0x4, &proto_ptr, sizeof(void *));
#endif

    proto[0] = 0x20; // != 0x50

    func_276010(self, target);
    assert(g_func_196570_called == 1);
    assert(g_vtable_called == 0);
    printf("PASS test_proto_type_not_50\n");
}

static void test_matching_callback() {
    unsigned char self[256];
    unsigned char target[256];
    unsigned char proto[256];
    void *vtable[128];
    unsigned char owner[64];

    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(proto, 0, sizeof(proto));
    std::memset(vtable, 0, sizeof(vtable));
    std::memset(owner, 0, sizeof(owner));

    g_func_196570_called = 0;
    g_vtable_called = 0;

    vtable[61] = (void *)mock_vtable_callback;
    void *vtable_ptr = vtable;
    std::memcpy(target, &vtable_ptr, sizeof(void *));

    void *target_ptr = target;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x38, &target_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x1C, &target_ptr, sizeof(void *));
#endif

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(target + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(target + 0x4, &proto_ptr, sizeof(void *));
#endif

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    proto[0] = 0x50;

    func_276010(self, target);
    assert(g_func_196570_called == 1);
    assert(g_vtable_called == 1);
    assert(g_last_target == target);
    assert(g_last_owner == owner);
    assert(g_last_arg2 == 0);
    assert(g_last_arg3 == 5);
    assert(g_last_arg4 == 0);
    printf("PASS test_matching_callback\n");
}

int main() {
    test_mismatch_target();
    test_proto_type_not_50();
    test_matching_callback();
    printf("All unit_action_build_6010 tests passed!\n");
    return 0;
}
