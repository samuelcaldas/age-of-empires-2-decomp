#pragma exceptions off
#include "unit_action_build_789a0.h"

extern "C" {
    int func_314550(void *world, void *target_ba0, int unit_idx, int mode);
}

typedef int (*RelationFn)(void *owner, void *target_ba0);
typedef int (*ValidateActionFn)(void *unit);

#if defined(__LP64__) || defined(_LP64)
#define UNIT_PROTO_OFFSET    0x8
#define UNIT_OWNER_OFFSET    0x10
#define OWNER_WORLD_OFFSET   0x1730
#define OWNER_ARRAY_OFFSET   0xE0
#define OWNER_RELATION_OFFSET 0x2E60
#define OWNER_BA0_OFFSET     0x1740
#else
#define UNIT_PROTO_OFFSET    0x4
#define UNIT_OWNER_OFFSET    0x8
#define OWNER_WORLD_OFFSET   0xB98
#define OWNER_ARRAY_OFFSET   0x70
#define OWNER_RELATION_OFFSET 0x1B30
#define OWNER_BA0_OFFSET     0xBA0
#endif

static bool check_allied_owners(void *self_owner, void *target_owner, int flag) {
    if (target_owner == self_owner) return true;
    if (flag != 1) return false;
    void *self_relation = *(void **)((char *)self_owner + OWNER_RELATION_OFFSET);
    RelationFn self_fn = *(RelationFn *)((char *)self_relation + 0x24);
    void *target_ba0 = *(void **)((char *)target_owner + OWNER_BA0_OFFSET);
    if (self_fn(self_owner, target_ba0) != 1) return false;
    void *target_relation = *(void **)((char *)target_owner + OWNER_RELATION_OFFSET);
    RelationFn target_fn = *(RelationFn *)((char *)target_relation + 0x24);
    void *self_ba0 = *(void **)((char *)self_owner + OWNER_BA0_OFFSET);
    return target_fn(target_owner, self_ba0) != 0;
}

static int check_builder_mode(void *self, void *target_owner, int unit_idx) {
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    if (*(short *)((char *)proto + 0xE) != 20) return 0;
    void **units = *(void ***)((char *)target_owner + OWNER_ARRAY_OFFSET);
    void *target_unit = units[unit_idx];
    if (*(unsigned char *)target_unit != 0x46) return 0;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    void *target_ba0 = *(void **)((char *)target_owner + OWNER_BA0_OFFSET);
    if (func_314550(world, target_ba0, unit_idx, 3) != 1) return 0;
    void **vtbl = *(void ***)self;
    ValidateActionFn validate = (ValidateActionFn)vtbl[56];
    return validate(self) & 1;
}

static int evaluate_garrison_flags(short target_type, unsigned char capability) {
    if (target_type == 0x2B || target_type == 0x2A || target_type == 0x12) {
        return (capability & 2) ? 1 : 0;
    }
    if (target_type == 0x13 || target_type == 0x4 || target_type == 0x24) {
        return (capability & 2) ? 1 : 0;
    }
    if (target_type == 0x39 || target_type == 0x2F || target_type == 0xC) {
        return (capability & 4) ? 1 : 0;
    }
    if (target_type == 0x2C || target_type == 0 || target_type == 0x38) {
        return (capability & 4) ? 1 : 0;
    }
    if (target_type == 0x2E || target_type == 0x2D || target_type == 0x6) {
        return 1;
    }
    if (target_type == 0x32) return 1;
    if (capability & 1) return 1;
    return (capability & 8) ? 1 : 0;
}

static int check_garrison_mode(void *self, void *target_owner, int unit_idx) {
    void **units = *(void ***)((char *)target_owner + OWNER_ARRAY_OFFSET);
    void *target_unit = units[unit_idx];
    if (*(unsigned char *)target_unit != 0x46) return 0;
    void *proto = *(void **)((char *)self + UNIT_PROTO_OFFSET);
    if (*(unsigned char *)proto != 0x50) return 0;
    void *attached_unit = *(void **)((char *)self + 0x130);
    void *eval_unit = (attached_unit != 0) ? attached_unit : self;
    void *eval_proto = *(void **)((char *)eval_unit + UNIT_PROTO_OFFSET);
    short max_hp = *(short *)((char *)eval_proto + 0x3E);
    float current_hp = *(float *)((char *)eval_unit + 0x30);
    if (current_hp <= ((float)max_hp * 0.5f)) return 0;
    if (*(signed char *)((char *)eval_proto + 0x1) <= 0) return 0;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    void *world = *(void **)((char *)owner + OWNER_WORLD_OFFSET);
    void *target_ba0 = *(void **)((char *)target_owner + OWNER_BA0_OFFSET);
    if (func_314550(world, target_ba0, unit_idx, 3) != 1) return 0;
    short target_type = *(short *)((char *)target_unit + 0xE);
    unsigned char capability = *(unsigned char *)((char *)eval_proto + 0x1A8);
    if (evaluate_garrison_flags(target_type, capability) != 1) return 0;
    void **vtbl = *(void ***)eval_unit;
    ValidateActionFn validate = (ValidateActionFn)vtbl[56];
    return validate(eval_unit) & 1;
}

int func_002789A0(void *self, void *target_owner, int unit_idx, int flag) {
    if (target_owner == 0) return 0;
    void *owner = *(void **)((char *)self + UNIT_OWNER_OFFSET);
    if (!check_allied_owners(owner, target_owner, flag)) return 0;
    unsigned char task_mode = *(unsigned char *)((char *)self + 0x39);
    if (task_mode == 2) {
        return check_builder_mode(self, target_owner, unit_idx);
    }
    return check_garrison_mode(self, target_owner, unit_idx);
}
