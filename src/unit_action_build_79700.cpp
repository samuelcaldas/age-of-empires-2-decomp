#pragma exceptions off
#include "unit_action_build_79700.h"

extern "C" {
    void func_267E60(void *self);
    void *func_332E60(void *world);
    int func_139720(void *action_mgr);
    void *func_139860(void *action_mgr);
    void *func_366D60(void *pool);
    void func_361370(void *task, void *self, void *s2, void *drop_site);
    void func_138D10(void *action_mgr);
}

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

typedef void *(*GetTargetFn)(void *task);
typedef int (*GetActionIdFn)(void *task);
typedef void (*SetCoordsFn)(void *task, void *target, float x, float y, float z);
typedef void *(*EvaluatePathFn)(void *self, void *target, int param, float x, float y, float z);
typedef void (*AssignTaskFn)(void *self, void *task);

void func_00279700(void *self) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (type != 0x2A && type != 0x3A) return;
    float remaining = *(float *)((char *)self + 0x40);
    if (remaining > 0.0f) return;
    func_267E60(self);
}

static int handle_existing_drop_task(void *self, void *drop_site, int target_type) {
    if (target_type == 0) return -1;
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    if (func_139720(action_mgr) == 0) return 0;
    void *task = func_139860(action_mgr);
    void **vtbl = *(void ***)task;
    GetTargetFn get_target = (GetTargetFn)vtbl[21];
    GetActionIdFn get_action = (GetActionIdFn)vtbl[8];
    if (get_target(task) == drop_site && get_action(task) == 0x95) return 1;
    if (func_139720(action_mgr) == 0) return 0;
    void *cur_task = func_139860(action_mgr);
    void **cur_vtbl = *(void ***)cur_task;
    GetActionIdFn cur_action_fn = (GetActionIdFn)cur_vtbl[8];
    if (cur_action_fn(cur_task) != 0x95) return 0;
    float dx = *(float *)((char *)drop_site + 0x44);
    float dy = *(float *)((char *)drop_site + 0x48);
    float dz = *(float *)((char *)drop_site + 0x4C);
    SetCoordsFn set_coords = (SetCoordsFn)cur_vtbl[15];
    set_coords(cur_task, drop_site, dx, dy, dz);
    return 1;
}

static int create_new_drop_task(void *self, void *drop_site) {
    float dx = *(float *)((char *)drop_site + 0x44);
    float dy = *(float *)((char *)drop_site + 0x48);
    float dz = *(float *)((char *)drop_site + 0x4C);
    void **vtbl = *(void ***)self;
    EvaluatePathFn eval_path = (EvaluatePathFn)vtbl[198];
    void *path_item = eval_path(self, drop_site, -1, dx, dy, dz);
    if (path_item == 0) return 0;
    void *new_task = func_366D60(0);
    if (new_task == 0) return 0;
    func_361370(new_task, self, path_item, drop_site);
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    func_138D10(action_mgr);
    AssignTaskFn assign_task = (AssignTaskFn)vtbl[196];
    assign_task(self, new_task);
    return 1;
}

int func_00279760(void *self, void *param1, int target_type) {
    (void)param1;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    void *drop_site = func_332E60(world);
    if (drop_site == 0) return 0;
    int existing_ret = handle_existing_drop_task(self, drop_site, target_type);
    if (existing_ret >= 0) return existing_ret;
    return create_new_drop_task(self, drop_site);
}
