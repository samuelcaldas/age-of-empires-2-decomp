#include <cassert>
#include "zone_spatial_entity_has_positive_velocity.h"
#include "zone_spatial_entity_reset_motion_state.h"
#include "zone_spatial_entity_set_motion_scale.h"
#include "zone_spatial_entity_get_state_id.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int s_func_26A420_called = 0;
extern "C" void func_26A420(void *ent) {
    s_func_26A420_called++;
}

static float s_m258_val = -1.0f;
static float s_m260_val = -1.0f;
static int s_m144_val = -1;

static void mock_method258(void *self, float val) {
    s_m258_val = val;
}

static void mock_method260(void *self, float val) {
    s_m260_val = val;
}

static void mock_method144(void *self, int val) {
    s_m144_val = val;
}

static void *s_mock_vtable[256];

struct Vector3 {
    float x, y, z;
};

struct SubEntity {
    char pad[0x1C];
    float f1C;
};

struct SpatialEntity {
    void *vtable;
    char pad[0x24 - 4];
    short f24;
    char pad2[0xB4 - 0x26];
    SubEntity *fB4;
    char pad3[0xBC - 0xB8];
    Vector3 *vel_vec;
};

static void test_has_positive_velocity() {
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    assert(func_001E0280(&ent) == 0);

    Vector3 v;
    v.x = 0.0f; v.y = 0.0f; v.z = 0.0f;
    ent.vel_vec = &v;
    assert(func_001E0280(&ent) == 0);

    v.x = 1.0f;
    assert(func_001E0280(&ent) == 1);
}

static void test_reset_motion_state() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method144;
    s_mock_vtable[79] = (void *)mock_method144;
    s_mock_vtable[148] = (void *)mock_method258;
    s_mock_vtable[150] = (void *)mock_method260;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.vtable = s_mock_vtable;

    s_func_26A420_called = 0;
    func_001E02E0(&ent);
    assert(s_func_26A420_called == 1);
    assert(s_m258_val == 0.0f);
    assert(s_m260_val == 0.0f);
    assert(s_m144_val == 0);
}

static void test_set_motion_scale_and_state_id() {
    SubEntity sub;
    sub.f1C = 1.0f;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.fB4 = &sub;
    ent.f24 = 42;

    func_001E04D0(&ent, 2.5f);
    assert(sub.f1C == 2.5f);
    assert(func_001E04F0(&ent) == 42);
}

int main(int argc, char **argv) {
    test_has_positive_velocity();
    test_reset_motion_state();
    test_set_motion_scale_and_state_id();
    return 0;
}
