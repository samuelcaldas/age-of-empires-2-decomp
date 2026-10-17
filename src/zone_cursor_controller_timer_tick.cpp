#pragma exceptions off

#include "zone_cursor_controller_timer_tick.h"

extern "C" {
int func_2261C0();
void func_1947B0(void *ptr);
int func_1DB6B0(void *self);
extern void *D_004E3108;
}

struct CursorController {
    char pad_0[0x14];
    int f14;
    int f18;
    char pad_1C[0x34 - 0x1C];
    int f34;
    int f38;
    char pad_3C[0x144 - 0x3C];
    int f144;
    int f148;
};

extern "C" void func_001DB7F0(CursorController *self) {
    int now = func_2261C0();
    if (self->f148 == 0) {
        return;
    }
    if ((now - self->f144) >= 0x33) {
        self->f144 = now;
        func_1947B0(D_004E3108);
    }
    if ((now - self->f38) < 0x22) {
        return;
    }
    if (func_1DB6B0(self) == 0) {
        return;
    }
    self->f38 = now;
    if (self->f34 != 0) {
        self->f18 = self->f14;
    }
}
