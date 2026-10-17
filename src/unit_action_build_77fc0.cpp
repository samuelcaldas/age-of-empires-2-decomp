#pragma exceptions off
#include "unit_action_build_77fc0.h"

extern "C" {
    void *func_1398F0(void *action_mgr);
    int func_139820(void *action_mgr, void *target, float x, float y, float z);
    void *func_139860(void *action_mgr);
    void func_147180(void *cmd, int anim_id);
    void func_1471B0(void *cmd, int sound_id);
    void func_14BD90(void *cmd, short target_id, short target_type, float x, float y, float z);
    void func_14BEF0(void *cmd);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define UNIT_OWNER_OFFSET    0x10
#define UNIT_CMD_OFFSET      0x130
#define UNIT_ACTION_OFFSET   0x138
#define OWNER_CIV_OFFSET     0xE0
#define PROTO_TASKS_OFFSET   0x150
#else
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_OWNER_OFFSET    0x8
#define UNIT_CMD_OFFSET      0xC8
#define UNIT_ACTION_OFFSET   0xCC
#define OWNER_CIV_OFFSET     0x70
#define PROTO_TASKS_OFFSET   0xC8
#endif

typedef void (*TriggerSoundFn)(void *self);
typedef int (*GetTaskActionFn)(void *task);
typedef void *(*SetTaskFn)(void *action_mgr, void *task_item, void *target, float x, float y, float z);
typedef void (*ApplyTaskFn)(void *self, void *task);

static bool check_sound_trigger(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short proto_id = *(short *)((char *)proto + 0x8);
    if (proto_id != 0x9C && proto_id != 0xDE) {
        void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
        void *civ = *(void **)((char *)owner + OWNER_CIV_OFFSET);
        int sound_offset = (*(unsigned char *)((char *)proto + 0xCE) == 1) ? 0x270 : 0x378;
        void *sound = *(void **)((char *)civ + sound_offset);
        if (sound == 0) return false;
        void **vtbl = *(void ***)self;
        TriggerSoundFn trigger_sound = (TriggerSoundFn)vtbl[26];
        trigger_sound(self);
    }
    return true;
}

static void *find_build_task_item(void *proto) {
    void *task_list = *(void **)((char *)proto + PROTO_TASKS_OFFSET);
    if (task_list == 0) return 0;
    short count = *(short *)((char *)task_list + 0x8);
    void **items = *(void ***)((char *)task_list + 0x4);
    for (int i = 0; i < count; ++i) {
        void *item = items[i];
        if (item != 0 && *(short *)((char *)item + 0x6) == 0x6A && *(short *)((char *)item + 0x8) == -1) {
            return item;
        }
    }
    return 0;
}

static int execute_task(void *self, void *target, void *task_item) {
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    void *current_task = func_1398F0(action_mgr);
    float tx = *(float *)((char *)target + 0x44);
    float ty = *(float *)((char *)target + 0x48);
    float tz = *(float *)((char *)target + 0x4C);
    if (task_item != 0 && task_item == current_task) {
        if (func_139820(action_mgr, target, tx, ty, tz) == 0) return 0;
        void *task_obj = func_139860(action_mgr);
        void **vtbl = *(void ***)task_obj;
        GetTaskActionFn get_action = (GetTaskActionFn)vtbl[8];
        return get_action(task_obj);
    }
    if (task_item == 0) return 0;
    void **mgr_vtbl = *(void ***)action_mgr;
    SetTaskFn set_task = (SetTaskFn)mgr_vtbl[4];
    void *new_task = set_task(action_mgr, task_item, target, tx, ty, tz);
    if (new_task == 0) return 0;
    void **task_vtbl = *(void ***)new_task;
    GetTaskActionFn get_action = (GetTaskActionFn)task_vtbl[8];
    int action_id = get_action(new_task);
    void **self_vtbl = *(void ***)self;
    ApplyTaskFn apply_task = (ApplyTaskFn)self_vtbl[196];
    apply_task(self, new_task);
    return action_id;
}

static void update_command_state(void *self, void *target, int action_id) {
    void *cmd_state = *(void **)((char *)self + UNIT_CMD_OFFSET);
    if (cmd_state == 0) return;
    void *cmd_obj = *(void **)cmd_state;
    int anim_id = (action_id == 0x6A) ? 0x2CE : -1;
    int sound_id = (action_id == 0x6A) ? 0x26A : -1;
    func_147180(cmd_obj, anim_id);
    func_1471B0(cmd_obj, sound_id);
    short target_id = *(short *)((char *)target + 0x24);
    void *target_proto = *(void **)((char *)target + UNIT_PROTO_OFFSET);
    short target_type = *(short *)((char *)target_proto + 0xE);
    float tx = *(float *)((char *)target + 0x44);
    float ty = *(float *)((char *)target + 0x48);
    float tz = *(float *)((char *)target + 0x4C);
    func_14BD90(cmd_obj, target_id, target_type, tx, ty, tz);
    func_14BEF0(cmd_obj);
}

void func_00277FC0(void *self, void *target) {
    if (target == self || target == 0) return;
    if (!check_sound_trigger(self)) return;
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    void *task_item = find_build_task_item(proto);
    int action_id = execute_task(self, target, task_item);
    update_command_state(self, target, action_id);
}
