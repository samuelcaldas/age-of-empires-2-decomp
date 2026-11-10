#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_reset_query_state.h"

struct SpatialGridState {
    char pad_00[0x12B574];
    int field_12B574;
    char pad_12B578[0x12B5B0 - 0x12B574 - 4];
    int field_12B5B0;
};

extern "C" {
static int g_func_1ED1F0_calls = 0;
static void *g_func_1ED1F0_self = nullptr;
static int g_observed_field_12B5B0_during_call = 0;
static int g_observed_field_12B574_during_call = 0;

void func_001ED1F0(SpatialGridState *self) {
    g_func_1ED1F0_calls++;
    g_func_1ED1F0_self = self;
    g_observed_field_12B5B0_during_call = self->field_12B5B0;
    g_observed_field_12B574_during_call = self->field_12B574;
}
}

static void test_layout() {
    assert(offsetof(SpatialGridState, field_12B574) == 0x12B574);
    assert(offsetof(SpatialGridState, field_12B5B0) == 0x12B5B0);
    assert(sizeof(SpatialGridState) == 0x12B5B4);
}

static void test_reset_query_state_behavior() {
    g_func_1ED1F0_calls = 0;
    g_func_1ED1F0_self = nullptr;
    g_observed_field_12B5B0_during_call = 0;
    g_observed_field_12B574_during_call = 0;

    SpatialGridState *state = (SpatialGridState *)std::malloc(sizeof(SpatialGridState));
    assert(state != nullptr);
    std::memset(state, 0x55, sizeof(SpatialGridState));

    state->field_12B574 = 100;
    state->field_12B5B0 = 200;

    func_001ED160(state);

    // Verified sequence and state mutations
    assert(g_func_1ED1F0_calls == 1);
    assert(g_func_1ED1F0_self == state);
    assert(g_observed_field_12B5B0_during_call == -2);
    assert(g_observed_field_12B574_during_call == 100);
    assert(state->field_12B5B0 == -2);
    assert(state->field_12B574 == -1);

    std::free(state);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
    case 0:
        test_layout();
        break;
    case 1:
        test_reset_query_state_behavior();
        break;
    default:
        return 2;
    }
    std::cout << "PASS" << std::endl;
    return 0;
}
