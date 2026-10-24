#pragma exceptions off
#include "unit_action_build_78590.h"

extern "C" {
    void func_139E40();
    void func_26F590(void *target, void *self, float param1, float param2);
}

#if defined(__LP64__) || defined(_LP64)
#define ACTION_TARGET_OFFSET 0x38
#define UNIT_PROTO_OFFSET    0x8
#define UNIT_OWNER_OFFSET    0x10
#define OWNER_BA0_OFFSET     0x1740
#else
#define ACTION_TARGET_OFFSET 0x1C
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_OWNER_OFFSET    0x8
#define OWNER_BA0_OFFSET     0xBA0
#endif

typedef void (*ActionCallbackFn)(void *self);

void func_278590(void *self) {
    (void)self;
}

static bool check_target_validity(void *target, void *target_owner_data) {
    if (target == 0) return false;
    void *target_owner = *(void **)((char *)target + UNIT_OWNER_OFFSET);
    void *owner_data = *(void **)((char *)target_owner + OWNER_BA0_OFFSET);
    if (owner_data != target_owner_data) return false;
    void *target_proto = *(void **)((char *)target + UNIT_PROTO_OFFSET);
    return *(unsigned char *)target_proto == 0x50;
}

static void trigger_action_callbacks(void *self) {
    void *target = *(void **)((char *)self + ACTION_TARGET_OFFSET);
    if (target == 0) return;
    void **vtbl = *(void ***)self;
    ActionCallbackFn callback_e8 = (ActionCallbackFn)vtbl[58];
    callback_e8(self);
    ActionCallbackFn callback_7c = (ActionCallbackFn)vtbl[31];
    callback_7c(self);
}

void func_002785A0(void *self, void *target_owner_data, int flag) {
    func_139E40();
    if ((flag & 0xFF) == 0) return;
    void *target = *(void **)((char *)self + ACTION_TARGET_OFFSET);
    if (!check_target_validity(target, target_owner_data)) return;
    func_26F590(target, self, -1.0f, -1.0f);
    trigger_action_callbacks(self);
}
