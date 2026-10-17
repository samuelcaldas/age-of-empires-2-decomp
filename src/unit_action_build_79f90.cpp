#pragma exceptions off
#include "unit_action_build_79f90.h"

extern "C" {
    void *func_139860(void *action_mgr);
    void *func_366D40(void *pool);
    void func_35FAC0(void *task, void *self, int param);
    void *func_366D90(void *pool);
    void func_364E20(void *task, void *self, void *target, int param, float x, float y);
}

typedef void (*SetTaskFn)(void *self, void *task);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET  0x8
#define UNIT_ACTION_OFFSET 0x138
#else
#define UNIT_PROTO_OFFSET  0x4
#define UNIT_ACTION_OFFSET 0xCC
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

static int dispatch_pack_task(void *self) {
    void *task = func_366D40(nullptr);
    if (task == 0) return 0;
    func_35FAC0(task, self, -1);
    void **vtbl = *(void ***)self;
    SetTaskFn set_task = (SetTaskFn)vtbl[196];
    set_task(self, task);
    return 1;
}

static int dispatch_unpack_task(void *self) {
    void *task = func_366D90(nullptr);
    if (task == 0) return 0;
    float sx = *(float *)((char *)self + 0x44);
    float sy = *(float *)((char *)self + 0x48);
    func_364E20(task, self, nullptr, -1, sx, sy);
    void **vtbl = *(void ***)self;
    SetTaskFn set_task = (SetTaskFn)vtbl[196];
    set_task(self, task);
    return 1;
}

int func_00279F90(void *self, int mode, int flag) {
    (void)mode;
    (void)flag;
    if (is_busy_packing(self)) return 0;
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (type == 0x36) return dispatch_pack_task(self);
    if (type == 0x33) return dispatch_unpack_task(self);
    return 0;
}
