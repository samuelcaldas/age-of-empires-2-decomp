#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_eval_motion_delta.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vec3f {
    float x;
    float y;
    float z;
};

struct MotionBlock {
    Vec3f delta;
    char pad[0x20];
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
    v.x = 1.0f;
    v.y = 2.0f;
    v.z = 3.0f;

    s_alloc_calls = 0;
    func_001DFD60(&ent, &v);

    assert(s_alloc_calls == 0);
    assert(mb.delta.x == 1.0f);
    assert(mb.delta.y == 2.0f);
    assert(mb.delta.z == 3.0f);
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
    func_001DFD60(&ent, &v);

    assert(s_alloc_calls == 0);
    assert(ent.motion == 0);
}

static void test_non_zero_allocates_and_sets() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.motion = 0;
    std::memset(&s_mock_motion, 0, sizeof(s_mock_motion));

    Vec3f v;
    v.x = 4.0f;
    v.y = 0.0f;
    v.z = 3.0f;

    s_alloc_calls = 0;
    func_001DFD60(&ent, &v);

    assert(s_alloc_calls == 1);
    assert(ent.motion == &s_mock_motion);
    assert(s_mock_motion.delta.x == 4.0f);
    assert(s_mock_motion.delta.y == 0.0f);
    assert(s_mock_motion.delta.z == 3.0f);
}

int main() {
    test_already_allocated();
    test_zero_vector_no_alloc();
    test_non_zero_allocates_and_sets();
    std::printf("zone_spatial_entity_eval_motion_delta_test passed\n");
    return 0;
}
