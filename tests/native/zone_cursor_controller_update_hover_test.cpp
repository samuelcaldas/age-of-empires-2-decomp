#include <cassert>
#include <cstdio>
#include <cstring>

#define func_225560 mock_func_225560
#define func_224300 mock_func_224300

static int g_225560_called = 0;
static int g_last_cursor_id = -1;
static int g_mock_x = 0;
static int g_mock_y = 0;

extern "C" {
void mock_func_225560(void *pt) {
    g_225560_called++;
    int *p = (int *)pt;
    p[0] = g_mock_x;
    p[1] = g_mock_y;
}

void mock_func_224300(int cursor_id) {
    g_last_cursor_id = cursor_id;
}
}

#include "../../src/zone/zone_cursor_controller_update_hover.cpp"

int main() {
    CursorController ctrl;
    memset(&ctrl, 0, sizeof(ctrl));

    ctrl.normal_cursor = 10;
    ctrl.hover_cursor = 20;
    ctrl.bound_left = 5;
    ctrl.bound_right = 15;
    ctrl.bound_top = 5;
    ctrl.bound_bottom = 15;
    ctrl.enabled = 1;
    ctrl.active = 1;

    // Inside bounds -> hover cursor
    g_mock_x = 10;
    g_mock_y = 10;
    int ret = func_001DB6B0(&ctrl);
    assert(ret == 1);
    assert(ctrl.active_cursor == 20);
    assert(g_last_cursor_id == 20);

    // Outside bounds -> normal cursor
    g_mock_x = 2;
    g_mock_y = 2;
    ret = func_001DB6B0(&ctrl);
    assert(ret == 1);
    assert(ctrl.active_cursor == 10);
    assert(g_last_cursor_id == 10);

    // Disabled -> normal cursor
    ctrl.enabled = 0;
    g_mock_x = 10;
    g_mock_y = 10;
    ret = func_001DB6B0(&ctrl);
    assert(ret == 1);
    assert(ctrl.active_cursor == 10);
    assert(g_last_cursor_id == 10);

    printf("zone_cursor_controller_update_hover_test passed\n");
    return 0;
}
