#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_copy_waypoint_list.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct SpatialEntity {
    char pad0[0x90];
    int field_90;
    char pad94[0x20];
    void *field_B4;
};

// Global context mock
struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

static GlobalContext s_ctx;
void *D_004E3180 = &s_ctx;

static int s_fce30_calls = 0;
static int s_fce00_calls = 0;
static int s_3334a0_calls = 0;
static int s_fd910_calls = 0;

static void *s_fce30_ret = 0;
static int s_fce00_ret = 0;
static void *s_3334a0_ret = 0;
static void *s_fd910_arg0 = 0;
static void *s_fd910_arg1 = 0;

extern "C" {
void *func_1FCE30(void *sub) {
    s_fce30_calls++;
    return s_fce30_ret;
}

int func_1FCE00(void *sub) {
    s_fce00_calls++;
    return s_fce00_ret;
}

void *func_3334A0(void *obj, int id) {
    s_3334a0_calls++;
    return s_3334a0_ret;
}

void func_1FD910(void *p0, void *p1) {
    s_fd910_calls++;
    s_fd910_arg0 = p0;
    s_fd910_arg1 = p1;
}
}

static void test_null_field_b4() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_B4 = 0;

    s_fce30_calls = 0;
    s_fd910_calls = 0;

    float ret = func_001DEFD0(&ent, 0);
    assert(ret == 0.0f);
    assert(s_fce30_calls == 0);
    assert(s_fd910_calls == 0);
}

static void test_fce30_found() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    int dummy_b4 = 0x1234;
    ent.field_B4 = &dummy_b4;

    s_fce30_calls = 0;
    s_fce00_calls = 0;
    s_3334a0_calls = 0;
    s_fd910_calls = 0;

    int dummy_target = 0x5678;
    s_fce30_ret = &dummy_target;

    float ret = func_001DEFD0(&ent, 0);
    assert(ret == 0.0f);
    assert(s_fce30_calls == 1);
    assert(s_fce00_calls == 0);
    assert(s_3334a0_calls == 0);
    assert(s_fd910_calls == 1);
    assert(s_fd910_arg0 == &dummy_target);
    assert(s_fd910_arg1 == (void *)((char *)&ent + 0x90));
}

static void test_fce00_fallback() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    int dummy_b4 = 0x1234;
    ent.field_B4 = &dummy_b4;

    s_fce30_calls = 0;
    s_fce00_calls = 0;
    s_3334a0_calls = 0;
    s_fd910_calls = 0;

    s_fce30_ret = 0;
    s_fce00_ret = 42;
    int dummy_target2 = 0x9ABC;
    s_3334a0_ret = &dummy_target2;

    float ret = func_001DEFD0(&ent, 0);
    assert(ret == 0.0f);
    assert(s_fce30_calls == 1);
    assert(s_fce00_calls == 1);
    assert(s_3334a0_calls == 1);
    assert(s_fd910_calls == 1);
    assert(s_fd910_arg0 == &dummy_target2);
    assert(s_fd910_arg1 == (void *)((char *)&ent + 0x90));
}

static void test_target_not_found() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    int dummy_b4 = 0x1234;
    ent.field_B4 = &dummy_b4;

    s_fce30_calls = 0;
    s_fce00_calls = 0;
    s_3334a0_calls = 0;
    s_fd910_calls = 0;

    s_fce30_ret = 0;
    s_fce00_ret = 42;
    s_3334a0_ret = 0;

    float ret = func_001DEFD0(&ent, 0);
    assert(ret == 0.0f);
    assert(s_fce30_calls == 1);
    assert(s_fce00_calls == 1);
    assert(s_3334a0_calls == 1);
    assert(s_fd910_calls == 0);
}

int main() {
    test_null_field_b4();
    test_fce30_found();
    test_fce00_fallback();
    test_target_not_found();
    std::printf("zone_spatial_entity_copy_waypoint_list_test passed\n");
    return 0;
}
