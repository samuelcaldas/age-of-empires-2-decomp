// Tests for func_00278270 — Milestone 109 (600B)
// Verifies mode-based task dispatch and command state updates.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_78270.h"

static int g_anim_id = 0;
static int g_sound_id = 0;
static int g_cmd_committed = 0;

extern "C" {
    void *func_1398F0(void *) { return nullptr; }
    int func_139820(void *, void *, float, float, float) { return 1; }
    void *func_139860(void *) { return nullptr; }
    void func_147180(void *, int anim_id) { g_anim_id = anim_id; }
    void func_1471B0(void *, int sound_id) { g_sound_id = sound_id; }
    void func_14BD90(void *, short, short, float, float, float) {}
    void func_14BEF0(void *) { g_cmd_committed++; }
}

static int mock_get_action(void *) {
    return 0x7A;
}

static void *mock_set_task(void *, void *, void *, float, float, float) {
    static void *task_vtbl[10];
    task_vtbl[8] = (void *)mock_get_action;
    static void *task_obj[2] = { task_vtbl, nullptr };
    return task_obj;
}

static void mock_apply_task(void *, void *) {}

static void test_self_target() {
    unsigned char self[256];
    func_00278270(self, self, 1);
    printf("PASS test_self_target\n");
}

static void test_mode_1_dispatch() {
    unsigned char self[512], target[256], self_proto[512], target_proto[256];
    unsigned char task_list[256], task_item[64];
    unsigned char action_mgr[256], cmd_state[64], cmd_obj[64];

    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(self_proto, 0, sizeof(self_proto));
    std::memset(target_proto, 0, sizeof(target_proto));
    std::memset(task_list, 0, sizeof(task_list));
    std::memset(task_item, 0, sizeof(task_item));
    std::memset(action_mgr, 0, sizeof(action_mgr));
    std::memset(cmd_state, 0, sizeof(cmd_state));
    std::memset(cmd_obj, 0, sizeof(cmd_obj));

    void *self_vtbl[256];
    self_vtbl[196] = (void *)mock_apply_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *mgr_vtbl[10];
    mgr_vtbl[4] = (void *)mock_set_task;
    void *mgr_vtbl_ptr = mgr_vtbl;
    std::memcpy(action_mgr, &mgr_vtbl_ptr, sizeof(void *));

    void *self_proto_ptr = self_proto;
    void *target_proto_ptr = target_proto;
    void *cmd_state_ptr = cmd_state;
    void *cmd_obj_ptr = cmd_obj;
    void *action_mgr_ptr = action_mgr;
    void *task_list_ptr = task_list;

    std::memcpy(cmd_state, &cmd_obj_ptr, sizeof(void *));

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x130, &cmd_state_ptr, sizeof(void *));
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_proto_ptr, sizeof(void *));
    std::memcpy(self_proto + 0x150, &task_list_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0xC8, &cmd_state_ptr, sizeof(void *));
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
    std::memcpy(target + 0x4, &target_proto_ptr, sizeof(void *));
    std::memcpy(self_proto + 0xC8, &task_list_ptr, sizeof(void *));
#endif

    // Task list setup for Mode 1: action 0x7A, target 0x3
    short task_count = 1;
    std::memcpy(task_list + 0x8, &task_count, sizeof(short));
    void *task_items[2] = { task_item, nullptr };
    void **task_items_ptr = task_items;
    std::memcpy(task_list + 0x4, &task_items_ptr, sizeof(void *));

    short item_action = 0x7A;
    short item_target = 0x3;
    std::memcpy(task_item + 0x6, &item_action, sizeof(short));
    std::memcpy(task_item + 0x8, &item_target, sizeof(short));

    g_anim_id = 0;
    g_sound_id = 0;
    g_cmd_committed = 0;

    func_00278270(self, target, 1);

    assert(g_anim_id == -1);
    assert(g_sound_id == -1);
    assert(g_cmd_committed == 1);
    printf("PASS test_mode_1_dispatch\n");
}

int main() {
    test_self_target();
    test_mode_1_dispatch();
    printf("All unit_action_build_78270 tests passed!\n");
    return 0;
}
