// Tests for func_276080 — Milestone 90 (148B)
// Verifies ActionBuild target unbind notification and proto dissociation handling.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_6080.h"

static int g_unbind_called = 0;
static int g_callback_called = 0;
static void *g_last_target = nullptr;
static void *g_last_owner = nullptr;
static int g_last_arg2 = -1;
static int g_last_arg3 = -1;
static int g_last_arg4 = -1;
static bool g_unlink_target_on_unbind = false;

static void mock_unbind_fn(void *, void *self) {
    g_unbind_called++;
    if (g_unlink_target_on_unbind) {
        void *null_ptr = nullptr;
#if defined(__LP64__) || defined(_LP64)
        std::memcpy((char *)self + 0x38, &null_ptr, sizeof(void *));
#else
        std::memcpy((char *)self + 0x1C, &null_ptr, sizeof(void *));
#endif
    }
}

static void mock_callback_fn(void *target, void *owner, int a2, int a3, int a4) {
    g_callback_called++;
    g_last_target = target;
    g_last_owner = owner;
    g_last_arg2 = a2;
    g_last_arg3 = a3;
    g_last_arg4 = a4;
}

static void setup_test(unsigned char *self, unsigned char *target, unsigned char *proto,
                       void **vtable, unsigned char *owner) {
    std::memset(self, 0, 512);
    std::memset(target, 0, 256);
    std::memset(proto, 0, 256);
    std::memset(vtable, 0, 128 * sizeof(void *));
    std::memset(owner, 0, 64);

    vtable[60] = (void *)mock_unbind_fn;
    vtable[62] = (void *)mock_callback_fn;

    void *vtable_ptr = vtable;
    std::memcpy(target, &vtable_ptr, sizeof(void *));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(target + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(target + 0x4, &proto_ptr, sizeof(void *));
#endif

    void *target_ptr = target;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x38, &target_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x1C, &target_ptr, sizeof(void *));
#endif

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    self[0x118] = 0x7F;
    g_unbind_called = 0;
    g_callback_called = 0;
    g_unlink_target_on_unbind = false;
}

static void test_null_target() {
    unsigned char self[512];
    std::memset(self, 0, sizeof(self));
    func_276080(self);
    assert(g_unbind_called == 0);
    printf("PASS test_null_target\n");
}

static void test_target_unchanged() {
    unsigned char self[512], target[256], proto[256], owner[64];
    void *vtable[128];
    setup_test(self, target, proto, vtable, owner);

    proto[0] = 0x50;
    g_unlink_target_on_unbind = false;

    func_276080(self);
    assert(g_unbind_called == 1);
    assert(g_callback_called == 0);
    assert(self[0x118] == 0x7F);
    printf("PASS test_target_unchanged\n");
}

static void test_target_unlinked_proto_not_50() {
    unsigned char self[512], target[256], proto[256], owner[64];
    void *vtable[128];
    setup_test(self, target, proto, vtable, owner);

    proto[0] = 0x20; // != 0x50
    g_unlink_target_on_unbind = true;

    func_276080(self);
    assert(g_unbind_called == 1);
    assert(g_callback_called == 0);
    assert(self[0x118] == 0);
    printf("PASS test_target_unlinked_proto_not_50\n");
}

static void test_target_unlinked_proto_50() {
    unsigned char self[512], target[256], proto[256], owner[64];
    void *vtable[128];
    setup_test(self, target, proto, vtable, owner);

    proto[0] = 0x50;
    g_unlink_target_on_unbind = true;

    func_276080(self);
    assert(g_unbind_called == 1);
    assert(g_callback_called == 1);
    assert(g_last_target == target);
    assert(g_last_owner == owner);
    assert(g_last_arg2 == 0);
    assert(g_last_arg3 == 5);
    assert(g_last_arg4 == 0);
    assert(self[0x118] == 0);
    printf("PASS test_target_unlinked_proto_50\n");
}

int main() {
    test_null_target();
    test_target_unchanged();
    test_target_unlinked_proto_not_50();
    test_target_unlinked_proto_50();
    printf("All unit_action_build_6080 tests passed!\n");
    return 0;
}
