#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "zone_spatial_entity_compute_rotation_matrix.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SubObj {
    char pad[0x3A];
    unsigned char count;
};

struct SpatialEntity {
    void **vtable;
    char pad_after_vtable[0x10 - 4];
    SubObj *sub_obj;
    char pad_14[0x35 - 0x14];
    unsigned char frame_index;
    char pad_36[0x7C - 0x36];
    float heading;
    char pad_80[0x9C - 0x80];
    Vector3 vec_9c;
    Vector3 vec_a8;
};

static int s_method240_calls = 0;
static void dummy_method240(SpatialEntity *self, const void *v1, const void *v2) {
    s_method240_calls++;
}

static void *s_fake_vtable[0x244 / 4];

extern "C" {
extern const void *D_938FC0;
const void *D_938FC0 = (const void *)0x1234;

void func_1D7ED0(void *out_matrix, const void *axis, float angle) {
    float *m = (float *)out_matrix;
    for (int i = 0; i < 9; ++i) {
        m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
    }
}

void func_1D8000(void *out_vec, const void *matrix, const void *in_vec) {
    Vector3 *o = (Vector3 *)out_vec;
    const Vector3 *i = (const Vector3 *)in_vec;
    o->x = i->x * 2.0f;
    o->y = i->y * 2.0f;
    o->z = i->z * 2.0f;
}
}

static void test_compute_rotation_matrix() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    std::memset(s_fake_vtable, 0, sizeof(s_fake_vtable));
    s_fake_vtable[0x240 / 4] = (void *)&dummy_method240;
    ent.vtable = s_fake_vtable;

    SubObj sub;
    sub.count = 16;
    ent.sub_obj = &sub;
    ent.frame_index = 3;

    ent.vec_9c.x = 3.0f;
    ent.vec_9c.y = 0.0f;
    ent.vec_9c.z = 4.0f;

    ent.vec_a8.x = 0.0f;
    ent.vec_a8.y = 5.0f;
    ent.vec_a8.z = 0.0f;

    s_method240_calls = 0;
    func_001E00F0(&ent);

    assert(s_method240_calls == 1);
    // Vectors should be normalized: 3/5, 0, 4/5
    assert(std::fabs(ent.vec_9c.x - 0.6f) < 1e-4f);
    assert(std::fabs(ent.vec_9c.z - 0.8f) < 1e-4f);
    assert(std::fabs(ent.vec_a8.y - 1.0f) < 1e-4f);

    // Heading calculation: (2 * pi / 16) * (3 + 1) = pi / 2 = ~1.570796f
    const float expected_heading = (6.2831853f / 16.0f) * 4.0f;
    assert(std::fabs(ent.heading - expected_heading) < 1e-3f);
}

int main() {
    test_compute_rotation_matrix();
    std::printf("zone_spatial_entity_compute_rotation_matrix_test passed\n");
    return 0;
}
