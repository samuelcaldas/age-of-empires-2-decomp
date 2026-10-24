#pragma exceptions off

#include "zone_cursor_controller_update_hover.h"

extern "C" {
void func_225560(void *pt);
void func_224300(int cursor_id);
}

struct Point {
    int x;
    int y;
};

struct CursorController {
    char pad_0[0xC];
    int normal_cursor;
    int hover_cursor;
    int active_cursor;
    int f18;
    int bound_left;
    int bound_top;
    int bound_right;
    int bound_bottom;
    int enabled;
    int active;
};

extern "C" int func_001DB6B0(CursorController *self) {
    Point pt;
    func_225560(&pt);
    if (self->enabled != 0 && self->active != 0) {
        if (pt.x >= self->bound_left && pt.x < self->bound_right &&
            pt.y >= self->bound_top && pt.y < self->bound_bottom) {
            self->active_cursor = self->hover_cursor;
        } else {
            self->active_cursor = self->normal_cursor;
        }
    } else {
        self->active_cursor = self->normal_cursor;
    }
    func_224300(self->active_cursor);
    return 1;
}
