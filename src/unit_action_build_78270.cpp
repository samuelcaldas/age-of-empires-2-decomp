#pragma exceptions off
#include "unit_action_build_78270.h"

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
#define UNIT_CMD_OFFSET      0x130
#define UNIT_ACTION_OFFSET   0x138
#define PROTO_TASKS_OFFSET   0x150
#else
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_CMD_OFFSET      0xC8
#define UNIT_ACTION_OFFSET   0xCC
#define PROTO_TASKS_OFFSET   0xC8
#endif

typedef int (*GetTaskActionFn)(void *task);
typedef void *(*SetTaskFn)(void *action_mgr, void *task_item, void *target, float x, float y, float z);
typedef void (*ApplyTaskFn)(void *self, void *task);

static bool matches_task_mode(void *item, int mode) {
    short action_type = *(short *)((char *)item + 0x6);
    short target_flag = *(short *)((char *)item + 0x8);
    if (mode == 1 && action_type == 0x7A && target_flag == 0x3) return true;
    return mode == 2 && action_type == 0x87 && target_flag == 0x4;
}

static void *find_mode_task_item(void *proto, int mode) {
    void *task_list = *(void **)((char *)proto + PROTO_TASKS_OFFSET);
    if (task_list == 0) return 0;
    short count = *(short *)((char *)task_list + 0x8);
    void **items = *(void ***)((char *)task_list + 0x4);
    for (int i = 0; i < count; ++i) {
        void *item = items[i];
        if (item != 0 && matches_task_mode(item, mode)) return item;
    }
    return 0;
}

static void *get_current_task(void *action_mgr, int mode, void *task_item) {
    if (mode == 2) {
        void *active_task = func_139860(action_mgr);
        if (active_task != 0 && *(short *)((char *)active_task + 0x4) == 0x87) {
            return task_item;
        }
    }
    return func_1398F0(action_mgr);
}

static void execute_mode_task(void *self, void *target, void *task_item, int mode) {
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    void *current_task = get_current_task(action_mgr, mode, task_item);
    float tx = *(float *)((char *)target + 0x44);
    float ty = *(float *)((char *)target + 0x48);
    float tz = *(float *)((char *)target + 0x4C);
    if (task_item != 0 && task_item == current_task) {
        if (func_139820(action_mgr, target, tx, ty, tz) == 0) return;
        void *task_obj = func_139860(action_mgr);
        void **vtbl = *(void ***)task_obj;
        GetTaskActionFn get_action = (GetTaskActionFn)vtbl[8];
        get_action(task_obj);
        return;
    }
    if (task_item == 0) return;
    void **mgr_vtbl = *(void ***)action_mgr;
    SetTaskFn set_task = (SetTaskFn)mgr_vtbl[4];
    void *new_task = set_task(action_mgr, task_item, target, tx, ty, tz);
    if (new_task == 0) return;
    void **task_vtbl = *(void ***)new_task;
    GetTaskActionFn get_action = (GetTaskActionFn)task_vtbl[8];
    get_action(new_task);
    void **self_vtbl = *(void ***)self;
    ApplyTaskFn apply_task = (ApplyTaskFn)self_vtbl[196];
    apply_task(self, new_task);
}

static void update_mode_command_state(void *self, void *target) {
    void *cmd_state = *(void **)((char *)self + UNIT_CMD_OFFSET);
    if (cmd_state == 0) return;
    void *cmd_obj = *(void **)cmd_state;
    func_147180(cmd_obj, -1);
    func_1471B0(cmd_obj, -1);
    short target_id = *(short *)((char *)target + 0x24);
    void *target_proto = *(void **)((char *)target + UNIT_PROTO_OFFSET);
    short target_type = *(short *)((char *)target_proto + 0xE);
    float tx = *(float *)((char *)target + 0x44);
    float ty = *(float *)((char *)target + 0x48);
    float tz = *(float *)((char *)target + 0x4C);
    func_14BD90(cmd_obj, target_id, target_type, tx, ty, tz);
    func_14BEF0(cmd_obj);
}

void func_00278270(void *self, void *target, int mode) {
    if (target == self) return;
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    int clean_mode = mode & 0xFF;
    void *task_item = find_mode_task_item(proto, clean_mode);
    if (task_item == 0) return;
    execute_mode_task(self, target, task_item, clean_mode);
    update_mode_command_state(self, target);
}
