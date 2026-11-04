#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_step_angular_motion.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vec3f {
    float x;
    float y;
    float z;
};

struct MotionBlock {
    Vec3f delta;
    Vec3f angular_velocity;
    char pad[0x14];
};

struct SpatialEntity {
    char pad[0xBC];
    MotionBlock *motion;
};

static int s_alloc_calls = 0;
static MotionBlock s_mock_motion;

extern "C" {
void *func_1FC3B0() {
    s_alloc_calls++;
    return &s_mock_motion;
}
}

static void test_already_allocated() {
    SpatialEntity ent;
    MotionBlock mb;
    std::memset(&ent, 0, sizeof(ent));
    std::memset(&mb, 0, sizeof(mb));
    ent.motion = &mb;

    Vec3f v;
    v.x = 1.5f;
    v.y = 2.5f;
    v.z = 3.5f;

    s_alloc_calls = 0;
    func_001DFE40(&ent, &v);

    assert(s_alloc_calls == 0);
    assert(mb.angular_velocity.x == 1.5f);
    assert(mb.angular_velocity.y == 2.5f);
    assert(mb.angular_velocity.z == 3.5f);
}

static void test_zero_vector_no_alloc() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.motion = 0;

    Vec3f v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;

    s_alloc_calls = 0;
    func_001DFE40(&ent, &v);

    assert(s_alloc_calls == 0);
    assert(ent.motion == 0);
}

static void test_nonzero_allocates_and_stores() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    std::memset(&s_mock_motion, 0, sizeof(s_mock_motion));
    ent.motion = 0;

    Vec3f v;
    v.x = 0.0f;
    v.y = 4.0f;
    v.z = 0.0f;

    s_alloc_calls = 0;
    func_001DFE40(&ent, &v);

    assert(s_alloc_calls == 1);
    assert(ent.motion == &s_mock_motion);
    assert(s_mock_motion.angular_velocity.x == 0.0f);
    assert(s_mock_motion.angular_velocity.y == 4.0f);
    assert(s_mock_motion.angular_velocity.z == 0.0f);
}

int main() {
    test_already_allocated();
    test_zero_vector_no_alloc();
    test_nonzero_allocates_and_stores();
    std::printf("zone_spatial_entity_step_angular_motion_test passed\n");
    return 0;
}
