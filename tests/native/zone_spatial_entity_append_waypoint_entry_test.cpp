#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_append_waypoint_entry.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad_00[0xB4];
    void *field_B4;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

static int s_calls_fce30 = 0;
static int s_calls_fce00 = 0;
static int s_calls_3334a0 = 0;
static int s_calls_1fd910 = 0;
static Vector3 s_passed_waypoint;

static GlobalContext s_mock_ctx;
extern "C" {
void *D_004E3180 = &s_mock_ctx;

void *func_1FCE30(void *sub) {
    s_calls_fce30++;
    return 0; // force lookup
}

int func_1FCE00(void *sub) {
    s_calls_fce00++;
    return 42;
}

void *func_3334A0(void *obj, int id) {
    s_calls_3334a0++;
    return (void *)0x5678;
}

void func_1FD910(void *target, void *waypoint) {
    s_calls_1fd910++;
    if (waypoint) {
        s_passed_waypoint = *(Vector3 *)waypoint;
    }
}
}

static void test_append_waypoint_when_field_b4_null() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_B4 = 0;

    Vector3 wp;
    wp.x = 1.0f;
    wp.y = 2.0f;
    wp.z = 3.0f;

    s_calls_fce30 = 0;
    s_calls_1fd910 = 0;

    float ret = func_001DF060(&ent, &wp);
    assert(ret == 0.0f);
    assert(s_calls_fce30 == 0);
    assert(s_calls_1fd910 == 0);
}

static void test_append_waypoint_dispatches_to_1fd910() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_B4 = (void *)0x1234;

    Vector3 wp;
    wp.x = 10.0f;
    wp.y = 20.0f;
    wp.z = 30.0f;

    s_calls_fce30 = 0;
    s_calls_fce00 = 0;
    s_calls_3334a0 = 0;
    s_calls_1fd910 = 0;

    float ret = func_001DF060(&ent, &wp);
    assert(ret == 0.0f);
    assert(s_calls_fce30 == 1);
    assert(s_calls_fce00 == 1);
    assert(s_calls_3334a0 == 1);
    assert(s_calls_1fd910 == 1);
    assert(s_passed_waypoint.x == 10.0f);
    assert(s_passed_waypoint.y == 20.0f);
    assert(s_passed_waypoint.z == 30.0f);
}

int main() {
    test_append_waypoint_when_field_b4_null();
    test_append_waypoint_dispatches_to_1fd910();
    std::printf("zone_spatial_entity_append_waypoint_entry_test passed\n");
    return 0;
}
