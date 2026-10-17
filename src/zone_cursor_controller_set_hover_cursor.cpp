#pragma exceptions off

#include "zone_cursor_controller_set_hover_cursor.h"

struct CursorController {
    int max;
    char pad[0xC];
    int hover_cursor;
};

extern "C" void func_001DB790(CursorController *self, int val) {
    if (val >= 0 && val < self->max) {
        self->hover_cursor = val;
    }
}
