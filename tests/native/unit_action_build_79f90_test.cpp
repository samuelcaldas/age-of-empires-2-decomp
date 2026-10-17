// Tests for func_00279F90 — Milestone 127 (252B)
// Verifies Trebuchet toggle pack / unpack dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79f90.h"

static int g_pack_task_created = 0;
static int g_unpack_task_created = 0;
static int g_set_task_called = 0;

extern "C" {
    void *func_139860(void *) { return nullptr; }
    void *func_366D40(void *) {
        g_pack_task_created++;
        static int mock_task1 = 1;
        return &mock_task1;
    }
    void *func_366D90(void *) {
        g_unpack_task_created++;
        static int mock_task2 = 2;
        return &mock_task2;
    }
    void func_35FAC0(void *, void *, int) {}
    void func_364E20(void *, void *, void *, int, float, float) {}
}

static void mock_set_task(void *, void *) {
    g_set_task_called++;
}

static void test_pack_dispatch() {
    unsigned char self[512], proto[64], action_mgr[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(action_mgr, 0, sizeof(action_mgr));

    void *self_vtbl[256];
    self_vtbl[196] = (void *)mock_set_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *action_mgr_ptr = action_mgr;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
#endif

    short packed_type = 0x36;
    std::memcpy(proto + 0xE, &packed_type, sizeof(short));

    g_pack_task_created = 0;
    g_set_task_called = 0;

    int ret = func_00279F90(self, 0, 0);
    assert(ret == 1);
    assert(g_pack_task_created == 1);
    assert(g_set_task_called == 1);
    printf("PASS test_pack_dispatch\n");
}

static void test_unpack_dispatch() {
    unsigned char self[512], proto[64], action_mgr[64];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(action_mgr, 0, sizeof(action_mgr));

    void *self_vtbl[256];
    self_vtbl[196] = (void *)mock_set_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *action_mgr_ptr = action_mgr;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
#endif

    short unpacked_type = 0x33;
    std::memcpy(proto + 0xE, &unpacked_type, sizeof(short));

    g_unpack_task_created = 0;
    g_set_task_called = 0;

    int ret = func_00279F90(self, 0, 0);
    assert(ret == 1);
    assert(g_unpack_task_created == 1);
    assert(g_set_task_called == 1);
    printf("PASS test_unpack_dispatch\n");
}

int main() {
    test_pack_dispatch();
    test_unpack_dispatch();
    printf("All unit_action_build_79f90 tests passed!\n");
    return 0;
}
