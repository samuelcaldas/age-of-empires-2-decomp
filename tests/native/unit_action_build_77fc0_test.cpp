// Tests for func_00277FC0 — Milestone 108 (676B)
// Verifies build/action task dispatch and command state updates.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_77fc0.h"

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
    return 0x6A; // Build action
}

static void *mock_set_task(void *, void *, void *, float, float, float) {
    static void *task_vtbl[10];
    task_vtbl[8] = (void *)mock_get_action;
    static void *task_obj[2] = { task_vtbl, nullptr };
    return task_obj;
}

static void mock_apply_task(void *, void *) {}
static void mock_trigger_sound(void *) {}

static void test_null_and_self_target() {
    unsigned char self[256];
    func_00277FC0(self, nullptr);
    func_00277FC0(self, self);
    printf("PASS test_null_and_self_target\n");
}

static void test_task_dispatch_build_action() {
    unsigned char self[512], target[256], self_proto[512], target_proto[256];
    unsigned char owner[1024], civ[2048], task_list[256], task_item[64];
    unsigned char action_mgr[256], cmd_state[64], cmd_obj[64];

    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(self_proto, 0, sizeof(self_proto));
    std::memset(target_proto, 0, sizeof(target_proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(civ, 0, sizeof(civ));
    std::memset(task_list, 0, sizeof(task_list));
    std::memset(task_item, 0, sizeof(task_item));
    std::memset(action_mgr, 0, sizeof(action_mgr));
    std::memset(cmd_state, 0, sizeof(cmd_state));
    std::memset(cmd_obj, 0, sizeof(cmd_obj));

    void *self_vtbl[256];
    self_vtbl[26] = (void *)mock_trigger_sound;
    self_vtbl[196] = (void *)mock_apply_task;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *mgr_vtbl[10];
    mgr_vtbl[4] = (void *)mock_set_task;
    void *mgr_vtbl_ptr = mgr_vtbl;
    std::memcpy(action_mgr, &mgr_vtbl_ptr, sizeof(void *));

    void *self_proto_ptr = self_proto;
    void *target_proto_ptr = target_proto;
    void *owner_ptr = owner;
    void *civ_ptr = civ;
    void *cmd_state_ptr = cmd_state;
    void *cmd_obj_ptr = cmd_obj;
    void *action_mgr_ptr = action_mgr;

    std::memcpy(cmd_state, &cmd_obj_ptr, sizeof(void *));

    void *task_list_ptr = task_list;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0x130, &cmd_state_ptr, sizeof(void *));
    std::memcpy(self + 0x138, &action_mgr_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_proto_ptr, sizeof(void *));
    std::memcpy(owner + 0xE0, &civ_ptr, sizeof(void *));
    std::memcpy(self_proto + 0x150, &task_list_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &self_proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0xC8, &cmd_state_ptr, sizeof(void *));
    std::memcpy(self + 0xCC, &action_mgr_ptr, sizeof(void *));
    std::memcpy(target + 0x4, &target_proto_ptr, sizeof(void *));
    std::memcpy(owner + 0x70, &civ_ptr, sizeof(void *));
    std::memcpy(self_proto + 0xC8, &task_list_ptr, sizeof(void *));
#endif

    // Proto ID: 0x9C (skips sound check)
    short proto_id = 0x9C;
    std::memcpy(self_proto + 0x8, &proto_id, sizeof(short));

    // Task list setup
    short task_count = 1;
    std::memcpy(task_list + 0x8, &task_count, sizeof(short));
    void *task_items[2] = { task_item, nullptr };
    void **task_items_ptr = task_items;
    std::memcpy(task_list + 0x4, &task_items_ptr, sizeof(void *));

    short item_action = 0x6A;
    short item_target = -1;
    std::memcpy(task_item + 0x6, &item_action, sizeof(short));
    std::memcpy(task_item + 0x8, &item_target, sizeof(short));

    g_anim_id = 0;
    g_sound_id = 0;
    g_cmd_committed = 0;

    func_00277FC0(self, target);

    assert(g_anim_id == 0x2CE);
    assert(g_sound_id == 0x26A);
    assert(g_cmd_committed == 1);
    printf("PASS test_task_dispatch_build_action\n");
}

int main() {
    test_null_and_self_target();
    test_task_dispatch_build_action();
    printf("All unit_action_build_77fc0 tests passed!\n");
    return 0;
}
