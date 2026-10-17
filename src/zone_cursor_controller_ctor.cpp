#pragma exceptions off

#include "zone_cursor_controller_ctor.h"

extern "C" {
int func_2261C0();
void func_224150();
}

struct CursorController {
    int f0;
    int f4;
    char pad_8[4];
    int fC;
    int f10;
    int f14;
    int f18;
    char pad_1C[0x2C - 0x1C];
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    char f40;
    char pad_41[0x140 - 0x41];
    int f140;
    int f144;
    int f148;
};

extern "C" CursorController *func_001DB460(CursorController *self) {
    self->fC = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f2C = 0;
    self->f30 = 0;
    self->f34 = 0;
    self->f0 = 0;
    self->f4 = 0;
    self->f140 = -1;
    self->f40 = 0;
    int t = func_2261C0();
    self->f38 = t - 0x24;
    self->f3C = 0;
    self->f148 = 1;
    self->f144 = 0;
    func_224150();
    return self;
}
