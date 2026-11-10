#ifndef ZONE_CURSOR_CONTROLLER_TIMER_TICK_H
#define ZONE_CURSOR_CONTROLLER_TIMER_TICK_H

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

extern "C" {
void func_001DB7F0(CursorController *self);
}

#endif // ZONE_CURSOR_CONTROLLER_TIMER_TICK_H
