#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_query_status.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct SpatialEntity {
    char pad_00[0x18];
    int field_18;
    char pad_1C[0x4C - 0x1C];
    float return_val;
};

static int s_calls_set_flag = 0;
static int s_calls_clear_flag = 0;
static float s_mock_prop = 5.0f;

extern "C" {
float func_267380(void *self) {
    return s_mock_prop;
}

void func_26AD30(void *self, int flag, int val) {
    s_calls_set_flag++;
}

void func_26AD60(void *self, int flag) {
    s_calls_clear_flag++;
}
}

static void test_query_status_match_sets_flag() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_18 = 1;
    ent.return_val = 42.0f;

    s_mock_prop = 5.0f;
    s_calls_set_flag = 0;
    s_calls_clear_flag = 0;

    float ret = func_001DD660(&ent, 5.0f);
    assert(ret == 42.0f);
    assert(s_calls_set_flag == 1);
    assert(s_calls_clear_flag == 0);
}

static void test_query_status_no_match_clears_flag() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_18 = 1;
    ent.return_val = 13.0f;

    s_mock_prop = 5.0f;
    s_calls_set_flag = 0;
    s_calls_clear_flag = 0;

    float ret = func_001DD660(&ent, 2.0f);
    assert(ret == 13.0f);
    assert(s_calls_set_flag == 0);
    assert(s_calls_clear_flag == 1);
}

static void test_query_status_field_18_zero_clears_flag() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.field_18 = 0;
    ent.return_val = 99.0f;

    s_mock_prop = 5.0f;
    s_calls_set_flag = 0;
    s_calls_clear_flag = 0;

    float ret = func_001DD660(&ent, 5.0f);
    assert(ret == 99.0f);
    assert(s_calls_set_flag == 1);
    assert(s_calls_clear_flag == 1);
}

int main() {
    test_query_status_match_sets_flag();
    test_query_status_no_match_clears_flag();
    test_query_status_field_18_zero_clears_flag();
    std::printf("zone_spatial_entity_query_status_test passed\n");
    return 0;
}
