#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_step_waypoint_motion.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct SubTypeObj {
    char pad[0xA8];
    void *field_A8;
    void *field_AC;
};

struct TargetObj {
    char pad[0xA8];
    void *field_A8;
    void *field_AC;
};

struct SpatialEntity {
    void **vtable;
    SubTypeObj *sub_type;
    char pad_08[0x8];
    void *field_10;
};

static int s_calls_267c20 = 0;
static int s_calls_method4c = 0;
static void *s_passed_method4c_arg = 0;

static void dummy_method4c(SpatialEntity *self, void *arg) {
    s_calls_method4c++;
    s_passed_method4c_arg = arg;
}

static void *s_fake_vtable[0x50 / 4];

extern "C" {
void func_267C20(void *self, void *target) {
    s_calls_267c20++;
}
}

static void test_step_waypoint_motion_matches_a8() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    std::memset(s_fake_vtable, 0, sizeof(s_fake_vtable));
    s_fake_vtable[0x4C / 4] = (void *)&dummy_method4c;
    ent.vtable = s_fake_vtable;

    SubTypeObj sub;
    std::memset(&sub, 0, sizeof(sub));
    sub.field_A8 = (void *)0x1111;
    sub.field_AC = (void *)0x2222;
    ent.sub_type = &sub;
    ent.field_10 = (void *)0x1111; // matches A8

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.field_A8 = (void *)0x8888;
    target.field_AC = (void *)0x9999;

    s_calls_267c20 = 0;
    s_calls_method4c = 0;
    s_passed_method4c_arg = 0;

    func_001DF2D0(&ent, &target);

    assert(s_calls_267c20 == 1);
    assert(s_calls_method4c == 1);
    assert(s_passed_method4c_arg == (void *)0x8888);
}

static void test_step_waypoint_motion_matches_ac() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    std::memset(s_fake_vtable, 0, sizeof(s_fake_vtable));
    s_fake_vtable[0x4C / 4] = (void *)&dummy_method4c;
    ent.vtable = s_fake_vtable;

    SubTypeObj sub;
    std::memset(&sub, 0, sizeof(sub));
    sub.field_A8 = (void *)0x1111;
    sub.field_AC = (void *)0x2222;
    ent.sub_type = &sub;
    ent.field_10 = (void *)0x2222; // matches AC

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.field_A8 = (void *)0x8888;
    target.field_AC = (void *)0x9999;

    s_calls_267c20 = 0;
    s_calls_method4c = 0;
    s_passed_method4c_arg = 0;

    func_001DF2D0(&ent, &target);

    assert(s_calls_267c20 == 1);
    assert(s_calls_method4c == 1);
    assert(s_passed_method4c_arg == (void *)0x9999);
}

int main() {
    test_step_waypoint_motion_matches_a8();
    test_step_waypoint_motion_matches_ac();
    std::printf("zone_spatial_entity_step_waypoint_motion_test passed\n");
    return 0;
}
