#pragma exceptions off
#include "unit_action_build_79110.h"

extern "C" {
    void *func_139860(void *action_mgr);
    int func_202B10(void *owner);
    void *func_366D40(void *pool);
    void *func_366D90(void *pool);
    void func_35FAC0(void *task, void *self, int param);
    void func_364E20(void *task, void *self, void *target, int param, float x, float y);
    void func_279B80(void *self, int param);
    void func_26AD60(void *self, int flag);
    void func_13A280(void *self, void *target, float x, float y, float z, int a2, int a3);
}

typedef int (*RelationFn)(void *owner, void *target_ba0);
typedef int (*CheckEligibilityFn)(void *self, void *target, int *out_val);
typedef void (*SetTaskFn)(void *self, void *task);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define UNIT_OWNER_OFFSET    0x10
#define UNIT_ACTION_OFFSET   0x138
#define OWNER_RELATION_OFFSET 0x2E60
#define OWNER_BA0_OFFSET     0x1740
#else
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_OWNER_OFFSET    0x8
#define UNIT_ACTION_OFFSET   0xCC
#define OWNER_RELATION_OFFSET 0x1B30
#define OWNER_BA0_OFFSET     0xBA0
#endif

static bool is_packing_or_unpacking(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    if (*(short *)((char *)proto + 0xE) != 0x36) return false;
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    void *active_task = func_139860(action_mgr);
    if (active_task == 0) return false;
    short action_id = *(short *)((char *)active_task + 0x4);
    return (action_id == 0x7D || action_id == 0x7C);
}

static bool is_target_allied(void *self, void *target) {
    if (target == 0) return false;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    if (func_202B10(owner) == 0) return false;
    void *relation_obj = *(void **)((char *)owner + OWNER_RELATION_OFFSET);
    RelationFn check_fn = *(RelationFn *)((char *)relation_obj + 0x24);
    void *target_owner = *(void **)((char *)target + UNIT_OWNER_OFFSET);
    void *target_ba0 = *(void **)((char *)target_owner + OWNER_BA0_OFFSET);
    return check_fn(owner, target_ba0) != 0;
}

static bool handle_trebuchet_approach(void *self, void *target, short proto_type, int eligible) {
    if (proto_type == 0x36 && eligible == 0) {
        void *task = func_366D40(0);
        if (task == 0) return true;
        func_35FAC0(task, self, -1);
        void **vtbl = *(void ***)self;
        SetTaskFn set_task = (SetTaskFn)vtbl[196];
        set_task(self, task);
        return true;
    }
    return false;
}

static bool handle_trebuchet_unpack_attack(void *self, void *target, short proto_type, int eligible) {
    if (proto_type == 0x33 && eligible == 0) {
        void *task = func_366D90(0);
        if (task == 0) return true;
        float self_x = *(float *)((char *)self + 0x44);
        float self_y = *(float *)((char *)self + 0x48);
        func_364E20(task, self, target, -1, self_x, self_y);
        void **vtbl = *(void ***)self;
        SetTaskFn set_task = (SetTaskFn)vtbl[196];
        set_task(self, task);
        return true;
    }
    return false;
}

static bool process_siege_targeting(void *self, void *target) {
    int out_val = 0;
    void **vtbl = *(void ***)self;
    CheckEligibilityFn check_fn = (CheckEligibilityFn)vtbl[211];
    int eligible = check_fn(self, target, &out_val);
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short proto_type = *(short *)((char *)proto + 0xE);
    if (handle_trebuchet_approach(self, target, proto_type, eligible)) return true;
    return handle_trebuchet_unpack_attack(self, target, proto_type, eligible);
}

void func_00279110(void *self, void *target, float x, float y, float z, int param_a2, int param_a3) {
    if (is_packing_or_unpacking(self)) return;
    if (is_target_allied(self, target)) return;
    if (target != 0 && process_siege_targeting(self, target)) return;
    func_13A280(self, target, x, y, z, param_a2, param_a3);
}
