#include <cassert>
#include "zone_spatial_entity_get_angular_velocity.h"
#include "zone_spatial_entity_get_vertical_velocity.h"
#include "zone_spatial_entity_get_angular_rate_z.h"
#include "zone_spatial_entity_set_position_vector.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct Vector3 {
    float x, y, z;
};

static float s_m44_x = 0.0f;
static float s_m44_z = 0.0f;
static float s_m44_y = 0.0f;

static void mock_method44(void *self, float x, float z, float y) {
    s_m44_x = x;
    s_m44_z = z;
    s_m44_y = y;
}

static void *s_mock_vtable[256];

struct SpatialEntity {
    void *vtable;
    char pad[0x90 - 4];
    Vector3 pos_90;
    char pad2[0xBC - 0x9C];
    Vector3 *vel_vec;
};

static void test_get_vels() {
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    Vector3 out;
    func_001DFE00(&out, &ent);
    assert(out.x == 0.0f && out.y == 0.0f && out.z == 0.0f);
    assert(func_001DFEE0(&ent) == 0.0f);
    assert(func_001DFF70(&ent) == 0.0f);

    Vector3 vecs[2];
    vecs[0].x = 1.0f; vecs[0].y = 2.0f; vecs[0].z = 3.0f;
    vecs[1].x = 4.0f; vecs[1].y = 5.0f; vecs[1].z = 6.0f;
    ent.vel_vec = vecs;

    func_001DFE00(&out, &ent);
    assert(out.x == 4.0f && out.y == 5.0f && out.z == 6.0f);
    assert(func_001DFEE0(&ent) == 3.0f);
    assert(func_001DFF70(&ent) == 6.0f);
}

static void test_set_position_vector() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method44;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.vtable = s_mock_vtable;

    Vector3 pos;
    pos.x = 10.0f; pos.y = 20.0f; pos.z = 30.0f;

    func_001E00B0(&ent, &pos);
    assert(ent.pos_90.x == 10.0f && ent.pos_90.y == 20.0f && ent.pos_90.z == 30.0f);
    assert(s_m44_x == 10.0f && s_m44_z == 30.0f && s_m44_y == 20.0f);
}

int main(int argc, char **argv) {
    test_get_vels();
    test_set_position_vector();
    return 0;
}
