#pragma exceptions off
#include "unit_action_build_79ba0.h"

extern "C" {
    int func_26AD20(void *self, int flag);
    void func_26AD30(void *self, int flag, int mode);
    int func_151970(void *obj);
    void *func_332E60(void *world, int res_type);
}

typedef void *(*GetTargetFn)(void *self);
typedef void *(*GetActiveObjFn)(void *self);
typedef void (*OrderDropFn)(void *self, short target_id, short target_type, float x, float y, float z);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET  0x8
#define UNIT_OWNER_OFFSET  0x10
#define OWNER_WORLD_OFFSET 0x1730
#else
#define UNIT_PROTO_OFFSET  0x4
#define UNIT_OWNER_OFFSET  0x8
#define OWNER_WORLD_OFFSET 0xB98
#endif

static void *resolve_drop_target(void *self) {
    void **vtbl = *(void ***)self;
    GetTargetFn get_target = (GetTargetFn)vtbl[55];
    void *target = get_target(self);
    if (target != 0) return target;
    GetActiveObjFn get_active = (GetActiveObjFn)vtbl[89];
    void *active = get_active(self);
    if (active == 0) return 0;
    int res_type = func_151970(*(void **)active);
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    return func_332E60(world, res_type);
}

static void order_idle_fallback(void *self) {
    *(short *)((char *)self + 0x10E) = -1;
    float sx = *(float *)((char *)self + 0x44);
    float sy = *(float *)((char *)self + 0x48);
    float sz = *(float *)((char *)self + 0x4C);
    void **vtbl = *(void ***)self;
    OrderDropFn order_drop = (OrderDropFn)vtbl[78];
    order_drop(self, -1, -1, sx, sy, sz);
}

static void order_deposit(void *self, void *target) {
    short target_id = *(short *)((char *)target + 0x24);
    *(short *)((char *)self + 0x10E) = target_id;
    void *target_proto = *(void **)((char *)target + UNIT_PROTO_OFFSET);
    short target_type = *(short *)((char *)target_proto + 0xE);
    float tx = *(float *)((char *)target + 0x44);
    float ty = *(float *)((char *)target + 0x48);
    float tz = *(float *)((char *)target + 0x4C);
    void **vtbl = *(void ***)self;
    OrderDropFn order_drop = (OrderDropFn)vtbl[78];
    order_drop(self, target_id, target_type, tx, ty, tz);
}

int func_00279BA0(void *self, int mode) {
    if (func_26AD20(self, 0x400) != 0) return 0;
    func_26AD30(self, 0x400, mode);
    void *target = resolve_drop_target(self);
    if (target == 0) {
        order_idle_fallback(self);
        return 0;
    }
    order_deposit(self, target);
    return 1;
}
