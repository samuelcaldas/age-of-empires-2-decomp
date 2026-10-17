// Tests for func_00279D80 — Milestone 126 (528B)
// Verifies Trebuchet ID-based siege command dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79d80.h"

static int g_order_move_called = 0;
static int g_set_task_called = 0;

extern "C" {
    void *func_139860(void *) { return nullptr; }
    static unsigned char g_target_obj[256];
    void *func_332E60(void *, int) { return g_target_obj; }
    int func_202B10(void *) { return 1; }
    void *func_366D40(void *) {
        static int mock_repack = 1;
        return &mock_repack;
    }
    void func_35FAC0(void *, void *, int) {}
    void *func_366D90(void *) {
        static int mock_unpack = 2;
        return &mock_unpack;
    }
    void func_364E20(void *, void *, void *, int, float, float) {}
}

static void mock_order_move(void *, void *, int, int, float, float, float) {
    g_order_move_called++;
}

static int mock_check_eligible(void *, void *, int *out_val) {
    *out_val = 0;
    return 1; // Eligible
}

static void mock_set_task(void *, void *) {
    g_set_task_called++;
}

static void test_packed_move_command() {
    unsigned char self[512], proto[64], owner[0x2000], world[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));

    void *self_vtbl[256];
    self_vtbl[192] = (void *)mock_order_move;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
    void *world_ptr = world;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
#endif

    short packed_type = 0x36; // Trebuchet packed
    std::memcpy(proto + 0xE, &packed_type, sizeof(short));

    g_order_move_called = 0;
    int ret = func_00279D80(self, 10, 0);
    assert(ret == 1);
    assert(g_order_move_called == 1);
    printf("PASS test_packed_move_command\n");
}

static void test_unpacked_attack_command() {
    unsigned char self[512], proto[64], owner[0x2000], world[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));

    void *self_vtbl[256];
    self_vtbl[211] = (void *)mock_check_eligible;
    self_vtbl[196] = (void *)mock_set_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
    void *world_ptr = world;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
#endif

    short unpacked_type = 0x33; // Trebuchet unpacked
    std::memcpy(proto + 0xE, &unpacked_type, sizeof(short));

    g_set_task_called = 0;
    int ret = func_00279D80(self, 10, 0);
    assert(ret == 1);
    assert(g_set_task_called == 1);
    printf("PASS test_unpacked_attack_command\n");
}

int main() {
    test_packed_move_command();
    test_unpacked_attack_command();
    printf("All unit_action_build_79d80 tests passed!\n");
    return 0;
}
