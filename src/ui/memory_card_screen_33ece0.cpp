#pragma exceptions off
#include "memory_card_screen.h"
#include "memory_card_dialog.h"

extern "C" {
int func_0033F280(MemoryCardScreen *self, int has_card);
void func_0033EC70(MemoryCardScreen *self, int a1);
void func_0033F660(MemoryCardScreen *self);
int func_002193F0(void *ctrl);
void func_00344120(void *a0);
void func_344580(void *a0, void *a1);
void func_36BD30(void *a0, int a1, int a2, const char *a3, int t0, int t1);

extern void *D_004E3180;
extern const char D_4D5380[];
}

extern "C" {

void func_0033ECE0(MemoryCardScreen *self) {
    if (self->field_80C <= 0) {
        return;
    }
    int action = self->field_804;
    if (action <= 0) {
        return;
    }
    if ((unsigned int)action >= 13) {
        func_0033EC70(self, -1);
        return;
    }

    switch (action) {
    case 1:
        func_0033EC70(self, -1);
        break;
    case 3:
        func_0033EC70(self, -1);
        if (self->field_808 != 0) {
            func_0033F660(self);
        }
        break;
    case 4:
    case 10:
        func_0033F280(self, 1);
        func_0033EC70(self, -1);
        break;
    case 5:
        if (self->field_824) {
            func_002193F0(self->field_824);
        }
        func_0033EC70(self, -1);
        break;
    case 6:
        if (self->field_808 != 0) {
            func_0033EC70(self, 5);
        } else {
            func_0033EC70(self, 6);
        }
        break;
    case 7:
        if (self->field_808 != 0) {
            func_0033EC70(self, 25);
        } else {
            func_0033EC70(self, 26);
        }
        break;
    case 8:
        func_0033EC70(self, 10);
        break;
    case 9:
        func_0033EC70(self, 11);
        break;
    case 11: {
        void *s0 = *(void**)((char*)&D_004E3180 + 36);
        func_0033EC70(self, -1);
        func_00344120(s0);
        func_344580(s0, &self->pad_84C[0]);
        func_0033F660(self);
        break;
    }
    case 12:
        func_0033F280(self, 0);
        func_0033EC70(self, -1);
        break;
    default:
        func_0033EC70(self, -1);
        break;
    }
}

}
