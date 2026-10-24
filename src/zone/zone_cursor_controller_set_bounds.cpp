#pragma exceptions off

#include "zone_cursor_controller_set_bounds.h"

struct CursorController {
    char pad[0x1C];
    int f1C;
    int f20;
    int f24;
    int f28;
};

extern "C" void func_001DB680(CursorController *self, int a1, int a2, int a3, int a4) {
    self->f1C = a1;
    self->f20 = a2;
    self->f24 = a3;
    self->f28 = a4;
}
