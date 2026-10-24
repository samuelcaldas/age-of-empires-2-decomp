#pragma exceptions off

#include "zone_cursor_controller_set_field_2c.h"

struct CursorController {
    char pad[0x2C];
    int f2C;
};

extern "C" void func_001DB650(CursorController *self, int val) {
    self->f2C = val;
}
