#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "zone_spatial_entity_update_motion_step.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct TargetObj {
    void **vtable;
    char pad_after_vtable[0xB0 - 4];
    float fixed_speed;
};

struct SubTypeObj {
    char pad[0xA4];
    float max_speed;
};

struct Field10Obj {
    char pad[0x1C];
    float speed_multiplier;
};

struct Field08Obj {
    char pad[0xB98];
    void *field_B98;
};

struct SpatialEntity {
    void **vtable;
    SubTypeObj *sub_type;
    Field08Obj *field_08;
    char pad_0C[0x4];
    Field10Obj *field_10;
    char pad_14[0x24 - 0x14];
    short field_24;
    char pad_26[0x64 - 0x26];
    int field_64;
};

static void *s_fake_vtable[0x74 / 4];
static int s_vtable_70_result = 0;
static int s_b8c80_result = 0;
static int s_b94d0_result = 0;
static TargetObj s_mock_target;

static int dummy_method70(TargetObj *self) {
    return s_vtable_70_result;
}

extern "C" {
void *func_333B30(void *p0, int id) {
    return &s_mock_target;
}

int func_1B8C80(void *obj, short val) {
    return s_b8c80_result;
}

int func_1B94D0(void *obj, short val) {
    return s_b94d0_result;
}
}

static void test_motion_step_action_2_returns_zero() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    Field08Obj f08;
    std::memset(&f08, 0, sizeof(f08));
    ent.field_08 = &f08;

    std::memset(&s_mock_target, 0, sizeof(s_mock_target));
    s_fake_vtable[0x70 / 4] = (void *)&dummy_method70;
    s_mock_target.vtable = s_fake_vtable;

    s_vtable_70_result = 1;
    s_b94d0_result = 2;

    float res = func_001E0350(&ent, 1.0f, 0.5f, 2.0f);
    assert(res == 0.0f);
}

static void test_motion_step_with_multiplier() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    ent.field_08 = 0; // target is null

    SubTypeObj sub_type;
    sub_type.max_speed = 5.0f;
    ent.sub_type = &sub_type;

    Field10Obj f10;
    f10.speed_multiplier = 2.0f;
    ent.field_10 = &f10;

    // speed = 1.0 + 2.0 * 1.5 = 4.0 <= (5.0 * 2.0 = 10.0) -> returns 4.0f
    float res = func_001E0350(&ent, 1.0f, 1.5f, 2.0f);
    assert(std::fabs(res - 4.0f) < 1e-4f);
}

int main() {
    test_motion_step_action_2_returns_zero();
    test_motion_step_with_multiplier();
    std::printf("zone_spatial_entity_update_motion_step_test passed\n");
    return 0;
}
