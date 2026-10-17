// Tests for func_0027A090 — Milestone 128 (316B)
// Verifies Trebuchet target-ground bombardment command dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7a090.h"

static int g_ground_move_created = 0;
static int g_ground_bombard_created = 0;
static int g_set_task_called = 0;

extern "C" {
    void *func_139860(void *) { return nullptr; }
    void *func_366D40(void *) {
        g_ground_move_created++;
        static int mock_task1 = 1;
        return &mock_task1;
    }
    void *func_366D90(void *) {
        g_ground_bombard_created++;
        static int mock_task2 = 2;
        return &mock_task2;
    }
    void func_35FAC0(void *, void *, int) {}
    void func_364E20(void *, void *, void *, int, float, float) {}
}

static void mock_set_task(void *, void *) {
    g_set_task_called++;
}

static void test_ground_bombard_dispatch() {
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

    short unpacked_type = 0x33; // Trebuchet unpacked
    std::memcpy(proto + 0xE, &unpacked_type, sizeof(short));

    g_ground_bombard_created = 0;
    g_set_task_called = 0;

    int ret = func_0027A090(self, 100.0f, 200.0f, 0.0f, 15.0f, 0, 0);
    assert(ret == 1);
    assert(g_ground_bombard_created == 1);
    assert(g_set_task_called == 1);
    printf("PASS test_ground_bombard_dispatch\n");
}

int main() {
    test_ground_bombard_dispatch();
    printf("All unit_action_build_7a090 tests passed!\n");
    return 0;
}
