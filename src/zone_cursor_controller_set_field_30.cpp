#pragma exceptions off

#include "zone_cursor_controller_set_field_30.h"

struct CursorController {
    char pad[0x30];
    int f30;
};

extern "C" void func_001DB660(CursorController *self, int val) {
    self->f30 = val;
}
