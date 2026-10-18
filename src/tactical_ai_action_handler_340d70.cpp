#pragma exceptions off
#include "tactical_ai_action_handler_340d70.h"

extern "C" {
int func_21A1C0(TacticalObj_340D70 *self);
void func_341040(TacticalObj_340D70 *self);
int func_2261c0();

int func_00340D70(TacticalObj_340D70 *self, int cmd, int arg2) {
    (void)arg2;
    if (self->field_840 == -1) {
        return 0;
    }

    int s0 = self->field_84C;

    if (cmd == 255) goto L_255;
    if (cmd == 18) goto L_18;
    if (cmd == 17) goto L_17;
    if (cmd == 16) goto L_16;
    if (cmd == 14) goto L_14;
    if (cmd == 13) goto L_13;
    if (cmd == 10) goto L_10;
    if (cmd == 12) goto L_12;
    if (cmd == 11) goto L_11;
    goto L_not_11;

L_11:
    self->field_84C = 12;
    self->field_83C = 12;
    goto L_fb0;

L_12:
L_10:
    if (s0 != 28) {
        self->field_84C = 14;
        if (self->field_840 == 0 && s0 != 8) {
            self->vfunc_d0(self->field_830, 1, 0, 0);
            return 1;
        }
    }
    goto L_fb0;

L_13:
    self->field_84C = 15;
    goto L_fb0;

L_14:
    self->field_84C = 19;
    goto L_fb0;

L_16:
L_17:
    if (s0 == 16) {
        self->field_84C = 22;
    } else if (s0 == 8) {
        self->field_84C = 24;
    } else if (s0 == 9) {
        self->field_84C = 23;
    } else {
        self->field_84C = 21;
    }
    goto L_fb0;

L_18:
    if (s0 == 9) {
        func_21A1C0(self);
    }
    if (s0 == 9) {
        self->field_84C = 25;
        func_341040(self);
        self->field_854 = func_2261c0();
        self->field_858 = 0;
    } else if (s0 == 8) {
        self->field_84C = 26;
        func_341040(self);
        self->field_854 = func_2261c0();
        self->field_858 = 0;
    } else if (s0 == 16) {
        self->field_84C = 27;
        func_341040(self);
        return 0;
    }
    self->vfunc_d0(self->field_830, 1, 0, 0xffff);
    return 1;

L_255:
    self->vfunc_1c(1);
    return 0;

L_fb0:
    if (cmd == 11) goto L_skip_850;
L_not_11:
    if (cmd == 17) goto L_skip_850;

    if ((unsigned int)(s0 - 8) < 2) {
        self->field_850 = self->field_84C;
        if (s0 == 9) {
            self->field_84C = 28;
        } else {
            self->field_84C = 29;
        }
    }

L_skip_850:
    if (s0 != self->field_84C) {
        if (s0 == 9) {
            func_21A1C0(self);
        }
        func_341040(self);
    }

    return 0;
}
}
