#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "zone_spatial_entity_rebind_motion_target.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad_00[0x9C];
    Vector3 vec_9c;
    Vector3 vec_a8;
};

static int s_calls_26aa00 = 0;
static int s_calls_3151e0 = 0;

extern "C" {
void func_26AA00(void *self, const void *dir, const void *up) {
    s_calls_26aa00++;
}

void func_3151E0(void *cross, const void *v1, const void *v2) {
    s_calls_3151e0++;
    Vector3 *c = (Vector3 *)cross;
    const Vector3 *a = (const Vector3 *)v1;
    const Vector3 *b = (const Vector3 *)v2;
    // Cross product: a x b
    c->x = a->y * b->z - a->z * b->y;
    c->y = a->z * b->x - a->x * b->z;
    c->z = a->x * b->y - a->y * b->x;
}
}

static void test_rebind_motion_target() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    Vector3 dir;
    dir.x = 1.0f;
    dir.y = 0.0f;
    dir.z = 0.0f;

    Vector3 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;

    s_calls_26aa00 = 0;
    s_calls_3151e0 = 0;

    func_001DFC60(&ent, &dir, &up);

    assert(s_calls_26aa00 == 1);
    assert(s_calls_3151e0 == 1);

    // vec_9c should be set to dir
    assert(ent.vec_9c.x == 1.0f);
    assert(ent.vec_9c.y == 0.0f);
    assert(ent.vec_9c.z == 0.0f);

    // up x dir = (0, 1, 0) x (1, 0, 0) = (0, 0, -1)
    // normalized: (0, 0, -1)
    assert(std::fabs(ent.vec_a8.x - 0.0f) < 1e-4f);
    assert(std::fabs(ent.vec_a8.y - 0.0f) < 1e-4f);
    assert(std::fabs(ent.vec_a8.z - (-1.0f)) < 1e-4f);
}

int main() {
    test_rebind_motion_target();
    std::printf("zone_spatial_entity_rebind_motion_target_test passed\n");
    return 0;
}
