#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_waypoint_step.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
static_assert(sizeof(WaypointActionManager) == 588, "WaypointActionManager ABI");

static int s_render_point_calls = 0;
static int s_render_target_calls = 0;
static float s_last_point_x = 0.0f;
static float s_last_point_y = 0.0f;
static int s_last_target_tx = 0;
static int s_last_target_ty = 0;

static int s_dummy_renderer = 0x186010;
void *D_004E3180 = &s_dummy_renderer;

extern "C" {

void *func_186010(void *global) {
    assert(global == D_004E3180);
    return global;
}

void func_204920(void *, int zero, float x, float y) {
    assert(zero == 0);
    s_render_point_calls++;
    s_last_point_x = x;
    s_last_point_y = y;
}

int func_123350(float val) {
    return static_cast<int>(val);
}

void func_204910(void *, int tx, int ty) {
    s_render_target_calls++;
    s_last_target_tx = tx;
    s_last_target_ty = ty;
}

} // extern "C"

static void reset_tracking() {
    s_render_point_calls = 0;
    s_render_target_calls = 0;
    s_last_point_x = 0.0f;
    s_last_point_y = 0.0f;
    s_last_target_tx = 0;
    s_last_target_ty = 0;
}

static void test_active_waypoint_rendering_and_decrement() {
    WaypointActionManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    mgr.m_field1B2 = 2;
    mgr.m_array1[2] = 1;
    mgr.m_array4[2] = 15.0f;
    mgr.m_array5[2] = 25.0f;

    reset_tracking();
    func_00307A00(&mgr);

    assert(s_render_point_calls == 1);
    assert(s_render_target_calls == 1);
    assert(s_last_point_x == 15.0f);
    assert(s_last_point_y == 25.0f);
    assert(s_last_target_tx == 15);
    assert(s_last_target_ty == 25);
    assert(mgr.m_field1B2 == 1);
}

static void test_inactive_waypoint_fallback_to_field1D0() {
    WaypointActionManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    mgr.m_field1B2 = 2;
    mgr.m_array1[2] = 0; // inactive
    mgr.m_field1D0 = 3;
    mgr.m_array1[3] = 1; // fallback active
    mgr.m_array4[3] = 50.0f;
    mgr.m_array5[3] = 60.0f;

    reset_tracking();
    func_00307A00(&mgr);

    assert(s_render_point_calls == 1);
    assert(s_render_target_calls == 1);
    assert(s_last_point_x == 50.0f);
    assert(s_last_point_y == 60.0f);
    assert(mgr.m_field1B2 == 2); // set to 3, then decremented to 2
}

static void test_inactive_waypoint_no_fallback_returns() {
    WaypointActionManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    mgr.m_field1B2 = 2;
    mgr.m_array1[2] = 0;
    mgr.m_field1D0 = -1; // no fallback

    reset_tracking();
    func_00307A00(&mgr);

    assert(s_render_point_calls == 0);
    assert(s_render_target_calls == 0);
    assert(mgr.m_field1B2 == 2); // untouched
}

static void test_ring_buffer_wrap() {
    // Case 1: m_field1B3 == 1 wraps to 4
    WaypointActionManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    mgr.m_field1B2 = 0;
    mgr.m_array1[0] = 1;
    mgr.m_field1B3 = 1; // full ring buffer

    reset_tracking();
    func_00307A00(&mgr);

    assert(mgr.m_field1B2 == 4);

    // Case 2: m_field1B3 == 0 restores m_field1D0
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_field1B2 = 0;
    mgr.m_array1[0] = 1;
    mgr.m_field1B3 = 0;
    mgr.m_field1D0 = 2;

    reset_tracking();
    func_00307A00(&mgr);

    assert(mgr.m_field1B2 == 2);
}

int main() {
    test_active_waypoint_rendering_and_decrement();
    test_inactive_waypoint_fallback_to_field1D0();
    test_inactive_waypoint_no_fallback_returns();
    test_ring_buffer_wrap();
    return 0;
}
