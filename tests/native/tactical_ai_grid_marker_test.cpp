#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_grid_marker.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");

static int s_draw_line_calls = 0;
static int s_last_mark = 0;
static int s_last_x1 = 0;
static int s_last_y1 = 0;
static int s_last_x2 = 0;
static int s_last_y2 = 0;

extern "C" {
int func_123350(float val) {
    return static_cast<int>(val);
}

void func_1acf10(void *, int x1, int y1, int x2, int y2, int mark) {
    s_draw_line_calls++;
    s_last_x1 = x1;
    s_last_y1 = y1;
    s_last_x2 = x2;
    s_last_y2 = y2;
    s_last_mark = mark;
}
}

static void reset_tracking() {
    s_draw_line_calls = 0;
    s_last_mark = 0;
    s_last_x1 = 0;
    s_last_y1 = 0;
    s_last_x2 = 0;
    s_last_y2 = 0;
}

static void test_grid_marker_box_drawing() {
    WaypointCostManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    WaypointCostCell grid[100];
    std::memset(grid, 0, sizeof(grid));
    grid[59].m_field20 = 0.5f;

    short lookup_table[60] = {0, 100, 0};
    mgr.m_field150 = lookup_table;
    mgr.m_grid = grid;
    mgr.m_field158 = 50;
    mgr.m_field15C = 50;
    mgr.m_field0C = 0;
    mgr.m_field10 = 100;

    reset_tracking();
    func_00308A70(&mgr, 20, 30, 70, 4);

    // Two diagonal lines drawn across the box
    assert(s_draw_line_calls == 2);
    assert(s_last_mark == 70);
    // Center was (110, 150), radius 4 -> [106, 114] x [146, 154]
    assert(s_last_x1 == 114);
    assert(s_last_y1 == 146);
    assert(s_last_x2 == 106);
    assert(s_last_y2 == 154);
}

int main() {
    test_grid_marker_box_drawing();
    return 0;
}
