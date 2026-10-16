#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_waypoint_cost.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
static_assert(sizeof(WaypointCostCell) == 36, "WaypointCostCell ABI");
static_assert(sizeof(WaypointCostManager) == 588, "WaypointCostManager ABI");

static int s_now_timestamp = 1500;
static int s_virtual_call_arg = 0;
static bool s_virtual_called = false;
static int s_draw_vertical_count = 0;
static int s_draw_horizontal_count = 0;
static int s_last_mark = 0;

static void dummy_method10(void *, int arg) {
    s_virtual_called = true;
    s_virtual_call_arg = arg;
}

static void *s_vtable[16];

extern "C" {

int func_123350(float val) {
    return static_cast<int>(val);
}

int func_2261c0() {
    return s_now_timestamp;
}

void func_1ad450(void *, int, int, int, int mark) {
    s_draw_vertical_count++;
    s_last_mark = mark;
}

void func_1ad270(void *, int, int, int, int mark) {
    s_draw_horizontal_count++;
    s_last_mark = mark;
}

} // extern "C"

static void reset_test_state() {
    s_now_timestamp = 1500;
    s_virtual_call_arg = 0;
    s_virtual_called = false;
    s_draw_vertical_count = 0;
    s_draw_horizontal_count = 0;
    s_last_mark = 0;
    std::memset(s_vtable, 0, sizeof(s_vtable));
    s_vtable[10] = reinterpret_cast<void *>(dummy_method10);
}

static void test_empty_waypoints_no_op() {
    WaypointCostManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_vtable = s_vtable;

    reset_test_state();
    func_00307640(&mgr);

    assert(!s_virtual_called);
    assert(s_draw_vertical_count == 0);
    assert(s_draw_horizontal_count == 0);
}

static void test_active_waypoint_cost_evaluation() {
    WaypointCostManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_vtable = s_vtable;

    WaypointCostCell grid[100];
    std::memset(grid, 0, sizeof(grid));
    grid[10].m_field20 = 0.5f;

    short lookup_table[60] = {0, 100, 0};
    mgr.m_field150 = lookup_table;
    mgr.m_grid = grid;
    mgr.m_field158 = 50;
    mgr.m_field15C = 50;
    mgr.m_field0C = 0;
    mgr.m_field10 = 100;
    mgr.m_field14 = 500;
    mgr.m_field18 = 500;

    mgr.m_array1[0] = 1;
    mgr.m_array4[0] = 20.0f;
    mgr.m_array5[0] = 30.0f;
    mgr.m_array2[0] = 1000; // elapsed = 1500 - 1000 = 500 < 700 (radius 16, mark 71)

    reset_test_state();
    func_00307640(&mgr);

    assert(s_virtual_called);
    assert(s_virtual_call_arg == 2);
    assert(s_draw_vertical_count == 4);
    assert(s_draw_horizontal_count == 4);
    assert(s_last_mark == 71);
}

static void test_expired_waypoint_ignored() {
    WaypointCostManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_vtable = s_vtable;

    WaypointCostCell grid[100];
    std::memset(grid, 0, sizeof(grid));
    short lookup_table[60] = {0, 100, 0};
    mgr.m_field150 = lookup_table;
    mgr.m_grid = grid;
    mgr.m_field158 = 50;
    mgr.m_field15C = 50;

    mgr.m_array1[0] = 1;
    mgr.m_array4[0] = 20.0f;
    mgr.m_array5[0] = 30.0f;
    mgr.m_array2[0] = 1000;

    reset_test_state();
    s_now_timestamp = 4000; // elapsed = 3000 >= 2400 (radius 0)
    func_00307640(&mgr);

    assert(!s_virtual_called);
    assert(s_draw_vertical_count == 0);
    assert(s_draw_horizontal_count == 0);
}

int main() {
    test_empty_waypoints_no_op();
    test_active_waypoint_cost_evaluation();
    test_expired_waypoint_ignored();
    return 0;
}
