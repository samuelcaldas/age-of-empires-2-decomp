// Tests for func_00279110 — Milestone 119 (804B)
// Verifies trebuchet targeting, alliance guard, and siege command dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79110.h"

static int g_func_13a280_called = 0;
static int g_set_task_called = 0;

extern "C" {
    void *func_139860(void *) { return nullptr; }
    int func_202B10(void *) { return 1; }
    void *func_366D40(void *) {
        static int mock_task = 1;
        return &mock_task;
    }
    void *func_366D90(void *) { return nullptr; }
    void func_35FAC0(void *, void *, int) {}
    void func_364E20(void *, void *, void *, int, float, float) {}
    void func_279B80(void *, int) {}
    void func_26AD60(void *, int) {}
    void func_13A280(void *, void *, float, float, float, int, int) {
        g_func_13a280_called++;
    }
}

static int mock_check_eligibility(void *, void *, int *out_val) {
    *out_val = 0;
    return 0; // Not eligible -> triggers approach task
}

static void mock_set_task(void *, void *) {
    g_set_task_called++;
}

static void test_allied_target_guard() {
    unsigned char self[256], target[256], proto[64], owner[0x4000], target_owner[0x4000];
    unsigned char relation_obj[64];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(target_owner, 0, sizeof(target_owner));
    std::memset(relation_obj, 0, sizeof(relation_obj));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
    void *target_owner_ptr = target_owner;
    void *relation_obj_ptr = relation_obj;

    // Allied relation returns 1
    auto mock_relation = [](void *, void *) -> int { return 1; };
    void *rel_fn = (void *)+mock_relation;
    std::memcpy(relation_obj + 0x24, &rel_fn, sizeof(void *));

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(target + 0x10, &target_owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x2E60, &relation_obj_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1B30, &relation_obj_ptr, sizeof(void *));
#endif

    g_func_13a280_called = 0;
    func_00279110(self, target, 0, 0, 0, 0, 0);
    assert(g_func_13a280_called == 0);
    printf("PASS test_allied_target_guard\n");
}

static void test_trebuchet_approach_task() {
    unsigned char self[256], target[256], proto[64], owner[0x4000], target_owner[0x4000];
    unsigned char relation_obj[64];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(target_owner, 0, sizeof(target_owner));
    std::memset(relation_obj, 0, sizeof(relation_obj));

    void *self_vtbl[256];
    self_vtbl[211] = (void *)mock_check_eligibility;
    self_vtbl[196] = (void *)mock_set_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
    void *target_owner_ptr = target_owner;
    void *relation_obj_ptr = relation_obj;

    // Enemy relation returns 0
    auto mock_relation = [](void *, void *) -> int { return 0; };
    void *rel_fn = (void *)+mock_relation;
    std::memcpy(relation_obj + 0x24, &rel_fn, sizeof(void *));

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(target + 0x10, &target_owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x2E60, &relation_obj_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1B30, &relation_obj_ptr, sizeof(void *));
#endif

    short trebuchet_packed = 0x36;
    std::memcpy(proto + 0xE, &trebuchet_packed, sizeof(short));

    g_set_task_called = 0;
    g_func_13a280_called = 0;
    func_00279110(self, target, 0, 0, 0, 0, 0);

    assert(g_set_task_called == 1);
    assert(g_func_13a280_called == 0);
    printf("PASS test_trebuchet_approach_task\n");
}

int main() {
    test_allied_target_guard();
    test_trebuchet_approach_task();
    printf("All unit_action_build_79110 tests passed!\n");
    return 0;
}
