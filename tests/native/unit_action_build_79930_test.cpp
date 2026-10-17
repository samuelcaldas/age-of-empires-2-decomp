// Tests for func_00279930 — Milestone 123 (620B)
// Verifies worker task-to-animation and tool sound dispatch.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_79930.h"

static int g_anim_set = 0;
static int g_sound_set = 0;
static int g_cmd_committed = 0;
static int g_interaction_applied = 0;

extern "C" {
    void func_147180(void *, int anim_id) { g_anim_set = anim_id; }
    void func_1471B0(void *, int sound_id) { g_sound_set = sound_id; }
    void func_14BD90(void *, short, short, float, float, float) {}
    void func_151490(void *, int, int, void *, short, void *) { g_interaction_applied++; }
    void func_14BEF0(void *) { g_cmd_committed++; }
}

static void mock_get_box(void *, void *) {}

static void test_build_action_dispatch() {
    unsigned char self[512], target[256], target_proto[64], cmd_state[64], cmd_obj[64];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(target_proto, 0, sizeof(target_proto));
    std::memset(cmd_state, 0, sizeof(cmd_state));
    std::memset(cmd_obj, 0, sizeof(cmd_obj));

    void *self_vtbl[256], *target_vtbl[256];
    self_vtbl[136] = (void *)mock_get_box;
    target_vtbl[136] = (void *)mock_get_box;
    void *self_vtbl_ptr = self_vtbl;
    void *target_vtbl_ptr = target_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));
    std::memcpy(target, &target_vtbl_ptr, sizeof(void *));

    void *cmd_state_ptr = cmd_state;
    void *cmd_obj_ptr = cmd_obj;
    void *target_proto_ptr = target_proto;
    std::memcpy(cmd_state, &cmd_obj_ptr, sizeof(void *));

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x130, &cmd_state_ptr, sizeof(void *));
    std::memcpy(target + 0x8, &target_proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0xC8, &cmd_state_ptr, sizeof(void *));
    std::memcpy(target + 0x4, &target_proto_ptr, sizeof(void *));
#endif

    short target_id = 15;
    short target_type = 0x28; // Building
    std::memcpy(target + 0x24, &target_id, sizeof(short));
    std::memcpy(target_proto + 0xE, &target_type, sizeof(short));

    g_anim_set = 0;
    g_sound_set = 0;
    g_cmd_committed = 0;
    g_interaction_applied = 0;

    // Action 0x87 (repair/construct) -> sound 0x277, anim 0x2DB
    func_00279930(self, 0x87, target, 10.0f, 20.0f, 0.0f);

    assert(g_anim_set == 0x2DB);
    assert(g_sound_set == 0x277);
    assert(g_cmd_committed == 1);
    assert(g_interaction_applied == 1);

    printf("PASS test_build_action_dispatch\n");
}

int main() {
    test_build_action_dispatch();
    printf("All unit_action_build_79930 tests passed!\n");
    return 0;
}
