#pragma exceptions off
#include "unit_action_build_79d80.h"

extern "C" {
    void *func_139860(void *action_mgr);
    void *func_332E60(void *world, int target_id);
    int func_202B10(void *owner);
    void *func_366D40(void *pool);
    void func_35FAC0(void *task, void *self, int param);
    void *func_366D90(void *pool);
    void func_364E20(void *task, void *self, void *target, int param, float x, float y);
}

typedef void (*OrderMoveFn)(void *self, void *target, int param1, int param2, float x, float y, float z);
typedef int (*CheckEligibilityFn)(void *self, void *target, int *out_val);
typedef void (*SetTaskFn)(void *self, void *task);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET  0x8
#define UNIT_OWNER_OFFSET  0x10
#define UNIT_ACTION_OFFSET 0x138
#define OWNER_WORLD_OFFSET 0x1730
#else
#define UNIT_PROTO_OFFSET  0x4
#define UNIT_OWNER_OFFSET  0x8
#define UNIT_ACTION_OFFSET 0xCC
#define OWNER_WORLD_OFFSET 0xB98
#endif

static bool is_busy_packing(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (type != 0x36 && type != 0x33) return false;
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    void *active = func_139860(action_mgr);
    if (active == 0) return false;
    short action_id = *(short *)((char *)active + 0x4);
    return (action_id == 0x7D || action_id == 0x7C);
}

static int order_packed_move(void *self, void *target) {
    float tx = *(float *)((char *)target + 0x44);
    float ty = *(float *)((char *)target + 0x48);
    float tz = *(float *)((char *)target + 0x4C);
    void **vtbl = *(void ***)self;
    OrderMoveFn order_move = (OrderMoveFn)vtbl[192];
    order_move(self, target, 1, -1, tx, ty, tz);
    return 1;
}

static int dispatch_siege_repack_task(void *self) {
    void *task = func_366D40(nullptr);
    if (task == 0) return 0;
    func_35FAC0(task, self, -1);
    void **vtbl = *(void ***)self;
    SetTaskFn set_task = (SetTaskFn)vtbl[196];
    set_task(self, task);
    return 0;
}

static int dispatch_siege_unpack_task(void *self, void *target) {
    void *task = func_366D90(nullptr);
    if (task == 0) return 0;
    float sx = *(float *)((char *)self + 0x44);
    float sy = *(float *)((char *)self + 0x48);
    func_364E20(task, self, target, -1, sx, sy);
    void **vtbl = *(void ***)self;
    SetTaskFn set_task = (SetTaskFn)vtbl[196];
    set_task(self, task);
    return 1;
}

static int handle_unpacked_siege(void *self, void *target) {
    int out_val = 0;
    void **vtbl = *(void ***)self;
    CheckEligibilityFn check_fn = (CheckEligibilityFn)vtbl[211];
    int eligible = check_fn(self, target, &out_val);
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (type == 0x36 && eligible == 0) {
        return dispatch_siege_repack_task(self);
    }
    if (eligible != 0 && type == 0x33) {
        return dispatch_siege_unpack_task(self, target);
    }
    return 0;
}

int func_00279D80(void *self, int target_id, int flag) {
    (void)flag;
    if (is_busy_packing(self)) return 0;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    void *target = func_332E60(world, target_id);
    if (target == 0) return 0;
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    if (*(short *)((char *)proto + 0xE) == 0x36) {
        return order_packed_move(self, target);
    }
    if (func_202B10(owner) == 0) return 0;
    return handle_unpacked_siege(self, target);
}
