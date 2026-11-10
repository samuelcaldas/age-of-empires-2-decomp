#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_validate_bounds.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vector3 {
    float x;
    float y;
    float z;
};

struct WorldObj {
    char pad[0xB98];
    void *m_b98;
};

struct SpatialEntity {
    char pad[0x8];
    WorldObj *world;
    char pad_0c[0x84];
    Vector3 pos; // 0x90
};

static int s_calls_332e60 = 0;
static int s_calls_220 = 0;
static int s_calls_1fe340 = 0;
static void *s_mock_target = (void *)0x1234;

static void dummy_method220(void *target, void *out_sp90) {
    s_calls_220++;
    Vector3 *v = (Vector3 *)out_sp90;
    v->x = 100.0f;
    v->y = 200.0f;
    v->z = 300.0f;
}

static void *s_fake_target_vtable[0x224 / 4];

extern "C" {
void *func_332e60(void *mgr, int id) {
    s_calls_332e60++;
    return s_mock_target;
}

void func_1FE340(void *p0, void *p1, void *p2, void *p3, int p4, int p5, int p6, int p7) {
    s_calls_1fe340++;
}
}

static void test_validate_bounds_target_minus_one() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    s_calls_332e60 = 0;
    int ret = func_001DDBF0(&ent, -1, 0, 0, 0, 0, 1.0f);
    assert(ret == 0);
    assert(s_calls_332e60 == 0);
}

static void test_validate_bounds_success() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    WorldObj w;
    std::memset(&w, 0, sizeof(w));
    w.m_b98 = (void *)0x8888;
    ent.world = &w;

    void *fake_obj[1];
    std::memset(s_fake_target_vtable, 0, sizeof(s_fake_target_vtable));
    s_fake_target_vtable[0x220 / 4] = (void *)&dummy_method220;
    fake_obj[0] = s_fake_target_vtable;
    s_mock_target = fake_obj;

    s_calls_332e60 = 0;
    s_calls_220 = 0;
    s_calls_1fe340 = 0;

    int ret = func_001DDBF0(&ent, 42, 0, 0, 0, 0, 1.0f);
    assert(ret == 0);
    assert(s_calls_332e60 == 1);
    assert(s_calls_220 == 1);
    assert(s_calls_1fe340 == 1);
}

int main() {
    test_validate_bounds_target_minus_one();
    test_validate_bounds_success();
    std::printf("zone_spatial_entity_validate_bounds_test passed\n");
    return 0;
}
