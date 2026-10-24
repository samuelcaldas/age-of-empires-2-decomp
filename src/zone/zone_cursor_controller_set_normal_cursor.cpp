#pragma exceptions off

#include "zone_cursor_controller_set_normal_cursor.h"

struct CursorController {
    int max;
    char pad[0x8];
    int normal_cursor;
};

extern "C" void func_001DB760(CursorController *self, int val) {
    if (val >= 0 && val < self->max) {
        self->normal_cursor = val;
    }
}
