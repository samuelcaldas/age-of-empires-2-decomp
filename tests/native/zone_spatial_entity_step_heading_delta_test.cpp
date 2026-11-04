#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "zone_spatial_entity_step_heading_delta.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual void m10();
    virtual void m14();
    virtual void m18();
    virtual void m1c();
    virtual void m20();
    virtual void m24();
    virtual void m28();
    virtual void m2c();
    virtual void m30();
    virtual void m34();
    virtual void m38();
    virtual void m3c();
    virtual void m40();
    virtual void method44(float x, float z, float y);

    char pad0[0x90 - 4];
    Vector3 pos;
    Vector3 direction;
};

static float s_called_x = 0.0f;
static float s_called_z = 0.0f;
static float s_called_y = 0.0f;
static int s_method44_calls = 0;

void SpatialEntity::m00() {}
void SpatialEntity::m04() {}
void SpatialEntity::m08() {}
void SpatialEntity::m0c() {}
void SpatialEntity::m10() {}
void SpatialEntity::m14() {}
void SpatialEntity::m18() {}
void SpatialEntity::m1c() {}
void SpatialEntity::m20() {}
void SpatialEntity::m24() {}
void SpatialEntity::m28() {}
void SpatialEntity::m2c() {}
void SpatialEntity::m30() {}
void SpatialEntity::m34() {}
void SpatialEntity::m38() {}
void SpatialEntity::m3c() {}
void SpatialEntity::m40() {}
void SpatialEntity::method44(float x, float z, float y) {
    s_called_x = x;
    s_called_z = z;
    s_called_y = y;
    s_method44_calls++;
}

extern "C" {
void func_314FE0(void *out, const void *in, float scale) {
    Vector3 *o = (Vector3 *)out;
    const Vector3 *i = (const Vector3 *)in;
    o->x = i->x * scale;
    o->y = i->y * scale;
    o->z = i->z * scale;
}
}

static void test_small_val_no_op() {
    SpatialEntity ent;
    std::memset(&ent.pad0, 0, sizeof(ent.pad0));
    ent.pos.x = 10.0f;
    ent.pos.y = 20.0f;
    ent.pos.z = 30.0f;
    ent.direction.x = 1.0f;
    ent.direction.y = 0.0f;
    ent.direction.z = 0.0f;

    s_method44_calls = 0;
    func_001E0000(&ent, 0.0000001f);
    assert(s_method44_calls == 0);
}

static void test_step_heading_delta_updates_and_calls_method() {
    SpatialEntity ent;
    std::memset(&ent.pad0, 0, sizeof(ent.pad0));
    ent.pos.x = 10.0f;
    ent.pos.y = 20.0f;
    ent.pos.z = 30.0f;
    ent.direction.x = 2.0f;
    ent.direction.y = 3.0f;
    ent.direction.z = 4.0f;

    s_method44_calls = 0;
    s_called_x = 0.0f;
    s_called_z = 0.0f;
    s_called_y = 0.0f;

    func_001E0000(&ent, 2.0f);

    assert(s_method44_calls == 1);
    assert(std::fabs(s_called_x - 14.0f) < 1e-4f);
    assert(std::fabs(s_called_y - 26.0f) < 1e-4f);
    assert(std::fabs(s_called_z - 38.0f) < 1e-4f);
}

int main() {
    test_small_val_no_op();
    test_step_heading_delta_updates_and_calls_method();
    std::printf("zone_spatial_entity_step_heading_delta_test passed\n");
    return 0;
}
