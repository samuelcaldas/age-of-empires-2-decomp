#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_tile_eval.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");

static int s_border_draw_calls = 0;
static int s_last_mark = 0;

static int s_sight_table[100];
void *D_50A5A0 = s_sight_table;

extern "C" {
int func_123350(float val) {
    return static_cast<int>(val);
}

void func_1aca60(void *, int, int, int, int, int mark) {
    s_border_draw_calls++;
    s_last_mark = mark;
}
}

static void reset_tracking() {
    s_border_draw_calls = 0;
    s_last_mark = 0;
    std::memset(s_sight_table, 0, sizeof(s_sight_table));
}

static void test_impassable_tile_aborts() {
    WaypointCostManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    WaypointCostCell grid[100];
    std::memset(grid, 0, sizeof(grid));
    // offset 2 is passable flag = 0
    *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(&grid[59]) + 2) = 0;

    mgr.m_grid = grid;
    mgr.m_field158 = 50;

    reset_tracking();
    func_00308C20(&mgr, 20, 30, 71, 2);

    assert(s_border_draw_calls == 0);
}

static void test_passable_visible_tile_draws_border() {
    WaypointCostManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    WaypointCostCell grid[100];
    std::memset(grid, 0, sizeof(grid));
    // passable flag = 1
    *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(&grid[59]) + 2) = 1;
    grid[59].m_field20 = 0.5f;

    short lookup_table[60] = {0, 100, 0};
    mgr.m_field150 = lookup_table;
    mgr.m_grid = grid;
    mgr.m_field158 = 50;
    mgr.m_field15C = 50;
    mgr.m_field0C = 0;
    mgr.m_field10 = 100;

    // Sight setup
    char player_buffer[3500];
    std::memset(player_buffer, 0, sizeof(player_buffer));
    *reinterpret_cast<int *>(player_buffer + 3108) = 0xFF; // mask
    *reinterpret_cast<void **>(reinterpret_cast<char *>(&mgr) + 288) = player_buffer;

    char sub292_dummy[64];
    *reinterpret_cast<void **>(reinterpret_cast<char *>(&mgr) + 292) = sub292_dummy;

    s_sight_table[30] = 0xFF; // sight bitmask matches

    reset_tracking();
    s_sight_table[30] = 0xFF;
    func_00308C20(&mgr, 20, 30, 71, 2);

    // 4 border segments drawn
    assert(s_border_draw_calls == 4);
    assert(s_last_mark == 71);
}

int main() {
    test_impassable_tile_aborts();
    test_passable_visible_tile_draws_border();
    return 0;
}
