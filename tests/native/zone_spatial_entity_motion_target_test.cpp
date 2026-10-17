#include <cassert>
#include "zone_spatial_entity_finalize_motion_step.h"
#include "zone_spatial_entity_get_velocity_vector.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int s_func_1FCD90_called = 0;
extern "C" void func_1FCD90(void *p) {
    s_func_1FCD90_called++;
}

static int s_method274_called = 0;
static void mock_method274() {
    s_method274_called++;
}

static void *s_mock_vtable[256];

struct Vector3 {
    float x, y, z;
};

struct SpatialEntity {
    void *vtable;
    char pad[0xB4 - 4];
    void *fB4;
    char pad2[0xBC - 0xB8];
    Vector3 *vel_vec;
};

static void test_finalize_motion_step() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method274;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.vtable = s_mock_vtable;

    s_method274_called = 0;
    s_func_1FCD90_called = 0;
    func_001DFC10(&ent);
    assert(s_method274_called == 1);
    assert(s_func_1FCD90_called == 0);

    ent.fB4 = (void *)0x1234;
    func_001DFC10(&ent);
    assert(s_method274_called == 2);
    assert(s_func_1FCD90_called == 1);
}

static void test_get_velocity_vector() {
    Vector3 out;
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    Vector3 vel;
    vel.x = 2.0f; vel.y = 4.0f; vel.z = 6.0f;

    func_001DFD20(&out, &ent);
    assert(out.x == 0.0f && out.y == 0.0f && out.z == 0.0f);

    ent.vel_vec = &vel;
    func_001DFD20(&out, &ent);
    assert(out.x == 2.0f && out.y == 4.0f && out.z == 6.0f);
}

int main(int argc, char **argv) {
    test_finalize_motion_step();
    test_get_velocity_vector();
    return 0;
}
