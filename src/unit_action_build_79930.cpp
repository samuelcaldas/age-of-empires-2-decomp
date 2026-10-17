#pragma exceptions off
#include "unit_action_build_79930.h"

extern "C" {
    void func_147180(void *cmd, int anim_id);
    void func_1471B0(void *cmd, int sound_id);
    void func_14BD90(void *cmd, short target_id, short target_type, float x, float y, float z);
    void func_151490(void *cmd, int anim_id, int sound_id, void *box1, short target_id, void *box2);
    void func_14BEF0(void *cmd);
}

typedef void (*GetBoxFn)(void *out_box, void *unit);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_CMD_OFFSET   0x130
#define UNIT_PROTO_OFFSET 0x8
#else
#define UNIT_CMD_OFFSET   0xC8
#define UNIT_PROTO_OFFSET 0x4
#endif

static void map_action_to_anim_and_sound(int action_id, int &anim_id, int &sound_id) {
    anim_id = -1;
    sound_id = -1;
    if (action_id == 0x7A || action_id == 0x95) {
        sound_id = 0x278;
        anim_id = 0x2DC;
        return;
    }
    if (action_id == 0x87 || action_id == 0x88 || action_id == 0x84) {
        sound_id = 0x277;
        anim_id = 0x2DB;
    }
}

static void apply_target_interaction(void *cmd_obj, void *self, void *target, int anim_id, int sound_id) {
    unsigned char self_box[16], target_box[16];
    void **self_vtbl = *(void ***)self;
    GetBoxFn self_box_fn = (GetBoxFn)self_vtbl[136];
    self_box_fn(self_box, self);
    void **target_vtbl = *(void ***)target;
    GetBoxFn target_box_fn = (GetBoxFn)target_vtbl[136];
    target_box_fn(target_box, target);
    short target_id = *(short *)((char *)target + 0x24);
    func_151490(cmd_obj, anim_id, sound_id, self_box, target_id, target_box);
}

static void apply_command_dispatch(void *cmd_obj, void *self, void *target,
                                   int anim_id, int sound_id, float x, float y, float z) {
    func_147180(cmd_obj, anim_id);
    func_1471B0(cmd_obj, sound_id);
    if (target != 0) {
        short target_id = *(short *)((char *)target + 0x24);
        void *proto = *(void **)((char *)target + UNIT_PROTO_OFFSET);
        short target_type = *(short *)((char *)proto + 0xE);
        func_14BD90(cmd_obj, target_id, target_type, x, y, z);
        if (sound_id >= 0) apply_target_interaction(cmd_obj, self, target, anim_id, sound_id);
        func_14BEF0(cmd_obj);
        return;
    }
    func_14BD90(cmd_obj, -1, -1, x, y, z);
    func_14BEF0(cmd_obj);
}

void func_00279930(void *self, int action_id, void *target, float x, float y, float z) {
    void *cmd_state = *(void **)((char *)self + UNIT_CMD_OFFSET);
    if (cmd_state == 0) return;
    void *cmd_obj = *(void **)cmd_state;
    int anim_id = -1, sound_id = -1;
    map_action_to_anim_and_sound(action_id, anim_id, sound_id);
    apply_command_dispatch(cmd_obj, self, target, anim_id, sound_id, x, y, z);
}
