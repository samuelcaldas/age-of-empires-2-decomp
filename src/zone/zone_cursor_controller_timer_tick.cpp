#pragma exceptions off

#include "zone_cursor_controller_timer_tick.h"

extern "C" {
int func_2261c0();
void func_1947B0(void *ptr);
int func_001DB6B0(void *self);
extern void *D_004E3108;
}

extern "C" void func_001DB7F0(CursorController *self) {
    int now = func_2261c0();
    if (self->f148 != 0) {
        if ((unsigned int)(now - self->f144) > 0x32) {
            self->f144 = now;
            func_1947B0(D_004E3108);
        }
    }
    if ((unsigned int)(now - self->f38) < 0x22) {
        return;
    }
    if (func_001DB6B0(self) == 0) {
        return;
    }
    self->f38 = now;
    if (self->f34 != 0) {
        self->f18 = self->f14;
    }
}
