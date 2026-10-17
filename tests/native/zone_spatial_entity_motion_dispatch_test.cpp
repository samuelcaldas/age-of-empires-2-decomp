#include <cassert>
#include "zone_spatial_entity_calc_scale_factor.h"
#include "zone_spatial_entity_set_status_flag.h"
#include "zone_spatial_entity_get_waypoint_entry.h"
#include "zone_spatial_entity_dispatch_motion_callback.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int s_func_26AD30_called = 0;
static int s_func_26AD30_a1 = 0;
static int s_func_26AD30_a2 = 0;

extern "C" void func_26AD30(void *self, int a1, int a2) {
    s_func_26AD30_called++;
    s_func_26AD30_a1 = a1;
    s_func_26AD30_a2 = a2;
}

static int s_method1EC_called = 0;
static void mock_method1ec() {
    s_method1EC_called++;
}

static void *s_mock_vtable[256];

struct SubEntity {
    char pad[0x1C];
    float f1C;
};

struct ConfigEntity {
    char pad[0xA4];
    float fA4;
};

struct Vector3 {
    float x, y, z;
};

struct SpatialEntity {
    void *vtable;
    ConfigEntity *f4;
    char pad2[0x8];
    SubEntity *f10;
    char pad3[0x88 - 0x14];
    Vector3 *items;
    short count;
};

static void test_calc_scale_factor() {
    ConfigEntity cfg;
    cfg.fA4 = 10.0f;
    SubEntity sub;
    sub.f1C = 2.5f;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.f4 = &cfg;
    ent.f10 = &sub;

    assert(func_001DEA90(&ent) == 25.0f);

    sub.f1C = -1.0f;
    assert(func_001DEA90(&ent) == 10.0f);

    ent.f10 = nullptr;
    assert(func_001DEA90(&ent) == 10.0f);
}

static void test_set_status_flag() {
    SpatialEntity ent;
    s_func_26AD30_called = 0;
    func_001DEB40(&ent, 5);
    assert(s_func_26AD30_called == 1);
    assert(s_func_26AD30_a1 == 0x40);
    assert(s_func_26AD30_a2 == 5);
}

static void test_get_waypoint_entry() {
    Vector3 pts[4];
    pts[0].x = 1.0f; pts[0].y = 2.0f; pts[0].z = 3.0f;
    pts[1].x = 4.0f; pts[1].y = 5.0f; pts[1].z = 6.0f;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.items = pts;
    ent.count = 2;

    assert(func_001DEB50(&ent, -1) == nullptr);
    assert(func_001DEB50(&ent, 2) == nullptr);
    Vector3 *p0 = (Vector3 *)func_001DEB50(&ent, 0);
    assert(p0 != nullptr && p0->x == 1.0f && p0->y == 2.0f && p0->z == 3.0f);
}

static void test_dispatch_motion_callback() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method1ec;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.vtable = s_mock_vtable;

    s_method1EC_called = 0;
    func_001DEDB0(&ent);
    assert(s_method1EC_called == 1);
}

int main(int argc, char **argv) {
    test_calc_scale_factor();
    test_set_status_flag();
    test_get_waypoint_entry();
    test_dispatch_motion_callback();
    return 0;
}
