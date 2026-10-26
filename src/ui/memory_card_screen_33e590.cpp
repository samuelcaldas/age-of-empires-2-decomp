#pragma exceptions off
#include "memory_card_screen.h"

extern "C" {
int func_0033EC50(MemoryCardScreen *self);
void func_0033F660(MemoryCardScreen *self);
void func_0033EC70(MemoryCardScreen *self, int a1);
void func_0033F9D0(MemoryCardScreen *self, int a1, int a2, int a3);
void func_2119B0(void *rect);
void func_225560(void *point);
int func_1F6660(MemoryCardScreen *self, int p1, int p2, void *rect);
}

extern "C" {

int func_0033E590(MemoryCardScreen *self, void *control, int action, int a3, int a4) {
    if (func_0033EC50(self)) {
        return 0;
    }

    if (control) {
        if (action == 1) {
            if (control == self->field_82C) {
                func_0033F660(self);
                return 1;
            }
            if (control == self->field_830) {
                int mode = self->field_808;
                if (mode == 0 || mode == 1) {
                    func_0033EC70(self, 3);
                } else if (self->field_840 < 100) {
                    int a2_val = 0;
                    if (mode == 4) {
                        a2_val = 0;
                    }
                    func_0033F9D0(self, 0, a2_val, -1);
                    func_0033EC70(self, 4);
                } else {
                    func_0033EC70(self, 5);
                }
                goto fallback;
            }
        }
    }

    if (control == self->field_824) {
        int rect[6];
        int pt[2];
        if ((action == 2 && a4 == 1) || action == 3) {
            func_2119B0(rect);
            func_225560(pt);
            if (func_1F6660(self, pt[0], pt[1], rect)) {
                int mode = self->field_808;
                if (mode == 0 || mode == 1) {
                    func_0033EC70(self, 1);
                } else if (mode == 3) {
                    func_0033EC70(self, 1);
                } else if (mode == 4) {
                    int a2_val = 1;
                    if (mode != 4) {
                        a2_val = 0;
                    }
                    func_0033F9D0(self, 0, a2_val, -1);
                    func_0033EC70(self, 2);
                } else if (mode == 2) {
                    func_0033EC70(self, 7);
                }
            }
        }
    }

fallback:
    return func_1FBD30(self, (int)control, action, a3, a4);
}

}
